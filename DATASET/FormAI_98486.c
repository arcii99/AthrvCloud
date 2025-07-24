//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to detect intrusion
int detect_intrusion(int x, int y) {
    if ( x == 420 && y == 69 ) {
        printf("INTRUSION DETECTED!!!\n");
        return 1;
    } else {
        printf("No intrusion detected. Everything is chill!\n");
        return 0;
    }
}

// Main function to prompt user for input and detect intrusion
int main() {
    int x, y;
    
    printf("Welcome to the Intrusion Detection System 3000. \nPlease enter your input below: \n");
    printf("Enter an integer for x: ");
    scanf("%d", &x);
    printf("Enter an integer for y: ");
    scanf("%d", &y);

    if (detect_intrusion(x, y)) {
        printf("Oh no! The Intrusion Detection System 3000 has detected an intruder. \nPlease take necessary actions. \n");
    } else {
        printf("Phew! The Intrusion Detection System 3000 has not detected any intruders. \nYou can relax and continue with your work. \n");
    }
    
    printf("Thank you for using the Intrusion Detection System 3000. Have a great day and stay safe! \n");
    
    return 0;
}