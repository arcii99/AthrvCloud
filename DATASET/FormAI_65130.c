//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CAPACITY 50
#define MAX_BAGGAGE 10
#define MAX_TIME 5

int conveyor_belt[MAX_CAPACITY], passenger_aisle[MAX_CAPACITY];

int front_conveyor_belt = 0, rear_conveyor_belt = 0, front_passenger_aisle = 0, rear_passenger_aisle = 0;

int check_conveyor_belt()
{
    if(front_conveyor_belt == rear_conveyor_belt)
        return 0;
    else
        return conveyor_belt[front_conveyor_belt];
}

bool check_passenger_aisle()
{
    if(front_passenger_aisle == rear_passenger_aisle)
        return false;
    else
        return true;
}

void dequeue_conveyor_belt()
{
    if(front_conveyor_belt == rear_conveyor_belt)
        printf("Conveyor belt is empty\n");
    else
        front_conveyor_belt++;
}

void dequeue_passenger_aisle()
{
    if(front_passenger_aisle == rear_passenger_aisle)
        printf("Passenger aisle is empty\n");
    else
        front_passenger_aisle++;
}

void enqueue_conveyor_belt(int baggage)
{
    if(rear_conveyor_belt == MAX_CAPACITY)
        printf("Conveyor belt is full\n");
    else
    {
        conveyor_belt[rear_conveyor_belt] = baggage;
        rear_conveyor_belt++;
    }
}

void enqueue_passenger_aisle(int baggage)
{
    if(rear_passenger_aisle == MAX_CAPACITY)
        printf("Passenger aisle is full\n");
    else
    {
        passenger_aisle[rear_passenger_aisle] = baggage;
        rear_passenger_aisle++;
    }
}

void transfer_bags()
{
    while(check_conveyor_belt())
    {
        if(check_passenger_aisle())
            break;

        int baggage = check_conveyor_belt();
        dequeue_conveyor_belt();
        int transfer_time = rand() % MAX_TIME + 1;
        printf("Baggage %d transferred to passenger aisle in %d seconds\n", baggage, transfer_time);
        sleep(transfer_time);
        enqueue_passenger_aisle(baggage);
    }
}

void add_bags_to_conveyor_belt()
{
    while(rear_conveyor_belt < MAX_CAPACITY)
    {
        int baggage = rand() % MAX_BAGGAGE + 1;
        enqueue_conveyor_belt(baggage);
        int add_time = rand() % MAX_TIME + 1;
        printf("Baggage %d added to conveyor belt in %d seconds\n", baggage, add_time);
        sleep(add_time);
    }
}

int main()
{
    srand(time(0));

    printf("Simulation begins...\n\n");

    add_bags_to_conveyor_belt();

    while(true)
    {
        transfer_bags();

        if(front_conveyor_belt == rear_conveyor_belt)
            break;

        int wait_time = rand() % MAX_TIME + 1;
        printf("Waiting for more bags to arrive on conveyor belt for %d seconds\n", wait_time);
        sleep(wait_time);
    }

    printf("\nAll baggage has been transferred to passenger aisle\n");

    return 0;
}