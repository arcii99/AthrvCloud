//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
		
	    // Create a puzzling pattern by checking if i or j is 
	    // even or odd using the modulo operator and printing
	    // different characters accordingly
	    
            if (i % 2 == 0 && j % 2 == 0) {
                printf("A");
            } else if (i % 2 == 0 && j % 2 != 0) {
                printf("B");
            } else if (i % 2 != 0 && j % 2 == 0) {
                printf("C");
            } else {
                printf("D");
            }

            // Depending on the value of i and j, we print additional
            // characters to create a unique pattern
            
            if (i % 3 == 0 && j % 3 == 0) {
                printf("E");
            } else if (i + j == n + 1) {
                printf("F");
            } else if (j < i && j <= n / 2) {
                printf("G");
            } else if (j > i && j >= n / 2 + 1) {
                printf("H");
            } else {
                printf("I");
            }
        }
        printf("\n");
    }

    return 0;
}