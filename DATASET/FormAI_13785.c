//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 1, b = 2, sum = 0;
    while(a <= 10) {
        if(a % 2) {
            // a is odd
            int odd_sum = 0;
            for(b = 2; b <= 20; b += 2) {
                odd_sum += b;
                if(odd_sum >= 25) {
                    break;
                }
            }
            sum += odd_sum;
        } else {
            // a is even
            int even_sum = 0;
            for(b = 1; b <= 10; b++) {
                even_sum += b;
                if(even_sum >= 15) {
                    break;
                }
            }
            sum += even_sum;
        }
        a++;
    }
    printf("The result is %d\n", sum);
    return 0;
}