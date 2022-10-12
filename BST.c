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
    if(node == NULL){
        NODE* temp;
        temp = (struct NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    if(data < (node->data)) {
        node->left = createtree(node->left,data);
    } else if (data > node->data) {
        node->right = createtree(node->right,data);
    }
    return node;
}