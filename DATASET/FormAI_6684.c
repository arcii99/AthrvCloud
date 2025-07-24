//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include<stdio.h> 

int curiosity(int n) { 
    if (n <= 0) { 
        return 0; 
    } 
    else { 
        printf("Curiosity killed the cat!\n"); 
        return n + curiosity(n-1); 
    } 
} 

int main() { 
    int num; 
    printf("Enter a number: "); 
    scanf("%d", &num); 
    printf("The sum of 1 to %d is %d\n", num, curiosity(num)); 
    return 0; 
}