//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TIME 100
#define MAX_LUGGAGE 5
#define MAX_GATE 3

typedef struct
{
    int id;
    int arrival_time;
    int luggage_count;
    int gate_number;
} Passenger;

void generate_passenger(Passenger* p)
{
    static int id = 1;
    p->id = id++;
    p->arrival_time = rand() % MAX_TIME;
    p->luggage_count = rand() % MAX_LUGGAGE + 1;
    p->gate_number = rand() % MAX_GATE + 1;
}

void print_passenger(Passenger p)
{
    printf("Passenger %d: arrival_time=%d luggage_count=%d gate_number=%d\n",
           p.id, p.arrival_time, p.luggage_count, p.gate_number);
}

int main()
{
    srand(time(NULL));
    Passenger queue[MAX_TIME];
    int queue_size = 0;
    Passenger luggage[3*MAX_TIME];
    int luggage_size = 0;
    Passenger gate[MAX_GATE];
    int i, j, last_gate = 0;
    for (i = 0; i < MAX_TIME; i++)
    {
        // Generate new passengers
        int new_passengers = rand() % 3;
        for (j = 0; j < new_passengers; j++)
        {
            Passenger new_passenger;
            generate_passenger(&new_passenger);
            queue[queue_size++] = new_passenger;
            print_passenger(new_passenger);
        }
        // Process queue
        for (j = 0; j < queue_size; j++)
        {
            if (queue[j].arrival_time <= i)
            {
                if (queue[j].luggage_count == 0)
                {
                    printf("Passenger %d goes directly to gate %d\n", queue[j].id, queue[j].gate_number);
                    gate[last_gate++] = queue[j];
                }
                else
                {
                    printf("Passenger %d goes to luggage section\n", queue[j].id);
                    luggage[luggage_size++] = queue[j];
                }
            }
        }
        queue_size -= luggage_size;
        // Process luggage
        for (j = 0; j < luggage_size; j++)
        {
            if (rand() % 2 == 0)
            {
                printf("Passenger %d finished baggage handling and goes to gate %d\n", luggage[j].id, luggage[j].gate_number);
                gate[last_gate++] = luggage[j];
            }
            else
            {
                printf("Passenger %d is still waiting for baggage handling\n", luggage[j].id);
                queue[queue_size++] = luggage[j];
            }
        }
        luggage_size = 0;
        // Process gate
        for (j = 0; j < MAX_GATE; j++)
        {
            if (gate[j].id != 0 && rand() % 2 == 0)
            {
                printf("Passenger %d board on gate %d\n", gate[j].id, gate[j].gate_number);
                gate[j].id = 0;
            }
        }
    }
    return 0;
}