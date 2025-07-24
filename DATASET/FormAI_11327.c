//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>

void exploration(int planet_count) {
    int surface_rockiness;
    printf("Exploring planet %d\n", planet_count);
    printf("How rocky does the surface look?(1-10): ");
    scanf("%d", &surface_rockiness);

    if(surface_rockiness < 5) {
        printf("This planet seems to have a fairly smooth surface. ");
    }
    else if(surface_rockiness >= 5 && surface_rockiness < 8) {
        printf("The surface of this planet looks quite rocky. ");
    }
    else {
        printf("This planet appears to have a very rough surface. ");
    }

    int choice;
    printf("Do you want to explore another planet? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if(choice == 1) {
        exploration(planet_count+1);
    }
    else {
        printf("Ending the mission. Returning to base.\n");
    }
}

int main() {
    printf("Preparing for space exploration mission.\n");
    exploration(1);
    return 0;
}