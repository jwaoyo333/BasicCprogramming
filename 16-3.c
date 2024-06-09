#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct account{
    int accNum;
    char name[30];
    double balance;
}ACC;

int main(void){
    double sum = 0;
    int input = 0;
    int buffer = 0;
    char buf_name[30] = {0};
    double money = 0;
    ACC ary[100] = {0};
    int i = 0;
    while(1){
        scanf("%d", &input);
        if(input==1){ //추가
            FILE* f = fopen("bank.bin", "wb");
            while(1){
            label:
                scanf("%d", &buffer);
                if(buffer==-1){
                    fwrite(ary, sizeof(ACC), i, f);
                    fclose(f);
                    break;
                }
                ary[i].accNum = buffer;
                scanf("%s%lf",ary[i].name, &ary[i].balance);
                if(buffer<0){
                    goto label;
                }
                i ++;
            }
            
        }else if(input==2){//검색
            FILE* f = fopen("bank.bin", "rb");
            fread(ary,sizeof(ACC), i, f);
            scanf("%s", buf_name);
            for(int j = 0; j<i; j++){
                if(strcmp(buf_name,ary[j].name)==0){
                    printf("%d %s %.2lf\n", ary[j].accNum, ary[j].name, ary[j].balance);
                    break;
                }
            }
            fclose(f);
        }else if(input==3){//입금
            FILE* f = fopen("bank.bin", "rb");
            fread(ary,sizeof(ACC), i, f);
            fclose(f);
            f = fopen("bank.bin", "wb");
            scanf("%s%lf", buf_name, &money);
            for(int j = 0; j<i; j++){
                if(strcmp(buf_name,ary[j].name)==0){
                    ary[j].balance+=money;
                    printf("%d %s %.2lf\n", ary[j].accNum, ary[j].name, ary[j].balance);
                    break;
                }
            }
            fwrite(ary, sizeof(ACC), i, f);
            fclose(f);
        }else if(input==4){//출금
            FILE* f = fopen("bank.bin", "rb");
            fread(ary,sizeof(ACC), i, f);
            fclose(f);
            f = fopen("bank.bin", "wb");
            scanf("%s%lf", buf_name, &money);
            for(int j = 0; j<i; j++){
                if(strcmp(buf_name,ary[j].name)==0){
                    ary[j].balance-=money;
                    printf("%d %s %.2lf\n", ary[j].accNum, ary[j].name, ary[j].balance);
                    break;
                }
            }
            fwrite(ary, sizeof(ACC), i, f);
            fclose(f);
        }else if(input==5){//출력
            FILE* f = fopen("bank.bin", "rb");
            fread(ary,sizeof(ACC), i, f);
            sum = 0;
            for(int j = 0; j<i; j++){
                sum = sum + ary[j].balance;
            }
            printf("Total=%.2lf\n", sum);
            for(int j = 0; j<i; j++){
                    printf("%d %s %.2lf\n", ary[j].accNum, ary[j].name, ary[j].balance);
            }
            fclose(f);
        }else{
            return 0;
        }
    }
    return 0;
}
