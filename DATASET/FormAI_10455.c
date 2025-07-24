//FormAI DATASET v1.0 Category: Browser Plugin ; Style: distributed
// This is a unique C Browser Plugin example program in a distributed style.
// This program blocks pop-ups and displays a message to the user.
// Written by [YOUR NAME HERE].

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Check the command-line arguments.
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    // Block pop-ups by modifying the JavaScript on the webpage.
    char js[1000];
    sprintf(js, "window.alert = function() {};");
    printf("Blocking pop-ups by modifying the webpage's JavaScript...\n");

    // Connect to all browser instances running on this machine.
    // In a real program, we would discover the instances via a network scan.
    // For simplicity, we'll just hard-code them in for this example.
    int num_instances = 3;
    char *instances[] = {"localhost:8080", "localhost:8081", "localhost:8082"};

    // Send the modified JavaScript to each instance.
    int i;
    for (i = 0; i < num_instances; i++) {
        char command[1000];
        sprintf(command, "curl --data \"%s\" %s", js, instances[i]);
        printf("Sending command to %s...\n", instances[i]);
        system(command);
    }

    // Display a message to the user.
    printf("Done! Enjoy browsing %s without pop-ups.\n", argv[1]);

    return 0;
}