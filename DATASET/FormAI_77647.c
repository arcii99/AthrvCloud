//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

// function to calculate checksum
int checksum(char *str, int len, int s) {
    int sum = s;

    for (int i = 0; i < len; i++) {
        sum += (int)str[i];
    }

    return sum % 256;
}

int main() {
    char str[100];
    int key;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter a key value: ");
    scanf("%d", &key);

    printf("Checksum = %d\n", checksum(str, strlen(str), key));

    return 0;
}