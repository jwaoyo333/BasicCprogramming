// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list{
    double score;
    struct linked_list * next;
}NODE;
#define SIZE sizeof(NODE)
typedef NODE* PNODE;

//노드 생성
PNODE create(double num){
    PNODE newNode = calloc(1,SIZE);
    newNode->score = num;
    newNode->next = NULL;
    return newNode;
}

//프린트

void printlist(PNODE start){
    PNODE p = start;
    while(p != NULL){
        printf("%.2lf\n", p->score);
        p = p->next;
    }
    printf("____________________\n");
    return;
}

// 노드 추가

PNODE append(PNODE head, double num){
    PNODE h = head, nnode = create(num), crt;
    if(h == NULL){
        h = nnode;
        return h;
    }
    crt = head;
    while(crt->next != NULL){
        crt = crt->next;
    }
    crt->next = nnode;
    return h;
}

// 앞에 노드 추가

PNODE appendtoHead(PNODE head, double num){
    PNODE h = head, nnode = create(num);
    if(h == NULL){
        h = nnode;
        return h;
    }
    nnode->next = h;
    return nnode;
}

// 인덱스 기준 탐색
PNODE searchbyIndex(PNODE head, int goal){
    PNODE tmp = NULL, h = head;
    tmp = h;
    if(goal == 0){
        printf("오류가 발생했습니다\n");
        return NULL;
    }
    for(int i = 0 ; i<goal-1 ; i++){
        if(tmp->next == NULL){
            printf("오류가 발생했습니다\n");
            return NULL;
        }
        tmp = tmp->next;
    }
    
    return tmp;
}

// 인덱스 기준 삽입

PNODE insert(PNODE head, int index, double score){
    PNODE h =head , crt = head, tmp = NULL, nn = create(score);
    if(index == 0){
        h = appendtoHead(head, score);
        return h;
    }
    if(head == NULL){
        h = nn;
        return h;
    }
    
    for(int i = 1 ; i<index-1; i++){
        if(crt->next == NULL){
            h = append(head, score);
            return h;
        }
        crt = crt->next;
    }
    tmp = crt->next;
    crt->next = nn;
    nn->next = tmp;
    return h;
}

// 인덱스 기준 삭제

PNODE deleteNode(PNODE head, int index){
    PNODE h =head , crt = head, tmp = NULL;
    if(index<=1){
        crt = h->next;
        free(h);
        h = crt;
        return h;
    }
    if(head == NULL){
        return h;
    }
    
    for(int i = 1 ; i<index-1; i++){
        if(crt->next->next == NULL){
            return h;
        }
        crt = crt->next;
    }
    tmp = crt->next;
    crt->next = tmp->next;
    free(tmp);
    return h;
}


int main() {
    PNODE head = NULL;
    head = insert(head, 1, 7);
    printlist(head);
    head = append(head, 0);
    head = append(head,1);
    head = append(head, 2);
    head = appendtoHead(head, 3);
    head = appendtoHead(head, 4);
    head = append(head, 5);
    printlist(head);
    head = insert(head, 0, 6);
    printlist(head);
    head = insert(head, 1, 8);
    printlist(head);
    head = deleteNode(head, 10);
    printlist(head);

    return 0;
}
