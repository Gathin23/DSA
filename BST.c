#include<stdio.h>
#include<stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};
typedef struct BST NODE;
NODE* node;


NODE* createtree(NODE* node,int data){
    // Base condition to create a node
    if(node == NULL){
        NODE* temp;
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    // This runs first to check where to place the node except for the first time
    if(data < (node->data)) {
        node->left = createtree(node->left,data);
    } else if (data > node->data) {
        node->right = createtree(node->right,data);
    }
    return node;
}

NODE* search(NODE* node,int data) {
    
    if(node == NULL){
        printf("Element not found");
    } else if (data < node->data) {
        node->left = search(node->left, data);
    } else if (data > node->data) {
        node->right = search(node->right , data);
    } else if (data == node->data){
        printf("\nElement found is: %d", node->data);
    }
    return node;
}

NODE* display(NODE* node, int level){
    int i;
    if (node != NULL){
        
        display(node->right, level+1);
        printf("\n");
        
        for(i = 0; i < level; i++){
            printf("    ");
        }
        
        printf("%d", node->data);
        display(node->left,level+1);
    }
}



void main()

{

  int data, ch, i, n;

  NODE* root = NULL;

  while (1)

  {

    printf("\n1.Insertion in Binary Search Tree");
    printf("\n2.Search Element in Binary Search Tree");
    printf("\n3.Delete Element in Binary Search Tree");
    printf("\n4.Display");
    printf("\n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", & ch);
    
    switch (ch)
    {
    case 1:
      printf("\nEnter the number of values: ");
      scanf("%d", & n);
      printf("\nEnter the values :\n");
      for (i = 0; i < n; i++)
      {
        scanf("%d", & data);
        root = createtree(root, data);
      }
      break;

    case 2:
      printf("\nEnter the element to search: ");
      scanf("%d", & data);
      root = search(root, data);
      break;

    // case 3:
    //   printf("\nEnter the element to delete: ");
    //   scanf("%d", & data);
    //   root = del(root, data);
    //   break;

    case 4: {
      display(root, 1);
      break;
    }

    case 5:
      exit(0);
    default:
      printf("\nWrong option");
      break;

    }

  }

}