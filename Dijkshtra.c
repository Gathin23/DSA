#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
int vertex[10],vsize=0,esize=0,cost=0;
struct EDGE
{
    int v1,v2,weight;
};
struct EDGE edges[25];
struct dis
{
    int cost,flag;
};
struct dis dist[10];
void insert()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&vsize);
    printf("Enter the vertices: ");
    for(int i=0;i<vsize;i++)
        scanf("%d",&vertex[i]);
}
void adjacency()
{
    int i=0,choice=1,c,d,w;
    while((choice==1)&&(i<25))
    {
        printf("Enter the adjacent vertices: ");
        scanf("%d%d",&c,&d);
        printf("Enter the weight of edge: ");
        scanf("%d",&w);
        if(w>0)
        {
            edges[i].v1=c;
            edges[i].v2=d;
            edges[i].weight=w;
            i++;
            esize++;
        }
        printf("1.Add an edge\t2.See shortest path\nEnter your choice: ");
        scanf("%d",&choice);
    }
    for(i=0;i<vsize;i++)
    {
        dist[i].cost=INT_MAX;
        dist[i].flag=0;
    }
}
void distance()
{
    int i,count=0,temp=INT_MAX,k,c,d,j,val;
    dist[0].cost=0;
    while(count<vsize)
    {
        for(i=0;i<vsize;i++)
        {
            if((dist[i].cost<=temp)&&(dist[i].flag==0))
            {
                temp=dist[i].cost;
                k=i;
            }
        }
        c=vertex[k];
        dist[k].flag=1;
        for(i=0;i<esize;i++)
        {
            if(edges[i].v1==c)
            {
                d=edges[i].v2;
                for(j=0;j<vsize;j++)
                {
                    if(vertex[j]==d)
                        break;
                }
                if(dist[j].cost==INT_MAX)
                {
                    dist[j].cost=0;
                    dist[j].cost=edges[i].weight+dist[k].cost;
                }
                else if((dist[k].cost+edges[i].weight)<=dist[j].cost)
                    dist[j].cost=dist[k].cost+edges[i].weight;
            }
        }
        count++;
        temp=INT_MAX;
    }
}
void display()
{
    printf("Distance between the source vertex(%d) and other vertices are as follows: \n",vertex[0]);
    printf("Destination\tDistance\n");
    for(int i=0;i<vsize;i++)
    {
        printf("%d\t\t%d\n",vertex[i],dist[i]);
    }
}
void main()
{
    insert();
    adjacency();
    distance();
    display();
}
