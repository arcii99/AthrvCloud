//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: brave
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674 * pow(10, -11)
#define NO_OF_PLANETS 5
#define WIDTH 800
#define HEIGHT 800
#define MARGIN 50
#define SCALE 0.000000000000001

typedef struct {
    double x, y;
} Vec;

typedef struct {
    char name[10];
    double mass;
    double diameter;
    Vec pos;
    Vec vel;
    Vec force;
} Planet;

Planet planets[NO_OF_PLANETS] = {
    {"Sun", 1.989 * pow(10, 30), 1392500, {0, 0}, {0, 0}, {0, 0}},
    {"Mercury", 3.3 * pow(10, 23), 4879, {-5.79 * pow(10, 10), 0}, {0, 47890}, {0, 0}},
    {"Venus", 4.87 * pow(10, 24), 12104, {0, 1.08 * pow(10, 11)}, {-35020, 0}, {0, 0}},
    {"Earth", 5.97 * pow(10, 24), 12756, {1.5 * pow(10, 11), 0}, {0, 29800}, {0, 0}},
    {"Mars", 6.39 * pow(10, 23), 6792, {0, -2.23 * pow(10, 11)}, {24007, 0}, {0, 0}}
};

void draw_planets(FILE *fp) {
    for (int i = 0; i < NO_OF_PLANETS; i++) {
        double size = log(planets[i].diameter) / 7;
        fprintf(fp, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" />\n",
                (planets[i].pos.x * SCALE) + (WIDTH / 2) + MARGIN, (planets[i].pos.y * SCALE) + (HEIGHT / 2) + MARGIN,
                size, strcmp(planets[i].name, "Sun") == 0 ? "yellow" : "grey");
    }
}

void calculate_force() {
    for (int i = 0; i < NO_OF_PLANETS; i++) {
        planets[i].force.x = 0;
        planets[i].force.y = 0;
        for (int j = 0; j < NO_OF_PLANETS; j++) {
            if (i != j) {
                double x_diff = planets[j].pos.x - planets[i].pos.x;
                double y_diff = planets[j].pos.y - planets[i].pos.y;
                double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
                double f = (G * planets[i].mass * planets[j].mass) / pow(distance, 2);
                planets[i].force.x += f * (x_diff / distance);
                planets[i].force.y += f * (y_diff / distance);
            }
        }
    }
}

void calculate_velocity() {
    for (int i = 0; i < NO_OF_PLANETS; i++) {
        double acc_x = planets[i].force.x / planets[i].mass;
        double acc_y = planets[i].force.y / planets[i].mass;
        planets[i].vel.x += acc_x;
        planets[i].vel.y += acc_y;
    }
}

void calculate_position() {
    for (int i = 0; i < NO_OF_PLANETS; i++) {
        planets[i].pos.x += planets[i].vel.x;
        planets[i].pos.y += planets[i].vel.y;
    }
}

int main() {
    FILE *output_file = fopen("solar_system.svg", "w");
    fprintf(output_file, "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n\n");
    fprintf(output_file, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", (WIDTH + 2 * MARGIN), (HEIGHT + 2 * MARGIN), (WIDTH + 2 * MARGIN), (HEIGHT + 2 * MARGIN));
    
    calculate_force();
    calculate_velocity();
    calculate_position();
    draw_planets(output_file);
    
    fprintf(output_file, "</svg>");
    fclose(output_file);
    
    return 0;
}