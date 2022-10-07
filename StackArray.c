#include <stdio.h>                                                                                                                          
#include <stdlib.h>                                                                                                                         
#define MAX 3                                                                                                                               
int st[MAX], top=-1;                                                                                                                        
void push(int st[], int val);                                                                                                               
int pop(int st[]);                                                                                                                          
int peek(int st[]);                                                                                                                         
void display(int st[]);                                                                                                                     
                                                                                                                                            
int main() {                                                                                                                                
        int val, option;                                                                                                                    
        do                                                                                                                                  
        {                                                                                                                                   

                printf("\n Select a option to proceed in a stack:");                                                                        
                printf("\n 1. Push a value");                                                                                               
                printf("\n 2. Pop a value");                                                                                                
                printf("\n 3. Peek a value");                                                                                               
                printf("\n 4. Display a value");                                                                                            
                printf("\n 5. Exit");                                                                                                       
                printf("\n Enter your option: ");                                                                                           
                scanf("%d", &option);                                                                                                       
                                                                                                                                            
        switch(option)                                                                                                                      
        {                                                                                                                                   
                case 1:                                                                                                                     
                        printf("\n Enter the value to push:  ");                                                                            
                        scanf("%d", &val);                                                                                                  
                        push(st, val);                                                                                                      
                        break;                                                                                                              
                case 2:                                                                                                                     
                        val = pop(st);                                                                                                      
                        if(val != -1)                                                                                                       
                        printf("\n The value deleted is: %d", val);                                                                         
                        break;                                                                                                              
                case 3:                                                                                                                     
                        val = peek(st);                                                                                                     
                        if(val != -1);                                                                                                      
                        printf("\n The value stored at top is: %d", val);                                                                   
                        break;                                                                                                              
                case 4:                                                                                                                     
                        display(st);                                                                                                        
                        break;                                                                                                              
         }                                                                                                                                  
        }while(option != 5);                                                                                                                
        return 0;                                                                                                                           
}                                                                                                                                           
                                                                                                                                            
                                                                                                                                            
void push(int st[], int val){                                                                                                               

        if(top == MAX-1)                                                                                                                    
        {                                                                                                                                   
                printf("\n Stack Overflow");                                                                                                
        }                                                                                                                                   
        else                                                                                                                                
        {                                                                                                                                   
                top++;                                                                                                                      
                st[top] = val;                                                                                                              
        }                                                                                                                                   
}                                                                                                                                           
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
int pop(int st[]) {                                                                                                                         
        int val;                                                                                                                            
        if(top == -1)                                                                                                                       
        {                                                                                                                                   
                printf("\n Stack Underflow");                                                                                                
                return -1;                                                                                                                  
        }                                                                                                                                   
        else                                                                                                                                
        {                                                                                                                                   
                val = st[top];                                                                                                              
                top--;                                                                                                                      
                return val;                                                                                                                 
        }                                                                                                                                   
}                                                                                                                                           
                                                                                                                                            
                                                                                                                                            
void display(int st[])                                                                                                                      
{                                                                                                                                           
        int i;                                                                                                                              
        if(top == -1)                                                                                                                       
                printf("\n Empty Stack");                                                                                                   
        else {                                                                                                                              
                                                                                                                                            
                for(i=top;i>=0;i--)                                                                                                         
                printf("\n %d",st[i]);                                                                                                      
                printf("\n");                                                                                                               
        }                                                                                                                                   
}                                                                                                                                           
                                                                                                                                            
                                                                                                                                            
int peek(int st[]) {                                                                                                                        
        if(top == -1) {                                                                                                                     
                printf("\n Empty Stack");                                                                                                   
                return -1;                                                                                                                  
        }                                                                                                                                   
        else                                                                                                                                
                return (st[top]);                                                                                                           
}