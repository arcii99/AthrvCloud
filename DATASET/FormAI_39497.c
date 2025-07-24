//FormAI DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
    int choice;
    char* weather[5] = {"sunny", "cloudy", "rainy", "windy", "snowy"};
    srand(time(0));
    
    printf("Welcome to the Weather Simulation!\n");
    printf("Enter 1 to know the current weather in your area.\n");
    printf("Enter 2 to generate a random weather.\n");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        char user_location[20];
        printf("Enter your current location: ");
        scanf("%s", user_location);
        
        printf("The current weather in %s is %s.\n", user_location, weather[rand()%5]);
    }
    else if(choice == 2)
    {
        printf("The generated weather is %s.\n", weather[rand()%5]);
    }
    else
    {
        printf("Invalid choice! Please choose 1 or 2.\n");
    }
    
    return 0;
}