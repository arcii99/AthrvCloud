//FormAI DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define     MAX_DEVICES     10
#define     MAX_NAME_LEN    20

typedef enum {OFF, ON} state_t;

typedef struct {
    char    name[MAX_NAME_LEN];
    state_t state;
    int     brightness;
} device_t;

device_t    devices[MAX_DEVICES];
int         num_devices = 0;

void    add_device(char *name) {
    if (num_devices >= MAX_DEVICES) {
        printf("Maximum number of devices reached!\n");
        return;
    }

    device_t newDevice;
    strcpy(newDevice.name, name);
    newDevice.state = OFF;
    newDevice.brightness = 0;

    devices[num_devices] = newDevice;
    num_devices++;
}

void    show_devices() {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%d. %s [State: %s, Brightness: %d]\n", i+1, devices[i].name, devices[i].state ? "ON" : "OFF", devices[i].brightness);
    }
}

void    turn_on_device(int index) {
    if (index < 1 || index > num_devices) {
        printf("Invalid device index!\n");
        return;
    }

    devices[index-1].state = ON;
    printf("%s is turned ON.\n", devices[index-1].name);
}

void    turn_off_device(int index) {
    if (index < 1 || index > num_devices) {
        printf("Invalid device index!\n");
        return;
    }

    devices[index-1].state = OFF;
    printf("%s is turned OFF.\n", devices[index-1].name);
}

void    increase_brightness(int index) {
    if (index < 1 || index > num_devices) {
        printf("Invalid device index!\n");
        return;
    }

    if (devices[index-1].state == OFF) {
        printf("%s is OFF, cannot increase brightness!\n", devices[index-1].name);
        return;
    }

    if (devices[index-1].brightness < 10) {
        devices[index-1].brightness++;
        printf("%s brightness increased to %d.\n", devices[index-1].name, devices[index-1].brightness);
    } else {
        printf("%s is already at maximum brightness!\n", devices[index-1].name);
    }
}

void    decrease_brightness(int index) {
    if (index < 1 || index > num_devices) {
        printf("Invalid device index!\n");
        return;
    }

    if (devices[index-1].state == OFF) {
        printf("%s is OFF, cannot decrease brightness!\n", devices[index-1].name);
        return;
    }

    if (devices[index-1].brightness > 0) {
        devices[index-1].brightness--;
        printf("%s brightness decreased to %d.\n", devices[index-1].name, devices[index-1].brightness);
    } else {
        printf("%s is already at minimum brightness!\n", devices[index-1].name);
    }
}

int main() {
    char    input[100];
    char    *token;
    char    *delim = " \t\n";

    printf("Welcome to Smart Home Automation!\n");
    printf("Commands:\n");
    printf("- add <device_name>\n");
    printf("- show\n");
    printf("- on <device_index>\n");
    printf("- off <device_index>\n");
    printf("- increase <device_index>\n");
    printf("- decrease <device_index>\n");
    printf("- exit\n\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        token = strtok(input, delim);
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(token, "add") == 0) {
            token = strtok(NULL, delim);
            if (token != NULL) {
                add_device(token);
            } else {
                printf("Invalid command. Usage: add <device_name>\n");
            }
        } else if (strcmp(token, "show") == 0) {
            show_devices();
        } else if (strcmp(token, "on") == 0) {
            token = strtok(NULL, delim);
            if (token != NULL) {
                int index = atoi(token);
                turn_on_device(index);
            } else {
                printf("Invalid command. Usage: on <device_index>\n");
            }
        } else if (strcmp(token, "off") == 0) {
            token = strtok(NULL, delim);
            if (token != NULL) {
                int index = atoi(token);
                turn_off_device(index);
            } else {
                printf("Invalid command. Usage: off <device_index>\n");
            }
        } else if (strcmp(token, "increase") == 0) {
            token = strtok(NULL, delim);
            if (token != NULL) {
                int index = atoi(token);
                increase_brightness(index);
            } else {
                printf("Invalid command. Usage: increase <device_index>\n");
            }
        } else if (strcmp(token, "decrease") == 0) {
            token = strtok(NULL, delim);
            if (token != NULL) {
                int index = atoi(token);
                decrease_brightness(index);
            } else {
                printf("Invalid command. Usage: decrease <device_index>\n");
            }
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}