//FormAI DATASET v1.0 Category: Robot movement control ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome! I am a curious robot.");
    int x = 0, y = 0; // initialize starting position
    printf("I am currently at position (%d, %d).", x, y);
    
    char direction;
    printf("Which direction do you want me to move in?[U/D/L/R]: ");
    scanf("%c", &direction);
    
    switch (direction) {
        case 'U':
            y += 1; // move up
            break;
        case 'D':
            y -= 1; // move down
            break;
        case 'L':
            x -= 1; // move left
            break;
        case 'R':
            x += 1; // move right
            break;
        default:
            printf("I don't recognize that direction. Please try again.");
            break;
    }
    
    printf("I moved in the %c direction and am now at position (%d, %d)!", direction, x, y);
    
    return 0;
}