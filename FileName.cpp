#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	char data[20];
	struct Node* next;
}Node;
Node* createNode(const char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	return newNode;
}
void append(Node** head, const char* data) {
	Node* newNode = createNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = newNode;
}
void printList(Node* head) {
	while (head != NULL) {
		printf("%s -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main() {
	Node* head = NULL;
	int n;
	char value[20];
	printf("������ ����� ������ �Է��ϼ���: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("��忡 ������ ���� �Է��ϼ���: ");
		scanf("%s", value);
		append(&head, value);
	}
	printf("�Էµ� ����Ʈ: ");
	printList(head);
	return 0;
}