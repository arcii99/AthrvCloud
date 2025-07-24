//FormAI DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>
#include <stdbool.h>

// Structures for different home appliances
struct Light {
    bool isOn;
};

struct Fan {
    bool isOn;
    int speed; // 1, 2, 3
};

struct Refrigerator {
    bool isOn;
};

// Main function
int main(void)
{
    struct Light livingRoomLight = {false};
    struct Fan livingRoomFan = {false, 0};
    struct Refrigerator kitchenRefrigerator = {false};

    // Smart automation according to time of day
    int hour = 15;
    if (hour >= 9 && hour <= 17) {
        livingRoomLight.isOn = true;
        livingRoomFan.isOn = true;
        livingRoomFan.speed = 2;
    } else {
        livingRoomLight.isOn = false;
        livingRoomFan.isOn = false;
    }

    // Smart automation according to temperature
    float temperature = 28.5;
    if (temperature > 30) {
        livingRoomFan.isOn = true;
        livingRoomFan.speed = 3;
    } else if (temperature > 25) {
        livingRoomFan.isOn = true;
        livingRoomFan.speed = 2;
    } else if (temperature > 22) {
        livingRoomFan.isOn = true;
        livingRoomFan.speed = 1;
    }

    // Smart automation according to fridge usage
    int fridgeOpenCount = 0;
    if (fridgeOpenCount >= 5) {
        kitchenRefrigerator.isOn = false;
    }

    return 0;
}