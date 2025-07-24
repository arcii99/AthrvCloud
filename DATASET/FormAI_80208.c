//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FLOORS 10
#define ELEVATORS 3

int elevator_pos[ELEVATORS] = {0};  //initialize elevator positions at the ground floor
int elevator_dir[ELEVATORS] = {1};  //initialize elevator direction as up
int floor_reqs[FLOORS] = {0};       //initialize floor requests as zero


/* This function simulates the movement of an elevator */
void move_elevator(int elev_num)
{
    int curr_pos = elevator_pos[elev_num];
    int curr_dir = elevator_dir[elev_num];
    int stop_req = 0;

    //check if elevator has any requests in its current direction
    for(int i=0; i<FLOORS; i++)
    {
        if(floor_reqs[i] && (curr_dir == 1 && i > curr_pos) || (curr_dir == -1 && i < curr_pos))
        {
            stop_req = 1;
            break;
        }
    }

    //if there are no requests in the current direction, switch direction and check again
    if(!stop_req)
    {
        curr_dir *= -1;
        elevator_dir[elev_num] = curr_dir;
        
        for(int i=FLOORS-1; i>=0; i--)
        {
            if(floor_reqs[i] && (curr_dir == 1 && i > curr_pos) || (curr_dir == -1 && i < curr_pos))
            {
                stop_req = 1;
                break;
            }
        }
    }

    //if there is at least one request in the current direction, move the elevator to the next floor in that direction
    if(stop_req)
    {   
        printf("Elevator %d moving %s...\n", elev_num+1, curr_dir == 1 ? "up" : "down");

        int next_floor = curr_pos;
        for(int i=0; i<abs(curr_dir); i++)
        {
            next_floor += curr_dir;
            if(floor_reqs[next_floor])
            {
                printf("Elevator %d stopping at floor %d\n", elev_num+1, next_floor+1);
                floor_reqs[next_floor] = 0;
            }
        }
        elevator_pos[elev_num] = next_floor;
    }   
}


int main()
{
    printf("Welcome to the Elevator Simulation\n\n");

    srand(time(0));  //seed the random number generator

    //start the simulation loop
    int sim_time = 60;  //simulate for 1 hour (60 minutes)
    for(int t=1; t<=sim_time; t++)
    {
        //check if there is a request on any floor
        int gen_req = rand() % 2;
        if(gen_req)
        {
            int req_floor = rand() % FLOORS;
            int req_dir = rand() % 2 ? 1 : -1;
            floor_reqs[req_floor] = req_dir;
            printf("Request generated on floor %d to go %s\n", req_floor+1, req_dir == 1 ? "up" : "down");
        }

        //move each elevator
        for(int e=0; e<ELEVATORS; e++)
        {
            move_elevator(e);
        }

        printf("\n");
    }

    printf("Simulation complete.\n");

    return 0;
}