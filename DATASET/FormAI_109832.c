//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void printNumbers(int n)
{
    if (n <= 0) {
        return;
    }
    
    printf("%d ", n);
    
    printNumbers(n-1);
}

int main()
{
    printf("Enter a number: ");
    
    int num;
    scanf("%d", &num);
    
    printf("The numbers are: ");
    printNumbers(num);
    
    return 0;
}