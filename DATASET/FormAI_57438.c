//FormAI DATASET v1.0 Category: Log analysis ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Surrealist Log Analysis Program!\n");
    printf("We will now analyze the logs of a parallel universe...\n");
    printf("...\n");
    printf("...\n");
    printf("...\n");
    printf("Log analysis complete!\n");

    char* logs[] = {"The sky was made of cheese",
                    "Cats flew in formation",
                    "The ocean was made of honey",
                    "Trees rapped about quantum physics"};

    int num_logs = 4;
    int i, j;

    printf("Here are some examples of the logs we analyzed:\n");
    for(i=0; i<num_logs; i++)
    {
        printf("%d. %s\n", i+1, logs[i]);
    }

    printf("Now let's count how many times certain surreal objects appear...\n");

    char* surreal_objects[] = {"cheese sky",
                               "flying cats",
                               "honey ocean",
                               "rapping trees"};

    int surreal_counts[] = {0, 0, 0, 0};

    for(i=0; i<num_logs; i++)
    {
        for(j=0; j<4; j++)
        {
            if(strstr(logs[i], surreal_objects[j]) != NULL)
                surreal_counts[j]++;
        }
    }

    printf("Surreal Object Counts:\n");
    for(i=0; i<4; i++)
    {
        printf("%s: %d\n", surreal_objects[i], surreal_counts[i]);
    }

    printf("Interesting, isn't it? Who needs boring real-world logs when we have surrealist ones?\n");

    return 0;
}