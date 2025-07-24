//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int room_number, max_rooms;
    float chance, rand_num;
    time_t t;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Enter the number of rooms in the house: ");
    scanf("%d", &max_rooms);
    
    printf("Enter the probability of a room being haunted (0-1): ");
    scanf("%f", &chance);
    
    printf("You enter the first room...\n");
    
    srand((unsigned) time(&t));
    
    for(room_number=1; room_number<=max_rooms; room_number++)
    {
        rand_num = (float)rand()/(float)RAND_MAX;
        
        if(rand_num < chance)
        {
            printf("Room %d is haunted! You are trapped!\n", room_number);
            break;
        }
        
        printf("Room %d is clear. You move on...\n", room_number);
    }
    
    if(room_number == max_rooms+1)
    {
        printf("You have successfully navigated through all %d rooms! Congratulations!\n", max_rooms);
    }
    
    return 0;
}