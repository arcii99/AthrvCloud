//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include<stdio.h>

#define MAX_N 1000
#define MAX_W 1000

int N, W;
int w[MAX_N],v[MAX_N];
int dp[MAX_N+1][MAX_W+1];

int max(int a, int b) {
    return a > b ? a : b;
}

void solve() {
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i+1][j];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[0][W]);
}

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    solve();
    return 0;
}