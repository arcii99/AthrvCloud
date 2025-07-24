//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 1800

typedef struct
{
    int id;
    int speed;
    int position;
} Car;

void print_road(Car cars[], int num_cars)
{
    int i, j, k;
    for(i = 0; i < num_cars; i++)
    {
        printf("|");
        for(j = 0; j < cars[i].position; j++)
        {
            printf(" ");
        }
        printf("%d", cars[i].id);
        for(k = cars[i].position + 1; k < 72; k++)
        {
            printf(" ");
        }
        printf("|\n");
    }
}

int main()
{
    srand(time(NULL));
    
    int time = 0;
    int num_cars = 0;
    
    Car cars[MAX_CARS];
    
    while(time < MAX_TIME)
    {
        if(rand() % 3 == 0 && num_cars < MAX_CARS)
        {
            Car new_car;
            new_car.id = num_cars + 1;
            new_car.speed = (rand() % 5) + 1; // car can go between 1 and 5 spaces forward per tick
            new_car.position = 0;
            
            cars[num_cars++] = new_car;
        }
        
        int i;
        for(i = 0; i < num_cars; i++)
        {
            if(cars[i].position + cars[i].speed >= 72)
            {
                num_cars--;
                continue;
            }
            
            int j;
            bool can_move = true;
            for(j = 0; j < num_cars; j++)
            {
                if(i == j) // don't check against self
                {
                    continue;
                }
                
                if(cars[i].position + cars[i].speed == cars[j].position)
                {
                    can_move = false;
                    break;
                }
            }
            
            if(can_move)
            {
                cars[i].position += cars[i].speed;
            }
        }
        
        printf("Time: %d seconds\n", time);
        print_road(cars, num_cars);
        printf("\n\n");
        
        time++;
    }
    
    printf("Simulation complete. Press any key to exit.");
    getchar();
    
    return 0;
}