#include <stdio.h>
#include <stdlib.h>

struct binaryTree
{
    int key;
    struct binaryTree *left;
    struct binaryTree *right;
} binaryTree;

struct binaryTree* createNode(int value)
{
    struct binaryTree* newBT = malloc(sizeof(struct binaryTree));
    newBT->key = value;
    newBT->left = NULL;
    newBT->right = NULL;
};

struct binaryTree* insertLeft(struct binaryTree* root, int value)
{
    root->left = insertLeft(root->left, value);
    return root;
};

struct binaryTree* insertRight(struct binaryTree* root, int value)
{
    root->right = insertRight(root->right, value);
    return root;
};


struct binaryTree* insertSort(struct binaryTree* root, int value)
{
    if (root == NULL) return createNode(value);

    if (value < root->key) 
        root->left = insertSort(root->left, value);
    else if (value > root->key) 
        root->right = insertSort(root->right, value);
    return root;
};

void binaryPrint(struct binaryTree* root)
{
    if (root == NULL) return;
    binaryPrint(root->left);
    printf("%d -> ", root->key);
    binaryPrint(root->right);
};

void deleteElement(int* nums, int index, int *size) {
    if (index < 0 || index >= *size) return;
    for (int i = index; i < *size - 1; i++) {
        nums[i] = nums[i + 1];
    }
    (*size)--;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct binaryTree* node = NULL;
    
    return node;
}