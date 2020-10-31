//Inorder traversal of binary tree with recursion
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void printInOrder(struct node* node){
    if(node == NULL)
        return;
    printInOrder(node->left);
    printf("%d\n", node->data);
    printInOrder(node->right);
}

int main(){
    struct node* root;
    root = newNode(1);   
    root->left = newNode(2);   
    root->right = newNode(3);   
    root->left->left = newNode(4);   
    root->left->right = newNode(5);   
    root->right->left = newNode(6);   
    root->right->right = newNode(7);   
   
    printf("InOrder: \n");
    printInOrder(root);

    return 0;
}
