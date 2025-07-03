#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void printList(struct Node* node) {
    printf("Danh sach hien tai: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct Node* head = NULL;

    head = createNode(30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printf("--- TRANG THAI BAN DAU ---\n");
    printList(head);
    printf("-------------------------\n\n");

    int userInput;
    printf("Nhap so nguyen ban muon them vao DAU danh sach: ");
    scanf("%d", &userInput);

    insertAtBeginning(&head, userInput);

    printf("\n--- TRANG THAI SAU KHI THEM ---\n");
    printList(head);
    printf("-----------------------------\n");

    freeList(head);

    return 0;
}