//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Cyberpunk style C Checksum Calculator example program

void checksum(char *data, int size) {
    int i;
    char checksum = 0;

    // Generate checksum
    for(i = 0; i < size; i++) {
        checksum += data[i];
    }

    // Print checksum
    printf("\n\n");
    printf(" ___  ____ ____ ____ _    ____    _  _ ____ ____ \n");
    printf("|__] |__/ |___ [__  |    [__     |__| |___ [__  \n");
    printf("|    |  \\ |___ ___] |___ ___]    |  | |___ ___] \n");
    printf("\n\n");
    printf("Data: %s\n", data);
    printf("Checksum: %d\n", (int) checksum);
}

int main() {
    char data[100];

    // Get input from user
    printf("  ____ _    _ _  _ ____     ____ _  _ ____ _  _ _____ ____  \n");
    printf(" |___ |    | |\\ | | __     [__  |  | |___ |\\ |   |   |___  \n");
    printf(" |___ |___ | | \\| |__]    ___] |__| |___ | \\|   |    ___] \n");
    printf("\n\n");
    printf("Enter data to calculate checksum:\n");
    scanf("%s", data);

    // Calculate checksum and print result
    checksum(data, strlen(data));

    return 0;
}