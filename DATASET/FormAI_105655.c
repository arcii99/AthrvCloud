//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of lights that can be controlled */
#define MAX_LIGHTS 10

/* Define the light structure */
typedef struct
{
    int id;
    char name[50];
    int isOn;
} Light;

/* Define the smart home hub structure */
typedef struct
{
    Light lights[MAX_LIGHTS];
    int numLights;
} SmartHomeHub;

/* Define the function to add a new light to the hub */
void addLight(SmartHomeHub *hub, char *name)
{
    /* Check if the maximum number of lights has been reached */
    if(hub->numLights >= MAX_LIGHTS)
    {
        printf("Error: Maximum number of lights exceeded!\n");
        return;
    }

    /* Create a new light object */
    Light light;
    light.id = hub->numLights + 1;
    strcpy(light.name, name);
    light.isOn = 0;

    /* Add the new light to the hub */
    hub->lights[hub->numLights] = light;
    hub->numLights++;

    printf("New light added: %s (id=%d)\n", name, light.id);
}

/* Define the function to turn a light on */
void turnOnLight(SmartHomeHub *hub, int id)
{
    /* Find the light with the specified id */
    Light *light = NULL;
    for(int i=0; i<hub->numLights; i++)
    {
        if(hub->lights[i].id == id)
        {
            light = &hub->lights[i];
            break;
        }
    }

    /* Check if the light was found */
    if(light == NULL)
    {
        printf("Error: Light with id=%d not found!\n", id);
        return;
    }

    /* Turn the light on */
    light->isOn = 1;
    printf("Light %s (id=%d) turned on.\n", light->name, id);
}

/* Define the function to turn a light off */
void turnOffLight(SmartHomeHub *hub, int id)
{
    /* Find the light with the specified id */
    Light *light = NULL;
    for(int i=0; i<hub->numLights; i++)
    {
        if(hub->lights[i].id == id)
        {
            light = &hub->lights[i];
            break;
        }
    }

    /* Check if the light was found */
    if(light == NULL)
    {
        printf("Error: Light with id=%d not found!\n", id);
        return;
    }

    /* Turn the light off */
    light->isOn = 0;
    printf("Light %s (id=%d) turned off.\n", light->name, id);
}

int main()
{
    /* Create a new smart home hub */
    SmartHomeHub hub;
    hub.numLights = 0;

    /* Add some lights */
    addLight(&hub, "Living Room");
    addLight(&hub, "Kitchen");
    addLight(&hub, "Bedroom");

    /* Turn some lights on and off */
    turnOnLight(&hub, 1);
    turnOffLight(&hub, 2);
    turnOnLight(&hub, 3);

    return 0;
}