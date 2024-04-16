#include <stdio.h>

int main() {
    int ary[100]={0};
    int count = 0;
    while(1){
        scanf("%d", &ary[count]);
        if(ary[count] == 0){
            break;
        }
        count ++;
    }
    double sum = 0;
    double avg = 0;
    int min = ary[0];
    int max = ary[0];
    
    for(int i = 0 ; i<count; i++){
        if(min>ary[i]){
            min = ary[i];
        }
        if(max<ary[i]){
            max = ary[i];
        }
        sum = sum + ary[i];    
    }
    avg = sum/count;
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
    printf("Avg = %.2lf\n", avg);
    
    return 0;
}
