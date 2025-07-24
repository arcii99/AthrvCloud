//FormAI DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to optimize boot time of the system by removing unnecessary programs from start-up.
void optimize_boot() {

    char* startupFolder = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\"; // Path to start-up folder
    char command[100];

    printf("Boot optimization in progress...\n");

    //Opening start-up folder
    FILE* fp = popen("dir /b \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\\"", "r");
    if (fp == NULL) {
        printf("Error: Failed to open start-up folder.\n");
        return;
    }

    char programName[100];

    //Removing unnecessary programs from start-up
    while (fgets(programName, sizeof programName, fp) != NULL) {

        //Checking if program is necessary for start-up
        if (strcmp(programName, "Google Chrome.lnk\n") == 0 || strcmp(programName, "Discord.lnk\n") == 0) {
            printf("Keeping program: %s", programName);
            continue;
        }

        //Removing unnecessary program from start-up
        sprintf(command, "del \"%s%s\"", startupFolder, programName);
        system(command);
        printf("Removed program: %s", programName);
    }

    printf("Boot optimization completed successfully.\n");
}

int main() {

    optimize_boot();

    return 0;
}