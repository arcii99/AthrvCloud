//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <string.h>

// Function to check if input command is valid
int valid_input(char input[]) {
    char *commands[] = {"bedroom", "living room", "kitchen", "bathroom"};
    for (int i=0; i<4; i++) {
        if (strcmp(input, commands[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to turn lights on or off for a given room
void control_lights(char command[], int state[]) {
    if (strcmp(command, "bedroom") == 0)
        state[0] = (state[0] == 0) ? 1 : 0;
    else if (strcmp(command, "living room") == 0)
        state[1] = (state[1] == 0) ? 1 : 0;
    else if (strcmp(command, "kitchen") == 0)
        state[2] = (state[2] == 0) ? 1 : 0;
    else if (strcmp(command, "bathroom") == 0)
        state[3] = (state[3] == 0) ? 1 : 0;
}

int main() {
    int state[] = {0, 0, 0, 0};
    char input[20];
    while (1) {
        printf("Enter a command to turn lights on/off (bedroom/living room/kitchen/bathroom): ");
        scanf("%s", input);
        if (valid_input(input)) {
            control_lights(input, state);
            printf("Lights in %s are now %s.\n", input, (state[0] == 1) ? "on" : "off");
        }
        else {
            printf("Invalid input. Please enter one of the following: bedroom/living room/kitchen/bathroom.\n");
        }
    }
    return 0;
}