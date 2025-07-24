//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complex
#include <stdio.h>
#include <string.h>

int calculate_checksum(char *str, int len);

int main() {
    char message[100];
    int checksum;

    printf("Enter message: ");
    scanf("%s", message);

    checksum = calculate_checksum(message, strlen(message));

    printf("\nChecksum for %s is %d\n", message, checksum);

    return 0;
}

int calculate_checksum(char *str, int len) {
    int checksum = 0;
    int i;

    for(i = 0; i < len; i++) {
        checksum += (int) str[i];
    }

    return checksum % 256;
}