// MAXIMAL CLIQUE OF GRAPH BY BRUTE FORCE

#include <stdio.h>
#include <stdlib.h>
#define N 5

int graph[N][N] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0}
    };

int main() {
    int c = 1 << N;
    int a[N];
    int m = 0;
    int mcl[N];
    for (int i = 0; i < c; i++) {
        int n = 0;
        for (int j = 0; j < N; j++)
            if (i & (1 << j)) a[n++] = j;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (graph[a[j]][a[k]] == 0) goto next_subgraph;
            }
        }
        if (n > m) {
            m = n;
            for (int i = 0; i < m; i++) mcl[i] = a[i];
        }
        next_subgraph:
    }
    printf("Maximal clique is: ");
    for (int i = 0; i < m; i++) printf("%d ", mcl[i]);
    printf("\n");
    return 0;
}