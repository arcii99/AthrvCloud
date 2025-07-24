//FormAI DATASET v1.0 Category: Smart home light control ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define MAX_LIGHTS 10
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0
#define MAX_TIME 23
#define MIN_TIME 0

// Define light struct
typedef struct Light {
    int id;
    int brightness;
    bool isOn;
    bool isDimmable;
} Light;

// Define time struct
typedef struct Time {
    int hour;
    int minute;
} Time;

// Define function prototypes
void printWelcomeMessage();
void printMainMenu();
void turnAllLightsOff(Light lights[], int numLights);
void turnAllLightsOn(Light lights[], int numLights);
void toggleAllLights(Light lights[], int numLights);
void setBrightness(Light *light, int brightness);
void toggleLight(Light *light);
void printAllLights(Light lights[], int numLights);
void printLight(Light light);
Light* selectLight(Light lights[], int numLights);
void setTimer(Light *light, Time *timer);
bool isTimeInRange(Time *time, Time *start, Time *end);

int main() {
    // Initialize lights
    Light lights[MAX_LIGHTS];
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].brightness = MAX_BRIGHTNESS;
        lights[i].isOn = false;
        lights[i].isDimmable = true;
    }

    // Initialize timer
    Time timerStart = {19, 0};
    Time timerEnd = {21, 0};
    Time currentTime;

    // Display welcome message and main menu
    printWelcomeMessage();
    printMainMenu();

    // Loop for user input
    char userInput;
    while (scanf(" %c", &userInput) == 1) {
        printf("\n");

        switch (userInput) {
            case '1':
                // Turn all lights off
                turnAllLightsOff(lights, MAX_LIGHTS);
                break;
            case '2':
                // Turn all lights on
                turnAllLightsOn(lights, MAX_LIGHTS);
                break;
            case '3':
                // Toggle all lights
                toggleAllLights(lights, MAX_LIGHTS);
                break;
            case '4':
                // Set brightness
                printAllLights(lights, MAX_LIGHTS);
                Light *selectedLight = selectLight(lights, MAX_LIGHTS);
                int brightness;
                printf("Enter brightness level (0-255): ");
                scanf("%d", &brightness);
                setBrightness(selectedLight, brightness);
                break;
            case '5':
                // Toggle light
                printAllLights(lights, MAX_LIGHTS);
                selectedLight = selectLight(lights, MAX_LIGHTS);
                toggleLight(selectedLight);
                break;
            case '6':
                // Print all lights
                printAllLights(lights, MAX_LIGHTS);
                break;
            case '7':
                // Set timer
                printf("Enter start time (HH:MM, 24 hour clock): ");
                scanf("%d:%d", &(timerStart.hour), &(timerStart.minute));
                printf("Enter end time (HH:MM, 24 hour clock): ");
                scanf("%d:%d", &(timerEnd.hour), &(timerEnd.minute));
                break;
            case '8':
                // Check timer
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                currentTime.hour = tm.tm_hour;
                currentTime.minute = tm.tm_min;
                if (isTimeInRange(&currentTime, &timerStart, &timerEnd)) {
                    turnAllLightsOn(lights, MAX_LIGHTS);
                } else {
                    turnAllLightsOff(lights, MAX_LIGHTS);
                }
                break;
            default:
                printf("Invalid input, try again.\n");
        }

        // Print main menu again
        printMainMenu();
    }

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to Smart Home Light Control!\n\n");
}

void printMainMenu() {
    printf("Options:\n");
    printf("1. Turn all lights off\n");
    printf("2. Turn all lights on\n");
    printf("3. Toggle all lights\n");
    printf("4. Set brightness for a light\n");
    printf("5. Toggle a light\n");
    printf("6. Print all lights\n");
    printf("7. Set timer for lights\n");
    printf("8. Check timer for lights\n");
    printf("Enter option number: ");
}

void turnAllLightsOff(Light lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].isOn = false;
    }
    printf("All lights turned off.\n");
}

void turnAllLightsOn(Light lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].isOn = true;
    }
    printf("All lights turned on.\n");
}

void toggleAllLights(Light lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        toggleLight(&lights[i]);
    }
    printf("All lights toggled.\n");
}

void setBrightness(Light *light, int brightness) {
    if (brightness < MIN_BRIGHTNESS) {
        brightness = MIN_BRIGHTNESS;
    } else if (brightness > MAX_BRIGHTNESS) {
        brightness = MAX_BRIGHTNESS;
    }
    light->brightness = brightness;
    printf("Brightness for light %d set to %d.\n", light->id, light->brightness);
}

void toggleLight(Light *light) {
    light->isOn = !light->isOn;
    printf("Light %d toggled.\n", light->id);
}

void printAllLights(Light lights[], int numLights) {
    printf("Lights:\n");
    for (int i = 0; i < numLights; i++) {
        printLight(lights[i]);
    }
}

void printLight(Light light) {
    printf("ID: %d | Brightness: %d | ", light.id, light.brightness);
    if (light.isOn) {
        printf("On\n");
    } else {
        printf("Off\n");
    }
}

Light* selectLight(Light lights[], int numLights) {
    int selection;
    printf("Enter light ID: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > numLights) {
        printf("Invalid light ID, please try again.\n");
        return selectLight(lights, numLights);
    }
    return &lights[selection - 1];
}

void setTimer(Light *light, Time *timer) {
    printf("Set timer for light %d\n", light->id);
    printf("Enter start time (HH:MM, 24 hour clock): ");
    scanf("%d:%d", &(timer->hour), &(timer->minute));
}

bool isTimeInRange(Time *time, Time *start, Time *end) {
    if (start->hour < end->hour) {
        if (time->hour < start->hour || time->hour > end->hour) {
            return false;
        } else if (time->hour == start->hour && time->minute < start->minute) {
            return false;
        } else if (time->hour == end->hour && time->minute > end->minute) {
            return false;
        } else {
            return true;
        }
    } else if (start->hour > end->hour) {
        if (time->hour < end->hour || time->hour > start->hour) {
            return true;
        } else if (time->hour == start->hour && time->minute >= start->minute) {
            return true;
        } else if (time->hour == end->hour && time->minute <= end->minute) {
            return true;
        } else {
            return false;
        }
    } else {
        if (time->hour == start->hour && time->minute >= start->minute && time->minute <= end->minute) {
            return true;
        } else {
            return false;
        }
    }
}