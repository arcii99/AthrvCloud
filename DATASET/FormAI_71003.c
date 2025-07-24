//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_PATH "example.log"
#define CONFIG_PATH "example.ini"

// Struct for configuration
typedef struct Config {
    int warning_level;
    int error_level;
    char log_path[256];
    char keywords[256];
} Config;

// Function to log messages
void log_message(char* message) {
    FILE* log_file = fopen(LOG_PATH, "a");
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

// Function to read configuration file
Config read_config() {
    Config config;
    config.warning_level = 1;
    config.error_level = 2;
    strcpy(config.log_path, LOG_PATH);
    strcpy(config.keywords, "");

    FILE* config_file = fopen(CONFIG_PATH, "r");
    if (config_file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), config_file)) {
            char key[256], value[256];

            // Split line into key and value
            sscanf(line, "%s %s", key, value);

            // Update configuration based on key
            if (strcmp(key, "warning_level") == 0) {
                config.warning_level = atoi(value);
            }
            else if (strcmp(key, "error_level") == 0) {
                config.error_level = atoi(value);
            }
            else if (strcmp(key, "log_path") == 0) {
                strcpy(config.log_path, value);
            }
            else if (strcmp(key, "keywords") == 0) {
                strcpy(config.keywords, value);
            }
        }
        fclose(config_file);
    }

    return config;
}

int main() {
    Config config = read_config();

    // Read messages from log file
    FILE* log_file = fopen(config.log_path, "r");
    if (log_file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), log_file)) {
            int level = 0;
            char keywords[256];

            // Split line into level and message
            sscanf(line, "%d %s", &level, keywords);
            char* message = strchr(line, ' ') + 1;

            // Determine if message should be logged based on configuration
            if (level == config.warning_level || level == config.error_level) {
                if (strlen(config.keywords) == 0 || strstr(keywords, config.keywords)) {
                    printf("%s", message);
                }
            }
        }
        fclose(log_file);
    }

    // Log a test message
    log_message("2 test error message");

    return 0;
}