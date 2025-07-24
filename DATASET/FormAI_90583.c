//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the cheerful Robot movement control program!\n");
    int direction = 0;
    int distance = 0;
    char choice;

    do {
        printf("Please enter the direction you want the Robot to move (1 - forward, 2 - backward, 3 - left, 4 - right): ");
        scanf("%d", &direction);

        printf("Please enter the distance you want the Robot to move: ");
        scanf("%d", &distance);

        switch (direction) {
            case 1:
                printf("Robot is moving forward by %d units\n", distance);
                // Your code here to move the Robot forward
                break;
            case 2:
                printf("Robot is moving backward by %d units\n", distance);
                // Your code here to move the Robot backward
                break;
            case 3:
                printf("Robot is moving left by %d units\n", distance);
                // Your code here to move the Robot to the left
                break;
            case 4:
                printf("Robot is moving right by %d units\n", distance);
                // Your code here to move the Robot to the right
                break;
            default:
                printf("Invalid direction entered. Please try again.\n");
        }

        printf("Do you want to move the Robot again? (y/n): ");
        scanf(" %c", &choice); // use " %c" to consume any whitespace characters left in input
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Robot movement control program. Have a great day!\n");

    return 0;
}