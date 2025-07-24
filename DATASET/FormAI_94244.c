//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void handle_error(int error_code);

int main() {
    srand(time(NULL));
    int error_chance = rand() % 2;
    if(error_chance) {
        int error_code = rand() % 5 + 1;
        handle_error(error_code);
    }
    printf("Post-apocalyptic programming is tough, but we press on...\n");
    return 0;
}

void handle_error(int error_code) {
    printf("ERROR CODE %d OCCURRED!\n", error_code);
    switch(error_code) {
        case 1:
            printf("The world has fallen apart and we cannot allocate memory.\n");
            exit(1);
            break;
        case 2:
            printf("The radiation has caused the code to become corrupted.\n");
            exit(2);
            break;
        case 3:
            printf("The program has encountered a fatal signal.\n");
            exit(3);
            break;
        case 4:
            printf("The resources are scarce and the program cannot open the file.\n");
            exit(4);
            break;
        case 5:
            printf("The cyber-punks have infiltrated the program and caused it to crash.\n");
            exit(5);
            break;
        default:
            printf("Unknown error occurred.\n");
            exit(6);
    }
}