//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short checksum(char *buf, unsigned size);

int main() {
    char input[100];
    unsigned short check = 0;
    printf("Enter a message to calculate its checksum (max 100 chars):\n");
    fgets(input, 100, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') input[--len] = '\0';
    check = checksum(input, len);
    printf("Checksum: %u\n", check);
    return 0;
}

unsigned short checksum(char *buf, unsigned size) {
    unsigned long sum = 0;
    unsigned short i;
    for (i = 0; i < size - 1; i += 2) {
        sum += *(unsigned short *)&buf[i];
        if (sum > 0xFFFF) {
            sum -= 0xFFFF;
        }
    }
    if (size % 2 != 0) {
        sum += *(unsigned char *)&buf[i];
        if (sum > 0xFFFF) {
            sum -= 0xFFFF;
        }
    }
    return (unsigned short)(~sum);
}