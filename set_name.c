//�m�W�榡�B��
#define data 50
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void bubble_set(char set[data]);  //�зǤ�
void set_arr(char set[data]); //�ե��榡
char * mfgets(char* s, int n, FILE* fp);

int main() {
	int j = 0; //�p��
	FILE *fp1, *fp3;//�ɮ׫���
	char people[data];//�W��

	fp1 = fopen("name.txt", "r");
	//    assert(fp1 != NULL);
	fp3 = fopen("set_name.txt", "w");
	//    assert(fp3 != NULL);

	while (mfgets(people, data, fp1) != NULL)//���X�W�l
	{
		bubble_set(people);

		set_arr(people);

		if (people[0] != '\0')
		{
			fprintf(fp3, "%s\n", people);
			j++;
		}

	}
	fprintf(stdout, "%d\n", j);
	fclose(fp1);
	fclose(fp3);

	//    system("pause");
	return 0;
}


void bubble_set(char set[data]) //�зǤ�
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


void set_arr(char set[data]) //�ե��榡
{
	int i = 0;

	for (i = 0; i < data; i++)
		if (set[i] == '\n' || set[i] == '\r') //�bmac�� �r�ꡥ\n�������� , �ٻݡ�\r�����j���] ���^�U�@�椧�_�l
		{
			set[i] = '\0';
			break;
		}
}


char * mfgets(char* s, int n, FILE* fp) {
	char* p = s;   //  �N�O p = &s[0];  // p points to s[0];
	int c, i = 0;  // �`�N c �n�ŧi�� int �Ψ�Ū���@��  char
	for (;; ) {
		c = fgetc(fp);  // �� fgetc �q��y fp Ū���@�r
		if (c == -1) break;  // -1 �O EOF, ��ܤw�g�S��ƥiŪ�F!
		s[i] = c;  //  ��Ū��N��J Buffer  ��
		++i;  // �w�gŪ�F i �Ӧr, i ��n���V�U�@�Ӧ�m
		if (i >= (n - 1)) break;  // �ܦhŪ���@n-1 �Ӧr
		if (c == '\n' || c == '\r') break;  // �w�gŪ�� NewLine '\n' �]�n��
	} // for
	if (i == 0) return 0; // ԣ�J�|���SŪ��N�J��EOF, �W�w�n�^�� 0
						  // �`�N, ԣ���SŪ���, ���i��EOF�P'\0'��J s
	s[i] = 0;  // ���r�굲��
	return s;  // ���ҧ� s �� array, �t�Xs[i] �ϥ�; �ҥH��ꤣ���ƻs�� p
}

