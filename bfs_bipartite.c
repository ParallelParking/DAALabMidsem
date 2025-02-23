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

void bfs(int v) {
    colour[v] = 0;
    int queue[N];
    int front = -1;
    int rear = -1;
    queue[++rear] = v;
    while (front != rear) {
        int c = queue[++front];
        for (int i = 0; i < N; i++) {
            if (graph[c][i] == 1) {
                if (colour[i] == -1) {
                    colour[i] = colour[c] ^ 1;
                    queue[++rear] = i;
                } else if (colour[i] == colour[c]) {
                    printf("Graph is not bipartite\n");
                    exit(1);
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) colour[i] = -1;
    for (int i = 0; i < N; i++)
        if (colour[i] == -1) bfs(i);
    printf("Graph is bipartite\n");
    return 0;
}