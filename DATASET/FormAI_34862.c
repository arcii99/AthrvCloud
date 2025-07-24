//FormAI DATASET v1.0 Category: Physics simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define NUM_PLAYERS 2
#define GRAVITY 9.8
#define TIME_STEP 0.01
#define MAX_COLLISIONS 1000
#define COLLISION_MARGIN 0.01

typedef struct Player {
    int id;
    float x, y;
    float vx, vy;
    float radius;
    bool collided;
} Player;

void update(Player *p) {
    // Update velocity due to gravity
    p->vy -= GRAVITY * TIME_STEP;
    
    // Update position due to velocity
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
}

void collide(Player *p1, Player *p2) {
    // Calculate distance between players
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    float dist = sqrt(dx*dx + dy*dy);
    
    // Calculate overlap distance
    float overlap = (p1->radius + p2->radius) - dist;
    
    if (overlap > COLLISION_MARGIN) {
        // Move players apart (in opposite directions)
        float factor = overlap / dist;
        p1->x -= dx * factor / 2;
        p1->y -= dy * factor / 2;
        p2->x += dx * factor / 2;
        p2->y += dy * factor / 2;
        
        // Calculate new velocities
        float dvx = p2->vx - p1->vx;
        float dvy = p2->vy - p1->vy;
        float dot = (dx*dvx + dy*dvy) / dist;
        float angle = atan2(dy, dx);
        float m1 = pow(p1->radius, 2);
        float m2 = pow(p2->radius, 2);
        float u1 = dot*(m1-m2)/(m1+m2) + p1->vx;
        float u2 = dot*(m2-m1)/(m1+m2) + p2->vx;
        float v1 = sqrt(pow(dvx, 2) + pow(dvy, 2))*cos(angle);
        float v2 = sqrt(pow(dvx, 2) + pow(dvy, 2))*sin(angle);
        
        // Update velocities
        p1->vx = u1*cos(angle) - v1*sin(angle);
        p1->vy = u1*sin(angle) + v1*cos(angle);
        p2->vx = u2*cos(angle) - v2*sin(angle);
        p2->vy = u2*sin(angle) + v2*cos(angle);
        
        // Mark players as collided
        p1->collided = true;
        p2->collided = true;
    }
}

int main() {
    // Initialize players
    Player players[NUM_PLAYERS];
    players[0].id = 0;
    players[0].x = 1;
    players[0].y = 3;
    players[0].vx = 5;
    players[0].vy = 10;
    players[0].radius = 0.5;
    players[0].collided = false;
    players[1].id = 1;
    players[1].x = 5;
    players[1].y = 6;
    players[1].vx = -2;
    players[1].vy = 7;
    players[1].radius = 0.75;
    players[1].collided = false;
    
    // Simulate collisions
    int numCollisions = 0;
    
    while (numCollisions < MAX_COLLISIONS) {
        // Update player positions
        for (int i = 0; i < NUM_PLAYERS; i++) {
            update(&players[i]);
        }
        
        // Check for collisions
        int numCollisionsThisStep = 0;
        
        for (int i = 0; i < NUM_PLAYERS; i++) {
            for (int j = i+1; j < NUM_PLAYERS; j++) {
                if (i != j && !players[i].collided && !players[j].collided) {
                    collide(&players[i], &players[j]);
                    numCollisionsThisStep++;
                }
            }
        }
        
        if (numCollisionsThisStep == 0) {
            break;
        }
        else {
            numCollisions += numCollisionsThisStep;
        }
    }
    
    // Print player positions
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d final position: (%f, %f)\n", players[i].id, players[i].x, players[i].y);
    }
    
    return 0;
}