//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include<stdio.h>

int main() {
    
    int n, i, flag;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Prime numbers between 2 and %d are: ", n);
    
    // loop through all numbers between 2 to n
    for (i = 2; i <= n; i++) {
        flag = 0;
        
        // check for factors
        for (int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}