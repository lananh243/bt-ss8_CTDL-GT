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

int searchNode(Node* node, int key){
	if(node == NULL){
		printf("Not Found \n");
		return 0;
	}
	if(node->data == key){
		printf("Found \n");
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
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    
     printf("Nhap cac gia tri: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        tree = insertNode(tree, value);
	}
	
	printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    
    searchNode(tree, searchValue);
    return 0;
}

