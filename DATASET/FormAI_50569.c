//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min, max, range, num, i;
    srand(time(NULL));
    
    printf("Enter the minimum number: ");
    scanf("%d", &min);
    
    printf("Enter the maximum number: ");
    scanf("%d", &max);
    
    range = max - min + 1;   // range of numbers
    
    printf("How many random numbers do you want to generate? ");
    scanf("%d", &num);
    
    for (i = 0; i < num; i++)
    {
        int rand_num = (rand() % range) + min;
        printf("%d\n", rand_num);
    }
    
    return 0;
}