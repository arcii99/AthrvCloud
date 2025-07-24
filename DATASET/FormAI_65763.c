//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int light_status = 0;
    printf("Welcome to our smart home light control system. Press 1 to turn on the lights, or any other key to turn them off:\n");
    char input = getchar();
    if (input == '1') {
        light_status = 1;
        printf("The lights are on, setting a romantic mood for you and your loved one...\n");
    } else {
        printf("The lights are off, let the romance begin!\n");
    }
    return 0;
}