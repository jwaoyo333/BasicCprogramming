#include <stdio.h>

int main(void){
    int data = 10;
    int *p1 = NULL, *p2 = &data;

    printf("%d\n", data);
    printf("%p %p\n", p1,p2);

    return 0;
}
