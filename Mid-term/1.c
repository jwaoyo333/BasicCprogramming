#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int ary[5];
    for(int i=0;i<5;i++){
        scanf("%d", &ary[i]);
    }

    double sum=0.0;
    double avg=0.0;
    int count = 0;

    for(int i=0;i<5;i++){
        if(ary[i]>0){
        sum=sum+ary[i];
        count ++;
        }
    }

    avg = sum / count;
    if(count == 0){
        printf("0");
        return 0;
    }
    printf("%.2lf", avg);

    return 0;
}
