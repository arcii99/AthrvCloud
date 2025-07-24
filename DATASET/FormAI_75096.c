//FormAI DATASET v1.0 Category: Smart home automation ; Style: portable
#include<stdio.h>
#include<string.h>

// Function to turn on/off the lights
void operateLights(char* command) {
    if(strcmp(command, "on") == 0) {
        printf("Lights turned on\n");
    } else if(strcmp(command, "off") == 0) {
        printf("Lights turned off\n");
    } else {
        printf("Invalid command\n");
    }
}

// Function to adjust the temperature
void setTemperature(int temp) {
    printf("Temperature set to %d degrees\n", temp);
}

// Function to lock/unlock the front door
void operateDoor(char* command) {
    if(strcmp(command, "lock") == 0) {
        printf("Front door locked\n");
    } else if(strcmp(command, "unlock") == 0) {
        printf("Front door unlocked\n");
    } else {
        printf("Invalid command\n");
    }
}

// Function to play music
void playMusic(int volume, char* genre) {
    printf("Now playing %s at volume %d\n", genre, volume);
}

int main() {
    // Welcome message
    printf("Welcome to Smart Home Automation System\n");
    printf("=======================================\n\n");

    // User interface
    while(1) {
        printf("Commands: \n");
        printf("1. Turn on/off lights (Example: lights on/off)\n");
        printf("2. Set temperature (Example: temperature 25)\n");
        printf("3. Lock/unlock front door (Example: frontdoor lock/unlock)\n");
        printf("4. Play music (Example: music 50 rock)\n");
        printf("5. Exit program (Example: exit)\n");

        char command[50];
        fgets(command, 50, stdin);

        // Parse the command
        char* token = strtok(command, " ");
        int num = 0;
        int volume = 0;
        char* genre = "";

        while( token != NULL ) {
            if(num == 1) {
                if(strcmp(command, "temperature") == 0) {
                    // Set temperature
                    token = strtok(NULL, " ");
                    int temp = atoi(token);
                    setTemperature(temp);
                } else if(strcmp(command, "lights") == 0) {
                    // Operate lights
                    token = strtok(NULL, " ");
                    operateLights(token);
                } else if(strcmp(command, "frontdoor") == 0) {
                    // Operate front door
                    token = strtok(NULL, " ");
                    operateDoor(token);
                } else if(strcmp(command, "music") == 0) {
                    // Play music
                    token = strtok(NULL, " ");
                    volume = atoi(token);
                    token = strtok(NULL, " ");
                    genre = token;
                    playMusic(volume, genre);
                } else if(strcmp(command, "exit") == 0) {
                    // Exit program
                    printf("Exiting Smart Home Automation System\n");
                    return 0;
                } else {
                    printf("Invalid command\n");
                    break;
                }
            }
            token = strtok(NULL, " ");
            num++;
        }
    }
    return 0;
}