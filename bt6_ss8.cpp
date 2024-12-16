#include<stdio.h>
#include<stdlib.h> 

//Dinh nghia 1 node
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//Tao ra 1 node

Node* createNode(int data){
	//cap phat bo nho
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//chen 1 node vao cay
Node* insertNode(Node* node,int data){
	if(node == NULL){
		node = createNode(data);
	}
	if(data < node->data){
		node->left = insertNode(node->left, data);
	}else if(data > node->data){
		node->right = insertNode(node->right, data);
	}
	return node;
}
//Ham kiem tra co phai BST hay ko  
int isBST(Node* node, int min, int max) {
    if (node == NULL) {
        return 1;
    }
    if (node->data < min || node->data > max) {
        return 0; 
    }
    return isBST(node->left, min, node->data - 1) &&
           isBST(node->right, node->data + 1, max);
}

int checkBST(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}


int main() {
	Node* tree = NULL;
	int n,value;
	printf("Nhap so luong nut : ");
	scanf("%d",&n);
	
	printf("Nhap gia tri cac nut lan luot la : \n");
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		tree = insertNode(tree, value);
		
	}
	
	if(checkBST(tree)){
		printf("Cay la cay nhi phan tim kiem"); 
	}else{
		printf("Cay ko phai la cay nhi phan tim kiem");
	} 
	return 0; 
}

