//FormAI DATASET v1.0 Category: Physics simulation ; Style: futuristic
#include <stdio.h>
#include <math.h>
#define TIME_STEP 0.1
#define GRAVITY 9.81
#define SHIP_MASS 10000.0
#define SHIP_MAX_SPEED 1000.0

struct vec {
    double x;
    double y;
    double z;
};

struct ship {
    double mass;
    double speed;
    double max_speed;
    struct vec position;
    struct vec velocity;
    struct vec acceleration;
};

struct obstacle {
    double radius;
    struct vec position;
};

struct enemy {
    double health;
    double damage;
    double range;
    double rate_of_fire;
    struct vec position;
};

void apply_gravity(struct ship *s) {
    s->acceleration.y = -GRAVITY;
}

void apply_thrusters(struct ship *s) {
    double thrust = 0.0;
    int choice = 0;
    printf("Enter thruster choice (1:forward, 2:back, 3:left, 4:right): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            thrust = 10000.0;
            break;
        case 2:
            thrust = -10000.0;
            break;
        case 3:
            thrust = 5000.0;
            break;
        case 4:
            thrust = -5000.0;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    s->acceleration.x = thrust / s->mass;
}

void collide_with_obstacle(struct ship *s, struct obstacle *o) {
    double distance = sqrt(pow(s->position.x - o->position.x, 2) + pow(s->position.y - o->position.y, 2) + pow(s->position.z - o->position.z, 2));
    if(distance <= o->radius) {
        s->velocity.x = -0.5 * s->velocity.x;
        s->velocity.y = -0.5 * s->velocity.y;
        s->velocity.z = -0.5 * s->velocity.z;
        printf("Obstacle collision!\n");
    }
}

void fire_enemy(struct ship *s, struct enemy *e) {
    double distance = sqrt(pow(s->position.x - e->position.x, 2) + pow(s->position.y - e->position.y, 2) + pow(s->position.z - e->position.z, 2));
    if(distance <= e->range) {
        e->health = e->health - e->damage;
        printf("Enemy health: %lf\n", e->health);
    }
}

int main() {
    struct ship s = {SHIP_MASS, 0.0, SHIP_MAX_SPEED, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    struct obstacle o = {100.0, {1000.0, 1000.0, 1000.0}};
    struct enemy e = {1000.0, 100.0, 5000.0, 5.0, {-1000.0, -1000.0, -1000.0}};
    for(int i=0; i<100; i++) {
        apply_gravity(&s);
        apply_thrusters(&s);
        s.velocity.x = s.velocity.x + s.acceleration.x * TIME_STEP;
        s.velocity.y = s.velocity.y + s.acceleration.y * TIME_STEP;
        s.velocity.z = s.velocity.z + s.acceleration.z * TIME_STEP;
        s.position.x = s.position.x + s.velocity.x * TIME_STEP;
        s.position.y = s.position.y + s.velocity.y * TIME_STEP;
        s.position.z = s.position.z + s.velocity.z * TIME_STEP;
        collide_with_obstacle(&s, &o);
        fire_enemy(&s, &e);
    }
    return 0;
}