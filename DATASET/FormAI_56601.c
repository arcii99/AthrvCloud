//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int arrowKey = 0;
    char* direction = "";
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the C Drone Remote Control!\n");
    
    while(arrowKey != 5){
        printf("\nChoose a direction for the drone to move:\n");
        printf("1 - Up\n");
        printf("2 - Down\n");
        printf("3 - Left\n");
        printf("4 - Right\n");
        printf("5 - Quit\n");
        
        scanf("%d", &arrowKey);
        
        switch(arrowKey){
            case 1:
                direction = "Up";
                break;
            case 2:
                direction = "Down";
                break;
            case 3:
                direction = "Left";
                break;
            case 4:
                direction = "Right";
                break;
            case 5:
                printf("Thank you for using the C Drone Remote Control.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
        
        int distance = rand() % 100;
        printf("Drone moved %d meters in direction %s\n", distance, direction);
    }
    
    return 0;
}