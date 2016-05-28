#define data 100
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

void bubble_set(char set[data]); //標準化
void set_arr(char set[data]); //校正格式
char * mfgets(char* s, int n, FILE* fp);

int main()
{
	FILE *fp1, *fp3;//檔案指標
	char safe[data]; //暫存字串
	int i = 0;


	fp1 = fopen("number.txt", "r");
	assert(fp1 != NULL);

	fp3 = fopen("set_number.txt", "w");
	assert(fp3 != NULL);

	while (mfgets(safe, data, fp1) != NULL)
	{
		bubble_set(safe);//標準化

		set_arr(safe);//校正格式

		if (safe[0] != '\0')
		{
			//            printf("%s\n", safe);//輸出（驗證）
			fprintf(fp3, "%s\n", safe);//印出
			i++;
		}
	}

	fprintf(stdout, "%d\n", i);

	fclose(fp1);
	fclose(fp3);


	system("pause");
	return 0;
}



void bubble_set(char set[data]) //標準化
{
	int i = 0, j = 0;

	for (i = data - 1; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (set[j] == '\n')
				break;

			if (set[j] == ' ' || set[j] == '	')
				set[j + 1] ^= set[j] ^= set[j + 1] ^= set[j];
		}
}



void set_arr(char set[data]) //校正格式
{
	int i = 0;

	for (i = 0; i < data; i++)
		if (set[i] == '\n' || set[i] == '\r') //在mac中 字串‘\n’為換行 , 還需‘\r’做迴車（ 跳回下一行之起始 ）
		{
			set[i] = '\0';
			break;
		}
}


char * mfgets(char* s, int n, FILE* fp) {
	char* p = s;   //  就是 p = &s[0];  // p points to s[0];
	int c, i = 0;  // 注意 c 要宣告成 int 用來讀取一個  char
	for (;; ) {
		c = fgetc(fp);  // 請 fgetc 從串流 fp 讀取一字
		if (c == -1) break;  // -1 是 EOF, 表示已經沒資料可讀了!
		s[i] = c;  //  有讀到就放入 Buffer  中
		++i;  // 已經讀了 i 個字, i 剛好指向下一個位置
		if (i >= (n - 1)) break;  // 至多讀取　n-1 個字
		if (c == '\n' || c == '\r') break;  // 已經讀到 NewLine '\n' 也要停
	} // for
	if (i == 0) return 0; // 啥碗糕都沒讀到就遇到EOF, 規定要回傳 0
						  // 注意, 啥都沒讀到時, 不可把EOF與'\0'填入 s
	s[i] = 0;  // 讓字串結束
	return s;  // 此例把 s 當 array, 配合s[i] 使用; 所以其實不必複製到 p
}
