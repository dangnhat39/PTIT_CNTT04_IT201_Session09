

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(Node** head_ref, int value, int position) {
    if (position < 0) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    if (position == 0) {
        Node* newNode = createNode(value);
        newNode->next = *head_ref;
        *head_ref = newNode;
        printf("Da them %d vao vi tri %d.\n", value, position);
        return;
    }

    Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri %d vuot qua do dai danh sach.\n", position);
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Da them %d vao vi tri %d.\n", value, position);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int value, position;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    printf("Danh sach lien ket ban dau: ");
    printList(head);
    printf("\n");

    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (bat dau tu 0): ");
    scanf("%d", &position);
    printf("\n");

    insertAtPosition(&head, value, position);

    printf("\nDanh sach lien ket sau khi them: ");
    printList(head);

    freeList(head);

    return 0;
}