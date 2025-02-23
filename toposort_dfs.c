#include <stdio.h>
#include <stdlib.h>
#define N 6

int graph[N][N] = {
    {0, 1, 1, 0, 0, 0},  
    {0, 0, 0, 1, 1, 0},  
    {0, 0, 0, 1, 0, 1},  
    {0, 0, 0, 0, 1, 0},  
    {0, 0, 0, 0, 0, 1},  
    {0, 0, 0, 0, 0, 0}   
};

int visited[N] = {0};
int pop_order[N];
int x = 0;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < N; i++)
        if (graph[v][i] && !visited[i]) dfs(i);
    pop_order[x++] = v;  
}

int main() {
    for (int i = 0; i < N; i++)
        if (!visited[i]) dfs(i); 
    for (int i = N - 1; i >= 0; i--)
        printf("%d ", pop_order[i]);
    printf("\n");
    return 0;
}