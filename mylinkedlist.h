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
};

struct ListNode* insert(struct ListNode* root, int value) {
    if (root == NULL) return createList(value);
    if (root->next != NULL)
        root->next = insert(root->next, value);
    else if (root->next == NULL) {
        struct ListNode* newNode = createList(value);
        root->next = newNode;
    }
    return root;
}

void printList(struct ListNode* root) {
    if (root == NULL) return;
    if (root->next == NULL) {
        printf("%d", root->val);
    } else {
        printf("%d -> ", root->val);
    }
    printList(root->next);
}


int listLenght(struct ListNode* root) {
    if (root == NULL) return 0;

    struct ListNode* curr = root;
    int cnt = 0;

    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}
