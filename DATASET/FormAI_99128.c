//FormAI DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char weather[5][10] = {"sunny", "cloudy", "rainy", "stormy", "snowy"};
    char time_of_day[2][10] = {"day", "night"};

    srand(time(NULL));
    int rand_num_weather = rand() % 5;
    int rand_num_time = rand() % 2;

    printf("Today's weather simulation:\n");
    printf("Weather: %s\n", weather[rand_num_weather]);
    printf("Time of day: %s\n\n", time_of_day[rand_num_time]);

    if(strcmp(weather[rand_num_weather], "sunny") == 0)
    {
        printf("The sun is shining bright,\n");
        if(strcmp(time_of_day[rand_num_time], "day") == 0)
        {
            printf("The skies are robin's egg blue,\n");
        }
        else
        {
            printf("The stars twinkle in the sky,\n");
        }
        printf("Everything looks so beautiful,\n");
        printf("Just like you.\n");
    }
    else if(strcmp(weather[rand_num_weather], "cloudy") == 0)
    {
        printf("The sky is filled with clouds,\n");
        if(strcmp(time_of_day[rand_num_time], "day") == 0)
        {
            printf("The world seems so grey,\n");
        }
        else
        {
            printf("The moon is hidden from sight,\n");
        }
        printf("But even though it's cloudy outside,\n");
        printf("My love for you will never fade away.\n");
    }
    else if(strcmp(weather[rand_num_weather], "rainy") == 0)
    {
        printf("The raindrops pitter-patter on my window,\n");
        if(strcmp(time_of_day[rand_num_time], "day") == 0)
        {
            printf("The world outside is dreary and wet,\n");
        }
        else
        {
            printf("But inside with you I'm warm and dry,\n");
        }
        printf("I'm glad I have you in my life,\n");
        printf("To chase away the rainy day blues.\n");
    }
    else if(strcmp(weather[rand_num_weather], "stormy") == 0)
    {
        printf("The lightning flashes, the thunder booms,\n");
        if(strcmp(time_of_day[rand_num_time], "day") == 0)
        {
            printf("The chaos of the storm is all around,\n");
        }
        else
        {
            printf("The night is dark and ominous,\n");
        }
        printf("But with you by my side,\n");
        printf("I feel like I can weather any storm.\n");
    }
    else if(strcmp(weather[rand_num_weather], "snowy") == 0)
    {
        printf("The snow gently falls from the sky,\n");
        if(strcmp(time_of_day[rand_num_time], "day") == 0)
        {
            printf("The world outside is covered in white,\n");
        }
        else
        {
            printf("The moonlight reflects off of the snow,\n");
        }
        printf("Winter can be harsh and cold,\n");
        printf("But it's warmer with you here by my side.\n");
    }

    return 0;
}