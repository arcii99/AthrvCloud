//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, a[100][100], k = 1;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&n,&m);

    // Initializing the matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    // Filling the matrix in a zigzag manner
    for(i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(j = 0; j < m; j++) {
                a[i][j] = k++;
            }
        } else {
            for(j = m-1; j >= 0; j--) {
                a[i][j] = k++;
            }
        }
    }

    // Printing the matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}