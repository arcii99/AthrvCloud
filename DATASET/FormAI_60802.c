//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Config;

void str_to_lowercase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int load_config(const char* file_path, Config* config, int max_configs) {
    FILE* fp = fopen(file_path, "r");

    if(fp == NULL) {
        perror("config file not found");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int num_configs = 0;

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL && num_configs < max_configs) {
        char* sep_pos = strchr(line, '=');

        if(sep_pos == NULL) {
            fprintf(stderr, "invalid config line: %s", line);
            continue;
        }

        strncpy(config[num_configs].key, line, sep_pos - line);
        config[num_configs].key[sep_pos - line] = '\0';

        strcpy(config[num_configs].value, sep_pos + 1);
        config[num_configs].value[strcspn(config[num_configs].value, "\r\n")] = 0;

        str_to_lowercase(config[num_configs].key);
        num_configs++;
    }

    fclose(fp);

    return num_configs;
}

void set_config_value(Config* config_arr, int num_configs, const char* key, const char* value) {
    char lower_key[MAX_LINE_LENGTH];
    strncpy(lower_key, key, MAX_LINE_LENGTH);
    str_to_lowercase(lower_key);

    for(int i = 0; i < num_configs; i++) {
        if(strcmp(config_arr[i].key, lower_key) == 0) {
            strcpy(config_arr[i].value, value);
            return;
        }
    }

    printf("config key \"%s\" not found\n", key);
}

void save_config(const char* file_path, Config* config_arr, int num_configs) {
    FILE* fp = fopen(file_path, "w");

    if(fp == NULL) {
        perror("failed to save config");
        return;
    }

    for(int i = 0; i < num_configs; i++) {
        fprintf(fp, "%s=%s\n", config_arr[i].key, config_arr[i].value);
    }

    fclose(fp);
}

int main() {
    Config config_arr[5];
    int num_configs = load_config("config.ini", config_arr, 5);

    set_config_value(config_arr, num_configs, "verbose", "true");
    set_config_value(config_arr, num_configs, "resolution", "1280x720");
    set_config_value(config_arr, num_configs, "autostart", "false");

    save_config("config.ini", config_arr, num_configs);

    return 0;
}