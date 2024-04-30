#include <stdio.h>

int main(void){
    char* pc = (char*)100;
    int* pi = (int*)100;
    double* pd=(double*)100;

    printf("%lld %lld %lld\n", (long long)(pc-1),(long long)pc,(long long)(pc+1));
    printf("%llu %llu %llu\n", (unsigned long long)(pi-1),(unsigned long long)pi,(unsigned long long)(pi+1));
    printf("%llu %llu %llu\n", (unsigned long long)(pd-1),(unsigned long long)pd,(unsigned long long)(pd+1));

    return 0;
}
