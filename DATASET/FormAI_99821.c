//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11		// Gravitational constant
#define SCALE 1e9			// Scale factor for positioning of planets
#define TIMESTEP 3600		// Timestep for simulation
#define DURATION 31536000	// Duration of simulation in seconds (1 year)

struct CelestialBody {
	char name[50];
	float mass;
	float x, y, z;
	float vx, vy, vz;
	float ax, ay, az;
	float radius;
	float r, g, b;
};

typedef struct CelestialBody celestial_t;

int main() {
	// Define celestial bodies using struct
	celestial_t sun = {"Sun", 1.9885e30, 0, 0, 0, 0, 0, 0, 0, 0, 696340, 1, 1, 0};
	celestial_t earth = {"Earth", 5.9722e24, -1*1.47098074e11, -1*2.65998723e10, 2.980000e4, -5.439656e4, 0, 0, 0, 0, 6371, 0, 0, 1};
	celestial_t moon = {"Moon", 7.342e22, earth.x - 3.844e8, earth.y, earth.z, earth.vx, earth.vy + 1.0230e3, 0, 0, 0, 0, 0.8, 0.8, 0.8};
	
	// Define array of celestial bodies
	celestial_t planets[3] = {sun, earth, moon};
	
	time_t start_time = time(NULL);
	
	// Simulation loop
	while (difftime(time(NULL), start_time) < DURATION) {
		// Calculate forces on each celestial body
		for (int i = 0; i < 3; i++) {
			celestial_t body1 = planets[i];
			float fx = 0, fy = 0, fz = 0;
			
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				
				celestial_t body2 = planets[j];
				float dx = body2.x - body1.x;
				float dy = body2.y - body1.y;
				float dz = body2.z - body1.z;
				float dist = sqrt(dx*dx + dy*dy + dz*dz);
				float force = (G * body1.mass * body2.mass) / (dist*dist);
				fx += force * dx / dist;
				fy += force * dy / dist;
				fz += force * dz / dist;
			}
			
			planets[i].ax = fx / body1.mass;
			planets[i].ay = fy / body1.mass;
			planets[i].az = fz / body1.mass;
		}
		
		// Update positions and velocities of each celestial body
		for (int i = 0; i < 3; i++) {
			celestial_t *body = &planets[i];
			body->vx += body->ax * TIMESTEP;
			body->vy += body->ay * TIMESTEP;
			body->vz += body->az * TIMESTEP;
			body->x += body->vx * TIMESTEP / SCALE;
			body->y += body->vy * TIMESTEP / SCALE;
			body->z += body->vz * TIMESTEP / SCALE;
		}
		
		// Print new positions
		for (int i = 0; i < 3; i++) {
			printf("%s: (%e, %e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
		}
		
		// Use delay to slow down simulation for visualization purposes (not part of simulation)
		clock_t start_time = clock();
		while (clock() < start_time + 1000) {}
	}
	
	return 0;
}