//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

void printHappyMessage() {
    printf("Yay! Everything is running smoothly :)\n");
}

void printSadMessage() {
    printf("Oh no! Something went wrong :(\n");
}

int checkConnection() {
    int status = system("ping -c 1 google.com > /dev/null 2>&1");
    if (status == 0) {
        printHappyMessage();
        return 1;
    } else {
        printSadMessage();
        return 0;
    }
}

void checkSpeed() {
    FILE *output;
    char speed[MAX_SIZE];
    output = popen("speedtest-cli --simple | grep Download | awk '{print $2}'", "r");
    fgets(speed, MAX_SIZE, output);
    printf("Your download speed is %s", speed);
    pclose(output);
}

int main() {
    // Check connection and speed every 10 seconds
    while (1) {
        if (checkConnection()) {
            checkSpeed();
        }
        sleep(10);
    }
    return 0;
}