//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TIME_LIMIT 60

int main(void)
{
    int count = 0;
    char text[100] = { 0 };
    char input_text[100] = { 0 };

    printf("Welcome to the typing speed test! You have 60 seconds to type as many words as possible.\n");

    printf("\nEnter the following text:\n");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed et commodo mi, vel facilisis magna. Fusce a pulvinar turpis. Aliquam sit amet metus nec justo malesuada euismod a a erat. Aenean nec dolor pulvinar, maximus mi eu, congue felis. Fusce eget tellus quis dolor rhoncus suscipit et in lorem. Donec vitae tellus non justo hendrerit accumsan vitae et felis. Nullam commodo, augue vel vestibulum luctus, orci velit convallis est, nec dictum nisi mauris in est. Suspendisse quis lectus bibendum, feugiat velit in, eleifend sapien. Vestibulum mi mauris, malesuada vitae elementum eu, tempus ut magna.");
    printf("\n\n");

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < TIME_LIMIT)
    {
        printf("Type the above text:\n");
        fgets(input_text, 100, stdin);

        int i = 0, j = 0;
        while (input_text[i] != '\0')
        {
            if (input_text[i] == text[j])
            {
                i++; j++;
            }
            else
            {
                i++;
            }
        }
        count = j;
    }

    printf("\n\n\n");

    printf("You typed %d words in %d seconds.\n", count / 5, TIME_LIMIT);

    return 0;
}