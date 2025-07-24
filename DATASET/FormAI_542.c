//FormAI DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char message[] = "dataminetobefun";
    int length = sizeof(message) / sizeof(char);

    printf("Before mining: %s\n", message);

    for (int i = 0; i < length; i++)
    {
        message[i] += 3;
    }

    printf("After mining: %s\n", message);

    int index = 0;
    char hidden[4];

    for (int i = 0; i < length; i++)
    {
        if (message[i] % 2 == 0)
        {
            hidden[index] = message[i];
            index++;
        }
    }

    printf("Hidden message: %c%c%c\n", hidden[0]-3, hidden[1]-3, hidden[2]-3);

    return 0;
}