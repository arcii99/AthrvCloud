//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>

// Function prototype
void log_event(char* event);

int main() {
    printf("Welcome to the System Event Logger!\n\n");
    printf("Please input your event below:\n");

    char event[100];
    scanf("%[^\n]s", event);
    getchar();  // To consume the \n character

    log_event(event);  // Call our function to log the event

    printf("\nCongratulations! Your event has been successfully logged.\n");
    printf("Now you can go ahead and forget about it - we'll take care of the rest.\n");

    return 0;
}

// Our custom logging function - logs to a file called "events.log"
void log_event(char* event) {
    FILE *file_pointer;
    file_pointer = fopen("events.log", "a");

    fprintf(file_pointer, "%s\n", event);

    fclose(file_pointer);

    printf("           ___\n");
    printf("      ____/ V \\_\n");
    printf("     /         \\\n");
    printf("    //  C   C  \\\\\n");
    printf("   / '   \\_/   ` \\\n");
    printf("  |    _______    |\n");
    printf("  \\   /       \\  /\n");
    printf("   \\ |         | /\n");
    printf("    \\|         |/\n");
    printf("     |         |\n");
    printf("     \\_________/\n");

    printf("Event logged - let's celebrate with a dance!\n\n");
}