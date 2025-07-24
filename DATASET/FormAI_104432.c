//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: invasive
#include <stdio.h>

int main()
{
    int time = 0;
    char color = 'r'; // start with red

    while (1) // infinite loop
    {
        if (time == 0)
        {
            printf("The light is %c\n", color);
        }

        time++; // increment time

        if (color == 'r') // if red
        {
            if (time == 10) // stay red for 10 seconds
            {
                time = 0; // reset time
                color = 'g'; // turn green
            }
        }
        else if (color == 'g') // if green
        {
            if (time == 15) // stay green for 15 seconds
            {
                time = 0; // reset time
                color = 'y'; // turn yellow
            }
        }
        else if (color == 'y') // if yellow
        {
            if (time == 5) // stay yellow for 5 seconds
            {
                time = 0; // reset time
                color = 'r'; // turn red
            }
        }
    }

    return 0;
}