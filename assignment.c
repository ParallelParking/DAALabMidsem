// ASSIGNMENT PROBLEM VIA BRUTE FORCE
// INVOLVES JOHNSON TROTTER 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4

int jobs[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
}; // jobs[i][j] is the time taken by ith person to do jth job

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int people[N] = {0, 1, 2, 3}; // To generate all possible permutations of people
    int dxn[N] = {0}; // 0 = left, 1 = right
    int min_cost = INT_MAX;
    int i;
    int best_assignment[N];
    while (1) {
        // calculate cost of current permutation:
        int curr_cost = 0;
        for (i = 0; i < N; i++) curr_cost += jobs[people[i]][i];
        if (curr_cost < min_cost) {
            min_cost = curr_cost;
            for (i = 0; i < N; i++) best_assignment[i] = people[i];
        }

        // find index of largest mobile integer
        int largest_mobile_index = -1;
        if (dxn[0] == 1 && people[1] < people[0]) largest_mobile_index = 0;
        if (dxn[N - 1] == 0 && people[N - 1] > people[N - 2] && people[N - 1] > people[largest_mobile_index])
            largest_mobile_index = N - 1;
        for (int i = 1; i < N - 1; i++) {
            if (largest_mobile_index != -1 && people[i] < people[largest_mobile_index]) continue;
            if (dxn[i] == 0) {
                if (people[i] > people[i - 1])
                    largest_mobile_index = i; 
            } else {
                if (people[i] > people[i + 1])
                    largest_mobile_index = i;
            }
        }

        // if largest mobile index = -1, permutations complete
        if (largest_mobile_index == -1) break;

        // swap largest mobile integer in required direction
        if (dxn[largest_mobile_index] == 0) {
            swap(&people[largest_mobile_index], &people[largest_mobile_index - 1]);
            swap(&dxn[largest_mobile_index], &dxn[largest_mobile_index - 1]);
            largest_mobile_index -= 1;
        } else {
            swap(&people[largest_mobile_index], &people[largest_mobile_index + 1]);
            swap(&dxn[largest_mobile_index], &dxn[largest_mobile_index + 1]);
            largest_mobile_index += 1;
        }
        
        // Invert dxn of all integers > recently moved one
        for (i = 0; i < N; i++)
            if (people[i] > people[largest_mobile_index]) dxn[i] ^= 1;
    }
    printf("Minimum cost assignment: %d\n", min_cost);
    printf("Assignment: ");
    for (i = 0; i < N; i++) printf("%d ", best_assignment[i]);
    printf("\n");
    return 0;
}