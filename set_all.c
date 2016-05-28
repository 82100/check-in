#define data 20
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include <time.h>

void set(char change[data]);

int main()
{
	FILE *fp1, *fp2, *fp3, *fp4;
	char student_number[data];//學號
	char name[data];//姓名
	char money[data];//繳系費

	fp1 = fopen("set_number.txt", "r");
	assert(fp1 != NULL);
	fp2 = fopen("set_name.txt", "r");
	assert(fp2 != NULL);
	fp3 = fopen("set_money.txt", "r");
	assert(fp3 != NULL);
	fp4 = fopen("set_all.txt", "w");
	assert(fp4 != NULL);

	while (fgets(money, data, fp3) != NULL)
	{
		fgets(student_number, data, fp1);
		fgets(name, data, fp2);

		set(money);
		set(student_number);
		set(name);


		//        fprintf( stdout  ,"%s \t %s \t %s\n", student_number , name , money ) ;
		fprintf(fp4, "%s \t %s \t %s\n", student_number, name, money);
	}


	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);

	//    system("pause");
	return 0;
}



void set(char change[data])
{
	int i = 0;

	for (i = 0; i < data; i++)
	{
		if (change[i] == '\n' || change[i] == ' ' || change[i] == '\r')
		{
			change[i] = '\0';
			break;
		}
	}
}