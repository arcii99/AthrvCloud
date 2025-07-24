//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>

int main() {
    int sum = 0;
    int data[] = { 1,2,3,4,5 };
    int size = sizeof(data) / sizeof(int);
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    printf("Checksum: %d", sum);
    return 0;
}