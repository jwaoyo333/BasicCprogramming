#include <stdio.h>

#define ROW 2
#define COL 3
int main(void){

    int td[][COL] = {{1,2,3},{4,5,6}};
    
    printf("%zd\n",sizeof(td));
    printf("%zd %zd\n",sizeof(td[0]),sizeof(td[1]));
    printf("%zd %zd\n",sizeof(*td),sizeof(*(td+1)));
    printf("%p %p\n",td,td+1);
    printf("%p %p\n",*td,*(td+1));

    for(int i=0,cnt =0 ; i<ROW; i++){

        printf("%p %p\n",td[i],*(td+i));
        for(int j =0;j<COL;j++, cnt++)
            printf("%d %d %d ", *(*td+cnt), *(td[i]+j), *(*(td+1)+j));
        printf("\n");
    }

    **td =10;
    *(*td+4) =20;
    *(*(td+1)+2) =30;
    pritnf("%d %d %d\n", td[0][0],td[1][1],td[1][2]);
    return 0;
}
