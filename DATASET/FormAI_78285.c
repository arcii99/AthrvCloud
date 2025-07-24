//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

int calcSum(int index, char* buffer, int checksum) {
    if (buffer[index] == '\0') {
        return checksum;
    }

    checksum += buffer[index];
    return calcSum(index+1, buffer, checksum);
}

int main() {
    char buffer[1024];
    printf("Enter a string: ");
    fgets(buffer, 1024, stdin);
    int checksum = calcSum(0, buffer, 0);
    printf("Checksum: %d", checksum);
    return 0;
}