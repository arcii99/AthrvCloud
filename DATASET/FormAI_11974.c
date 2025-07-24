//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
/* A unique C Checksum Calculator Program */
#include <stdio.h>

int main() {
    unsigned long int sum = 0;
    char input[1000];
    int i;
    printf("Enter the string to calculate checksum:\n");
    scanf("%s", &input);

    /* Traverse through the string to calculate checksum */
    for (i = 0; input[i] != '\0'; i++) {
        sum += input[i];
        sum = (sum << 1) | (sum >> ((sizeof(unsigned long int) * 8) - 1)); 
    }

    printf("Checksum: %lu\n", sum);
    return 0;
}