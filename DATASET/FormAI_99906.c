//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>

int main() {
    int num, sum = 0, temp;

    printf("Enter numbers to calculate checksum (-1 to end): ");

    while(1) {
        scanf("%d", &num);
        if(num == -1) break;
        sum += num;
        if(sum >= 256) {
            temp = sum / 256;
            sum = sum % 256;
            sum += temp;
        }
    }

    printf("Checksum: %d\n", 255 - sum);

    return 0;
}