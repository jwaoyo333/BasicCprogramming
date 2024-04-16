#include <stdio.h>

void sort(int ary[]){
    int tmp;
    for(int i =0; i<10;i++){
        for(int j = i ; j<10 ; j++){
        if(ary[i]>ary[j]){
            tmp = ary[j];
            ary[j] = ary[i];
            ary[i] = tmp;
        }
        }
    }
    
    return;
}

int main(void){
    int a[5] = {0};
    int b[5] = {0};
    
    for(int i =0 ; i < 5 ; i++){
        scanf("%d", &a[i]);
    }
    for(int i =0 ; i < 5 ; i++){
        scanf("%d", &b[i]);
    }
    
    int c[10] = {0};
    
    for(int i = 0 ; i<5 ; i++){
        c[i] = a[i];
    }
    int num = 5;
    int check = 0;
    for(int i =0;i<5;i++){
        check = 0;
        for(int j = 0; j<5 ; j++){
            if(c[j]==b[i]){
                check = 1;
                break;
            }
        }
        if(check == 0){
            c[num] = b[i];
            num ++;
        }
    }
    
    sort(c);
    for(int i = 0 ; i<10 ; i++){
        if(c[i]==0){
            break;
        }
        printf("%d ", c[i]);
    }
    return 0;
}
