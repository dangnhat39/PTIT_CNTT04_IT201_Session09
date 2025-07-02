//
// Created by Nhat on 02/07/2025.
//
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

    return 0;
}