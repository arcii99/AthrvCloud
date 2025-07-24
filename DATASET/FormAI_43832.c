//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int rand1 = rand() % 100 + 1; // generate random number between 1 and 100
    int rand2 = rand() % 100 + 1;
    int sum = rand1 + rand2; // calculate sum
    printf("What is the result of %d + %d?\n", rand1, rand2);
    int answer;
    scanf("%d", &answer);
    if (answer == sum)
    {
        printf("Correct! You are a math genius!\n");
    }
    else
    {
        printf("Wrong! The answer is %d. You need to brush up on your math skills!\n", sum);
    }
    return 0;
}