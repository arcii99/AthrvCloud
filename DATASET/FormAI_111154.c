//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main() {
    int n, i;
    bool flag;
    
    printf("Enter the maximum range: ");
    scanf("%d", &n);
    
    printf("The prime numbers between 1 and %d are:\n", n);
    
    for (i = 2; i <= n; i++) {
        flag = is_prime(i);
        if (flag)
            printf("%d ", i);
    }
    
    printf("\n");
    return 0;
}

bool is_prime(int n) {
    int i, count = 0;
    bool flag = false;
    
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            count++;
            break;
        }
    }
    
    if (count == 0 && n != 1)
        flag = true;
    
    return flag;
}