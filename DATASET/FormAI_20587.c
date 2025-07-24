//FormAI DATASET v1.0 Category: Binary Converter ; Style: surprised
#include<stdio.h> 
#include<math.h> 

int main() 
{ 
    int num, decimal_num, rem, base = 1, binary = 0; 

    printf("Enter a decimal integer: "); 
    scanf("%d", &num); 
    
    decimal_num = num; 
    
    while(num > 0) 
    { 
        rem = num % 2; 
        binary = binary + rem * base; 
        num = num / 2; 
        base = base * 10; 
    } 
    
    printf("The binary equivalent of %d is %d\n", decimal_num, binary); 
    printf("Whoa! We just converted decimal to binary. I can't believe it worked!"); 
    
    return 0; 
}