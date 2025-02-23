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

int main() {
    int toposort[N];
    int removed[N] = {0};
    int x = 0;
    while (x != N) {
        // Find vertex with indegree 0
        int v = -1;
        for (int i = 0; i < N; i++) {
            if (removed[i]) continue;
            for (int j = 0; j < N; j++) {
                if (graph[j][i]) goto next_vertex; 
            }
            v = i;
            break;
            next_vertex:
        }
        
        // add v to result
        toposort[x++] = v;
        removed[v] = 1;
        // remove vertex v by removing all outward edges
        for (int i = 0; i < N; i++) graph[v][i] = 0;
    }
    for (int i = 0; i < N; i++) printf("%d ", toposort[i]);
    printf("\n");
    return 0;
}