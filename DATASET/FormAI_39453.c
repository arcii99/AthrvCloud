//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11	// gravitational constant

#define SUN_MASS 1.989e30
#define MERCURY_MASS 0.33e24
#define VENUS_MASS 4.87e24
#define EARTH_MASS 5.97e24
#define MARS_MASS 0.642e24
#define JUPITER_MASS 1898e24
#define SATURN_MASS 568e24
#define URANUS_MASS 86.8e24
#define NEPTUNE_MASS 102e24

#define AU 149.6e9	// astronomical unit
#define PI 3.14159265359

typedef struct Vector {
	double x;
	double y;
} Vector;

typedef struct Body {
	char name[20];
	double mass;
	Vector position;
	Vector velocity;
	Vector acceleration;
} Body;

Vector addVectors(Vector v1, Vector v2) {
	Vector v = {v1.x + v2.x, v1.y + v2.y};
	return v;
}

Vector subtractVectors(Vector v1, Vector v2) {
	Vector v = {v1.x - v2.x, v1.y - v2.y};
	return v;
}

Vector scaleVector(Vector v, double scalar) {
	Vector s = {v.x * scalar, v.y * scalar};
	return s;
}

double dotProduct(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

double magnitude(Vector v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

double distance(Vector v1, Vector v2) {
	return magnitude(subtractVectors(v1, v2));
}

Vector direction(Vector v) {
	double mag = magnitude(v);
	Vector d = {v.x / mag, v.y / mag};
	return d;
}

double sqr(double x) {
	return x * x;
}

void updateBody(Body* b, Body* s, int n) {
	int i;
	b->acceleration.x = 0.0;
	b->acceleration.y = 0.0;
	for (i = 0; i < n; ++i) {
		if (s[i].mass <= 0.0) {
			continue;
		}
		Vector diff = subtractVectors(s[i].position, b->position);
		double d = magnitude(diff);
		if (d == 0.0) {
			continue;
		}
		double F = G * s[i].mass * b->mass / sqr(d);
		b->acceleration = addVectors(b->acceleration, scaleVector(direction(diff), F / b->mass));
	}
	b->velocity = addVectors(b->velocity, scaleVector(b->acceleration, 86400.0));
	b->position = addVectors(b->position, scaleVector(b->velocity, 86400.0));
}

int main() {
	Body sun = {"Sun", SUN_MASS, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
	Body mercury = {"Mercury", MERCURY_MASS, {0.0, 0.3871 * AU}, {47362.0, 0.0}, {0.0, 0.0}};
	Body venus = {"Venus", VENUS_MASS, {0.0, 0.7233 * AU}, {35020.0, 0.0}, {0.0, 0.0}};
	Body earth = {"Earth", EARTH_MASS, {0.0, 1.0 * AU}, {29783.0, 0.0}, {0.0, 0.0}};
	Body mars = {"Mars", MARS_MASS, {0.0, 1.524 * AU}, {24007.0, 0.0}, {0.0, 0.0}};
	Body jupiter = {"Jupiter", JUPITER_MASS, {0.0, 5.203 * AU}, {13070.0, 0.0}, {0.0, 0.0}};
	Body saturn = {"Saturn", SATURN_MASS, {0.0, 9.5826 * AU}, {8979.0, 0.0}, {0.0, 0.0}};
	Body uranus = {"Uranus", URANUS_MASS, {0.0, 19.2184 * AU}, {6355.0, 0.0}, {0.0, 0.0}};
	Body neptune = {"Neptune", NEPTUNE_MASS, {0.0, 30.07 * AU}, {5185.0, 0.0}, {0.0, 0.0}};

	Body solarSystem[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
	int n = 9;

	int i;
	for (i = 0; i < n; ++i) {
		printf("%s\tmass: %e\t (%e, %e)\t (%e, %e)\n", solarSystem[i].name, solarSystem[i].mass,
			solarSystem[i].position.x, solarSystem[i].position.y, solarSystem[i].velocity.x, solarSystem[i].velocity.y);
	}

	double t = 0.0;
	double dt = 3600.0; // 1 hour

	while (t <= 31557600.0 * 4.5) {	// simulation for 4.5 years
		for (i = 0; i < n; ++i) {
			updateBody(&solarSystem[i], solarSystem, n);
		}
		t += dt;
	}

	return 0;
}