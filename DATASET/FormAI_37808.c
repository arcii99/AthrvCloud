//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int lights_on = 0;

    while(1) {
        printf("Enter a command: ");
        fgets(input, 100, stdin);

        if(strcmp(input, "turn on lights\n") == 0) {
            lights_on = 1;
            printf("Lights turned on\n");
        } else if(strcmp(input, "turn off lights\n") == 0) {
            lights_on = 0;
            printf("Lights turned off\n");
        } else if(strcmp(input, "status\n") == 0) {
            if(lights_on) {
                printf("Lights are on\n");
            } else {
                printf("Lights are off\n");
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}