#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
    double num; // NODE의 value
    struct linked_list * next; // 다음 NODE를 가리키는 값
}NODE;

typedef NODE* LINK; // NODE를 가리키는 포인터 변수

NODE* create(double n){
    NODE* newnode = (NODE *)calloc(1,sizeof(NODE)); // NODE의 사이즈 만큼 메모리를 할당한 후 0으로 초기화
    newnode->num = n; // NODE에 value input
    newnode->next = NULL; //node의 next값 초기화
    
    return newnode; // 새롭게 만들어진 node를 return
}

NODE* appendNode(LINK head, double score){
    LINK newone = create(score); // create 변수를 활용, 새로운 인자로 들어온 score 값을 가지는 node 생성
    LINK crt = head; // 리스트의 마지막 값을 갖기 위한 임시 포인터
    while(crt->next!=NULL){
        crt = crt->next; // crt->next == NULL 리스트의 마지막 노드라는 뜻 때문에, cre->next가 NULL이 아닌 한 계속해서 갱신
    }
    crt->next = newone; // 마지막 노드의 next로 새로 선언된 노드를 결합
    
    return head; // 새롭게 만들어진 리스트의 시작부분을 반환
}

NODE* appendNodeToHead(LINK head, double score){
    LINK newnode = create(score); // create 변수를 활용, 새로운 인자로 들어온 score 값을 가지는 node 생성
    newnode->next = head; //새로운 노드의 뒤 노드로 head 연결
    
    return newnode; //새로운 head가 된 newnode를 반환
}

void print_list(LINK head){ //리스트의 현재 상태를 파악하기 위해 만든 함수
    LINK crt = head; // 리스트 탐색을 위한 임시 포인터 변수
    while(crt!=NULL){ //crt == NULL == 마지막 노드의 next값을 집어넣었다는 뜻 때문에 반복 종료
        printf("%lf\n", crt->num); //crt의 value 프린트
        crt = crt->next; // 다음 노드 탐색을 위해 임시 포인터 증가
    }
    
    printf("###\n"); // 리스트 구분을 위한 출력
    return;
}

NODE* insert(LINK head, double score, int index){
    LINK newone = create(score); // create 변수를 활용, 새로운 인자로 들어온 score 값을 가지는 node 생성
    LINK p = head; // 삽입 위치를 찾기 위한 임시 포인터 변수 p 선언
    for(int i = 1; i<index-1; i++){
        p = p->next; //첫 번째 노드부터 탐색을 진행하여 p를 index-1번째 노드로 설정, 이렇게 해야 삽입한 새로운 노드가 index번째에 위치함
    }
    LINK tmp = p->next; // 연결을 위한 임시 포인터 변수 tmp에 새로 추가될 노드에 연결될 현재의 index 번째 노드의 주소 넣음
    p->next = newone; //index-1번째의 다음 노드에 새로운 노드 추가 따라서 새로운 노드가 index번째가 됨
    newone->next = tmp;//index번째 노드가 된 newone의 다음 노드로 기존 노드 연결

    return head; //새롭게 구성된 리스트의 head를 return.
}

NODE* deleteNode(LINK head, int index){
    LINK tmp = head, p = head, last = head;// 삽입 위치를 찾기 위한 임시 포인터 변수 p 선언, 이후 이용할 tmp와 last 변수 선언
    for(int i = 1;i<index-1;i++){
        p = p->next;//첫 번째 노드부터 탐색을 진행하여 p를 index-1번째 노드로 설정
    }
    tmp = p->next; 
    tmp = tmp->next; // 두 행을 이용하여 tmp가 삭제할 노드의 다음 노드를 가리키도록 함
    last = p->next; //last가 삭제될 노드를 가리키도록 함 
    p->next = tmp; // index-1번째 노드를 index+1번째 노드를 연결하고
    free(last); // 삭제될 노드의 메모리를 해제
    
    return head; // 새롭게 구성된 리스트의 head를 리턴
}

int main() {
    LINK a = create(1);
    LINK head = a;
    head = appendNode(head, 2);
    
    print_list(head);
    
    head=appendNodeToHead(head, 0);
    print_list(head);
    
    head = insert(head, 1.2 , 3);
    print_list(head);
    
    
    head = deleteNode(head, 3);
    print_list(head);
    return 0;
}
