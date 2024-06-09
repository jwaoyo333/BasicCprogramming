#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char name[20];
    double midterm;
    double final;
    double quiz;
}student;

typedef struct {
    int no;
    char name[20];
    double midterm;
    double final;
    double quiz;
    double total;
}score;

int main(void) {

    char fname[100];
    char oname[100];
    scanf("%s", fname);
    scanf("%s", oname);
    FILE* f = fopen(fname, "rb");
    FILE *of = fopen(oname, "w");

    
    
    int num = 0;

    fread(&num, sizeof(int), 1, f);
    student* ary = (student *)calloc(num, sizeof(student));
    fread(ary, sizeof(student),num,f);

    score *p = (score *)calloc(num, sizeof(score));
    for(int i = 0 ; i < num ; i++){
        p[i].no = i+1;
        p[i].midterm = ary[i].midterm;
        p[i].final = ary[i].final;
        p[i].quiz = ary[i].quiz;
        p[i].total = p[i].midterm+p[i].final+p[i].quiz;
        strcpy(p[i].name,ary[i].name);
    }
    for(int i = 0 ; i < num ; i++){
        fprintf(of,"%d %s %.1lf %.1lf %.1lf %.1lf \n",p[i].no,p[i].name,p[i].midterm,p[i].final,p[i].quiz,p[i].total);
    }
    
    return 0;
}
