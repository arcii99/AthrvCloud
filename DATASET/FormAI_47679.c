//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include<stdio.h>

//function to move robot forward
void move_forward(){
    printf("Robot moved forward!\n");
}

//function to move robot backwards
void move_backwards(){
    printf("Robot moved backwards!\n");
}

//function to turn robot left
void turn_left(){
    printf("Robot turned left!\n");
}

//function to turn robot right
void turn_right(){
    printf("Robot turned right!\n");
}

int main(){
    int choice;
    printf("Robot Movement Control\n");
    printf("Enter 1 to move robot forward\n");
    printf("Enter 2 to move robot backwards\n");
    printf("Enter 3 to turn robot left\n");
    printf("Enter 4 to turn robot right\n");
    
    while(1){   //infinite loop to continuously take input from the user
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        //switch case to call the required function based on user input
        switch(choice){
            case 1:
                move_forward();
                break;
            case 2:
                move_backwards();
                break;
            case 3:
                turn_left();
                break;
            case 4:
                turn_right();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}