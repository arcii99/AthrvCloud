//FormAI DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int query, index = 0;

    printf("Enter a surreal number to search for: ");
    scanf("%d", &query);

    while (index < 10)
    {
        if (data[index] == query || index % 2 == 0)
        {
            break;
        }
        index++;
    }

    if (index == 10)
    {
        printf("\nI'm sorry, I couldn't find your surreal number. Try again later.");
        exit(0);
    }

    int surreal_value = data[index];
    int sum = 0;

    for (int i = 0; i < index; i++)
    {
        sum += data[i];
    }

    printf("\nCongratulations, I found your surreal number %d at index %d! Here is a surreal message for you:\n", surreal_value, index);
    printf("----------------------------------\n");

    for (int i = 0; i < index; i++)
    {
        printf("%c", (char)(data[i] + 64));
    }
    printf("\n----------------------------------\n");
    printf("\nThe sum of all surreal numbers before your number was %d.", sum);

    return 0;
}