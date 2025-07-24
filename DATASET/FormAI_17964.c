//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
// This program is a traffic light controller example
// The system will simulate the following sequence for a set of two traffic lights

// 1. Green light one on, red light two on
// 2. Yellow light one on, red light two on (two seconds delay)
// 3. Red light one on, green light two on
// 4. Red light one on, yellow light two on (two seconds delay)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>   // for sleep() function
#include<time.h>     // for srand() function

// define traffic light structure
struct traffic_light {
    int green;     // green light status
    int yellow;    // yellow light status
    int red;       // red light status
};

// function prototypes
void set_traffic_lights(struct traffic_light[], int);
void display_traffic_lights(struct traffic_light[], int);
void delay(int);

int main() {
    // create array of two traffic lights
    struct traffic_light lights[2];
    int i, count = 0;
    
    // set random seed for delay function
    srand(time(0));
    
    // initialize traffic lights
    set_traffic_lights(lights, 2);
    
    // loop through traffic light sequence
    while(count < 5) {
        // display current traffic light status
        display_traffic_lights(lights, 2);
        
        // switch from green to yellow on light one
        if(lights[0].green == 1 && lights[0].yellow == 0 && lights[0].red == 0) {
            lights[0].green = 0;
            lights[0].yellow = 1;
            delay(2);
        }
        
        // switch from yellow to red and green to yellow on light one
        else if(lights[0].green == 0 && lights[0].yellow == 1 && lights[0].red == 0) {
            lights[0].yellow = 0;
            lights[0].red = 1;
            lights[1].green = 1;
            delay(2);
        }
        
        // switch from red to green on light one
        else if(lights[0].green == 0 && lights[0].yellow == 0 && lights[0].red == 1) {
            lights[0].red = 0;
            lights[1].yellow = 1;
            delay(2);
        }
        
        // switch from yellow to red on light two
        else if(lights[1].green == 0 && lights[1].yellow == 1 && lights[1].red == 0) {
            lights[1].yellow = 0;
            lights[1].red = 1;
            count++;
            delay(2);
        }
        
        // display current traffic light status
        display_traffic_lights(lights, 2);
    }
    
    return 0;
}

// function to set initial traffic light status
void set_traffic_lights(struct traffic_light lights[], int n) {
    int i;
    for(i=0; i<n; i++) {
        lights[i].green = 0;
        lights[i].yellow = 0;
        lights[i].red = 1;
    }
    lights[0].green = 1;
}

// function to display current traffic light status
void display_traffic_lights(struct traffic_light lights[], int n) {
    int i;
    printf("\n");
    for(i=0; i<n; i++) {
        if(lights[i].green == 1) {
            printf("Green\n");
        }
        else if(lights[i].yellow == 1) {
            printf("Yellow\n");
        }
        else {
            printf("Red\n");
        }
    }
}

// function to provide delay between light changes
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while(clock() < start_time + milli_seconds);
}