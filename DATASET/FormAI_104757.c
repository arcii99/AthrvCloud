//FormAI DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    int time;
    printf("What time is it? (in 24 hour format)\n");
    scanf("%d", &time);

    if (time >= 6 && time < 9) {
        printf("Good morning! Turning on the lights in the living room and kitchen.\n");
        system("smart_home_light_control LIVING_ROOM ON");
        system("smart_home_light_control KITCHEN ON");
    }
    else if (time >= 9 && time < 18) {
        printf("It's day time. Turning off all lights except those in the study room.\n");
        system("smart_home_light_control LIVING_ROOM OFF");
        system("smart_home_light_control KITCHEN OFF");
        system("smart_home_light_control BEDROOM OFF");
        system("smart_home_light_control BATHROOM OFF");
        system("smart_home_light_control STUDY_ROOM ON");
    }
    else if (time >= 18 && time < 22) {
        printf("Good evening! Turning on the lights in the living room, kitchen, bedroom and bathroom.\n");
        system("smart_home_light_control LIVING_ROOM ON");
        system("smart_home_light_control KITCHEN ON");
        system("smart_home_light_control BEDROOM ON");
        system("smart_home_light_control BATHROOM ON");
        system("smart_home_light_control STUDY_ROOM OFF");
    }
    else {
        printf("Good night. Turning off all lights.\n");
        system("smart_home_light_control LIVING_ROOM OFF");
        system("smart_home_light_control KITCHEN OFF");
        system("smart_home_light_control BEDROOM OFF");
        system("smart_home_light_control BATHROOM OFF");
        system("smart_home_light_control STUDY_ROOM OFF");
    }

    return 0;
}