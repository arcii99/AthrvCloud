//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LIGHTS 10

int main() {

    int i, j, n, m, light_num, brightness;
    char input[50];
    int lights[MAX_LIGHTS];
    printf("***Welcome to the Smart Home Light Control***\n");

    //initialize all lights to off
    for(i=0;i<MAX_LIGHTS;i++){
        lights[i]=0; 
    }
    printf("Enter the number of lights in the home (max %d): ", MAX_LIGHTS);
    scanf("%d",&n);
    
    // check input value
    if (n > MAX_LIGHTS) {
        printf("Invalid input. Please enter a value between 1 and %d.\n", MAX_LIGHTS);
        return 1;
    }
    
    //turn on the lights
    printf("\nTurning on all lights in the home...\n");
    for (i=0; i<n; i++) {
        lights[i] = 1;
    }

    // loop until user quits
    while(1) {
        printf("\nEnter 'exit' to quit the program.\n");
        printf("Enter a command (e.g. 'turn on light 1', 'turn off all lights', 'set brightness light 2 50', etc.): ");
        fgets(input,50,stdin);
        
        // remove newline character at the end of input string
        if ((strlen(input)>0) && (input[strlen(input)-1] == '\n'))
            input[strlen(input)-1] = '\0';

        // exit command
        if(strcmp(input, "exit") == 0) {
            printf("\nGoodbye! Remember to turn off the lights before leaving.\n");
            break;
        }

        // turn on command
        if(strstr(input, "turn on") != NULL) {
            sscanf(input, "turn on light %d", &light_num);
            if((light_num >= 1) && (light_num <= n)){
                lights[light_num-1] = 1;
                printf("Turning on light %d...\n", light_num);
            }else{
                printf("Invalid input. Please enter a value between 1 and %d.\n", n);
            }
        }

        // turn off command
        else if(strstr(input, "turn off") != NULL) {
            sscanf(input, "turn off light %d", &light_num);
            if((light_num >= 1) && (light_num <= n)){
                lights[light_num-1] = 0;
                printf("Turning off light %d...\n", light_num);
            }else if(strcmp(input, "turn off all lights") == 0) {
                printf("Turning off all lights in the home...\n");
                for (i=0; i<n; i++) {
                    lights[i] = 0;
                }
            }else{
                printf("Invalid input. Please enter a value between 1 and %d.\n", n);
            }
        }

        // set brightness command
        else if(strstr(input, "set brightness") != NULL) {
            sscanf(input, "set brightness light %d %d", &light_num, &brightness);
            if((light_num >= 1) && (light_num <= n)){
                if((brightness >= 0) && (brightness <= 100)){
                    printf("Setting brightness of light %d to %d...\n", light_num, brightness);
                }else{
                    printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
                }
            }else{
                printf("Invalid input. Please enter a value between 1 and %d.\n", n);
            }
        }

        // get status command
        else if(strcmp(input, "get status") == 0) {
            printf("Current light status:\n");
            for (i=0; i<n; i++) {
                printf("Light %d is ", i+1);
                if (lights[i] == 1) {
                    printf("on.\n");
                }else{
                    printf("off.\n");
                }
            }
        }

        // invalid command
        else{
            printf("Invalid command. Please enter a valid command.\n");
        }
    }
    return 0;
}