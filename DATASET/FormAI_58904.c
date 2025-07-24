//FormAI DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>

int main()
{
    int n = 5;
    int arr[][5] = {
       {0, 1, 1, 1, 0},
       {1, 0, 1, 0, 1},
       {1, 1, 0, 1, 1},
       {1, 0, 1, 0, 1},
       {0, 1, 1, 1, 0}
    };

    printf("   ");
    for(int i=1; i<=n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int i=0; i<n; i++) {
        printf("%d  ", i+1);
        for(int j=0; j<n; j++) {
            if(arr[i][j]) {
                printf("✪ ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}