//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408	// Gravitational constant
#define DAY 86400	// Number of seconds in a day

typedef struct {
	double mass;	// Mass of the planet (kg)
	double radius;	// Radius of the planet (m)
	double x, y, z;	// Position vector components (m)
	double vx, vy, vz;	// Velocity vector components (m/s)
	double ax, ay, az;	// Acceleration vector components (m/s^2)
} Planet;

double distance(Planet a, Planet b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	double dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_vel(Planet *p, double fx, double fy, double fz, double dt) {
	p->vx += fx / p->mass * dt;
	p->vy += fy / p->mass * dt;
	p->vz += fz / p->mass * dt;
}

void update_pos(Planet *p, double dt) {
	p->x += p->vx * dt;
	p->y += p->vy * dt;
	p->z += p->vz * dt;
}

void update_acc(Planet *p, double fx, double fy, double fz) {
	p->ax += fx / p->mass;
	p->ay += fy / p->mass;
	p->az += fz / p->mass;
}

void apply_force(Planet *a, Planet *b) {
	double r = distance(*a, *b);
	double f = G * a->mass * b->mass / (r*r);
	double fx = f * (b->x - a->x) / r;
	double fy = f * (b->y - a->y) / r;
	double fz = f * (b->z - a->z) / r;
	update_acc(a, fx, fy, fz);
	update_acc(b, -fx, -fy, -fz);
}

void simulate(Planet *planets, int n, double dt, double tmax) {
	for (int t = 0; t < tmax; t += dt) {
		// Apply gravitational forces to each pair of planets
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				apply_force(&planets[i], &planets[j]);
			}
		}

		// Update positions, velocities, and accelerations
		for (int i = 0; i < n; i++) {
			update_vel(&planets[i], planets[i].ax, planets[i].ay, planets[i].az, dt);
			update_pos(&planets[i], dt);
			planets[i].ax = 0;
			planets[i].ay = 0;
			planets[i].az = 0;
		}
	}
}

int main() {
	// Initialize planet data
	Planet earth = {5.97e24, 6.37e6, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	Planet moon = {7.35e22, 1.74e6, 3.84e8, 0, 0, 0, 1020, 0, 0, 0, 0};
	Planet mars = {6.39e23, 3.39e6, 2.27e11, 0, 0, 0, 0, 0, 0, 0, 0};
	Planet venus = {4.87e24, 6.05e6, 1.08e11, 0, 0, 0, 0, 0, 0, 0, 0};
	Planet planets[] = {earth, moon, mars, venus};

	// Run simulation for 365 days
	simulate(planets, sizeof(planets)/sizeof(*planets), DAY, 365);

	// Print final positions
	printf("Final positions:\n");
	for (int i = 0; i < sizeof(planets)/sizeof(*planets); i++) {
		printf("%d: (%.2f, %.2f, %.2f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
	}

	return 0;
}