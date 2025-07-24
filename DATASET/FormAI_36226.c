//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h> 

int main() 
{ 
    int num1, num2, sum, difference, product, quotient, modulo; 

    printf("Welcome to the funny calculator that does arithmetic like a clown!\n"); 
    printf("Enter the first number: "); 
    scanf("%d", &num1); 
    printf("Enter the second number: "); 
    scanf("%d", &num2); 

    // Let's do some math with a joke twist!
    sum = num1 + num2; 
    difference = num1 - num2; 
    product = num1 * num2; 
    quotient = num1 / num2; 
    modulo = num1 % num2; 
    
    printf("Calculating...\n"); 
    
    printf("Drum roll please!\n"); 
    
    printf("The sum of %d and %d is... %d! Is that bananas or what?\n", num1, num2, sum); 
    
    printf("Now let's subtract %d from %d... drum roll please... Ta-da! %d! I'm so funny, I should be arrested!\n", num2, num1, difference); 
    
    printf("So, if we multiply %d and %d together, we get... %d, and the crowd goes wild!\n", num1, num2, product); 
    
    printf("Now, let's divide %d by %d. Prepare to be amazed... Here it is! %d! I'm on fire!\n", num1, num2, quotient); 
    
    printf("And last but not least, let's take the modulo of %d and %d. Wait for it... drum roll please... %d! Haha, did you see that coming? I didn't!\n", num1, num2, modulo); 
    
    return 0; 
}