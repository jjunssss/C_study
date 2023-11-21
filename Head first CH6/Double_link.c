#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NE
{
    struct NE* next;
    struct NE* prev;
    char data[10];
}NE;
typedef struct doublelink
{
    struct NE* head;
    struct NE* tail;
}doublelink;

doublelink* list;

void init()
{
    list = (doublelink*)malloc(sizeof(doublelink));
    list->head = NULL;
    list->tail = NULL;
}

struct NE* create(char *val)
{
    struct NE* ne = (NE*)malloc(sizeof(NE));
    ne->next = NULL;
    ne->prev = NULL;
    strcpy(ne->data, val);
    return ne;
}

void addne(char *val)
{
    struct NE* addne = create(val);
    if (list->tail == NULL) //NE가 없는 상태
    {
        list->head = addne; //addne에 head 선언
        list->tail = addne; //addne에 tail 선언
        list->tail->prev = list->head; //node의 prev를 head로
        list->head->next = list->tail; //node의 next를 tail로
    }
    else   // ne가 1개 이상
    {
        list->tail->next = addne; //원래 node의 next를 newaddne를 보게
        addne->prev = list->tail; // newaddne를 prev를 원래 node를 보게 
        list->tail = addne; //<- newaddne를 tail로 
    }
}

void delne(char *val)
{   
    if (list->tail == NULL)
    {
        printf("delne\n"); // list tail이 NULL이면 Head도 없음
        return;
    }
    struct NE* delne = list->head;
    while(delne != list->tail) //tail의 전까지 루프(while문을 돌지않으면 노드가 1개 이하)
    {
        if (strcmp(delne->data, val) == 0) // 찾는값과 같을 경우
        {
            delne->prev->next = delne->next;    //delne와 연결을 끊어줌
            delne->next->prev = delne->prev;
            printf("%s del\n", delne->data);
            free(delne); //메모리를 끊어줌
            break;
        }
        delne = delne->next;
    }
    if (strcmp(delne->data, val) == 0)
    {   
        if (delne == list->head) // node가 1개일 경우 NULL로 해제 
        {
            list->head = NULL;
            list->tail = NULL;
            printf("%s del\n", delne->data);
            free(delne);
        }
        else if (delne == list->tail) //끝 node인 tail을 지우게 될 경우
        {
            delne->prev->next = delne->prev;
            list->tail = delne->prev;
            printf("%s del\n", delne->data);
            free(delne);
        }
        
    }
}

void show()
{
    if (list->tail == NULL) // 값이 없을 경우 
    {
        printf("ne\n");
        return;
    }
    struct NE* ne = list->head;
    while(ne != list->tail) // tail전까지의 node
    {
        printf("%s->", ne->data);
        ne = ne->next;
    }
    printf("%s.\n", ne->data); // 마지막 node
}





int main()
{
    init();
    addne("20");
    // printf("%s", list->tail->data);
    addne("30");
    // printf("->%s", list->tail->data);
    addne("50");

    delne("30");
    show();
    delne("50");
    show();
    delne("20");
    show();
    delne("20");
    show();
}









