#include <stdio.h>

typedef int element;
typedef struct node *nodePointer;
typedef struct {
	nodePointer llink;
	element data;
	nodePointer rlink;
}node;

node* head; // head node�� �������� ����

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

//���Ḯ��Ʈ�� �ִ� ��� ���Ҹ� ���
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
			printf("���� ����Ʈ �ȿ� �ֽ��ϴ�.");
			return;
		}
		temp = temp->rlink;
	}
	printf("���� ����Ʈ �ȿ� �����ϴ�.");
}

int main() {
	head = NULL;
	int nodeNum, nodeData, serchData;

	printf("����� ���� : ");
	scanf_s("%d", &nodeNum);

	for (int i = 0; i < nodeNum; i++) {
		printf("��� #%d�� ������ : ", i + 1);
		scanf_s("%d", &nodeData);
		Insert(nodeData);
	}

	Print();
	printf("Ž���� �� : ");
	scanf_s("%d", &serchData);
	searchNode(serchData);

	return 0;
}
