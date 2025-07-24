//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

/* Define the car state structure */
typedef struct {
    double x;   // x position
    double y;   // y position
    double theta;   // orientation angle in degrees
    double v;   // linear velocity
    double omega;   // angular velocity
} CarState;

/* Define the control signal structure */
typedef struct {
    double w1;   // wheel 1 velocity
    double w2;   // wheel 2 velocity
    double w3;   // wheel 3 velocity
    double w4;   // wheel 4 velocity
} ControlSignal;

/* Update the car state given the control signal and elapsed time */
CarState update_car_state(CarState state, ControlSignal signal, double dt) {
    CarState new_state = state; // start with current state
    double cos_theta = cos(new_state.theta * 3.14159 / 180.0);   // convert to radians and take cosine
    double sin_theta = sin(new_state.theta * 3.14159 / 180.0);   // convert to radians and take sine
    
    /* Compute forward and rotation velocities */
    double v_x = (signal.w1 + signal.w2 + signal.w3 + signal.w4) / 4.0;
    double v_theta = (-signal.w1 + signal.w2 - signal.w3 + signal.w4) / 4.0;
    
    /* Update state */
    new_state.x += v_x * cos_theta * dt;
    new_state.y += v_x * sin_theta * dt;
    new_state.theta += v_theta * dt;
    
    /* Clip angle to range [-180, 180) */
    while(new_state.theta < -180.0) {
        new_state.theta += 360.0;
    }
    while(new_state.theta >= 180.0) {
        new_state.theta -= 360.0;
    }
    
    /* Update linear and angular velocities */
    new_state.v = v_x;
    new_state.omega = v_theta;
    
    return new_state;
}

int main() {
    /* Initialize car state */
    CarState state = {0.0, 0.0, 0.0, 0.0, 0.0};
    
    /* Initialize control signal */
    ControlSignal signal = {0.0, 0.0, 0.0, 0.0};
    
    /* Simulation parameters */
    double dt = 0.1;   // time step
    double sim_time = 10.0;   // simulation time
    
    /* Simulation loop */
    for(double t=0.0; t<sim_time; t+=dt) {
        /* Update control signal */
        signal.w1 = sin(t);
        signal.w2 = cos(t);
        signal.w3 = sin(2.0*t);
        signal.w4 = cos(2.0*t);
        
        /* Update car state */
        state = update_car_state(state, signal, dt);
        
        /* Print current state to console */
        printf("Time: %f, X: %f, Y: %f, Theta: %f, V: %f, Omega: %f\n",
               t, state.x, state.y, state.theta, state.v, state.omega);
    }
    
    /* Done */
    return 0;
}