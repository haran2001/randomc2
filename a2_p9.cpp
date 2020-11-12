//basic operations on binary tree

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node *left, *right;
};

struct node* newNode(int item){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root){
	if(root != NULL){
		inorder(root->left);
		cout << root->key<<" ";
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key){
	if (node == NULL) return newNode(key);

	if(key > node->key)
		node->right =  insert(node->right, key);
	else
		node->left =  insert(node->left, key);
	return node;
}

struct node *minValueNode(struct node* node){
	struct node* current = node;

	while(current && current->left != NULL)
		current = current->left;
	return current;
}

struct node* deleteNode(struct node* root, int key){
	if(root == NULL) return root;
	
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	
	else{
		if(root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);				
	}

	return root;
}

unsigned int getLeafCount(struct node* node)  
{  
    if(node == NULL)      
        return 0;  
    if(node->left == NULL && node->right == NULL)  
        return 1;          
    else
        return getLeafCount(node->left)+  
            getLeafCount(node->right);  
}  

int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  
int main(){
	struct node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 9);
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 4);
	
	root = deleteNode(root, 4);
	inorder(root);
	return 0;
}