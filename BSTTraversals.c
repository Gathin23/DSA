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

struct node *search(struct node *node,int val) {
    
    if(node == NULL){
        printf("Element not found");
    } else if (val < node->val) {
        node->left = search(node->left, val);
    } else if (val > node->val) {
        node->right = search(node->right , val);
    } else if (val == node->val){
        printf("\nElement found is: %d", node->val);
    }
    return node;
}

struct node *findMin(struct node *node){
  if(node == NULL){
    return NULL;
  }
  if(node ->left){
    return findMin(node->left);
  }else{
    return node;
  }
}

struct node *del(struct node *node,int val){
  struct node *temp;
  if(node == NULL){
    printf("\nElements not found");
  }else if(val < node->val){
    node->left = del(node->left,val);
  }else if (val > node->val){
    node->right = del(node->right,val);
  }else{
  
    if(node->right && node->left){
      
      temp = findMin(node->right);
      node->val = temp->val;
      node->right = del(node->right,temp->val);
    }else{
      temp = node;
      if(node->left == NULL){
        node = node->right;
      }else if(node->right == NULL){
        node = node->left;
      }
      free(temp);
    }
  }
  return node;
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
    int opt, val;
    int num;

    do{
        printf("\n 1.Insert node \n 2.Search \n 3.Delete \n 4.Inorder Traversal \n 5.Preorder Traversal\n 6.Postorder Traversal\n 7.Exit");
        printf("\n Enter your choise: ");
        scanf("%d",&opt);

        switch (opt) {
            case 1:
                printf("\n Enter the number: ");
                scanf("%d",&num);
                root = insertNode(root,num);
                break;

            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d", &val);
                root = search(root, val);
                break; 

            case 3:
                printf("\nEnter the element to delete: ");
                scanf("%d", & val);
                root = del(root, val);
                break;   
            
            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;        

            case 7:
                exit(0);
                break;
            
            default:
                printf("Wrong option");
                break;
        }

    } while(opt != 7);
}