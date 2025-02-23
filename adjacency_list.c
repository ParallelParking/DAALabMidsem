// IMPLEMENTING A GRAPH USING ADJACENCY LIST

#include <stdio.h>
#include <stdlib.h>

// ADJACENCY LIST STRUCT
typedef struct node {
    int data;
    struct node* down;
    struct node* right;
} NODE;

NODE* createNode(int x) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if (!newnode) {
        printf("Heap full");
        exit(0);
    }
    newnode->data = x;
    newnode->right = NULL;
    newnode->down = NULL;
    return newnode;
}

// Following behaviours:
// If empty list, return new head with data
// If relevant source not found, list updated and relevant source returned
// If relevant source found, returned.
NODE* getSource(NODE** root, int x) {
    if (!(*root)) {
        *root = createNode(x);
        return *root;
    }
    for (NODE* temp = *root; temp; temp = temp->down) {
        if (temp->data == x) return temp;
        if (!temp->down) {
            temp->down = createNode(x);
            return temp->down;
        }
    }
    return NULL;
}

// Following behaviours:
// If terminal found for a source, do nothing
// Else add terminal and return
void putTerminal(NODE** source, int x) {
    NODE* temp = *source;
    for (; temp->right; temp = temp->right)
        if (temp->data == x) return;
    if (temp->data != x)
        temp->right = createNode(x);
}

void displayList(NODE* root) {
    while (root) {
        printf("%d: ", root->data);
        NODE* term = root->right;
        while (term) {
            printf("%d ", term->data);
            term = term->right;
        }
        printf("\n");
        root = root->down;
    }
}

int main() {
    NODE* list = NULL;
    printf("Enter terminal 1 = -1 to exit\n");
    // ASSUMPTION: undirected graph.
    while (1) {
        printf("Enter terminals: ");
        int x;
        int y;
        scanf("%d%d", &x, &y);
        if (x == -1) break;
        NODE* a = getSource(&list, x);
        NODE* b = getSource(&list, y);
        putTerminal(&a, y);
        putTerminal(&b, x);
    }
    displayList(list);
    return 0;
}