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

int order[N];
int x = 0;

void bfs(int v) {
    visited[v] = 1;
    int queue[N];
    int front = -1;
    int rear = -1;
    queue[++rear] = v;
    while (front != rear) {
        int c = queue[++front];
        order[x++] = c;
        for (int i = 0; i < N; i++) {
            if (graph[c][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++)
        if (visited[i] == 0) bfs(i);
    printf("BFS visit order: ");
    for (int i = 0; i < N; i++) printf("%d ", order[i]);
    printf("\n");
}