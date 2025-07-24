//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    float current_temp = 30.0;
    float min_temp = 15.0;
    float max_temp = 40.0;
    float diff_temp = max_temp - min_temp;

    printf("Welcome to the Surreal Temperature Monitor!\n");
    printf("The current temperature is %.1f degrees Celsius.\n", current_temp);

    while(1)
    {
        int rand_num = rand() % 5;

        switch(rand_num)
        {
            case 0:
                current_temp += 1.5;
                printf("The temperature is rising rapidly, it is now %.1f degrees Celsius.\n", current_temp);
                break;
            case 1:
                current_temp -= 1.0;
                printf("The temperature is dropping, it is now %.1f degrees Celsius.\n", current_temp);
                break;
            case 2:
                current_temp += 0.5;
                printf("The temperature is rising slowly, it is now %.1f degrees Celsius.\n", current_temp);
                break;
            case 3:
                current_temp -= 0.8;
                printf("The temperature is dropping slightly, it is now %.1f degrees Celsius.\n", current_temp);
                break;
            case 4:
                printf("The temperature is staying constant at %.1f degrees Celsius.\n", current_temp);
                break;
            default:
                printf("The temperature monitor has malfunctioned and has shut down\n");
                exit(1);
        }

        if(current_temp > max_temp)
        {
            printf("Warning! The temperature has exceeded the maximum limit!\n");
            break;
        }

        if(current_temp < min_temp)
        {
            printf("Warning! The temperature has dropped below the minimum limit!\n");
            break;
        }

        sleep(1); //wait one second before updating temperature
    }

    printf("Surreal Temperature Monitor Shutting Down...\n");
    return 0;
}