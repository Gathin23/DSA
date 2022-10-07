#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL; // Initially the list is empty

void push(int);
void pop();
void display();

int main()
{
    int choice, value;
    while(1){
        printf("1. Push a value\n2. Pop a value\n3. Display Stack\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: printf("\nInvalid Choice\n");
    }}}


    //http://www.btechsmartclass.com/data_structures/stack-using-linked-list.html refer if doubt
    void push(int value)
    {
        struct Node *newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value; // get value for the node
        if(top == NULL)
            newNode->next = NULL;
        else
            newNode->next = top; // Make the node as TOP
        top = newNode;
        printf("Node is Inserted\n\n");
    }

    void pop()
    {
    if(top == NULL)
        printf("\nEMPTY STACK\n");
    else{
        struct Node *temp = top;
        printf("\nPopped Element : %d", temp->data);
        printf("\n");
        top = temp->next; // After popping, make the next node as TOP
        free(temp);
        }
    }

    void display()
    {
    // Print the stack
    if(top == NULL)
        printf("\nEMPTY STACK\n");
    else
    {
        printf("The stack is \n");
        struct Node *temp = top;
        while(temp->next != NULL){
            printf("%d -> ",temp->data);
            temp = temp -> next;
        }
        printf("%d -> NULL\n\n",temp->data);
    }
}