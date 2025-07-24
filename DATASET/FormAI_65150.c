//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h> 

// Robot movement directions  
enum direction { 
    NORTH, 
    SOUTH, 
    WEST, 
    EAST 
}; 

// Structure for Robot 
struct robot { 
    int x, y; 
    enum direction facing; 
}; 

// Function to move Robot 
void move(struct robot* bot, int steps) 
{ 
    if (bot->facing == NORTH) 
        bot->y += steps; 

    else if (bot->facing == SOUTH) 
        bot->y -= steps; 

    else if (bot->facing == EAST) 
        bot->x += steps; 

    else if (bot->facing == WEST) 
        bot->x -= steps; 
} 

// Function to turn Robot 
void turn(struct robot* bot, enum direction d) 
{ 
    bot->facing = d; 
} 

int main() 
{ 
    struct robot bot = { 0, 0, EAST }; 

    printf("Starting location: (%d, %d)\n", bot.x, bot.y);

    // Robot movement 
    move(&bot, 5); 
    turn(&bot, NORTH); 
    move(&bot, 3); 
    turn(&bot, WEST); 
    move(&bot, 2); 
    turn(&bot, SOUTH); 
    move(&bot, 4); 
    turn(&bot, EAST); 
    move(&bot, 1); 

    printf("Final location: (%d, %d)\n", bot.x, bot.y);

    return 0; 
}