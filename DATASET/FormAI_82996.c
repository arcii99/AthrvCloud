//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int length = 0, width = 0;
    printf("Enter the length of the pattern: ");
    scanf("%d", &length);
    printf("Enter the width of the pattern: ");
    scanf("%d", &width);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rand_num = rand() % 2;
            if (rand_num == 0)
            {
                printf("*");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}