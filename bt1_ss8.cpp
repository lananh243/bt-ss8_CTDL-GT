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

//Duyet theo phuong phap tien thu tu
void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d \t", node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

//Duyet theo phuong phap trung thu tu
void inorderTraversal(Node* node){
	if(node != NULL){
		inorderTraversal(node->left);
	printf("%d \t", node->data);
	inorderTraversal(node->right);
	}
}

//Duyet theo phuong phap hau thu tu
void postTraversal(Node* node){
	if(node != NULL){
		postTraversal(node->left);
	postTraversal(node->right);
	printf("%d \t", node->data);
	}
}
int main() {
	Node* tree = NULL;
	int n,value;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	printf("Nhap gia tri cac phan tu lan luot la : \n");
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		tree = insertNode(tree, value);
		
	}
	printf("Duyet tien thu tu: \n");
    preorderTraversal(tree);
    printf("\n");
    printf("Duyet theo trung thu tu: \n");
    inorderTraversal(tree);
    printf("\n");
    printf("Duyet theo hau thu tu: \n");
    postTraversal(tree);
    
	return 0;
	
}

