#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
// void delete_begin();
// void delete_end();
// void delete_pos();
 

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;

int main()     {
        int choice;
        while(1){
               
                printf(" 1.Create\n");
                printf(" 2.Display\n");
                printf(" 3.Insert at the beginning\n");
                printf(" 4.Insert at the end \n");
                printf(" 5.Insert at specified position\n");
                printf(" 6.Delete from beginning\n");
                printf(" 7.Delete from the end \n");
                printf(" 8.Delete from specified position \n");
                printf(" 9.Exit\n");
                printf(" Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        // case 6:
                        //                 delete_begin();
                        //                 break;
                        // case 7:
                        //                 delete_end();
                        //                 break;
                        // case 8:
                        //                 delete_pos();
                        //                 break;
                        
                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}

void create(){
        struct node *ptr,*temp;
        temp = (struct node *)malloc(sizeof(struct node));

        if (temp == NULL){
                printf("Out of Memory");
                return;
        }
        
        printf("Enter the number to store: ");
        scanf("%d",&temp->data);
        temp->next = NULL;

        if(start == NULL){
                start = temp;
        }
        else{
                ptr=start;
                while(ptr->next != NULL){
                        ptr = ptr->next;
                }
                ptr->next = temp;
        }
}

void display(){
        struct node *ptr;
        
        if(start == NULL){
                printf("The list is empty \n");
        }
        else {
                ptr = start;
                while(ptr->next != NULL) {
                        printf("%d -> ",ptr->data);
                        ptr = ptr->next;
                }
                printf("%d -> NULL\n", ptr->data);

        }
}

void insert_begin() {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL){
                printf("Out of memory");
                return;
        }
        printf("Enter the number to store: ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        if (start == NULL){
               start = temp;
        }
        else {
                temp->next = start;
                start = temp;
        }
}

void insert_end(){
        struct node *temp,*ptr;
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL){
                printf("Out of memory");
                return;
        }
        printf("Enter the number to store: ");
        scanf("%d",&temp->data);
        temp->next = NULL;
        if (start == NULL){
               start = temp;
        }
        else {
                ptr = start;
                while(ptr->next != NULL) {
                        printf("%d -> ",ptr->data);
                        ptr = ptr->next;
                }
                ptr->next = temp;  
        }
}

void insert_pos(){
        struct node *temp,*ptr;
        int pos;
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL){
                printf("Out of memory");
                return;
        }
        
        printf("Enter the number to store: ");
        scanf("%d",&temp->data);
        printf("Enter the position to insert: ");
        scanf("%d",&pos);
        temp->next = NULL;
        
        if (start == NULL){
               start = temp;
        }
        else{
                ptr = start;
                for(int i=0;i<pos-1;i++){
                        ptr=ptr->next;
                }
                temp->next = ptr->next;
                ptr->next = temp;
                
        }
}

