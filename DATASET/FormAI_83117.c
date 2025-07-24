//FormAI DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    // Create a log file
    int log_fd = open("system_logs.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    // Check if file was successfully created
    if (log_fd == -1)
    {
        printf("Error creating the log file.\n");
        exit(EXIT_FAILURE);
    }

    // Write a welcome message to the log file
    char welcome_message[] = "Welcome to our system administration program!\n";
    write(log_fd, welcome_message, strlen(welcome_message));

    // Open file containing list of users on the system
    FILE *user_file = fopen("/etc/passwd", "r");

    // Check if file was successfully opened
    if (user_file == NULL)
    {
        printf("Error opening the user file.\n");
        exit(EXIT_FAILURE);
    }

    // Read each line of the user file
    char line[256];
    while (fgets(line, sizeof(line), user_file))
    {
        // Parse the user's information from the line
        char *username = strtok(line, ":");
        char *password = strtok(NULL, ":");
        char *uid = strtok(NULL, ":");
        char *gid = strtok(NULL, ":");
        char *gecos = strtok(NULL, ":");
        char *homedir = strtok(NULL, ":");
        char *shell = strtok(NULL, ":");

        // Write the user's information to the log file
        char user_info[256];
        sprintf(user_info, "Username: %s, UID: %s, Home Directory: %s\n", username, uid, homedir);
        write(log_fd, user_info, strlen(user_info));
    }

    // Close the user file
    fclose(user_file);

    // Print a message to the user indicating that the program has completed successfully
    printf("System administration program completed successfully. Check the log file for more information.\n");

    // Close the log file
    close(log_fd);

    return 0;
}