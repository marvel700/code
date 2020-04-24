#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;
typedef struct { // 두 개의 필드로 구성
	element data; // 데이터
	struct ListNode* link; // 포인터
}ListNode;

ListNode* head; // 입력받을 노드

void insert(int n) { // 삽입 시 오름차순으로 정렬하여 삽입하는 함수
	ListNode* p = head; // head의 주소를 받는 node
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); // 임시node
	ListNode* pre = NULL;

	temp->data = n;
	temp->link = NULL;

	if (head == NULL)
		head = temp;

	else if (p->data > temp->data) { //p의 data가 node의 data보다 클 경우 node를 p앞에서 삽입
		temp->link = p;
		head = temp;
	}
	else {
		while (p->link != NULL && p->data < temp->data) { // head의 data가 node보다 작을 경우 다음 node
			pre = p;
			p = p->link;
		}

		temp->link = p; // p의 node가 임시node보다 클 경우 
		pre->link = temp;
	}
}


// 리스트 역순 함수
ListNode* reverse() {
	ListNode* copyNode, * q, * reverse;

	copyNode = head;
	q = NULL;

	while (copyNode != NULL) {	// NULL이 나올 때까지 반복
		reverse = q;	// 역순으로 된 리스트
		q = copyNode;
		copyNode = copyNode->link;
		q->link = reverse;	// q의 링크 방향을 바꾼다.
	}
	return q;
}

int main() {
	int add;	// 노드의 개수를 받을 변수
	char repeat = ' ';
	ListNode* temp; // head를 넣을 연결 리스트

	head = NULL;	// 노드들 NULL로 초기화

	while (repeat != 'N') {
		printf("정수를 입력하시오 : ");
		scanf_s("%d", &add);
		insert(add);

		printf("더 입력하시겠습니까? ");
		repeat = getchar();

		printf("\n");
	}

	temp = head;

	printf("오름차순 리스트 : ");
	for (; temp != NULL; temp = temp->link)
		printf("%d ", temp->data);
	printf("\n");

	head = reverse(); // 오름차순으로 배열된 리스트를 역순으로 head에 저장
	printf("역순 리스트 : ");
	for (; head != NULL; head = head->link)
		printf("%d ", head->data);

	return 0;
}