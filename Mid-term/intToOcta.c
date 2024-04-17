#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void numCount(int ary[], int n, int ari[]){
    printf("intger %d is %#12o. \n", n, n);

    for(int i = 0 ; i<12 ; i++){
        switch(ary[i]){
            case 0:
                ari[0] = ari[0]+1;
                break;
            case 1:
                ari[1] ++;
                break;
            case 2:
                ari[2] ++;
                break;
            case 3:
                ari[3] ++;
                break;
            case 4:
                ari[4] ++;
                break;
            case 5:
                ari[5] ++;
                break;
            case 6:
                ari[6] ++;
                break;
            case 7:
                ari[7] ++;
                break;
            default:
                printf("error\n");
        }
    }

    for(int i = 0 ; i <8 ; i++){
        printf("%d in octa : %d\n", i , ari[i]);
    }
    return;
}

void dToO(int ary[], int n){
    for(int i = 0; i<12 ; i++){
        if(n==0){
            ary[i]=n;
            break;
        }
        ary[i]=n%8;
        n = n/8;
    }

    return;
}


int main(void){
    int answer[12]={0};
    int check[8] = {0};
    int num = 0;

    scanf("%d", &num);
    dToO(answer, num);
    numCount(answer, num, check);
    return 0;
}
