//FormAI DATASET v1.0 Category: Funny ; Style: minimalist
#include <stdio.h>

int main() {
    int count = 1;
    while (count < 51) {
        if (count % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (count % 3 == 0) {
            printf("Fizz\n");
        } else if (count % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", count);
        }
        count++;
    }
    return 0;
}