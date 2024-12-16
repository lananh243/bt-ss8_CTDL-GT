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

int height(Node* node) {
    if (node == NULL) {
        return 0; 
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
	Node* tree = NULL;
	int n,value;
	printf("Nhap so luong dinh : ");
	scanf("%d",&n);
	
	printf("Nhap gia tri cac dinh lan luot la : \n");
	for(int i; i < n; i++){
		scanf("%d",&value);
		tree = insertNode(tree, value);
		
	}
	int treeHeight = height(tree);
    printf("Chieu cao cua cay: %d\n", treeHeight);
} 
