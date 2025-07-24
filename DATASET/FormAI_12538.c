//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>

#define MAX_N 1000

int main(void) {
    int n, k, w[MAX_N], sum[MAX_N];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (i > 0) {
            sum[i] = sum[i - 1] + w[i];
        } else {
            sum[i] = w[i];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        ans += (sum[i + k - 1] - sum[i] + w[i]) * (k - 1);
    }
    printf("%d\n", ans);
    return 0;
}