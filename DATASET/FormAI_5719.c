//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// A custom struct which contains two integer values
typedef struct {
    int32_t value1;
    int32_t value2;
} Values;

// A global array of Values struct with size ARRAY_SIZE
Values global_array[ARRAY_SIZE];

// A function which populates the global_array with random values
void populate_array(void) {
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++) {
        global_array[i].value1 = rand();
        global_array[i].value2 = rand();
    }
}

// A function which securely copies data from one array to another
void secure_copy(Values *destination, Values *source, size_t size) {
    if(destination == NULL || source == NULL) {
        return;
    }
    
    // Use the memmove function to copy data instead of memcpy to avoid buffer overflow
    memmove(destination, source, size);
}

int main(void) {
    // Populate the global_array with random values
    populate_array();

    // Select a random index from 0 to ARRAY_SIZE-1
    int random_index = rand() % ARRAY_SIZE;

    // Create a local array of Values struct with size 1
    Values local_array[1];

    // Copy the data from the random index of global_array to local_array
    secure_copy(local_array, &global_array[random_index], sizeof(Values));

    // Check if the values were securely copied
    if(local_array[0].value1 == global_array[random_index].value1 && local_array[0].value2 == global_array[random_index].value2) {
        printf("Secure copy successful!\n");
    } else {
        printf("Secure copy failed!\n");
    }

    return 0;
}