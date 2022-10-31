#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int n=0,arr[MAX],matrix[MAX][MAX];
char* city[MAX];

void insert(){
    int i,j;
    printf("Enter the no.of vertices: ");
    scanf("%d",&n);
    printf("Enter the vertices \n");
    for(i=0; i<n; i++){
        printf("Enter the name of the city: ");
        city[i]=malloc(sizeof(char)*30);
        scanf("%s",city[i]);
        getchar();
    }
    printf("\nList of cities with their index number: \n");
    for(i=0; i<n; i++){
        printf("%d. %s\n",i,city[i]);
    }
    printf("\n");

    for(int i=0; i<n ;i++){
        arr[i]= i;
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matrix[i][j]=0;
        }
    }
}

void add_edge(){
    int v1,v2,i,j;
    printf("Add edge between (enter index number of any two cities): ");
    scanf("%d",&v1);
    scanf("%d",&v2);
    for(i=0; i<n ;i++)
        for(j=0; j<n ;j++)
            if((arr[i]==v1) && (arr[j]==v2)){
                matrix[i][j]=1;
                matrix[j][i]=1;
                printf("Edge created..\n");
            }
        printf("\n");
}

void dfs(){
    int i,j,output[n],stack[n],flag,temp=0,top=0,g;
    output[temp]=arr[0];
    temp++;
    stack[top]=arr[0];
    top++;
    for(i=0; i<n; i++){
            g=stack[top-1];
            if(arr[i]==g){
                for(j=0; j<n; j++){
                    flag=0;
                    if(matrix[i][j]==1){
                        for(int k=0; k<temp; k++){
                            if(output[k]==arr[j]){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0){
                            output[temp]=arr[j];
                            temp++;
                            stack[top]=arr[j];
                            top++;
                            break;
                        }
                    }
                    if(j==n-1)
                        top--;
                }
                i=-1;
            }
            if(top==-1)
                break;
        }
        for(i=0; i<n; i++){
            printf("%s   ",city[output[i]]);
        }
        printf("\n\n");
}

void bfs(){
    int front=0,rear=0,g,i,j,output[n],queue[n],flag,temp=0;
    queue[rear]=arr[0];
    rear++;
    for(i=0; i<n; i++){
        g=queue[front];
        if(arr[i]==g){
            for(j=0; j<n; j++){
                flag=0;
                if(matrix[i][j]==1){
                    for(int k=0; k<rear; k++){
                        if(queue[k]==arr[j]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        queue[rear]=arr[j];
                        rear++;
                    }
                }
            }
            front++;
            i=-1;
        }
        if(front>=rear)
            break;
    }
    for(i=0; i<n; i++)
            printf("%s   ",city[queue[i]]);

    printf("\n\n");
}

int main(){
    int ch,i;
    do
    {
        printf("What operation do you want to perform ?\n");
        printf("1.Insert all vertices 2.Add edges 3.Display(DFS) 4.Display(BFS) 5.Exit: ");
        scanf("%d",&ch);
        switch(ch){
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
                printf("Invalid option !! Please try again.\n");
        }
    }while(ch!=5);

    for(i=0; i<n; i++){
        free(city[i]);
    }
    return 0;
}
