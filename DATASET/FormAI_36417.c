//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D pos;
    Vector2D vel;
    double mass;
} Particle;

void updatePosition(Particle* p, double dt) {
    p->pos.x += p->vel.x * dt;
    p->pos.y += p->vel.y * dt;
}

void updateVelocity(Particle* p, Vector2D force, double dt) {
    p->vel.x += force.x * dt / p->mass;
    p->vel.y += force.y * dt / p->mass;
}

double calculateDistance(Vector2D p1, Vector2D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

Vector2D calculateForce(Particle* p1, Particle* p2, double G) {
    double dist = calculateDistance(p1->pos, p2->pos);
    double magnitude = G * p1->mass * p2->mass / (dist * dist);
    double angle = atan2(p2->pos.y - p1->pos.y, p2->pos.x - p1->pos.x);
    Vector2D force = {magnitude * cos(angle), magnitude * sin(angle)};
    return force;
}

void simulateParticles(int numParticles) {
    Particle particles[numParticles];
    srand(time(NULL));
    for (int i = 0; i < numParticles; i++) {
        particles[i].pos.x = rand() % 101;
        particles[i].pos.y = rand() % 101;
        particles[i].vel.x = rand() % 11 - 5;
        particles[i].vel.y = rand() % 11 - 5;
        particles[i].mass = 1 + (double)rand() / RAND_MAX * 9;
    }

    const double G = 1;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < numParticles; j++) {
            Vector2D totalForce = {0, 0};
            for (int k = 0; k < numParticles; k++) {
                if (j != k) {
                    Vector2D force = calculateForce(&particles[j], &particles[k], G);
                    totalForce.x += force.x;
                    totalForce.y += force.y;
                }
            }
            updateVelocity(&particles[j], totalForce, 0.01);
        }
        for (int j = 0; j < numParticles; j++) {
            updatePosition(&particles[j], 0.01);
        }
    }

    // Draw particles
    char canvas[101][101] = {' '};
    for (int i = 0; i < numParticles; i++) {
        int x = (int)round(particles[i].pos.x);
        int y = (int)round(particles[i].pos.y);
        if (x >= 0 && x < 101 && y >= 0 && y < 101) {
            canvas[y][x] = 'o';
        }
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    simulateParticles(50);
    return 0;
}