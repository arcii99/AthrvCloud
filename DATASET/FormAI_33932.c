//FormAI DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>

int main() {
  printf("Welcome to the Paranoid Smart Home Automation Program!\n");

  int door_is_locked = 1;
  int windows_are_closed = 1;
  int alarm_is_active = 0;
  int lights_are_on = 0;
  int motion_detected = 0;

  printf("Checking if doors are locked...\n");

  if (door_is_locked == 0) {
    printf("The doors appear to be unlocked. Activating alarm...\n");
    alarm_is_active = 1;
  } else {
    printf("The doors are securely locked.\n");
  }

  printf("Checking if windows are closed...\n");

  if (windows_are_closed == 0) {
    printf("The windows appear to be open. Activating alarm...\n");
    alarm_is_active = 1;
  } else {
    printf("The windows are securely closed.\n");
  }

  printf("Checking for motion...\n");

  if (motion_detected == 1) {
    printf("Motion has been detected. Activating lights...\n");
    lights_are_on = 1;
  } else {
    printf("No motion has been detected.\n");
  }

  printf("Checking if alarm is active...\n");

  if (alarm_is_active == 1) {
    printf("The alarm is active. Contacting authorities...\n");
  } else {
    printf("The alarm is not active.\n");
  }

  printf("Checking if lights are on...\n");

  if (lights_are_on == 1) {
    printf("The lights are on. Checking for unauthorized access...\n");
    if (door_is_locked == 1 && windows_are_closed == 1) {
      printf("Access appears to be authorized. Turning off lights...\n");
      lights_are_on = 0;
    } else {
      printf("Unauthorized access detected. The alarm has been activated...\n");
      alarm_is_active = 1;
    }
  } else {
    printf("The lights are not on.\n");
  }

  printf("System check complete. Exiting program...\n");

  return 0;
}