//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

int main(){
	float g = 9.81; // acceleration due to gravity
	float t = 0; // time
	float dt = 0.01; // time step
	float x_0 = 0; // initial position x
	float y_0 = 10; // initial position y
	float v_x = 5; // initial velocity in x-direction
	float v_y = 0; // initial velocity in y-direction
	float x_old, y_old;

	// loop until ball hits ground (y = 0)
	while (y_0 > 0){

		x_old = x_0; // save old x position
		y_old = y_0; // save old y position

		// update position based on velocity
		x_0 = x_old + v_x * dt;
		y_0 = y_old + v_y * dt;

		// update velocity due to gravity
		v_y = v_y - g * dt;

		// output current position and time
		printf("t = %f\tx = %f\ty = %f\n", t, x_0, y_0);

		// check if ball hits ground
		if (y_0 <= 0){
			printf("Ball has hit the ground at t = %f seconds.\n", t);
			break;
		}

		// calculate new velocity in x direction based on air resistance
		v_x = v_x - v_x * 0.01;

		t += dt; // increment time
	}

	return 0;
}