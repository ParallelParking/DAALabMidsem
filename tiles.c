#include <stdio.h>

int tiling(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return tiling(n - 1) + tiling(n - 2);
}

int main() {
    int n = 5;
    printf("possible tilings: %d\n", tiling(n));
    return 0;
}