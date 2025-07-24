//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int events[n][2];
    for(int i=0; i<n; i++) {
        scanf("%d%d", &events[i][0], &events[i][1]);
    }

    int rooms[m];
    for(int i=0; i<m; i++) {
        rooms[i] = 0;
    }

    int count = 0; 
    for(int i=0; i<n; i++) {
        int j=0;
        for(j=0; j<m; j++) {
            if(events[i][0] >= rooms[j]) {
                rooms[j] = events[i][1];
                count++;
                break;
            }
        }
    }

    printf("%d", count);
    return 0;
}