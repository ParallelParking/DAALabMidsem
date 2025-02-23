// MIDDLE SCHOOL METHOD TO GENERATE GCD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x;
    int y;
    printf("Enter 2 numbers: ");
    scanf("%d%d", &x, &y);
    int m = x < y ? x : y;
    int gcd = 1;
    for (int i = 2; i < m; i++) {
        for (int j = 2; j < i; j++)
            if (i % j == 0) goto next_num;
        while (x % i == 0 && y % i == 0) {
            x /= i;
            y /= i;
            gcd *= i;
        }
        next_num:
    }
    printf("GCD is: %d\n", gcd);
    return 0;
}