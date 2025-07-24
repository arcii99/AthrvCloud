//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

// A recursive function to calculate factorial
int medieval_factorial(int n){
    if(n == 0 || n == 1){
        printf("Verily! Thou hast arrived at the end of thy path.\n");
        return 1;
    }
    else{
        printf("Thou must go deeper into thy journey to findeth the answer!\n");
        return n * medieval_factorial(n-1);
    }
}

int main(){
    int num;
    printf("Hark! What number wouldst thou like to findeth the factorial of? \n");
    scanf("%d", &num);
    printf("Ah, I see! A noble quest indeed. Let me see what the heavens have in store for thee...\n");
    int factorial = medieval_factorial(num);
    printf("Behold, thy answer: %d", factorial);
    return 0;
}