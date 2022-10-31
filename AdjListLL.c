#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node{
    int num;
    struct node *next;
};

struct node *graph[MAX];
int ct=0;

void insert(){
    int a;
    if(ct>=MAX)
        printf("OVERFLOW !!\n");
    else{
        printf("Enter the vertex: ");
        scanf("%d",&a);
        struct node *q=malloc(sizeof(struct node));
        q->num=a;
        q->next=NULL;
        graph[ct]=q;
        ct++;
        printf("Vertex created successfully.\n\n");
    }
}

void add_edge(){
    int v1,v2,flag=0;
    printf("Enter the adjacent vertices: ");
    scanf("%d",&v1);
    scanf("%d",&v2);

    for(int i=0; i<ct; i++){
        if((graph[i]->num)==v1){
            struct node *temp=graph[i];
            while(1){
                if(temp->next==NULL){
                    struct node *adj=malloc(sizeof(struct node));
                    adj->num=v2;
                    adj->next=NULL;
                    temp->next=adj;
                    flag=1;
                    break;
                }
                else
                    temp=temp->next;
            }
        }
        else if(graph[i]->num==v2){
            struct node *temp=graph[i];
            while(1){
                if(temp->next==NULL){
                    struct node *adj=malloc(sizeof(struct node));
                    adj->num=v1;
                    adj->next=NULL;
                    temp->next=adj;
                    flag=1;
                    break;
                }
                else{
                    temp=temp->next;
                }
            }
        }
    }

    if(flag==1)
        printf("Edge created..\n\n");
}

void bfs(){
    int queue[MAX],i,j;
    int front=0,rear=0,temp,flag=0;
    queue[rear]=graph[0]->num;
    struct node *p;
    while(front<=rear){
            for(i=0; i<ct; i++){
                if(queue[front]==graph[i]->num){
                    p=graph[i];
                    p=p->next;
                    while(p){
                        flag=0;
                        temp=0;
                        while(temp<=rear){
                            if(p->num==queue[temp]){
                                flag=1;
                                break;
                            }
                            else
                                temp++;
                        }
                        if(flag==0)
                            queue[++rear]=p->num;
                        p=p->next;
                    }
                }
            }
            front++;
        }
        for(j=0 ;j<front; j++)
            printf("%d  ",queue[j]);

        printf("\n\n");
    }

void dfs(){
        int output[MAX],stack[MAX],top=0,flag=0,temp=0,i,j;
        output[temp++]=graph[0]->num;
        stack[top++]=graph[0]->num;
        struct node *p=graph[0]->next;
        while(p){
            flag=0;
            for(i=0;i<temp;i++)
                if(output[i]==p->num){
                    flag=1;
                    break;
                }
            if(flag==0){
                output[temp++]=p->num;
                stack[top++]=p->num;
            }
            else
                top--;
            for(int i=0;i<ct;i++){
                if(graph[i]->num==stack[top-1]){
                    p=graph[i]->next;
                    for(int j=0;j<temp;j++){
                        if((p->next!=NULL)&&(p->num==output[j])){
                            p=p->next;
                            j=-1;
                        }
                    }
                }
            }
            if(temp==ct)
                break;
        }

        for(j=0;j<temp;j++)
            printf("%d  ",output[j]);

        printf("\n\n");
}


int main()
{
    int ch;
    do
    {
        printf("What operation do you want to perform ?\n");
        printf("1.Insert vertex 2.Add edges 3.Display(DFS) 4.Display(BFS) 5.Exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                add_edge();
                break;
            case 3:
                dfs();
                break;
            case 4:
                bfs();
                break;
            case 5:
                printf("Thank you !!\n");
                break;
            default:
                printf("Invalid option !! Please try again.\n\n");
        }
    }while(ch!=5);

    return 0;
}
