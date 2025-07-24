//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LIGHTS_PATH "/dev/lights"
#define AC_PATH "/dev/thermostat"
#define DOOR_PATH "/dev/door"
#define WINDOW_PATH "/dev/window"

//Function to toggle lights
void toggle_lights(bool shouldTurnOn){
    int fd;
    fd = open(LIGHTS_PATH, O_WRONLY);
    if(fd < 0){
        printf("Error opening lights device file\n");
        return;
    }
    if(shouldTurnOn){
        write(fd, "1", 1);
    } else {
        write(fd, "0", 1);
    }
    close(fd);
}

//Function to adjust AC temperature
void adjust_temperature(int temperature){
    int fd;
    fd = open(AC_PATH, O_WRONLY);
    if(fd < 0){
        printf("Error opening AC device file\n");
        return;
    }
    char buf[4];
    sprintf(buf, "%d", temperature);
    write(fd, buf, 3);
    close(fd);
}

//Function to lock/unlock door
void lock_door(bool shouldLock){
    int fd;
    fd = open(DOOR_PATH, O_WRONLY);
    if(fd < 0){
        printf("Error opening door device file\n");
        return;
    }
    if(shouldLock){
        write(fd, "1", 1);
    } else {
        write(fd, "0", 1);
    }
    close(fd);
}

//Function to open/close windows
void toggle_window(bool shouldOpen){
    int fd;
    fd = open(WINDOW_PATH, O_WRONLY);
    if(fd < 0){
        printf("Error opening window device file\n");
        return;
    }
    if(shouldOpen){
        write(fd, "1", 1);
    } else {
        write(fd, "0", 1);
    }
    close(fd);
}

//Signal handler for SIGINT
void handle_sigint(int sig){
    toggle_lights(false); //Turn off the lights
    exit(0);
}

int main(){
    signal(SIGINT, handle_sigint); //Set up signal handler for SIGINT

    //Set up initial state
    toggle_lights(true);
    adjust_temperature(20);
    lock_door(true);
    toggle_window(false);

    //Toggle the lights for 10 seconds
    int i;
    for(i=0; i<10; i++){
        toggle_lights(!((i%2)==0));
        sleep(1);
    }

    //Change the temperature to 25 degrees
    adjust_temperature(25);

    //Lock the door and close the windows
    lock_door(true);
    toggle_window(false);

    //Wait for 5 seconds to let things settle
    sleep(5);

    //Toggle the lights for 10 seconds
    for(i=0; i<10; i++){
        toggle_lights(!((i%2)==0));
        sleep(1);
    }

    //Unlock the door and open the windows
    lock_door(false);
    toggle_window(true);

    //Keep the lights on for the next 30 seconds
    for(i=0; i<30; i++){
        toggle_lights(true);
        sleep(1);
    }

    //Turn off the lights and exit
    toggle_lights(false);
    return 0;
}