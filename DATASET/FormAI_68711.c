//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67E-11   //Gravitational constant
#define AU 149.6E+9  //Astronomical unit
#define MASS_SUN 1.989E+30  //Mass of sun
#define VEL_SUN 0.0  //Velocity of sun
#define SCALE 250.0/AU  //Pixels per astronomical unit
#define X_MAX 800  //Max width of the window
#define Y_MAX 800  //Max height of the window

typedef struct planet {
    char *name;
    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;
    float mass;
    float radius;
    float color[3];
} Planet;

void initialize_planet(Planet *planet, char *name, float x_pos, float y_pos, 
float x_vel, float y_vel, float mass, float radius, float color[]) 
{
    planet->name = name;
    planet->x_pos = x_pos;
    planet->y_pos = y_pos;
    planet->x_vel = x_vel;
    planet->y_vel = y_vel;
    planet->mass = mass;
    planet->radius = radius;
    planet->color[0] = color[0];
    planet->color[1] = color[1];
    planet->color[2] = color[2];
}

void compute_force(Planet *planet1, Planet *planet2, float *x_force, float *y_force) 
{
    float dist, force;
    
    dist = sqrt(pow((planet2->x_pos - planet1->x_pos), 2) + pow((planet2->y_pos - planet1->y_pos), 2));
    force = (G * planet1->mass * planet2->mass) / pow(dist, 2);
    *x_force = force * (planet2->x_pos - planet1->x_pos) / dist;
    *y_force = force * (planet2->y_pos - planet1->y_pos) / dist;
}

void update_position(Planet *planet, float x_force, float y_force, float time_step) 
{
    float x_acc, y_acc;
    
    x_acc = x_force / planet->mass;
    y_acc = y_force / planet->mass;
    planet->x_vel += x_acc * time_step;
    planet->y_vel += y_acc * time_step;
    planet->x_pos += planet->x_vel * time_step;
    planet->y_pos += planet->y_vel * time_step;
}

void draw_planet(Planet *planet, FILE *output_file) 
{
    fprintf(output_file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d);\"/>\n",
    (int)(planet->x_pos * SCALE), (int)(planet->y_pos * SCALE), (int)planet->radius,
    (int)(planet->color[0]), (int)(planet->color[1]), (int)(planet->color[2]));
}

int main() 
{
    srand(time(NULL));
    
    FILE *output_file = fopen("solar_system.svg", "w");
    fprintf(output_file, "<svg width=\"%d\" height=\"%d\">\n", X_MAX, Y_MAX);
    
    Planet sun, earth, moon;
    initialize_planet(&sun, "Sun", 0.0, 0.0, VEL_SUN, VEL_SUN, MASS_SUN, 109.2, 
    (float[]){255.0, 255.0, 0.0});
    initialize_planet(&earth, "Earth", AU, 0.0, 0.0, 29.78E+3, 5.97E+24, 3.67, 
    (float[]){0.0, 0.0, 255.0});
    initialize_planet(&moon, "Moon", AU + 384.4E+6, 0.0, 0.0, 1.022E+3, 7.342E+22, 
    1.0, (float[]){220.0, 220.0, 220.0});
    
    float time_step = 3600.0;
    
    for (int i = 0; i < 31536000; i += (int)time_step) {
        fprintf(output_file, "<g transform=\"translate(%d,%d)\">\n", X_MAX/2, Y_MAX/2);
        draw_planet(&sun, output_file);
        draw_planet(&earth, output_file);
        compute_force(&sun, &earth, &earth.x_pos, &earth.y_pos);
        update_position(&earth, earth.x_pos, earth.y_pos, time_step);
        fprintf(output_file, "</g>\n");

        fprintf(output_file, "<g transform=\"translate(%d,%d)\">\n", (int)(X_MAX/2 +
        earth.x_pos * SCALE), (int)(Y_MAX/2));
        draw_planet(&moon, output_file);
        compute_force(&earth, &moon, &moon.x_pos, &moon.y_pos);
        update_position(&moon, moon.x_pos, moon.y_pos, time_step);
        fprintf(output_file, "</g>\n");
    }
    
    fprintf(output_file, "</svg>");
    fclose(output_file);
    
    return 0;
}