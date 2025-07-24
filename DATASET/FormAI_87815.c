//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int cmp(const void *a, const void *b) {
    return (*(int *) b) - (*(int *) a);
}

int main() {
    int n, m;
    int values[MAX_N];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    qsort(values, n, sizeof(int), cmp);

    int ans = 0;
    for (int i = 0; i < n; ) {
        int sum = values[i];
        int j = i + 1;
        while (sum + values[j] <= m && j < n) {
            sum += values[j++];
        }
        ans++;
        if (j == n) {
            break;
        }
        i = j;
    }

    printf("%d\n", ans);

    return 0;
}