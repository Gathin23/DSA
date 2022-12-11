#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node *getNode(int val) {

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root,int val){
    
    if(root == NULL){
        return getNode(val);
    }

    if (val < root->val){
        root->left = insertNode(root->left,val);
    }
    if (val > root->val){
        root ->right = insertNode(root->right,val);
    }
    return root;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    printf(" %d ",root->val);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    printf(" %d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->val);
}

int main(){

    struct node *root = NULL;
    int opt;
    int num;

    do{
        printf("\n 1.Insert node \n 2.Inorder Traversal \n 3.Preorder Traversal\n 4.Postorder Traversal\n 5.Exit");
        printf("\n Enter your choise: ");
        scanf("%d",&opt);

        switch (opt) {
            case 1:
                printf("\n Enter the number: ");
                scanf("%d",&num);
                root = insertNode(root,num);
                break;
            
            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;        

            case 5:
                exit(0);
                break;
            
            default:
                printf("Wrong option");
                break;
        }

    } while(opt != 5);
}