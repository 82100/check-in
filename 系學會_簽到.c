#define data 20
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include <time.h>



struct List
{
    char student_number[data];//學號
    char name[data];//姓名
    char money[data];//繳系費
    char arrive[data];//已到
};

typedef struct List List;

int search(int *choose, struct List list, char number[20]);

int main()
{
    char number[data];
    int choose = 0;
    List list;
    FILE *fp;
    //    int i = 0 ;
    
    do{
        printf("<1> 開始簽到 <999> 清除資料 (-1結束) : ");
        scanf("%d", &choose);
    } while (choose != 1 && choose != 999 && choose != -1);
    
    if (choose == 1){
        fp = fopen("output.txt", "a+");
        assert(fp != NULL);
        fclose(fp);
    }
    
    else if (choose == 999){
        printf("確定清除資料 ?? <111> Yes  :");
        scanf("%d", &choose);
        if (choose == 111){
            fp = fopen("output.txt", "w");
            assert(fp != NULL);
            fclose(fp);
        }
    }
    
    while (choose == 1){
        strcpy(list.arrive, "未到");
        
        printf("輸入學號(-1結束):");
        scanf("%s", number);
        
        if (!strcmp(number, "-1"))
            break;
        
        search(&choose, list, number);
        
        //        strcpy( list.student_number , "\0") ;
        //        strcpy( list.name , "\0") ;
        //        strcpy( list.money , "\0") ;
        //        strcpy( list.arrive , "\0") ;
        //        strcpy( number , "\0") ;
        
        choose = 1;
        
    }
    
    //  system("pause");
    return 0;
}


int search(int *choose, struct List list, char number[20])
{
    FILE *fp, *fp2;
    List temp;
    
    //查詢個人資料
    fp = fopen("set_all.txt", "r");
    assert(fp != NULL);
    do{
        if ((fscanf(fp, "%s\t%s\t%s", list.student_number, list.name, list.money)) == EOF){
            printf("\n查無此人\n\n");
            fclose(fp);
            return 0;
        }
        
    } while (strcmp(number, list.student_number));
    fclose(fp);
    //end
    
    //確認無重複報到
    fp2 = fopen("output.txt", "r");
    assert(fp2 != NULL);
    while ((fscanf(fp, "%s\t%s\t%s\t%s", temp.student_number, temp.name, temp.money, temp.arrive)) != EOF)
    {
        if (!(strcmp(number, temp.student_number)) && !strcmp(temp.arrive, "到達") == 1)
        {
            printf("%s", temp.student_number);
            printf("%s", temp.name);
            printf("\n已簽到\n\n");
            fclose(fp2);
            return 0;
        }
    }
    fclose(fp2);
    // end
    
    
    printf("%s\n", list.student_number);
    printf("%s\n", list.name);
    printf("是否繳系費 : %s\n", list.money);
    printf("%s\n", list.arrive);
    
    do{
        printf("是否簽到? <1>是 <0>否 :");
        scanf("%d", &(*choose));
    } while (*choose != 1 && *choose != 0);
    
    if (*choose == 1){
        fp = fopen("output.txt", "a");
        assert(fp != NULL);
        
        printf("簽到中...\n");
        strcpy(list.arrive, "到達\0");
        printf("%s\n\n", list.arrive);
        
        fprintf(fp, "%s\t%s\t%s\t%s\n", list.student_number, list.name, list.money, list.arrive);
        fclose(fp);
    }
    
    
    if (*choose == 0)
        return 0;
    
    
    
    *choose = 0;
    return 0;
}