#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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

void prependNode(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(Node** head, int value, int position) {
    if (position <= 0) return;
    if (position == 1) {
        prependNode(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirstNode(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position <= 0) return;
    if (position == 1) {
        deleteFirstNode(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printDetailedList(Node* head) {
    Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("Node %d: %d\n", count, temp->data);
        temp = temp->next;
        count++;
    }
}

int searchList(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int searchValue;
    int newValue;
    int insertValue, insertPos;
    int deletePos;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Danh sách liên kết: ");
    printList(head);

    printDetailedList(head);

    printf("\nNhập số cần tìm: ");
    scanf("%d", &searchValue);

    if (searchList(head, searchValue)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("\nDanh sách liên kết có %d phần tử\n", countNodes(head));

    printf("\nNhập số muốn thêm vào đầu danh sách: ");
    scanf("%d", &newValue);
    prependNode(&head, newValue);

    printf("\nDanh sách sau khi thêm vào đầu: ");
    printList(head);

    deleteFirstNode(&head);
    printf("\nDanh sách sau khi xóa phần tử đầu: ");
    printList(head);

    printf("\nNhập giá trị muốn chèn: ");
    scanf("%d", &insertValue);
    printf("Nhập vị trí muốn chèn: ");
    scanf("%d", &insertPos);
    insertAtPosition(&head, insertValue, insertPos);

    printf("\nDanh sách sau khi chèn vào vị trí %d: ", insertPos);
    printList(head);

    printf("\nNhập vị trí muốn xóa: ");
    scanf("%d", &deletePos);
    deleteAtPosition(&head, deletePos);

    printf("\nDanh sách sau khi xóa tại vị trí %d: ", deletePos);
    printList(head);

    return 0;
}
