//FormAI DATASET v1.0 Category: Smart home light control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main(){
    int light = 0;
    char command;
    
    printf("Welcome to Smart Home Light Control!\n");
    
    while(1){
        printf("Enter a command (o - turn on, f - turn off, q - quit): ");
        scanf("%c", &command);

        if(command == 'o'){
            light = 1;
            printf("Light turned on.\n");
        }
        else if(command == 'f'){
            light = 0;
            printf("Light turned off.\n");
        }
        else if(command == 'q'){
            printf("Closing Smart Home Light Control...\n");
            break;
        }
        else{
            printf("Invalid command. Please try again.\n");
        }
        //clear the input buffer to prevent unexpected input interrupts
        while ((getchar()) != '\n');
    }
    
    return 0;
}