//FormAI DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Opening the log file
    FILE *file = fopen("adventurer_log.txt", "r");
    if (file == NULL) {
        printf("Failed to open log file.\n");
        return 1;
    }
    
    // Counting the number of entries in the log file
    int num_entries = 0;
    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        num_entries++;
    }
    printf("The adventurer has logged %d entries.\n\n", num_entries);
    rewind(file);
    
    // Reading and analyzing each entry in the log file
    int num_kills = 0;
    int num_treasures = 0;
    int num_traps = 0;
    char quest_status[10] = "Incomplete";
    while (fgets(line, 1000, file) != NULL) {
        // Parsing the entry to extract important data
        char date[11];
        char time[9];
        char action[50];
        sscanf(line, "%s %s %[^.].", date, time, action);
        
        // Analyzing the action taken by the adventurer
        if (strcmp(action, "killed a dragon") == 0 || strcmp(action, "killed a giant") == 0) {
            num_kills++;
        } else if (strcmp(action, "found a treasure") == 0) {
            num_treasures++;
        } else if (strcmp(action, "was caught in a trap") == 0) {
            num_traps++;
        } else if (strcmp(action, "completed the quest") == 0) {
            strcpy(quest_status, "Complete");
        }
    }
    
    // Displaying the analysis results
    printf("The adventurer has slain %d dragons and giants,\n", num_kills);
    printf("discovered %d treasures, and fell for %d traps.\n", num_treasures, num_traps);
    printf("The quest is currently %s.\n\n", quest_status);
    
    // Closing the file and ending the program
    fclose(file);
    return 0;
}