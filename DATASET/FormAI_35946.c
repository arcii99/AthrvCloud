//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int temperature, light;
    char command[20];
    printf("\n********* Smart Home Automation *********\n");
    while(1) {
        printf("\nEnter command: ");
        scanf("%s", command);
        if(strcmp(command, "temperature") == 0) {
            printf("\nCurrent temperature is %dF\n", temperature);
            printf("Enter new temperature: ");
            scanf("%d", &temperature);
            printf("Temperature set to %dF\n", temperature);
        }
        else if(strcmp(command, "light") == 0) {
            printf("\nCurrent light level is %d\n", light);
            printf("Enter new light level (1-10): ");
            scanf("%d", &light);
            if(light >= 1 && light <= 10) {
                printf("Light level set to %d\n", light);
            }
            else {
                printf("Invalid input. Please enter a number between 1 and 10.\n");
            }
        }
        else if(strcmp(command, "exit") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        }
        else {
            printf("\nInvalid command. Available commands: temperature, light, exit.\n");
        }
    }
    return 0;
}