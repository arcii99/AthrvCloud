//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Declare a struct called Brain to store the processing data
struct Brain {
    char memory[1000]; // For storing raw data
    int thoughts[1000]; // For storing processed data
    int num_thoughts; // To keep track of the number of thoughts
};

// Define a function that processes the raw data
void think(struct Brain *brain) {
    char *memory_ptr = brain->memory;
    int *thoughts_ptr = brain->thoughts;
    int num_thoughts = 0;
    int prev_char = 0;
    int cur_thought = 0;

    while (*memory_ptr != '\0') {
        int cur_char = (int) *memory_ptr;
        if (cur_char != prev_char) {
            thoughts_ptr[num_thoughts] = cur_thought;
            num_thoughts++;
            cur_thought = 1;
        } else {
            cur_thought++;
        }
        prev_char = cur_char;
        memory_ptr++;
    }
    thoughts_ptr[num_thoughts] = cur_thought;
    brain->num_thoughts = num_thoughts + 1;
}

int main() {
    // Let's test out the program with some input
    struct Brain brain;
    strcpy(brain.memory, "aaabbbaaa");
    think(&brain);

    // Print out the processed thoughts
    printf("[ ");
    for (int i = 0; i < brain.num_thoughts; i++) {
        printf("%d ", brain.thoughts[i]);
    }
    printf("]\n");

    return 0;
}