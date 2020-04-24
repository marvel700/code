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
    if (root != NULL) {  // 공백이 아닐경우
        printf("%d \n", root->data);    // root의 data를 출력
        printLeft(root->leftchild);  // root의 왼쪽으로 이동해서 출력
    }
    else // 공백일 경우 NULL 출력
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
    if (node == NULL) return newNode(data);  // root가 공백일 경우 새로운 노드를 반환

    if (data < node->data)  // 입력받은 data가 node의 data보다 작을 경우 왼쪽에 저장
        node->leftchild = insert(node->leftchild, data);
    else if (data > node->data) // 입력받은 data가 node의 data보다 클 경우 오른쪽에 저장
        node->rightchild = insert(node->rightchild, data);

    return node;
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 15); // 첫노드를 반환받음으로서 root를 시작
    insert(root, 4);
    insert(root, 1);
    insert(root, 20);
    insert(root, 16);
    insert(root, 25);

    printf("[루트의 왼쪽노드들을 모두 출력]\n");
    printLeft(root);
    printf("[루트의 오른쪽노드들을 모두 출력]\n");
    printRight(root);


    return 0;
}