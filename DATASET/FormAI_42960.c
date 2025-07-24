//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>

int main() {
    printf("\nHey there! Let's create a super fun program for system administration!\n");

    // Declare variables
    int numUsers = 0;
    int totalSize = 0;

    // Get user input for number of users
    printf("\nHow many users are on the system? ");
    scanf("%d", &numUsers);

    // Get user input for each user's storage size
    for (int i = 1; i <= numUsers; i++) {
        int size = 0;
        printf("What is the storage size (in GB) for user %d? ", i);
        scanf("%d", &size);
        totalSize += size;
    }

    // Calculate average size per user
    float avgSize = totalSize / (float) numUsers;

    // Output results
    printf("\nThe total storage size for all users is %d GB.\n", totalSize);
    printf("The average storage size per user is %.2f GB.\n", avgSize);

    printf("\nThanks for creating this fun system administration program with me! Happy coding!\n");

    return 0;
}