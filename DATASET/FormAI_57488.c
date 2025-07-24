//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    int length = strlen(input);
    int checksum = 0;
    printf("Calculating checksum...\n");
    for(int i = 0; i < length-1; i++) {
        checksum += (int) input[i];
    }
    printf("Checksum: %d\n", checksum);
    return 0;
}