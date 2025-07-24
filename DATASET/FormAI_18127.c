//FormAI DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>

int main() {
    int num, rem, arr[100], i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    while(num > 0) {
        rem = num % 2;
        arr[i] = rem;
        i++;
        num = num / 2;
    }
    
    printf("Binary equivalent: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", arr[j]);
    }
    printf("\n");
    
    return 0;
}