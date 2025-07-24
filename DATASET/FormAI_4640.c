//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COMMAND_FORWARD 1
#define COMMAND_TURN_RIGHT 2
#define COMMAND_TURN_LEFT 3
#define COMMAND_BACKWARD 4
#define COMMAND_STOP 5

#define TIME_STEP 500

void forward(int duration);
void turn_right(int duration);
void turn_left(int duration);
void backward(int duration);
void stop(int duration);
void execute_command(int command, int duration);

int main() {
    srand(time(NULL));
    int num_instructions = 10;
    int instructions[num_instructions];
    int durations[num_instructions];
    printf("Generating random control instructions...\n\n");
    for (int i = 0; i < num_instructions; i++) {
        instructions[i] = rand() % 5 + 1;
        durations[i] = rand() % 4 + 1;
        printf("Instruction %d: %d for %d seconds\n", i+1, instructions[i], durations[i]);
    }
    printf("\nExecuting control instructions...\n\n");
    for (int i = 0; i < num_instructions; i++) {
        execute_command(instructions[i], durations[i]);
    }
    printf("\nControl instructions executed.\n");
    return 0;
}

void forward(int duration) {
    printf("Moving forward for %d seconds...\n", duration);
    // Code to move robot forward
    // Delay for duration * TIME_STEP milliseconds
    printf("Stopped moving forward.\n\n");
}

void turn_right(int duration) {
    printf("Turning right for %d seconds...\n", duration);
    // Code to turn robot right
    // Delay for duration * TIME_STEP milliseconds
    printf("Stopped turning right.\n\n");
}

void turn_left(int duration) {
    printf("Turning left for %d seconds...\n", duration);
    // Code to turn robot left
    // Delay for duration * TIME_STEP milliseconds
    printf("Stopped turning left.\n\n");
}

void backward(int duration) {
    printf("Moving backward for %d seconds...\n", duration);
    // Code to move robot backward
    // Delay for duration * TIME_STEP milliseconds
    printf("Stopped moving backward.\n\n");
}

void stop(int duration) {
    printf("Stopping for %d seconds...\n", duration);
    // Code to stop robot
    // Delay for duration * TIME_STEP milliseconds
    printf("Stopped.\n\n");
}

void execute_command(int command, int duration) {
    switch (command) {
        case COMMAND_FORWARD:
            forward(duration);
            break;
        case COMMAND_TURN_RIGHT:
            turn_right(duration);
            break;
        case COMMAND_TURN_LEFT:
            turn_left(duration);
            break;
        case COMMAND_BACKWARD:
            backward(duration);
            break;
        case COMMAND_STOP:
            stop(duration);
            break;
        default:
            printf("Invalid command.\n");
            break;
    }
}