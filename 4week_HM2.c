/**/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coef, expon;
	struct Node* link;
};

struct Node* init(struct Node* head) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->coef = 0;
	temp->expon = -1;
	head = temp;
	temp->link = head;

	return head;
}

void insert_last(struct Node* head, int coef, int expon) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->coef = coef;
	temp->expon = expon;

	//temp->link = head->link;
//	head->link = temp;

	struct Node* temp1 = head;
	while (temp1->link != head) temp1 = temp1->link;
	temp1->link = temp;
	temp->link = head;
}

struct Node* subPoly(struct Node* poly1, struct Node* poly2) {
	struct Node* result = (struct Node*)malloc(sizeof(struct Node));
	result = init(result);
	struct Node* A = poly1;
	struct Node* B = poly2;
	int sub;

	A = A->link;
	B = B->link;

	while (1) {
		if (A->expon == B->expon) {
			if (A->expon == -1 && B->expon == -1) {
				return result;
			}
			sub = A->coef - B->coef;
			insert_last(result, sub, A->expon);
			A = A->link;
			B = B->link;
		}
		else if (A->expon > B->expon) {
			insert_last(result, A->coef, A->expon);
			A = A->link;
		}
		else {
			insert_last(result, -(B->coef), B->expon);
			B = B->link;
		}
	}
}

void print_list(struct Node* head) {
	struct Node* p;
	if (head == NULL) return;
	p = head->link; // 지수가 -1인 항을 피함
	printf(" %d^%d ", p->coef, p->expon);
	p = p->link;
	do {
		printf("+ %d^%d ", p->coef, p->expon);
		p = p->link;
	} while (p != head); // p가 헤더노드를 가리키면 종료
	printf("\n\n");
}

int main() {
	struct Node* poly1 = NULL;
	struct Node* poly2 = NULL;
	struct Node* subpoly = NULL;

	poly1 = init(poly1);
	poly2 = init(poly2);

	insert_last(poly1, -4, 11);
	insert_last(poly1, 3, 10);
	insert_last(poly1, 2, 8);
	insert_last(poly1, -6, 5);
	insert_last(poly1, 1, 0);


	printf("다항식1 입력 : ");
	print_list(poly1);

	insert_last(poly2, 3, 11);
	insert_last(poly2, -6, 7);
	insert_last(poly2, 4, 6);
	insert_last(poly2, -2, 5);
	insert_last(poly2, -2, 1);

	printf("다항식2 입력 : ");
	print_list(poly2);

	subpoly = subPoly(poly1, poly2);
	printf("차 = ");
	print_list(subpoly);

	return 0;
}