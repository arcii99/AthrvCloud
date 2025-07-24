//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <string.h>

int calculateChecksum(char *str);

int main() {
    char input[100];
    printf("Enter a string to calculate checksum: ");
    scanf("%s", input);

    int checksum = calculateChecksum(input);
    printf("Checksum of %s is %d\n", input, checksum);

    return 0;
}

int calculateChecksum(char *str) {
    int checksum = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        checksum += (int) str[i];
    }
    return checksum;
}