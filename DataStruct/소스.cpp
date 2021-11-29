#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* create_node(int value);
Node* add_node(Node* head,int item);
Node* delete_node(Node* head, int item);
Node* clear(Node* head);
int is_in_list(Node* head, int item);
int is_empty(Node* head);
void print_list(Node* head);

int main()
{
    int n, item;
    Node* head = NULL;

    while (1)
    {
        printf("------------------------------------------------------------------\n");
        printf("무엇을 하시겠습니까?\n");
        printf("1.add_node 2.delete_node 3.clear_list 4.print_list 5.exit\n");
        printf("------------------------------------------------------------------\n->");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                item;
                printf("추가할 item을 입력하세요 :");
                scanf("%d", &item);
                head = add_node(head, item);
                break;
            case 2:
                if (is_empty(head) == TRUE)
                {
                    printf("List is empty\n");
                    break;
                }
                item;
                printf("삭제할 item을 입력하세요 :");
                scanf("%d", &item);
                head = delete_node(head, item);
                break;
            case 3:
                head = clear(head);
                break;
            case 4:
                print_list(head);
                break;
            case 5:
                //종료시킬때 메모리에 있는 node들을 전부 free 시켜준다.
                head = clear(head);
                exit(0);
        }

    }

    return 0; 
}

Node* create_node(int value) {

    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    temp->data = value;
    temp->next = NULL;

    return temp;
}
Node* add_node(Node* head, int item)
{
    Node *tmp;
    Node* pre = head;
    tmp = create_node(item);

    if (tmp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }
    

    //case 1: 처음으로 값을 넣을때
    //case 2: item 값이 리스트에서 가장 작을때 --> insert_first
    if (head == NULL || pre->data >= item)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }

    while (1)
    {
        //case 3 : pre 노드보다 data 값은 크고 pre 노드가 마지막 노드이다 --> pre->next = tmp
        //case 4 : 두 케이스에 해당이 안되고 pre 노드의 다음 노드data 값보다 item값이 작을때  -->pre->next = tmp
        if (pre->next == NULL || pre->next->data >=item )
        {
            tmp->next = pre->next;
            pre->next = tmp;
            break;
        }

        pre = pre->next;
    }

    return head;
}
void print_list(Node* head)
{
    if (is_empty(head) == TRUE)
    {
        printf("List is Empty\n");
        return;
    }

    printf("print list : ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node* delete_node(Node* head, int item)
{
    if (is_in_list(head, item) == FALSE)
    {
        printf("List doesn't have '%d'\n",item);
        return head;
    }

    Node* pre = head;
    Node* tmp = NULL;

    //head node 삭제
    if (pre->data == item)
    {
        tmp = pre;
        head = pre->next;
        free(tmp);

        printf("'%d' is deleted'\n", item);
        return head;
    }

    while (1)
    {
        if (pre->next->data == item)
        {
            tmp = pre->next;
            pre->next = tmp->next;
            break;
        }
        pre = pre->next;
    }
    
    printf("'%d' is deleted'\n", item);

    free(tmp);
    return head;
}
Node* clear(Node* head)
{
    if (is_empty(head) == TRUE)
    {
        printf("List is Empty\n");
        return NULL;
    }
    
    Node* tmp = head;

    while (tmp != NULL)
    {
        Node* deleteNode = tmp;
        tmp = tmp->next;
        free(deleteNode);
    }

    printf("List is cleared\n");

    return NULL;
}
int is_in_list(Node* head, int item)
{
    Node* tmp = head;

    while (tmp != NULL)
    {
        if (tmp->data == item)
        {
            return TRUE;
        }
        tmp = tmp->next;
    }
    return FALSE;
}
int is_empty(Node* head)
{
    if (head == NULL)
        return TRUE;

    return FALSE;
}