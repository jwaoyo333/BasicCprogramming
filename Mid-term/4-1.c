#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binary(int x, int ary[]){
    for(int i =0 ; i<32 ; i++){
        if(x/2>0){
            if(x%2==0){
                ary[i]=0;
                x = x/2;
            }else if(x%2 == 1){
                ary[i]=1;
                x = x-1;
                x = x/2;
            }
        }else{
            if(x==1){
                ary[i]=1;
                x = 0;
                break;
            }
            ary[i] = 0;
        }
    }
}

int dtoo(int x){
    if(x==-2147483648){
        return 1;
    }

    int ari[32] = {0};
    int count = 0; 

    if(x<0){
        x = x*-1; // 절댓값
        binary(x,ari);
        for(int i =0 ; i<32 ; i++){
            if(ari[i]==1){
                ari[i]=0;
            }else if(ari[i]==0){
                ari[i]=1;
            }
        } // 1의 보수 취하기

        ari[0] = ari[0] + 1; // 2의 보수 1단계
        for(int i =0 ; i<32 ; i++){
            if(ari[i]==2&&i+1<32){
                ari[i]=0;
                ari[i+1]=ari[i+1]+1;
            }else if(ari[i]==2&&i==31){
                ari[i]=0;
            }
        } // 2의 보수 자릿수 정리.

        for(int i =0 ; i<32 ; i++){
            if(ari[i]==1){
                count ++;
            }
        } // 1의 갯수 세기

    }else if(x>0){
        binary(x, ari);
        for(int i =0 ; i<32 ; i++){
            if(ari[i]==1){
                count ++;
            }
        }
    }else{
        return 0;
    }
    return count;
}

int main(void){
    printf("1: %d\n", dtoo(1));
    printf("-1:%d\n", dtoo(-1));
    printf("3:%d\n", dtoo(3));
    printf("9:%d\n", dtoo(9));
    printf("7:%d\n", dtoo(7));
    printf("-21blah:%d\n", dtoo(-2147483648));
    printf("21blah:%d\n", dtoo(2147483647));
    printf("-256:%d\n", dtoo(-256));
    printf("0 : %d\n", dtoo(0));

    return 0;
}
