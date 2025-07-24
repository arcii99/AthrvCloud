//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>

int main() {
    int input, checksum = 0;

    printf("Enter integers to calculate checksum. Enter -1 to end input.\n");

    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        checksum += input;
    }

    printf("Checksum: %d\n", checksum);
    
    return 0;
}