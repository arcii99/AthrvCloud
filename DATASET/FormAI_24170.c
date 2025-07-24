//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>

int checksum(char str[]) {
    int sum = 0;
    int i = 0;

    while (str[i] != '\0') {
        sum += str[i];
        i++;
    }

    return sum;
}

int main() {
    char message[100];
    int result;

    printf("Enter a message to calculate its checksum: ");
    scanf("%s", message);

    result = checksum(message);

    printf("The checksum of the message '%s' is %d\n", message, result);

    return 0;
}