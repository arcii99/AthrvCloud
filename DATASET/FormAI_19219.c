//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11
#define M 5.9736e24
#define R 6378.1e3
#define DT 1.0
#define SCALE 1e-6
#define WIDTH 160
#define HEIGHT 80

typedef struct {
    double x, y;
} point_t;

typedef struct {
    point_t p;
    point_t v;
    double m;
} object_t;

point_t get_gravity(object_t obj1, object_t obj2) {
    double distance = sqrt(pow(obj1.p.x - obj2.p.x, 2) + pow(obj1.p.y - obj2.p.y, 2));
    double force = G * obj1.m * obj2.m / pow(distance, 2);
    double angle = atan2(obj2.p.y - obj1.p.y, obj2.p.x - obj1.p.x);
    point_t gravity;
    gravity.x = force * cos(angle) / obj1.m;
    gravity.y = force * sin(angle) / obj1.m;
    return gravity;
}

void update_position(object_t *obj) {
    obj->p.x += obj->v.x * DT * SCALE;
    obj->p.y += obj->v.y * DT * SCALE;
}

void update_velocity(object_t *obj, point_t gravity) {
    obj->v.x += gravity.x * DT;
    obj->v.y += gravity.y * DT;
}

void clear_screen() {
    system("clear");
}

void draw_point(point_t p) {
    int x = (int) ((p.x/R + 1) * WIDTH / 2 + 0.5);
    int y = (int) ((p.y/R + 1) * HEIGHT / 2 + 0.5);
    printf("\033[%d;%dH*", HEIGHT - y, x);
}

void draw_objects(object_t *objects, int count) {
    for (int i = 0; i < count; i++) {
        draw_point(objects[i].p);
    }
}

int main() {
    srand(time(NULL));
    int count = 5;
    object_t objects[count];
    objects[0] = (object_t) { .p = { .x = 0, .y = 0 }, .v = { .x = 0, .y = 0 }, .m = 1.0 };  // planet
    for (int i = 1; i < count; i++) {
        double angle = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double distance = R + ((double) rand() / RAND_MAX) * R;
        double velocity = sqrt(G * M / distance);
        objects[i] = (object_t) { .p = { distance * cos(angle), distance * sin(angle) }, 
                                  .v = { velocity * sin(angle), velocity * cos(angle) },
                                  .m = ((double) rand() / RAND_MAX) * 10 };
    }
    while (1) {
        clear_screen();
        for (int i = 0; i < count; i++) {
            point_t gravity = { 0, 0 };
            for (int j = 0; j < count; j++) {
                if (i != j) {
                    point_t g = get_gravity(objects[i], objects[j]);
                    gravity.x += g.x;
                    gravity.y += g.y;
                }
            }
            update_velocity(&objects[i], gravity);
            update_position(&objects[i]);
        }
        draw_objects(objects, count);
        fflush(stdout);
        usleep(100000);
    }
    return 0;
}