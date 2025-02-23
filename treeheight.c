#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node NODE;

struct node {
    int data;
    struct node* right;
    struct node* left;
};

NODE* createNode(int x) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if (!newnode) {
        printf("Heap full");
        exit(0);
    }
    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

int maximum(int a, int b) {
    return a > b ? a : b;
}

int height(NODE* root) {
    if (!root) return -1;
    return maximum(height(root->right), height(root->left)) + 1;
}

int main() {
    int x;
    char path[MAX];
    NODE* root = NULL;
    while (1) {
        if (!root) {
            printf("Enter root: ");
            scanf("%d", &x);
            root = createNode(x);
            printf("Enter 'EXIT' at path to exit\n");
            continue;
        }
        printf("Enter path: ");
        scanf("%s", path);
        if (strcmp(path, "EXIT") == 0) break;
        printf("Enter data: ");
        scanf("%d", &x);
        NODE* t = root;
        int i = 0;
        while (path[i + 1] != '\0') {
            if (path[i] == 'R') t = t->right;
            else t = t->left;
            i += 1;
        }
        NODE* n = createNode(x);
        if (path[i] == 'R') t->right = n;
        else t->left = n;
    }
    int h = height(root);
    printf("height: %d\n", h);
    return 0;
}