//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

#define MAX_DEVICES 10   // maximum number of devices in the house

// device types
#define LIGHT 0
#define DOOR 1
#define WINDOW 2
#define THERMOSTAT 3

// device states
#define OFF 0
#define ON 1
#define LOCKED 2
#define UNLOCKED 3
#define OPEN 4
#define CLOSED 5
#define HEATING 6
#define COOLING 7

// device struct
typedef struct device {
  int type;   // type of device
  int state;  // state of device
} Device;

// smart home struct
typedef struct smart_home {
  Device devices[MAX_DEVICES];  // array of devices
  int num_devices;              // number of devices
} SmartHome;

int main() {
  // initialize smart home
  SmartHome home;
  home.num_devices = 0;

  // add devices to smart home
  Device light1 = {LIGHT, OFF};
  home.devices[home.num_devices++] = light1;
  Device light2 = {LIGHT, OFF};
  home.devices[home.num_devices++] = light2;
  Device door1 = {DOOR, LOCKED};
  home.devices[home.num_devices++] = door1;
  Device door2 = {DOOR, LOCKED};
  home.devices[home.num_devices++] = door2;
  Device window1 = {WINDOW, CLOSED};
  home.devices[home.num_devices++] = window1;
  Device window2 = {WINDOW, CLOSED};
  home.devices[home.num_devices++] = window2;
  Device thermostat = {THERMOSTAT, COOLING};
  home.devices[home.num_devices++] = thermostat;

  // print initial state of smart home
  printf("Welcome to your Cyberpunk Smart Home!\n");

  printf("\nDevices:\n");
  for (int i = 0; i < home.num_devices; i++) {
    printf("Device %d: ", i+1);
    if (home.devices[i].type == LIGHT) {
      printf("Light");
    } else if (home.devices[i].type == DOOR) {
      printf("Door");
    } else if (home.devices[i].type == WINDOW) {
      printf("Window");
    } else if (home.devices[i].type == THERMOSTAT) {
      printf("Thermostat");
    }
    printf(", State: ");
    if (home.devices[i].state == OFF) {
      printf("Off\n");
    } else if (home.devices[i].state == ON) {
      printf("On\n");
    } else if (home.devices[i].state == LOCKED) {
      printf("Locked\n");
    } else if (home.devices[i].state == UNLOCKED) {
      printf("Unlocked\n");
    } else if (home.devices[i].state == OPEN) {
      printf("Open\n");
    } else if (home.devices[i].state == CLOSED) {
      printf("Closed\n");
    } else if (home.devices[i].state == HEATING) {
      printf("Heating\n");
    } else if (home.devices[i].state == COOLING) {
      printf("Cooling\n");
    }
  }

  // control devices with voice commands
  char command[20];
  while (true) {
    // prompt for voice command
    printf("\nVoice Command: ");
    scanf("%s", command);

    if (strcmp(command, "turn on lights") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == LIGHT) {
          home.devices[i].state = ON;
        }
      }
      printf("Lights turned on!\n");
    } else if (strcmp(command, "turn off lights") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == LIGHT) {
          home.devices[i].state = OFF;
        }
      }
      printf("Lights turned off!\n");
    } else if (strcmp(command, "lock doors") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == DOOR) {
          home.devices[i].state = LOCKED;
        }
      }
      printf("Doors locked!\n");
    } else if (strcmp(command, "unlock doors") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == DOOR) {
          home.devices[i].state = UNLOCKED;
        }
      }
      printf("Doors unlocked!\n");
    } else if (strcmp(command, "open windows") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == WINDOW) {
          home.devices[i].state = OPEN;
        }
      }
      printf("Windows opened!\n");
    } else if (strcmp(command, "close windows") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == WINDOW) {
          home.devices[i].state = CLOSED;
        }
      }
      printf("Windows closed!\n");
    } else if (strcmp(command, "heat house") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == THERMOSTAT) {
          home.devices[i].state = HEATING;
        }
      }
      printf("House heating up!\n");
    } else if (strcmp(command, "cool house") == 0) {
      for (int i = 0; i < home.num_devices; i++) {
        if (home.devices[i].type == THERMOSTAT) {
          home.devices[i].state = COOLING;
        }
      }
      printf("House cooling down!\n");
    } else if (strcmp(command, "exit") == 0) {
      printf("Exiting Smart Home...\n");
      break;
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}