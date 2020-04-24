#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;
typedef struct { // �� ���� �ʵ�� ����
	element data; // ������
	struct ListNode* link; // ������
}ListNode;

ListNode* head; // �Է¹��� ���

void insert(int n) { // ���� �� ������������ �����Ͽ� �����ϴ� �Լ�
	ListNode* p = head; // head�� �ּҸ� �޴� node
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); // �ӽ�node
	ListNode* pre = NULL;

	temp->data = n;
	temp->link = NULL;

	if (head == NULL)
		head = temp;

	else if (p->data > temp->data) { //p�� data�� node�� data���� Ŭ ��� node�� p�տ��� ����
		temp->link = p;
		head = temp;
	}
	else {
		while (p->link != NULL && p->data < temp->data) { // head�� data�� node���� ���� ��� ���� node
			pre = p;
			p = p->link;
		}

		temp->link = p; // p�� node�� �ӽ�node���� Ŭ ��� 
		pre->link = temp;
	}
}


// ����Ʈ ���� �Լ�
ListNode* reverse() {
	ListNode* copyNode, * q, * reverse;

	copyNode = head;
	q = NULL;

	while (copyNode != NULL) {	// NULL�� ���� ������ �ݺ�
		reverse = q;	// �������� �� ����Ʈ
		q = copyNode;
		copyNode = copyNode->link;
		q->link = reverse;	// q�� ��ũ ������ �ٲ۴�.
	}
	return q;
}

int main() {
	int add;	// ����� ������ ���� ����
	char repeat = ' ';
	ListNode* temp; // head�� ���� ���� ����Ʈ

	head = NULL;	// ���� NULL�� �ʱ�ȭ

	while (repeat != 'N') {
		printf("������ �Է��Ͻÿ� : ");
		scanf_s("%d", &add);
		insert(add);

		printf("�� �Է��Ͻðڽ��ϱ�? ");
		repeat = getchar();

		printf("\n");
	}

	temp = head;

	printf("�������� ����Ʈ : ");
	for (; temp != NULL; temp = temp->link)
		printf("%d ", temp->data);
	printf("\n");

	head = reverse(); // ������������ �迭�� ����Ʈ�� �������� head�� ����
	printf("���� ����Ʈ : ");
	for (; head != NULL; head = head->link)
		printf("%d ", head->data);

	return 0;
}