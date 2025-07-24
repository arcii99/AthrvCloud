//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    char message[1000];
    int i, checksum = 0;
    printf("Enter message to calculate checksum: ");
    scanf("%s", message);
    for(i = 0; message[i] != '\0'; ++i) {
        checksum += message[i];
        checksum %= 255;
    }
    printf("Checksum: %d\n", checksum);
    return 0;
}