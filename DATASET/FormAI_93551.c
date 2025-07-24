//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>

int checksum(char* str) {
    int sum = 0;
    while (*str != '\0') {
        sum += *str;
        str++;
    }
    return sum;
}

int main() {
    char* str;
    int length;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);
    printf("Checksum of \"%s\" is %d.\n", str, checksum(str));

    return 0;
}