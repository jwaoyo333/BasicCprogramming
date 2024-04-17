#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    char num = 97+rand()%26;
    char answer = 0;
    int count = 0;
    while(1){
        count ++;
        printf("맞히기 : ");
        scanf("%c",&answer);
        getchar();
        if(answer > num){
            printf("입력문자가 출력문자보다 큽니다.\n");
        }else if(answer<num){
            printf("입력문자가 출력문자보다 작습니다.\n");
        }else if(answer==num){
            printf("정답입니다! 시도 횟수 %d번\n", count);
            break;
        }

        
    }
    return 0;
}
