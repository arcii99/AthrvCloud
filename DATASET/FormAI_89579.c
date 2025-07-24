//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int input, sum=0, count=0;
    
    printf("Enter a list of numbers separated by spaces: ");
    
    while (scanf("%d", &input) == 1) {
        sum += input;
        count++;
    }
    
    printf("The sum of the numbers is %d\n", sum);
    printf("The average of the numbers is %.2f\n", (float) sum/count);
    
    return 0;
}