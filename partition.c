// EQUAL PARTITION PROBLEM BRUTE FORCE

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1,5,11,5};
    int n = 4;
    int t = 0;
    for (int i = 0; i < n; i++) t += a[i];
    if (t % 2 == 1) {
        printf("No partition possible\n");
        exit(0);
    }
    t /= 2;
    int c = 1 << n;
    for (int i = 0; i < c; i++) {
        int s = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) s += a[j];
        if (s == t) {
            printf("Successful partition: \{");
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) printf(" %d ", a[j]);
            printf("} {");
            for (int j = 0; j < n; j++)
                if (!(i & (1 << j))) printf(" %d ", a[j]);
            printf("}\n");
            break;
        }
    }
    return 0;
}