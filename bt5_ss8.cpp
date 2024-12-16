#include<stdio.h>
#include<stdlib.h>
//Dinh nghia 1 nut
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//Tao ra 1 nut
Node* createNode(int data){
	//Cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//Chen 1 nut vao cai cay
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

//Duyet cay theo trung thu tu trai goc phai
void inorderTraversal(Node* node){
	if(node != NULL) {
		inorderTraversal(node->left);
		printf("%d \t", node->data);
		inorderTraversal(node->right);
	}
} 
//Tim kiem gia tri trong cay 
int searchNode(Node* node, int key){
	if(node == NULL){
		return 0;
	}
	if(node->data == key){
		return 1;
	}
	if(key < node->data){
		return searchNode(node->left, key);
	}
	return searchNode(node->right, key);
}

int main() {
	Node* tree = NULL;
	int n, value, searchValue;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	printf("Nhap gia tri cac phan tu lan luot la : \n");
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		tree = insertNode(tree, value);
		
	}
	printf("Duyet cay theo thu tu inorder: \n");
    inorderTraversal(tree);
    printf("\n"); 
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    if(searchNode(tree, searchValue)){
    	printf("Gia tri %d ton tai trong cay",searchValue); 
	}else{
		printf("Gia tri %d ko ton tai trong cay",searchValue);
	} 

}

