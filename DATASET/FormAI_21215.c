//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t light_id;
    bool is_on;
    float intensity;
} Light;

typedef struct
{
    Light* lights;
    uint32_t num_lights;
} House;

void change_light_status(Light* light, bool is_on)
{
    light->is_on = is_on;
}

void change_light_intensity(Light* light, float intensity)
{
    light->intensity = intensity;
}

void print_all_lights_status(House* house)
{
    printf("Current light status:\n");
    for (uint32_t i = 0; i < house->num_lights; i++)
    {
        printf("Light %d: %s, %f\n", house->lights[i].light_id, house->lights[i].is_on ? "ON" : "OFF", house->lights[i].intensity);
    }
}

int main(void)
{
    // Initialize house and lights
    House h = {
        .lights = (Light[]) {
            {.light_id = 0, .is_on = false, .intensity = 0.0},
            {.light_id = 1, .is_on = false, .intensity = 0.0},
            {.light_id = 2, .is_on = false, .intensity = 0.0},
            {.light_id = 3, .is_on = false, .intensity = 0.0},
            {.light_id = 4, .is_on = false, .intensity = 0.0}
        },
        .num_lights = 5
    };

    // Print initial status
    print_all_lights_status(&h);

    // Turn on light 2 and set intensity to 0.5
    change_light_status(&(h.lights[2]), true);
    change_light_intensity(&(h.lights[2]), 0.5);

    // Print updated status
    print_all_lights_status(&h);

    return EXIT_SUCCESS;
}