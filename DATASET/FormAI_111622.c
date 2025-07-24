//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

bool isLightOn = false;

void* lightControl(void *arg) {
    while (true) {
        if (isLightOn) {
            printf("Light is on\n");
            // code to turn on light
        } else {
            printf("Light is off\n");
            // code to turn off light
        }
    }
}

int main() {
    pthread_t thread;
    int status;

    status = pthread_create(&thread, NULL, lightControl, NULL);
    if (status != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    while (true) {
        char input[10];
        printf("Type 'on' to turn on light or 'off' to turn off light: ");
        scanf("%s", input);

        if (strcmp(input, "on") == 0) {
            isLightOn = true;
        } else if (strcmp(input, "off") == 0) {
            isLightOn = false;
        } else {
            printf("Invalid input\n");
        }
    }

    pthread_join(thread, NULL);
    return 0;
}