#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int value) {
    struct ListNode* newList = (struct ListNode*)malloc(sizeof(struct ListNode));
    newList->val = value;
    newList->next = NULL;
    return newList;
}

struct ListNode* insertInt(struct ListNode* head, int value) {
    if (head == NULL) return createList(value);
    if (head->next != NULL)
        head->next = insertInt(head->next, value);
    else if (head->next == NULL) {
        struct ListNode* newNode = createList(value);
        head->next = newNode;
    }
    return head;
}

void printList(struct ListNode* head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        printf("%d", head->val);
    } else {
        printf("%d -> ", head->val);
    }
    printList(head->next);
}


int listLenght(struct ListNode* head) {
    if (head == NULL) return 0;

    struct ListNode* curr = head;
    int cnt = 0;

    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

int getIntValueByIndex(struct ListNode* head, int index) {
    int lenght = listLenght(head);
    if (index > lenght)
        return -1;
    
    struct ListNode* curr = head;
    int cnt = 0;
    
    while (cnt != index) {
        curr = curr->next;
        cnt+=1;
    }
    
    return curr->val;
}

void setIntValueByIndex(struct ListNode* head, int index, int value) {
    int lenght = listLenght(head);
    if (index > lenght)
        return;

    struct ListNode* curr = head;
    int cnt = 0;

    while (cnt != index) {
        curr = curr->next;
        cnt+=1;
    }
    curr->val = value;
}