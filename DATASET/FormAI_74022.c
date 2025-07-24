//FormAI DATASET v1.0 Category: Date and time ; Style: brave
#include <stdio.h>
#include <time.h>

void printTime(char* message) {
    time_t currentTime = time(NULL);
    struct tm* timeInfo = localtime(&currentTime);

    char timeString[9];
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);

    printf("%s %s\n", timeString, message);
}

int main() {
    printTime("Starting the program");

    int i, j, row = 5, col = 5;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printTime("Finished the program");
  
    return 0;
}