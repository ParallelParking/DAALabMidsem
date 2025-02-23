#include <stdio.h>

int power(int a, int n) {
    if (n == 0) return 1;
    int x = power(a, n / 2);
    if (n % 2 == 0) return x * x;
    else return a * x * x;
}

int main() {
    int a = 4;
    int n = 12;
    printf("4^12 = %d\n", power(a, n));
    return 0;
}