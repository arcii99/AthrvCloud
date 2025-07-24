//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float g = 9.8; // acceleration due to gravity
    float v = 0; // initial velocity is zero
    float t = 0; // initial time is zero
    float h = 0; // initial height is zero
    float obj_height = 5; // height of the object we want to hit
    float angle = 45; // initial angle of projection is 45 degrees
    float x, y;
    float tof; // time of flight
    int hit = 0; // flag to determine if the object is hit or not

    printf("Enter the initial velocity > ");
    scanf("%f", &v);
    printf("Enter the projection angle > ");
    scanf("%f", &angle);

    angle = angle * M_PI / 180; // converting angle to radians

    while(!hit){

        // position of the object at time t
        x = v * cos(angle) * t;
        y = h + (v * sin(angle) * t) - (0.5 * g * pow(t, 2));

        printf("Time: %f \t Height: %f \t Distance: %f\n", t, y, x);

        t += 0.1; // incrementing time by 0.1 seconds

        if(y <= obj_height){
            tof = (v * sin(angle)) / g; // time of flight
            printf("Object hit after %f seconds. Distance from the object is %f\n", tof, x);
            hit = 1;
        }
    }

    return 0;
}