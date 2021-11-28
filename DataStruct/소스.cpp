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
void delete_node(Node* head, int item);
void clear(Node* head);
int is_in_list(Node* head, int item);
int is_empty(Node* head);
void print_list(Node* head);

int main()
{
   Node* head = create_node(7);

   head = add_node(head,  0);
   head = add_node(head,  2);
   head = add_node(head,  5);
   head = add_node(head,  3);

    print_list(head);
    
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
    
    //case 1: item ���� ����Ʈ���� ���� ������ --> insert_first
    if (head->data > item)
    {
        tmp->next = head;
        head = tmp;
        return head;
    }

    while (1)
    {
        //case 2 : pre ��庸�� data ���� ũ�� pre ��尡 ������ ����̴� --> pre->next = tmp
        //case 3 : �� ���̽��� �ش��� �ȵǰ� pre ����� ���� ���data ������ item���� ������  -->pre->next = tmp
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
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
