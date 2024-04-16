// Online C compiler to run C program online
#include <stdio.h>

void dtoo(int x){
    int ary[32] = {0};
    int octo[12] = {0};
    int count = 0;

    for(int i = 0 ; i<32 ; i++){
        if(x&1 == 1){
            ary[i]=1;
        }else{
            ary[i]=0;
        }
        x = x>>1;
    }
    for(int i = 0 ; i<32 ; i=i+3){
        if(ary[i] == 1){
            octo[count]+=1;
        }
        if(ary[i+1]==1){
            octo[count]+=2;
        }
        if(ary[i+2]==1&&i+2!=32){
            octo[count]+=4;
        }
        
        count ++;
    }
    for(int i = 0; i<12 ; i++){
        printf("%d", octo[i]);
    }
    
    return;
}

int main(void){
    
    dtoo(1);
    printf("\n");
    dtoo(3);
    printf("\n");
    dtoo(9);
        printf("\n");
    dtoo(7);
        printf("\n");
    dtoo(65602);
        printf("\n");
}
