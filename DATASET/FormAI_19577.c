//FormAI DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The following constants are used to define the size of data structures */
#define MAX_NAME_LEN 100
#define MAX_COMMAND_LEN 100
#define MAX_OPTIMIZATION_LEN 100

/* This struct represents a startup item */
struct StartupItem {
    char name[MAX_NAME_LEN];
    char command[MAX_COMMAND_LEN];
};

/* This struct represents an optimization setting */
struct OptimizationSetting {
    char name[MAX_OPTIMIZATION_LEN];
    int value;
};

/* This function reads startup items from a file */
int read_startup_items(const char *filename, struct StartupItem startup_items[], int max_items) {
    FILE *fp;
    char line[1024];
    char *name, *command;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL && count < max_items) {
        name = strtok(line, ",");
        command = strtok(NULL, "\n");

        if (name != NULL && command != NULL) {
            strncpy(startup_items[count].name, name, MAX_NAME_LEN);
            strncpy(startup_items[count].command, command, MAX_COMMAND_LEN);
            count++;
        }
    }

    fclose(fp);

    return count;
}

/* This function reads optimization settings from a file */
int read_optimization_settings(const char *filename, struct OptimizationSetting settings[], int max_settings) {
    FILE *fp;
    char line[1024];
    char *name, *value;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL && count < max_settings) {
        name = strtok(line, ",");
        value = strtok(NULL, "\n");

        if (name != NULL && value != NULL) {
            strncpy(settings[count].name, name, MAX_OPTIMIZATION_LEN);
            settings[count].value = atoi(value);
            count++;
        }
    }

    fclose(fp);

    return count;
}

/* This function randomly selects startup items to disable based on optimization settings */
void select_startup_items_to_disable(struct StartupItem startup_items[], int num_items, struct OptimizationSetting settings[], int num_settings, int disabled_items[]) {
    int i, j, k;
    int prob;

    for (i = 0; i < num_items; i++) {
        disabled_items[i] = 0;
    }

    for (i = 0; i < num_settings; i++) {
        prob = settings[i].value;

        for (j = 0; j < num_items; j++) {
            /* Check if the startup item should be disabled based on the optimization settings */
            if (strstr(startup_items[j].command, settings[i].name) != NULL) {
                /* Randomly select whether to disable the startup item or not */
                if (rand() % 100 < prob) {
                    disabled_items[j] = 1;
                }
            }
        }
    }
}

/* This function writes the new startup items to a file */
int write_startup_items(const char *filename, struct StartupItem startup_items[], int num_items, int disabled_items[]) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    for (i = 0; i < num_items; i++) {
        if (!disabled_items[i]) {
            fprintf(fp, "%s,%s\n", startup_items[i].name, startup_items[i].command);
        }
    }

    fclose(fp);

    return 0;
}

/* Main program */
int main(int argc, char *argv[]) {
    int num_startup_items, num_optimization_settings;
    struct StartupItem startup_items[100];
    struct OptimizationSetting optimization_settings[100];
    int disabled_items[100];

    /* Seed the random number generator */
    srand(time(NULL));

    /* Read the startup items */
    num_startup_items = read_startup_items("startup_items.txt", startup_items, 100);
    if (num_startup_items <= 0) {
        printf("Error reading startup items\n");
        return -1;
    }

    /* Read the optimization settings */
    num_optimization_settings = read_optimization_settings("optimization_settings.txt", optimization_settings, 100);
    if (num_optimization_settings <= 0) {
        printf("Error reading optimization settings\n");
        return -1;
    }

    /* Select the startup items to disable */
    select_startup_items_to_disable(startup_items, num_startup_items, optimization_settings, num_optimization_settings, disabled_items);

    /* Write the new startup items */
    write_startup_items("new_startup_items.txt", startup_items, num_startup_items, disabled_items);

    return 0;
}