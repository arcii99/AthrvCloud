//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int checksum = 0;
    printf("Enter a string: ");
    scanf("%s", input);
    for(int i=0; i<strlen(input); i++) {
        checksum += input[i];
    }
    printf("Checksum: %d", checksum);
    return 0;
}