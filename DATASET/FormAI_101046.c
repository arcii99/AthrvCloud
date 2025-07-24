//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int data[10], checksum = 0;
    printf("Enter 10 integers:\n");

    // Taking input from the user
    for(int i = 0; i < 10; i++) {
        scanf("%d", &data[i]);
    }

    // Calculating checksum
    for(int i = 0; i < 10; i++) {
        checksum = checksum + data[i];
    }
    checksum = ~checksum + 1;

    // Displaying results
    printf("Checksum = %d\n", checksum);
    return 0;
}