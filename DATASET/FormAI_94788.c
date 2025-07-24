//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>

int main() {
	// Getting the user input for length of the pattern
    int length;
    printf("Enter the length of the pattern: ");
    scanf("%d", &length);

    // Printing the C pattern
    for (int row = 0; row < length; row++) {
        for (int column = 0; column < length; column++) {
            // Check if first column or last row or last row column where C needs to be printed
            if (column == 0 || row == 0 || row == length - 1 && column > 0 && column < length - 1) {
                printf("C");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}