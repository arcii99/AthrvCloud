//FormAI DATASET v1.0 Category: System administration ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LENGTH 1024
#define DEFAULT_CONFIG_FILE "config.txt"

// Structure to hold configuration data
struct ConfigData {
    char username[50];
    char password[50];
    int port;
    char hostname[50];
};

// Function to parse the configuration file
void parseConfigFile(char *filename, struct ConfigData *config) {
    FILE *fptr;
    char line[MAX_LINE_LENGTH];
    char *token;

    // Open the file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Unable to open configuration file %s\n", filename);
        exit(1);
    }

    // Loop through each line of the file
    while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL) {
        // Remove any trailing newline characters
        strtok(line, "\n");
        // Tokenize the line based on whitespace
        token = strtok(line, " ");
        // Check the configuration option
        if (strcmp(token, "username") == 0) {
            // Save the username
            token = strtok(NULL, " ");
            strcpy(config->username, token);
        }
        else if (strcmp(token, "password") == 0) {
            // Save the password
            token = strtok(NULL, " ");
            strcpy(config->password, token);
        }
        else if (strcmp(token, "port") == 0) {
            // Save the port
            token = strtok(NULL, " ");
            config->port = atoi(token);
        }
        else if (strcmp(token, "hostname") == 0) {
            // Save the hostname
            token = strtok(NULL, " ");
            strcpy(config->hostname, token);
        }
        else {
            printf("Warning: Unknown configuration option %s\n", token);
        }
    }

    // Close the file
    fclose(fptr);
}

int main(int argc, char *argv[]) {
    struct ConfigData config;
    char *configFile;

    // Set defaults for the configuration structure
    strcpy(config.username, "admin");
    strcpy(config.password, "password");
    config.port = 22;
    strcpy(config.hostname, "localhost");

    // Check for a command-line argument specifying a config file
    if (argc == 2) {
        configFile = argv[1];
    }
    else {
        configFile = DEFAULT_CONFIG_FILE;
    }

    // Parse the configuration file
    parseConfigFile(configFile, &config);

    // Print out the configuration data
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);
    printf("Port: %d\n", config.port);
    printf("Hostname: %s\n", config.hostname);

    return 0;
}