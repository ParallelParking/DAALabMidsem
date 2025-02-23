// APPROXIMATE FLOOR OF SQRT FOR ANY NUMBER

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    int u = n;
    int l = 0;
    while (l <= u) {
        printf("%d %d\n", l, u);
        int m = (l + u) / 2;
        int b = m + 1;
        if (m * m <= n && b * b > n) {
            printf("%d\n", m);
            break;
        } else if (b * b <= n) {
            l = m + 1;
        } else if (m * m > n) {
            u = m - 1;
        }
    } 
    return 0;
}