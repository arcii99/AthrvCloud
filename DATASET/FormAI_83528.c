//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isOn = false;
int brightness = 0;

void turnOn() {
    isOn = true;
    printf("The lights are now on.\n");
}

void turnOff() {
    isOn = false;
    printf("The lights are now off.\n");
}

void setBrightness(int level) {
    brightness = level;
    printf("The brightness is now set to %d.\n", brightness);
}

void setTimer(int time) {
    printf("The lights will turn off in %d seconds.\n", time);
    sleep(time);
    turnOff();
}

int main() {
    char input[100];
    char* command;
    int level;
    int time;

    while(true) {
        printf("Enter a command: ");
        fgets(input, 100, stdin);

        // tokenize input to separate command and arguments
        command = strtok(input, " ");
        if(command == NULL) {
            printf("Invalid command.\n");
            continue;
        }

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // execute command
        if(strcmp(command, "on") == 0) {
            turnOn();
        }
        else if(strcmp(command, "off") == 0) {
            turnOff();
        }
        else if(strcmp(command, "brightness") == 0) {
            level = atoi(strtok(NULL, " "));
            setBrightness(level);
        }
        else if(strcmp(command, "timer") == 0) {
            time = atoi(strtok(NULL, " "));
            setTimer(time);
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}