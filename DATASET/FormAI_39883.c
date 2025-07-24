//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define traffic speed and density thresholds
#define SPEED_THRESHOLD 30
#define DENSITY_THRESHOLD 80

// define random number generator functions
int random_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double random_double(double min, double max)
{
    return (double)rand() / (double)RAND_MAX * (max - min) + min;
}

// define traffic simulation functions
void init_traffic(int* traffic, int size, double density)
{
    // initialize traffic density
    int cars = (int)(density * size);
    
    // randomly distribute cars in the traffic
    for (int i = 0; i < cars; i++)
    {
        int pos = random_int(0, size - 1);
        traffic[pos] = 1;
    }
}

void update_traffic(int* traffic, int size, double speed_limit)
{
    int next[size];
    
    // calculate average traffic speed
    double sum_speed = 0;
    int count_speed = 0;
    for (int i = 0; i < size; i++)
    {
        if (traffic[i])
        {
            double speed = random_double(speed_limit * 0.8, speed_limit);
            sum_speed += speed;
            count_speed++;
        }
    }
    double avg_speed = sum_speed / count_speed;
    
    // update traffic flow based on speed and density
    for (int i = 0; i < size; i++)
    {
        if (traffic[i])
        {
            // check front and back space
            int space_front = 1;
            int space_back = 1;
            int j = i + 1;
            while (j < size && !traffic[j] && (j - i) <= SPEED_THRESHOLD)
            {
                space_front++;
                j++;
            }
            j = i - 1;
            while (j >= 0 && !traffic[j] && (i - j) <= SPEED_THRESHOLD)
            {
                space_back++;
                j--;
            }
            
            // calculate probability of changing lane
            double density_front = (double)space_front / SPEED_THRESHOLD * 100;
            double density_back = (double)space_back / SPEED_THRESHOLD * 100;
            double density_total = density_front + density_back;
            double prob_change = (density_total > DENSITY_THRESHOLD) ? 0.5 : 0.1;
            
            // calculate new position and speed
            int new_pos = i + (int)avg_speed;
            int new_speed = (int)avg_speed;
            if (random_double(0, 1) < prob_change)
            {
                int lane_change = random_int(-1, 1);
                new_pos += lane_change;
            }
            
            // check if new position is valid
            if (new_pos < 0) new_pos = 0;
            if (new_pos >= size) new_pos = size - 1;
            if (traffic[new_pos]) new_speed = 0;
            
            // move car to new position and speed
            next[new_pos] = 1;
            traffic[i] = 0;
            if (new_speed == 0)
            {
                next[new_pos] = 0;
                traffic[new_pos] = 1;
            }
        }
    }
    
    // copy next traffic state to current traffic state
    for (int i = 0; i < size; i++)
    {
        traffic[i] = next[i];
    }
}

// main function
int main()
{
    // initialize random number generator
    srand(time(NULL));
    
    // set simulation parameters
    int size = 100;
    double density = 0.5;
    double speed_limit = 100;
    
    // initialize traffic
    int traffic[size];
    for (int i = 0; i < size; i++)
    {
        traffic[i] = 0;
    }
    init_traffic(traffic, size, density);
    
    // simulate traffic flow
    for (int i = 0; i < 100; i++)
    {
        printf("t=%d: ", i);
        for (int j = 0; j < size; j++)
        {
            if (traffic[j])
            {
                printf("█");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        
        update_traffic(traffic, size, speed_limit);
    }
    
    return 0;
}