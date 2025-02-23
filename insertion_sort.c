#include <stdio.h>
#include <stdlib.h>

int swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int main() {
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    int n = 10;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j - 1] > a[j]) swap(&a[j], &a[j - 1]);
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}