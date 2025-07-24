//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the room names and corresponding light status
#define KITCHEN "Kitchen"
#define BEDROOM "Bedroom"
#define LIVING_ROOM "Living Room"
#define BATHROOM "Bathroom"

int is_light_on(const char *room); // returns the status of the light in the specified room
void turn_on_light(const char *room); // turns on the light in the specified room
void turn_off_light(const char *room); // turns off the light in the specified room

int main()
{
    // initialize the available rooms and their lights' status
    const char *rooms[] = {KITCHEN, BEDROOM, LIVING_ROOM, BATHROOM};
    int room_status[] = {0, 0, 0, 0};

    // display the available rooms and their current light status
    printf("Available rooms:\n");
    for (int i = 0; i < sizeof(rooms) / sizeof(rooms[0]); i++)
    {
        printf("%s: Light is %s\n", rooms[i], is_light_on(rooms[i]) ? "ON" : "OFF");
    }
    printf("\n");

    // demonstrate turning on and off the lights synchronously

    printf("Turning on the lights in all rooms...\n");
    for (int i = 0; i < sizeof(rooms) / sizeof(rooms[0]); i++)
    {
        turn_on_light(rooms[i]);
        room_status[i] = 1; // update the light status for the room
    }

     printf("Lights are now on in all rooms.\n\n");

     printf("Turning off the lights in all rooms...\n");
     for (int i = 0; i < sizeof(rooms) / sizeof(rooms[0]); i++)
     {
         turn_off_light(rooms[i]);
         room_status[i] = 0; // update the light status for the room
     }

     printf("Lights are now off in all rooms.\n");

     return 0;
}

// simulate the light being on or off in the specified room
int is_light_on(const char *room)
{
    // generate a random number between 0 and 1
    int random_num = rand() % 2;

    if (strcmp(room, KITCHEN) == 0)
    {
        return random_num;
    }
    else if (strcmp(room, BEDROOM) == 0)
    {
        return random_num;
    }
    else if (strcmp(room, LIVING_ROOM) == 0)
    {
        return random_num;
    }
    else if (strcmp(room, BATHROOM) == 0)
    {
        return random_num;
    }
    else
    {
        printf("Error: Invalid room specified!\n");
        return 0;
    }
}

void turn_on_light(const char *room)
{
    printf("Turning on the light in %s.\n", room);
}

void turn_off_light(const char *room)
{
    printf("Turning off the light in %s.\n", room);
}