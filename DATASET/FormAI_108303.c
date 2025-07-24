//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter message to calculate checksum: ");
    fgets(input, 100, stdin);
    int length = strlen(input);
    int i, sum = 0;
    for(i = 0; i < length; i++) {
        sum += (int)input[i];
    }
    // Take one's complement of sum
    sum = ~sum;
    printf("Checksum: %d\n", sum);
    return 0;
}