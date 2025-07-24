//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

// Recursive function to print a happy message
void happy(int n)
{
    if (n == 0)
    {
        printf("Yay, we did it! \n");
    }
    else if (n < 0)
    {
        printf("Oops, we made a mistake :( \n");
    }
    else
    {
        printf("We're making progress! %d more times to go! \n", n);
        happy(n-1);
    }
}

int main()
{
    int num_times = 10;

    printf("Let's spread some happiness! \n\n");

    // Call the recursive function
    happy(num_times);

    printf("\nDone spreading happiness! \n");

    return 0;
}