#include <stdio.h>

int main()
{
    
    int a = 0;
    scanf("%d", &a);
    for(int i = 0 ; i< a; i++){
        for(int j = a-i-1 ; j>0;j-- ){
            printf("0");
        }
        for(int j = 0 ; j<i+1 ; j++){
            printf("%c", i+65);
        }
        printf("\n");
    }
    int b = a-1;
    for(int i = b ; i>0; i--){
        for(int j = 0 ; j<a-i ; j++){
            printf("0");
        }
        for(int j = i ; j>0 ; j--){
            printf("%c", i+64);
        }
        printf("\n");
    }
    
    return 0;
}
