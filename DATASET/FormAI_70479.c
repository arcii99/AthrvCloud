//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_LIGHTS 10

typedef struct {
  char name[50];
  int brightness;
  int isOn;
} Light;

void printLights(Light* lights, int size) {
  printf("Lights:\n");
  for (int i = 0; i < size; i++) {
    printf("\t%d) %s - %s (%d%%)\n", i+1, lights[i].name, lights[i].isOn ? "On" : "Off", lights[i].brightness);
  }
}

void turnOnOff(Light* lights, int id, int onOff) {
  if (onOff) {
    printf("Turning on %s\n", lights[id].name);
    lights[id].isOn = 1;
  } else {
    printf("Turning off %s\n", lights[id].name);
    lights[id].isOn = 0;
  }
}

void dimLight(Light* lights, int id, int brightness) {
  printf("Dimming %s to %d%%.\n", lights[id].name, brightness);
  lights[id].brightness = brightness;
}

int main() {
  Light lights[MAX_LIGHTS] = {
    {"Main bedroom light", 100, 0},
    {"Kitchen light", 80, 1},
    {"Living room light 1", 90, 0},
    {"Living room light 2", 90, 1},
    {"Guest bedroom light", 100, 1}
  };
  int numLights = 5;
  char command[50];
  while (1) {
    printLights(lights, numLights);
    printf("\nEnter a command (on <light number>, off <light number>, dim <light number> <brightness>, or exit)\n> ");
    fgets(command, 50, stdin);
    char* token = strtok(command, " \n");
    if (!token) {
      continue;
    }
    if (strcmp(token, "exit") == 0) {
      printf("Exiting...\n");
      break;
    }
    int id = atoi(strtok(NULL, " \n")) - 1;
    if (strcmp(token, "on") == 0) {
      turnOnOff(lights, id, 1);
    } else if (strcmp(token, "off") == 0) {
      turnOnOff(lights, id, 0);
    } else if (strcmp(token, "dim") == 0) {
      int brightness = atoi(strtok(NULL, " \n"));
      dimLight(lights, id, brightness);
    }
  }
  return 0;
}