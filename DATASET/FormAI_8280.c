//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constant values for light modes
#define OFF 0
#define ON 1
#define DIM 2
#define BRIGHT 3
#define FLASH 4

//struct to represent a single light
struct Light {
    char name[20];
    int mode;
};

//function to print the current status of a light
void print_light_status(struct Light light) {
    printf("%s is currently ", light.name);
    switch(light.mode) {
        case OFF:
            printf("off\n");
            break;
        case ON:
            printf("on\n");
            break;
        case DIM:
            printf("dimmed\n");
            break;
        case BRIGHT:
            printf("bright\n");
            break;
        case FLASH:
            printf("flashing\n");
            break;
    }
}

//function to change the mode of a light
void set_light_mode(struct Light *light, int new_mode) {
    light->mode = new_mode;
    print_light_status(*light);
}

int main(void) {
    //create an array of 3 lights
    struct Light lights[3];
    
    //initialize the lights
    strcpy(lights[0].name, "Living Room");
    lights[0].mode = OFF;
    
    strcpy(lights[1].name, "Kitchen");
    lights[1].mode = ON;
    
    strcpy(lights[2].name, "Bedroom");
    lights[2].mode = DIM;
    
    //print the status of all lights
    for(int i=0; i<3; i++) {
        print_light_status(lights[i]);
    }
    
    //turn on the living room light
    set_light_mode(&lights[0], ON);
    
    //dim the bedroom light
    set_light_mode(&lights[2], DIM);
    
    //flash the kitchen light
    set_light_mode(&lights[1], FLASH);
    
    return 0;
}