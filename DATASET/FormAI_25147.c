//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

void print_traffic_light(int color)
{
    switch(color)
    {
        case RED:
            printf("Red\n");
            break;
        case YELLOW:
            printf("Yellow\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
        default:
            printf("Invalid color\n");
            break;
    }
}

int main()
{
    int current_color = RED;
    int next_color;
    int count = 0;
    srand(time(NULL));
    
    while(count < 10)
    {
        // Generate new color
        do{
            next_color = rand() % 3 + 1;
        } while(next_color == current_color);
        
        // Change colors
        if(current_color == RED && next_color == GREEN)
        {
            current_color = GREEN;
        }
        else if(current_color == GREEN && next_color == YELLOW)
        {
            current_color = YELLOW;
        }
        else if(current_color == YELLOW && next_color == RED)
        {
            current_color = RED;
        }
        else
        {
            continue;
        }
        
        // Print traffic light
        printf("Traffic light color: ");
        print_traffic_light(current_color);
        count++;
    }
    
    return 0;
}