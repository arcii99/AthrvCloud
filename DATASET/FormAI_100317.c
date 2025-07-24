//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *a = (int*) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int *b = (int*) malloc(m * sizeof(int));
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        int max_val = a[i];
        for(int j=0; j<m; j++) {
            if(b[j] < max_val) {
                continue;
            }
            if(b[j] >= max_val) {
                ans++;
                b[j] = 0;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}