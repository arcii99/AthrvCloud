//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop through rows
    for (int i = 0; i < rows; i++) {

        // Loop through columns
        for (int j = 0; j <= rows; j++) {
            int distance1 = abs(j - rows); // Distance from middle of row top half
            int distance2 = abs(j - rows + 1); // Distance from middle of row bottom half

            // If distance is equal to i, print i+1
            if (distance1 == i || distance2 == i) {
                printf("%d ", i+1);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}