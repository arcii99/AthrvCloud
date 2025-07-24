//FormAI DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ERROR_MSG_LEN 50

void handle_error(int error_code) {
    char error_message[MAX_ERROR_MSG_LEN];

    switch(error_code) {
        case 1:
            strcpy(error_message, "File not found.");
            break;
        case 2:
            strcpy(error_message, "Permission denied.");
            break;
        case 3:
            strcpy(error_message, "Memory allocation failed.");
            break;
        default:
            strcpy(error_message, "Unknown error.");
            break;
    }

    printf("Error %d: %s\n", error_code, error_message);
    exit(EXIT_FAILURE);
}

int main() {
    srand(time(NULL));

    int rand_int = rand() % 4;

    if(rand_int == 0) {
        handle_error(1); // File not found error
    }
    else if(rand_int == 1) {
        handle_error(2); // Permission denied error
    }
    else if(rand_int == 2) {
        handle_error(3); // Memory allocation failed error
    }
    else {
        printf("No errors occurred.\n");
    }

    return 0;
}