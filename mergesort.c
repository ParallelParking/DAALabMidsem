#include <stdio.h>
#include <stdlib.h>

void merge(int* b, int* c, int* a, int p, int q) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (j < p && k < q) {
        if (b[j] < c[k]) a[i++] = b[j++];
        else a[i++] = c[k++];
    }
    while (j < p) a[i++] = b[j++];
    while (k < q) a[i++] = c[k++];
}

void mergesort(int* a, int n) {
    if (n <= 1) return;
    int m = n / 2;
    int o = n - m;
    int* b = malloc(sizeof(int) * m);
    int* c = malloc(sizeof(int) * o);
    for (int i = 0; i < m; i++) b[i] = a[i];
    for (int i = m; i < n; i++) c[i - m] = a[i];
    mergesort(b, m);
    mergesort(c, o);
    merge(b, c, a, m, o);
    free(b);
    free(c);
}

int main() {
    printf("Enter no. of ele: ");
    int n;
    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    mergesort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}