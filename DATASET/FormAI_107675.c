//FormAI DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {

    char logData[1000] = "9 AM: Sherlock Holmes arrives at 221B Baker Street to begin his latest case. "
                          "10 AM: Mrs. Hudson, the landlady, reports a burglary in one of the apartments. "
                          "12 PM: Holmes examines the crime scene and notices footprints near the window. "
                          "1 PM: Holmes interviews the neighbors and collects alibis for each suspect. "
                          "3 PM: Holmes analyzes the log data from the apartment building. "
                          "6 PM: Holmes solves the case and catches the perpetrator. ";

    char *logPtr;
    logPtr = strtok(logData, ":"); // Split the log data into separate events

    while(logPtr != NULL) {
        if(strstr(logPtr, "AM")) { // Check if event occurred in the morning
            printf("It was a bright and early morning at 221B Baker Street...\n");
        } else { // Event occurred in the afternoon or evening
            printf("The sun had set over the city as Holmes continued his investigation...\n");
        }

        printf("At %s o'clock, ", logPtr); // Print the current time of the event

        logPtr = strtok(NULL, ":"); // Continue iterating through the log

        if(strstr(logPtr, "burglary")) { // Check if the event was related to a burglary
            printf("Holmes was informed of a burglary in one of the apartments.\n");
        } else if(strstr(logPtr, "examines")) { // Check if the event was related to an examination of the crime scene
            printf("Holmes examines the crime scene and notices footprints near the window.\n");
        } else if(strstr(logPtr, "interviews")) { // Check if the event was related to interviewing suspects
            printf("Holmes interviews the neighbors and collects alibis for each suspect.\n");
        } else if(strstr(logPtr, "analyzes")) { // Check if the event was related to analyzing log data
            printf("Holmes analyzes the log data from the apartment building.\n");
        } else if(strstr(logPtr, "solves")) { // Check if the event was related to solving the case
            printf("Holmes solves the case and catches the perpetrator.\n");
        }

        logPtr = strtok(NULL, ":"); // Move onto the next event in the log
    }

    printf("And so, another case has been solved.\n");
    printf("Until the next mystery...\n");

    return 0;
}