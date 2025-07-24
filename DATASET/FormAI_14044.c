//FormAI DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int light1 = 0;
    int light2 = 0;
    char input[20];

    while(1){
        printf("Enter a command (light1 on, light1 off, light2 on, light2 off, or exit): ");
        scanf("%s", input);

        if(strcmp(input, "light1 on") == 0){
            light1 = 1;
            printf("Light 1 turned on\n");
        }
        else if(strcmp(input, "light1 off") == 0){
            light1 = 0;
            printf("Light 1 turned off\n");
        }
        else if(strcmp(input, "light2 on") == 0){
            light2 = 1;
            printf("Light 2 turned on\n");
        }
        else if(strcmp(input, "light2 off") == 0){
            light2 = 0;
            printf("Light 2 turned off\n");
        }
        else if(strcmp(input, "exit") == 0){
            printf("Exiting program\n");
            break;
        }
        else{
            printf("Invalid input. Please enter a valid command.\n");
        }
    }

    return 0;
}