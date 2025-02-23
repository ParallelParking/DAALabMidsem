#include <stdio.h>
#include <stdlib.h>

int swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r) {
    int i = l;
    int j = r + 1;
    int p = a[l];
    do {
        do {
            i += 1;
        } while (a[i] < p);
        do {
            j -= 1;
        } while (a[j] > p);
        swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int r) {
    if (l >= r) return;
    int s = partition(a, l, r);
    quicksort(a, l, s - 1);
    quicksort(a, s + 1, r);
}

int main() {
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    int n = 10;
    quicksort(a, 0, 9);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}