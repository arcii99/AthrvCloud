//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_COMMAND_LEN 100

int main() {
    char input[MAX_COMMAND_LEN]; // Buffer for user command
    char filename[MAX_FILENAME_LEN]; // Name of backup file
    time_t rawtime; // Current time
    struct tm *timeinfo; // Current time broken down into struct

    printf("Welcome to the C File Backup System!\n");

    while (1) {
        // Prompt for user command
        printf("\nEnter a command (backup/restore/exit): ");
        fgets(input, MAX_COMMAND_LEN, stdin);

        // Determine which command was entered
        if (strncmp(input, "backup", 6) == 0) {
            // Get filename for backup file
            printf("Enter filename to backup: ");
            fgets(filename, MAX_FILENAME_LEN, stdin);

            // Strip newline from filename
            strtok(filename, "\n");

            // Get current time and format as string
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            char timestamp[20];
            strftime(timestamp, 20, "%Y-%m-%d_%H-%M-%S", timeinfo);

            // Create backup filename with timestamp
            char backup_filename[MAX_FILENAME_LEN + 20];
            sprintf(backup_filename, "%s_%s", filename, timestamp);

            // Open original file and backup file
            FILE *original_file = fopen(filename, "r");
            FILE *backup_file = fopen(backup_filename, "w");

            // Check if files were successfully opened
            if (!original_file || !backup_file) {
                printf("Error opening files for backup\n");
            } else {
                // Copy contents of original file to backup file
                char c;
                while ((c = getc(original_file)) != EOF)
                    putc(c, backup_file);

                printf("Backup successful!\n");

                // Close files
                fclose(original_file);
                fclose(backup_file);
            }
        } else if (strncmp(input, "restore", 7) == 0) {
            // Get filename for original file
            printf("Enter filename to restore: ");
            fgets(filename, MAX_FILENAME_LEN, stdin);

            // Strip newline from filename
            strtok(filename, "\n");

            // List all backup files for the original file
            printf("Backup files for %s:\n", filename);

            // Use system command to list files with matching name prefix
            char system_cmd[MAX_COMMAND_LEN + 20];
            sprintf(system_cmd, "ls %s_*", filename);
            system(system_cmd);

            // Prompt for user input of backup filename
            printf("Enter backup filename to restore: ");
            fgets(input, MAX_COMMAND_LEN, stdin);

            // Strip newline from input
            strtok(input, "\n");

            // Create backup filename with timestamp from user input
            char backup_filename[MAX_FILENAME_LEN + 20];
            sprintf(backup_filename, "%s_%s", filename, input);

            // Open original file and backup file
            FILE *original_file = fopen(filename, "w");
            FILE *backup_file = fopen(backup_filename, "r");

            // Check if files were successfully opened
            if (!original_file || !backup_file) {
                printf("Error opening files for restore\n");
            } else {
                // Copy contents of backup file to original file
                char c;
                while ((c = getc(backup_file)) != EOF)
                    putc(c, original_file);

                printf("Restore successful!\n");

                // Close files
                fclose(original_file);
                fclose(backup_file);
            }
        } else if (strncmp(input, "exit", 4) == 0) {
            // Exit program
            printf("Goodbye!\n");
            exit(0);
        } else {
            // Invalid command
            printf("Invalid command\n");
        }
    }

    return 0;
}