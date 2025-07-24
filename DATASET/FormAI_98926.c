//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>

int mysteryFunction(int n, int m) {
    int result = 0;
    int i, j;
    for(i = m; i >= n; i = i >> 1) {
        for(j = n; j < i; j += i / 2) {
            result += i - j;
        }
    }
    return result;
}

int main() {
    int n, m;
    printf("Enter two integers n, m where n < m: ");
    scanf("%d %d", &n, &m);
    if(n >= m) {
        printf("Error: n must be less than m");
        return 1;
    }
    printf("The result of the mystery function is: %d", mysteryFunction(n, m));
    return 0;
}