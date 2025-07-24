//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_INPUT_SIZE 100
#define MAX_DEVICES 100

typedef struct device
{
    char name[20];
    int num_inputs;
    int input[10];
    int output;
    int state;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char name[], int num_inputs, int input[], int output)
{
    Device d;
    strcpy(d.name, name);
    d.num_inputs = num_inputs;
    memcpy(d.input, input, num_inputs * sizeof(int));
    d.output = output;
    d.state = 0;
    devices[num_devices++] = d;
}

int simulate()
{
    int i, j, changed = 1, stable = 0;
    // Keep simulating until the circuit stabilizes
    while (changed && !stable)
    {
        changed = 0;
        stable = 1;
        for (i = 0; i < num_devices; i++)
        {
            Device d = devices[i];
            int new_state = 0;
            // Evaluate the device's inputs
            for (j = 0; j < d.num_inputs; j++)
            {
                int input_index = d.input[j];
                if (devices[input_index].state)
                {
                    new_state = 1;
                }
            }
            // Update the device's output state, if it has changed
            if (new_state != d.state)
            {
                d.state = new_state;
                devices[i] = d;
                changed = 1;
            }
            // Check if the circuit has stabilized
            if (i == num_devices - 1 && changed)
            {
                stable = 0;
            }
        }
    }
    // Return the final output state of the last device in the circuit
    return devices[num_devices - 1].state;
}

int main()
{
    // Define the devices in the circuit
    add_device("and1", 2, (int[]){0, 1}, -1);
    add_device("and2", 2, (int[]){2, 3}, -1);
    add_device("or1", 2, (int[]){4, 5}, -1);
    add_device("not1", 1, (int[]){6}, -1);

    // Generate random input states
    srand(time(NULL));
    for (int i = 0; i < num_devices; i++)
    {
        if (devices[i].num_inputs == 0)
        {
            devices[i].state = rand() % 2;
            devices[i].output = devices[i].state;
        }
    }

    // Simulate the circuit and print the output
    int output = simulate();
    printf("Output: %d\n", output);

    return 0;
}