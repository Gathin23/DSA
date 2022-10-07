#include <stdio.h>                                                                                                                          
#define SIZE 5                                                                                                                              
                                                                                                                                            
void enQueue(int);                                                                                                                          
void deQueue();                                                                                                                             
void display();                                                                                                                             
                                                                                                                                            
int items[SIZE], front = -1, rear = -1;                                                                                                     
                                                                                                                                            
int main(){                                                                                                                                 
        int option,val;                                                                                                                     
do                                                                                                                                          
{                                                                                                                                           
printf("\n 1. Add");                                                                                                                        
printf("\n 2. Delete");                                                                                                                     
printf("\n 3. Display Queue");                                                                                                              
printf("\n 4. Exit");                                                                                                                       
printf("\n Enter your option: ");                                                                                                           
scanf("%d", &option);                                                                                                                       
switch(option)                                                                                                                              
{                                                                                                                                           
case 1:                                                                                                                                     
printf("\n Enter the Value to add in queue: ");                                                                                             
scanf("%d", &val);                                                                                                                          
enQueue(val);                                                                                                                               
break;                                                                                                                                      
case 2:                                                                                                                                     
deQueue(items);                                                                                                                             
break;                                                                                                                                      
case 3:                                                                                                                                     
display(items);                                                                                                                             
break;                                                                                                                                      
 }                                                                                                                                          
}while(option != 4);                                                                                                                        
}                                                                                                                                           
                                                                                                                                            
void enQueue(int value) {                                                                                                                   
  if (rear == SIZE - 1)                                                                                                                     
    printf("\nQueue Full");                                                                                                                 
  else {                                                                                                                                    
    if (front == -1)                                                                                                                        
      front = 0;                                                                                                                            
    rear++;                                                                                                                                 
    items[rear] = value;                                                                                                                    
    printf("\nThe value insterted is: %d", value);                                                                                          
  }                                                                                                                                         
}                                                                                                                                           
                                                                                                                                            
void deQueue() {                                                                                                                            
  if (front == -1)                                                                                                                          
    printf("\nEmpty Queue");                                                                                                                
  else {                                                                                                                                    
    printf("\nThe value deleted is: %d", items[front]);                                                                                     
    front++;                                                                                                                                
    if (front > rear)                                                                                                                       
      front = rear = -1;                                                                                                                    
  }                                                                                                                                         
}                                                                                                                                           
                                                                                                                                            
// Function to print the queue                                                                                                              
void display() {                                                                                                                            
  if (rear == -1)                                                                                                                           
    printf("\nEmpty Queue");                                                                                                                
  else {                                                                                                                                    
    int i;                                                                                                                                  
    printf("\nQueue: \n");                                                                                                                  
    for (i = front; i <= rear; i++)                                                                                                         
      printf("%d  ", items[i]);                                                                                                             
  }                                                                                                                                         
  printf("\n");                                                                                                                             
}