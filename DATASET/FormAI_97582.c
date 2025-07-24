//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct
{
    double x;   // x-coordinate
    double y;   // y-coordinate
    double z;   // z-coordinate
    double vx;  // velocity along x-axis
    double vy;  // velocity along y-axis
    double vz;  // velocity along z-axis
    double mass;    // mass of the object
} Object;

void update_velocity(Object *object, Object *other_object, double time_step)
{
    double dx = other_object->x - object->x;
    double dy = other_object->y - object->y;
    double dz = other_object->z - object->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force_magnitude = G * object->mass * other_object->mass / (distance*distance);
    double force_x = force_magnitude * dx / distance;
    double force_y = force_magnitude * dy / distance;
    double force_z = force_magnitude * dz / distance;
    double acceleration_x = force_x / object->mass;
    double acceleration_y = force_y / object->mass;
    double acceleration_z = force_z / object->mass;
    object->vx += acceleration_x * time_step;
    object->vy += acceleration_y * time_step;
    object->vz += acceleration_z * time_step;
}

void update_position(Object *object, double time_step)
{
    object->x += object->vx * time_step;
    object->y += object->vy * time_step;
    object->z += object->vz * time_step;
}

void simulate(Object objects[], int num_objects, double duration, double time_step)
{
    for (double t = 0; t < duration; t += time_step)
    {
        for (int i = 0; i < num_objects; i++)
        {
            for (int j = 0; j < num_objects; j++)
            {
                if (i != j)
                {
                    update_velocity(&objects[i], &objects[j], time_step);
                }
            }
        }

        for (int i = 0; i < num_objects; i++)
        {
            update_position(&objects[i], time_step);
        }

        printf("Time: %f\n", t);

        for (int i = 0; i < num_objects; i++)
        {
            printf("Object %d (x, y, z) = (%f, %f, %f)\n", i+1, objects[i].x, objects[i].y, objects[i].z);
        }
    }
}

int main()
{
    Object objects[] = {
        {0, 0, 0, 0, 0, 0, 5.972e24},
        {0, 6371000, 0, 7800, 0, 0, 1000},
        {0, -6371000, 0, -7800, 0, 0, 1000},
        {6371000, 0, 0, 0, 7700, 0, 1000},
        {-6371000, 0, 0, 0, -7700, 0, 1000},
        {0, 0, 6371000, 0, 0, 7700, 1000},
        {0, 0, -6371000, 0, 0, -7700, 1000}
    };

    int num_objects = sizeof(objects) / sizeof(objects[0]);

    simulate(objects, num_objects, 86400, 60);

    return 0;
}