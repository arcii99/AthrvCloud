//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int limit, count = 0, num = 3, factor;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("\n2 ");
    for(count = 2; count <= limit;) {
        for(factor = 2; factor <= num-1; factor++) {
            if(num%factor == 0) {
                break;
            }
        }
        if(factor == num) {
            count++;
            printf("%d ", num);
        }
        num++;
    }
    return 0;
}