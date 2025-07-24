//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int direction = 0; // 0 - North, 1 - East, 2 - South, 3 - West
    
    char input[100];
    
    printf("Enter movement instructions: ");
    scanf("%s", input);
    
    for(int i = 0; input[i] != '\0'; i++) {
        char instruction = input[i];
        
        if(instruction == 'F') { // Move forward
            switch(direction) {
                case 0: y++; break;
                case 1: x++; break;
                case 2: y--; break;
                case 3: x--; break;
            }
        }
        else if(instruction == 'L') { // Turn left
            direction--;
            if(direction < 0) {
                direction += 4;
            }
        }
        else if(instruction == 'R') { // Turn right
            direction++;
            if(direction > 3) {
                direction -= 4;
            }
        }
    }
    
    printf("Robot's final position: (%d, %d)\n", x, y);
    printf("Robot is facing ");
    switch(direction) {
        case 0: printf("North"); break;
        case 1: printf("East"); break;
        case 2: printf("South"); break;
        case 3: printf("West"); break;
    }
    printf("\n");
    
    return 0;
}