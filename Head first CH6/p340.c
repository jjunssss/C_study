#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *question;
    struct node *no;
    struct node *yes;
} node;

int yes_no(char *question)
{
    char answer[3];
    printf("%s? (y/n): ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char *question)
{
    node *n = malloc(sizeof(node));
    n->question = strdup(question);
    n->no = NULL;
    n->yes = NULL;
    return n;
}

void release(node *n)
{
    if(n) {
        if (n->no)
            release(n->no);
        if (n->yes)
            release(n->yes);
        if (n->question)
            free(n->question);
        free(n);
    }
}

int main(){
    char question[80];
    char suspect[40];
    node *start_node = create("피의자가 수염이 있다");
    start_node->no = create("로레타 반스워쓰");
    start_node->yes = create("비니 더 스푼");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question))
            {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("피의자 확인됨\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                /* yes 노드에 새로운 피의자 이름 추가*/
                printf("새로운 피의자 이름?");
                fgets(suspect, 40, stdin);
                node *yes_node = create(suspect);
                current->yes = yes_node;

                /* no 노드에 새로운 피의자 이름 추가 */
                node *no_node = create(current->question);
                current->no = no_node;

                /* 그리고 다음의 새로운 질문으로 질문을 변경 */
                printf("%s에게는 참이지만 %s에게는 거짓인 새로운 질문을 입력하십시오", suspect, current->question);
                fgets(question, 80, stdin);
                current->question = strdup(question);

                break;
            }
        }
    } while (yes_no("다시 실행"));
    release(start_node);
    return 0;
}