//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    srand(time(0));
    int rooms[5] = {1, 2, 3, 4, 5};
    int ghosts = rand()%3+1;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("There are five rooms in this house. You must find all the ghosts before you can leave. Boo!\n");
    printf("You're starting in room %d.\n", rooms[0]);
    int num_ghosts_found = 0;
    int room_num = 0;
    while(num_ghosts_found < ghosts)
    {   
        int search = rand()%5+1;
        if(search == 1 || search == 2 || search == 3)
        {
            printf("You search room %d and find nothing.\n", rooms[room_num]);
        }
        else
        {   
            printf("You search room %d and find a ghost! AHH!\n", rooms[room_num]);
            num_ghosts_found++;
        }
        room_num++;
        if(room_num >= 5)
        {
            room_num = 0;
        }
    }
    printf("Congratulations, you found all %d ghosts! You may now exit the haunted house.\n", ghosts);
    return 0;
}