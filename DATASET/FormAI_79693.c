//FormAI DATASET v1.0 Category: Scientific ; Style: excited
/*
Excitedly demonstrating an example program in C!

We will be creating a function that calculates the factorial of a number using a loop. 
I'm so excited to share this amazing code with you!

*/

#include <stdio.h>

int factorial(int n) {
    int result = 1;

    for(int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int num = 5;
    int fact = factorial(num);

    printf("The factorial of %d is %d! Wow, that was amazing! \n", num, fact);

    return 0;
}

/*
Wow! Wasn't that amazing? In just a few lines of code, we were able to calculate the factorial of a number using a loop. 
I hope you're as excited as I am about the power and creativity of the C language. 
Keep coding and exploring the endless possibilities of C programming!
*/