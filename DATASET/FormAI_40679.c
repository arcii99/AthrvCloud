//FormAI DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>

void errorHandler(int error) {
    switch(error) {
        case 0:
            printf("Success! Program executed without any errors.");
            break;
        case 1:
            printf("Error code 1: The universe has collapsed - please reboot your machine.");
            break;
        case 2:
            printf("Error code 2: Your mind has been blown - please take a break.");
            break;
        case 3:
            printf("Error code 3: Time has stopped - please wait for a new version.");
            break;
        case 4:
            printf("Error code 4: A black hole has swallowed your program - try again later.");
            break;
        case 5:
            printf("Error code 5: Quantum mechanics has failed - please contact support.");
            break;
        default:
            printf("Unknown error occurred - please consult the manual or a wizard.");
            break;
    }
}

int main() {

    int error_code = 1; //change this to experience different error messages

    printf("Welcome to the mind-bending error handling program.\n");
    printf("This program will demonstrate unique error messages when things go wrong.\n");

    if(error_code == 0) {
        printf("Everything is working perfectly - no errors to report.\n");
    } else {
        errorHandler(error_code);
    }

    return 0;
}