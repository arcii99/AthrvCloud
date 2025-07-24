//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int car_direction = 0; // 0 - forward, 1 - backward, 2 - left, 3 - right
    int car_speed = 0; // 0 - stop, 1- slow speed, 2 - medium speed, 3 - high speed
    int battery_power = 100; // initial battery level
    int distance_traveled = 0; // keeps track of total distance travelled
    int time_elapsed = 0; // keeps track of time elapsed

    srand(time(NULL)); // Initializing the random number generator

    printf("Welcome to Remote control Vehicle Simulator.\n\n");
    printf("Use 'W' key to move forward, 'S' key to move backward, 'A' key to move left and 'D' key to move right.\n");
    printf("Use '1' key to set speed to slow, '2' key to set speed to medium and '3' key to set speed to high.\n");
    printf("Press 'Q' key to quit the program.\n\n");
    
    while(1) // Loop to keep the program running
    {
        int random_battery_loss = rand()%5 + 1; // generates a random number between 1-5 for battery loss
        int random_distance = rand()%10 + 1; // generates a random number between 1-10 for distance travelled
        int random_time = rand()%5 + 1; // generates a random number between 1-5 for time elapsed

        // Updating battery level, distance travelled and time elapsed
        battery_power -= random_battery_loss;
        distance_traveled += random_distance;
        time_elapsed += random_time;

        if(battery_power <= 0) // Checking if battery has ran out
        {
            printf("Battery has ran out. Program is terminating.\n");
            break; // Exiting the program
        }
        else if(distance_traveled >= 1000) // Checking if distance limit has reached
        {
            printf("Distance limit has reached. Program is terminating.\n");
            break; // Exiting the program
        }

        printf("Direction: ");
        if(car_direction == 0) printf("Forward");
        else if(car_direction == 1) printf("Backward");
        else if(car_direction == 2) printf("Left");
        else if(car_direction == 3) printf("Right");

        printf("\tSpeed: ");
        if(car_speed == 0) printf("Stop");
        else if(car_speed == 1) printf("Slow");
        else if(car_speed == 2) printf("Medium");
        else if(car_speed == 3) printf("High");

        printf("\tBattery power: %d%%\n", battery_power);

        // Taking user input
        char input = getchar();
        while(getchar() != '\n');
        if(input == 'q' || input == 'Q') // Quitting the program if user presses 'Q' key
        {
            printf("Program is terminating.\n");
            break;
        }
        else if(input == 'w' || input == 'W') // Moving forward if user presses 'W' key
        {
            car_direction = 0;
        }
        else if(input == 's' || input == 'S') // Moving backward if user presses 'S' key
        {
            car_direction = 1;
        }
        else if(input == 'a' || input == 'A') // Moving left if user presses 'A' key
        {
            car_direction = 2;
        }
        else if(input == 'd' || input == 'D') // Moving right if user presses 'D' key
        {
            car_direction = 3;
        }
        else if(input == '1') // Setting speed to slow if user presses '1' key
        {
            car_speed = 1;
        }
        else if(input == '2') // Setting speed to medium if user presses '2' key
        {
            car_speed = 2;
        }
        else if(input == '3') // Setting speed to high if user presses '3' key
        {
            car_speed = 3;
        }
    }

    return 0;
}