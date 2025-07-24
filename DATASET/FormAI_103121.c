//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>

int main() {

    int sum = 0;
    char message[] = "This is a test message";
    int length = sizeof(message) - 1;
    int i;

    for (i = 0; i < length; i++) {
        sum += message[i];
    }

    int checksum = sum % 256;

    printf("Message: %s\n", message);
    printf("Checksum: %d\n", checksum);

    return 0;

}