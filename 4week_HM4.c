#include<stdio.h>

struct node {
    int data;
    struct node* leftchild, * rightchild;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

void printLeft(struct node* root) {
    if (root != NULL) {  // ������ �ƴҰ��
        printf("%d \n", root->data);    // root�� data�� ���
        printLeft(root->leftchild);  // root�� �������� �̵��ؼ� ���
    }
    else // ������ ��� NULL ���
        printf("NULL\n");
}

void printRight(struct node* root) {
    if (root != NULL) {
        printf("%d \n", root->data);
        printRight(root->rightchild);
    }
    else
        printf("NULL\n");
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) return newNode(data);  // root�� ������ ��� ���ο� ��带 ��ȯ

    if (data < node->data)  // �Է¹��� data�� node�� data���� ���� ��� ���ʿ� ����
        node->leftchild = insert(node->leftchild, data);
    else if (data > node->data) // �Է¹��� data�� node�� data���� Ŭ ��� �����ʿ� ����
        node->rightchild = insert(node->rightchild, data);

    return node;
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 15); // ù��带 ��ȯ�������μ� root�� ����
    insert(root, 4);
    insert(root, 1);
    insert(root, 20);
    insert(root, 16);
    insert(root, 25);

    printf("[��Ʈ�� ���ʳ����� ��� ���]\n");
    printLeft(root);
    printf("[��Ʈ�� �����ʳ����� ��� ���]\n");
    printRight(root);


    return 0;
}