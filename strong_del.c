// DELETE STRONG NUMBERS USING RECURSION

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

void delStrong(int* a, int i, int* n) {
    if (i == *n) return;
    int x = a[i];
    int s = 0;
    while (x) {
        int f = x % 10;
        x /= 10;
        s += factorial(f);
    }
    if (s == a[i]) {
        for (int j = i; j < *n - 1; j++) a[j] = a[j + 1];
        (*n)--;
        delStrong(a, i, n);
    } else {
        delStrong(a, i + 1, n);
    }
}

int main() {
    int a[] = {1,2,3,4,145,6,7};
    int n = 7;
    delStrong(a, 0, &n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}