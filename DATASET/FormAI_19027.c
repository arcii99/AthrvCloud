//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define FLOORS 10   //number of floors in the building
#define ELEVATORS 2 //number of elevators in the building

/* Function prototypes */
void print_building(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[]);
void move_elevator(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[]);
int get_direction(int elevator_state);
int get_next_floor(int elevator_state, int current_floor, int direction);
void board_passengers(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[]);
void unboard_passengers(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[]);
int count_passengers(int passengers[][ELEVATORS], int elevator_state);

int main()
{
    int building[FLOORS][ELEVATORS] = {0};
    int passengers[FLOORS][ELEVATORS] = {0};
    int elevator_state[ELEVATORS] = {1, 1}; //1 for going up, -1 for going down, 0 for stopped

    //simulate elevator for 20 cycles
    for (int i = 0; i < 20; i++)
    {
        print_building(building, passengers, elevator_state);
        move_elevator(building, passengers, elevator_state);
        board_passengers(building, passengers, elevator_state);
        unboard_passengers(building, passengers, elevator_state);
    }

    return 0;
}

void print_building(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[])
{
    system("clear"); //clear console before printing
    printf("\n");
    for (int i = FLOORS-1; i >= 0; i--)
    {
        printf("Floor %2d: ", i+1);
        for (int j = 0; j < ELEVATORS; j++)
        {
            if (passengers[i][j] > 0)
            {
                printf("[%d]", passengers[i][j]);
            }
            else if (building[i][j] > 0 && building[i][j] < 10)
            {
                printf("{%d}", building[i][j]);
            }
            else if (elevator_state[j] == 1 && building[i][j] == 10)
            {
                printf("{^}"); //represents elevator going up
            }
            else if (elevator_state[j] == -1 && building[i][j] == 10)
            {
                printf("{v}"); //represents elevator going down
            }
            else if (building[i][j] == 0)
            {
                printf("[ ]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void move_elevator(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[])
{
    for (int i = 0; i < ELEVATORS; i++)
    {
        int direction = get_direction(elevator_state[i]); //get direction of elevator, 1 for up, -1 for down, 0 for stopped
        int current_floor = 0; //initialize to ground floor

        //find the current floor of the elevator
        for (int j = 0; j < FLOORS; j++)
        {
            if (building[j][i] == 10)
            {
                current_floor = j;
                break;
            }
        }

        int next_floor = get_next_floor(elevator_state[i], current_floor, direction);

        //update the state of the elevator and move to the next floor
        if (elevator_state[i] == 1 && next_floor <= FLOORS)
        {
            building[current_floor][i] = 0; //clear current floor
            building[next_floor][i] = 10; //set next floor
            elevator_state[i] = (next_floor == FLOORS) ? -1 : 1; //change direction if elevator has reached the top floor
        }
        else if (elevator_state[i] == -1 && next_floor > 0)
        {
            building[current_floor][i] = 0; //clear current floor
            building[next_floor][i] = 10; //set next floor
            elevator_state[i] = (next_floor == 0) ? 1 : -1; //change direction if elevator has reached the ground floor
        }
    }
}

int get_direction(int elevator_state)
{
    if (elevator_state == 1)
    {
        return 1; //going up
    }
    else if (elevator_state == -1)
    {
        return -1; //going down
    }
    else
    {
        return 0; //stopped
    }
}

int get_next_floor(int elevator_state, int current_floor, int direction)
{
    if (elevator_state == 1)
    {
        return current_floor + 1;
    }
    else if (elevator_state == -1)
    {
        return current_floor - 1;
    }
    else
    {
        return current_floor + direction;
    }
}

void board_passengers(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[])
{
    for (int i = 0; i < ELEVATORS; i++)
    {
        int current_floor = 0; //initialize to ground floor

        //find the current floor of the elevator
        for (int j = 0; j < FLOORS; j++)
        {
            if (building[j][i] == 10)
            {
                current_floor = j;
                break;
            }
        }

        int direction = get_direction(elevator_state[i]); //get direction of elevator, 1 for up, -1 for down

        //board passengers going in the same direction as the elevator and going to floors on the way
        for (int j = current_floor; (j < FLOORS && direction == 1) || (j > 0 && direction == -1); j += direction)
        {
            if (passengers[j][i] > 0) //there are passengers waiting on this floor
            {
                if (direction == 1 && j > current_floor) //going up, check if passenger wants to go up
                {
                    building[j][i] = passengers[j][i];
                    passengers[j][i] = 0;
                }
                else if (direction == -1 && j < current_floor) //going down, check if passenger wants to go down
                {
                    building[j][i] = passengers[j][i];
                    passengers[j][i] = 0;
                }
            }
        }
    }
}

void unboard_passengers(int building[][ELEVATORS], int passengers[][ELEVATORS], int elevator_state[])
{
    for (int i = 0; i < ELEVATORS; i++)
    {
        int current_floor = 0; //initialize to ground floor

        //find the current floor of the elevator
        for (int j = 0; j < FLOORS; j++)
        {
            if (building[j][i] == 10)
            {
                current_floor = j;
                break;
            }
        }

        //unboard passengers going to the current floor
        if (passengers[current_floor][i] > 0)
        {
            passengers[current_floor][i] = 0;
        }
    }
}

int count_passengers(int passengers[][ELEVATORS], int elevator_state)
{
    int count = 0;

    for (int i = 0; i < FLOORS; i++)
    {
        if (passengers[i][elevator_state] > 0)
        {
            count++;
        }
    }

    return count;
}