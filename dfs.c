#include <stdio.h>
#include <stdlib.h>
#define N 5

int graph[N][N] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {0,0,0,0,0},
    {0,0,1,0,1},
    {0,0,0,0,0}
    };

int visited[N] = {0};

int push_order[N];
int pop_order[N];
int x = 0;
int y = 0;

void dfs(int v) {
    visited[v] = 1;
    push_order[x++] = v;
    for (int i = 0; i < N; i++)
        if (graph[v][i] == 1 && visited[i] == 0) dfs(i);
    pop_order[y++] = v;
}

int main() {
    for (int i = 0; i < N; i++)
        if (visited[i] == 0) dfs(i);
    printf("Push order: ");
    for (int i = 0; i < N; i++) printf("%d ", push_order[i]);
    printf("\nPop order: ");
    for (int i = 0; i < N; i++) printf("%d ", pop_order[i]);
    printf("\n");
    return 0;
}