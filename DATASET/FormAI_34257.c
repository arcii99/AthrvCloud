//FormAI DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int year = 2022;
    int month = 1;

    printf("Welcome to the Digital Diary of year %d.\n\n", year);

    while (month <= 12)
    {
        printf("Month %d\n", month);

        int days_in_month = 28 + rand() % 5;

        for (int i = 1; i <= days_in_month; i++)
        {
            int mood = rand() % 5;
            char* mood_string;

            switch(mood)
            {
                case 0:
                    mood_string = "Happy";
                    break;
                case 1: 
                    mood_string = "Sad";
                    break;
                case 2:
                    mood_string = "Surprised";
                    break;
                case 3:
                    mood_string = "Angry";
                    break;
                case 4:
                    mood_string = "Confused";
                    break;
            }

            printf("Day %d\nMood: %s\n", i, mood_string);

            char* activity = (rand() % 2 == 0) ? 
                "Went for a walk in a park" : "Stayed home all day";
                
            printf("Activity: %s\n\n", activity);
        }

        printf("End of month %d\n\n", month);

        month++;
    }

    printf("End of year %d\n", year);

    return 0;
}