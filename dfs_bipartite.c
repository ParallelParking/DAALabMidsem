#include <stdio.h>
#include <stdlib.h>
#define N 6

int graph[N][N] = {
    {0, 0, 0, 1, 1, 1},  
    {0, 0, 0, 1, 1, 0},  
    {0, 0, 0, 0, 1, 1},  
    {1, 1, 0, 0, 0, 0},  
    {1, 1, 1, 0, 0, 0},  
    {1, 0, 1, 0, 0, 0}   
};

int colour[N];

void dfs(int v) {
    if (colour[v] == -1) colour[v] = 0;
    for (int i = 0; i < N; i++) {
        if (graph[v][i] == 1) {
            if (colour[i] == -1) {
                colour[i] = colour[v] ^ 1;
                dfs(i);
            } else if (colour[v] == colour[i]) {
                printf("Graph is not bipartite\n");
                exit(0);
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) colour[i] = -1;
    for (int i = 0; i < N; i++)
        if (colour[i] == -1) dfs(i);
    printf("Graph is bipartite\n");
    return 0;
}