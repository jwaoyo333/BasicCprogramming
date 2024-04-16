#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumOneBit(int x){
    int ary[32] = {0};
    int count = 0;

    for(int i = 0 ; i<32 ; i++){
        if(x&1 == 1){
            ary[i]=1;
        }else{
            ary[i]=0;
        }
        x = x>>1;
    }

    for(int i =0 ; i<32 ; i++){
        if(ary[i]==1){
            count ++;
        }
    }
    return count;
}

int main(void){
    int input = 0;
    int sum = 0;
    while(1){
        scanf("%d", &input);
        if(input == 0){
            break;
        }
        sum = sum + sumOneBit(input);
    }

    printf("%d", sum);
    return 0;
}
