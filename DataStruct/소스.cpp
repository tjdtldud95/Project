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
        printf("������ �Ͻðڽ��ϱ�?\n");
        printf("1.add_node 2.delete_node 3.clear_list 4.print_list 5.exit\n");
        printf("------------------------------------------------------------------\n->");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                item;
                printf("�߰��� item�� �Է��ϼ��� :");
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
                printf("������ item�� �Է��ϼ��� :");
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
                //�����ų�� �޸𸮿� �ִ� node���� ���� free �����ش�.
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
    

    //case 1: ó������ ���� ������
    //case 2: item ���� ����Ʈ���� ���� ������ --> insert_first
    if (head == NULL || pre->data >= item)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }

    while (1)
    {
        //case 3 : pre ��庸�� data ���� ũ�� pre ��尡 ������ ����̴� --> pre->next = tmp
        //case 4 : �� ���̽��� �ش��� �ȵǰ� pre ����� ���� ���data ������ item���� ������  -->pre->next = tmp
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

    //head node ����
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