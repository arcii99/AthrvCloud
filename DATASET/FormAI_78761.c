//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: artistic
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int p[1010], w[1010];
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]);

    int dp[1010][10010] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-w[i]]+p[i]);
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}