#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortWithoutDuplication(int arry[], int *size){

    int i,j = 0;
    int tmp = 0;

    for(i = 0 ; i<*size ; i++){ 
        for(j = i+1 ; j<*size ; j++){
            if(arry[i]==arry[j]){
                for(int z = j ; z<*size-1 ; z++){
                    arry[z] = arry[z+1];
                    *size-=1;
                }
            }
        }
    } // 중복 삭제 과정에서 문제 있음. 해결 요망 //

    for(i = 0 ; i<*size ; i++){
        for(j=i ; j<*size ; j++){
            if(arry[i]>arry[j]){
                tmp = arry[j];
                arry[j] = arry[i];
                arry[i] = tmp;
            }
        }
    }
}


int main(void){
    int size = 10;
    int *psize = &size;
    int ary[10] = {0};
    
    for(int num = 0 ; num<size ; num++){
        scanf("%d", &ary[num]);
    }
    sortWithoutDuplication(ary, psize);

    for(int num = 0 ; num<size ; num++){
        printf("%d ", ary[num]);
    }

    return 0;
}
