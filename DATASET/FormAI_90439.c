//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
    float g = 9.8; // gravitational acceleration
    float t = 0.0; // time initialized to 0
    float dt = 0.01; // time step
    float v0 = 50.0; // initial velocity
    float theta = M_PI/4; // angle in radians
    float x = 0.0; // x position initialized to 0
    float y = 0.0; // y position initialized to 0
    
    while (y >= 0.0) { // projectile is in the air
        float vx = v0 * cos(theta); // x component of velocity
        float vy = v0 * sin(theta); // y component of velocity
        float ax = 0.0; // x component of acceleration
        float ay = -g; // y component of acceleration
        
        x += vx * dt; // update x position
        y += vy * dt; // update y position
        
        vx += ax * dt; // update x component of velocity
        vy += ay * dt; // update y component of velocity
        
        v0 = sqrt(vx*vx + vy*vy); // update magnitude of velocity
        theta = atan2(vy, vx); // update angle of velocity
        
        t += dt; // increase time step
        
        printf("t=%0.2f, x=%0.2f, y=%0.2f, v=%0.2f, theta=%0.2f\n", t, x, y, v0, theta*180/M_PI);
    }
    
    return 0;
}