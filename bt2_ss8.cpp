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

//Hien thi cay 
void displayTree(Node* node, int level) {
    if (node == NULL) return;
    printf("%d ", node->data);
    displayTree(node->left, level + 1);
    displayTree(node->right, level + 1);
}

//Tim cac dinh o lop 2
void findLevelTwoNodes(Node* node, int currentLevel) {
    if (node == NULL) return;
    if (currentLevel == 2) {
        printf("%d \t", node->data);
        return;
    }
    findLevelTwoNodes(node->left, currentLevel + 1);
    findLevelTwoNodes(node->right, currentLevel + 1);
}

int main(){
	Node* tree = NULL;
    int n,value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    
     printf("Nhap cac gia tri: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        tree = insertNode(tree, value);
	}
   	
    printf("Cac dinh lop 2: ");
    findLevelTwoNodes(tree, 0);
    printf("\n");
    
    return 0;
}
