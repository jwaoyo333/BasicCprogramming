// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
    int num;
    struct linked_list * next;
}NODE;

typedef NODE* LINK;

NODE* create(int n){
    NODE* newnode = (NODE *)calloc(1,sizeof(NODE));
    newnode->num = n;
    newnode->next = NULL;
    
    return newnode;
}

NODE* append(LINK head, LINK next){
    LINK crt = head;
    while(crt->next!=NULL){
        crt = crt->next;
    }
    crt->next = next;
    
    return head;
}

NODE* appendHead(LINK head, LINK newnode){
    newnode->next = head;
    
    return newnode;
}

void print_list(LINK head){
    LINK crt = head;
    while(crt!=NULL){
        printf("%d\n", crt->num);
        crt = crt->next;
    }
    
    printf("###\n");
    return;
}

void insert(LINK newone, LINK head, int num){
    LINK p = head;
    for(int i = 1; i<num-1; i++){
        p = p->next;
    }
    LINK tmp = p->next;
    p->next = newone;
    newone->next = tmp;

    return;
}

int main() {
    LINK a = create(2);
    LINK b = create(3);
    LINK c = create(4);
    LINK d = create(5);
    
    LINK head = a;
    head=append(head, b);
    head=append(head, c);
    head=append(head, d);
    
    print_list(head);
    
    LINK e = create(8);
    head=appendHead(head, e);
    
    print_list(head);
    
    LINK f = create(0);
    insert(f,head,2);
    
    print_list(head);
    
    return 0;
}
