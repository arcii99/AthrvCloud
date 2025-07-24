//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8	// Number of planets in the solar system
#define G_CONST 6.67e-11	// Gravitational constant

// Struct to store planet information
typedef struct planet {
	char name[20];	// Planet name
	double mass;	// Planet mass in kilograms
	double pos[3];	// Planet position x,y,z in meters
	double vel[3];	// Planet velocity x,y,z in meters/second
} Planet;

// Function prototypes
void update_positions(Planet *planets, double timestep);
void update_velocities(Planet *planets, double timestep);

int main() {
	// Define planets in the solar system
	Planet planets[NUM_PLANETS] = {
		{"Mercury", 3.3e23, {0, 0, 0}, {0, 0, 0}},
		{"Venus", 4.86e24, {0, 0, 0}, {0, 0, 0}},
		{"Earth", 5.97e24, {0, 0, 0}, {0, 0, 0}},
		{"Mars", 6.39e23, {0, 0, 0}, {0, 0, 0}},
		{"Jupiter", 1.89e27, {0, 0, 0}, {0, 0, 0}},
		{"Saturn", 5.68e26, {0, 0, 0}, {0, 0, 0}},
		{"Uranus", 8.68e25, {0, 0, 0}, {0, 0, 0}},
		{"Neptune", 1.02e26, {0, 0, 0}, {0, 0, 0}}
	};

	double timestep = 1000;	// Simulate 1 day of planetary motion (timestep = 1 second)
	int num_steps = 365;	// Simulate 1 year of planetary motion (365 days)

	// Randomly set initial planet positions and velocities
	for (int i = 0; i < NUM_PLANETS; i++) {
		planets[i].pos[0] = (double)rand() / RAND_MAX * 1e10;
		planets[i].pos[1] = (double)rand() / RAND_MAX * 1e10;
		planets[i].pos[2] = (double)rand() / RAND_MAX * 1e10;
		planets[i].vel[0] = (double)rand() / RAND_MAX * 1e4;
		planets[i].vel[1] = (double)rand() / RAND_MAX * 1e4;
		planets[i].vel[2] = (double)rand() / RAND_MAX * 1e4;
	}

	// Simulate planetary motion
	for (int i = 0; i < num_steps; i++) {
		update_positions(planets, timestep);	// Update positions of all planets
		update_velocities(planets, timestep);	// Update velocities of all planets

		printf("Step %d\n", i);
		for (int j = 0; j < NUM_PLANETS; j++) {
			// Print planet information
			printf("%s - Position: (%.2f, %.2f, %.2f) meters, Velocity: (%.2f, %.2f, %.2f) meters/second\n",
			       planets[j].name, planets[j].pos[0], planets[j].pos[1], planets[j].pos[2],
			       planets[j].vel[0], planets[j].vel[1], planets[j].vel[2]);
		}
	}

	return 0;
}

// Function to update all planet positions after a given time step
void update_positions(Planet *planets, double timestep) {
	for (int i = 0; i < NUM_PLANETS; i++) {
		// Update position using velocity and time
		planets[i].pos[0] += planets[i].vel[0] * timestep;
		planets[i].pos[1] += planets[i].vel[1] * timestep;
		planets[i].pos[2] += planets[i].vel[2] * timestep;
	}
}

// Function to update all planet velocities after a given time step
void update_velocities(Planet *planets, double timestep) {
	for (int i = 0; i < NUM_PLANETS; i++) {
		// Calculate velocity change due to gravitational forces from other planets
		double force_x = 0;
		double force_y = 0;
		double force_z = 0;

		for (int j = 0; j < NUM_PLANETS; j++) {
			if (i == j) {
				continue;	// Skip self-gravity calculation
			}

			// Calculate distance between planet i and j
			double dist_x = planets[j].pos[0] - planets[i].pos[0];
			double dist_y = planets[j].pos[1] - planets[i].pos[1];
			double dist_z = planets[j].pos[2] - planets[i].pos[2];
			double dist = sqrt(dist_x * dist_x + dist_y * dist_y + dist_z * dist_z);

			// Calculate gravitational force between planet i and j
			double force = (G_CONST * planets[i].mass * planets[j].mass) / (dist * dist);

			// Calculate force components in x, y, and z directions
			force_x += force * dist_x / dist;
			force_y += force * dist_y / dist;
			force_z += force * dist_z / dist;
		}

		// Update velocity using force and time
		planets[i].vel[0] += force_x / planets[i].mass * timestep;
		planets[i].vel[1] += force_y / planets[i].mass * timestep;
		planets[i].vel[2] += force_z / planets[i].mass * timestep;
	}
}