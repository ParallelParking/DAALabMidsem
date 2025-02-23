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

void inorder(NODE* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

NODE* cca(NODE* root, int a, int b) {
    if (!root) return NULL;
    if (root->data == a || root->data == b) return root;
    NODE* lca = cca(root->left, a, b);
    NODE* rca = cca(root->right, a, b);
    if (lca && rca) return root;
    return lca ? lca : rca;
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
    printf("Enter 2 numbers: ");
    int a, b;
    scanf("%d%d", &a, &b);
    NODE* lowest_common_ancestor = cca(root, a, b);
    printf("CCA is: %d\n", lowest_common_ancestor->data);
    return 0;
}