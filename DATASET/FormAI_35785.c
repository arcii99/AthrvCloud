//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define DELTA_T 0.1 // seconds

typedef struct {
    double x;
    double y;
} Vec2D;

typedef struct {
    Vec2D position;
    Vec2D velocity;
    double mass;
} Object;

void update_object_position(Object *object) {
    // Calculating new position based on velocity and acceleration
    object->position.x += object->velocity.x * DELTA_T;
    object->position.y += object->velocity.y * DELTA_T - 0.5 * GRAVITY * pow(DELTA_T, 2);
}

void update_object_velocity(Object *object) {
    // Calculating new velocity based on gravity
    object->velocity.y -= GRAVITY * DELTA_T;
}

double calculate_distance(Vec2D point1, Vec2D point2) {
    // Calculating Euclidean distance between two points
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

int main() {
    Object ball = {
        .position = {0, 10},
        .velocity = {5, 0},
        .mass = 0.45 // kg
    };
    
    Object target = {
        .position = {50, 0},
        .velocity = {0, 0},
        .mass = 0 // target is stationary and massless
    };
    
    double distance = calculate_distance(ball.position, target.position);
    
    while (distance > 0.5) { // stop simulation when ball is close to target
        update_object_position(&ball);
        update_object_velocity(&ball);
        
        distance = calculate_distance(ball.position, target.position);
        
        printf("Ball x position: %.2f meters\n", ball.position.x);
        printf("Ball y position: %.2f meters\n", ball.position.y);
        printf("Distance to target: %.2f meters\n\n", distance);
    }
    
    printf("Target reached!\n");
    
    return 0;
}