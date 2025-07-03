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

void deleteAtPosition(Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Danh sach rong, khong co gi de xoa.\n");
        return;
    }

    Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        printf("Da xoa thanh cong phan tu tai vi tri %d.\n", position);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri %d khong ton tai trong danh sach.\n", position);
        return;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
    printf("Da xoa thanh cong phan tu tai vi tri %d.\n", position);
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
    int position;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    printf("Danh sach lien ket ban dau: ");
    printList(head);
    printf("\n");

    printf("Nhap vi tri muon xoa (bat dau tu 0): ");
    scanf("%d", &position);
    printf("\n");

    deleteAtPosition(&head, position);

    printf("\nDanh sach lien ket sau khi xoa: ");
    printList(head);

    freeList(head);

    return 0;
}