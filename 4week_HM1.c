#include <stdio.h>

typedef int element;
typedef struct node *nodePointer;
typedef struct {
	nodePointer llink;
	element data;
	nodePointer rlink;
}node;

node* head; // head node를 전역변수 선언

node* getNewnode(int data) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	return newnode;
}

void Insert(int data) {
	node* newnode = getNewnode(data);
	if (head == NULL) {
		head = newnode;
		return;
	}
	head->llink = newnode;
	newnode->rlink = head;
	head = newnode;
}

//연결리스트에 있는 모든 원소를 출력
void Print() { 
	node* temp = head;
	while (temp != NULL) {
		printf("<-|%d|-> ", temp->data);
		temp = temp->rlink;
	}
	printf("\n");
}

void searchNode(int data) {
	node* temp = head;
	while (temp != NULL) {
		if (data == temp->data) {
			printf("값이 리스트 안에 있습니다.");
			return;
		}
		temp = temp->rlink;
	}
	printf("값이 리스트 안에 없습니다.");
}

int main() {
	head = NULL;
	int nodeNum, nodeData, serchData;

	printf("노드의 개수 : ");
	scanf_s("%d", &nodeNum);

	for (int i = 0; i < nodeNum; i++) {
		printf("노드 #%d의 데이터 : ", i + 1);
		scanf_s("%d", &nodeData);
		Insert(nodeData);
	}

	Print();
	printf("탐색할 값 : ");
	scanf_s("%d", &serchData);
	searchNode(serchData);

	return 0;
}
