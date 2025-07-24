//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>   // standard input/output functions
#include <stdlib.h>  // for system() function

// Function to clear the screen
void clear_screen() {
    system("clear");
}

int main() {
    int speed;
    printf("Welcome to the Internet Speed Test Application.\n\n");
    printf("This program will test your internet connection speed.\n\n");
    printf("Press ENTER to continue.\n\n");
    getchar();  // waits for user to press enter

    // Clear the screen
    clear_screen();

    // Generate a random integer between 1 and 100 to simulate internet speed
    speed = rand() % 100 + 1;

    // Display the internet speed
    printf("Your internet speed is %d Mbps.\n", speed);

    // Determine the user's internet speed status
    if (speed >= 80) {
        printf("You have an EXCELLENT internet connection!\n");
    } else if (speed >= 50) {
        printf("You have a GOOD internet connection.\n");
    } else if (speed >= 30) {
        printf("Your internet connection is FAIR.\n");
    } else {
        printf("Your internet connection is POOR.\n");
    }

    return 0;
}