//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    char* planets[8] = {"Mercury", "Venus", "Earth", "Mars",
                         "Jupiter", "Saturn", "Uranus", "Neptune"};
    double masses[8] = {0.330, 4.87, 5.97, 0.642,
                         1898, 568, 86.8, 102};
    double distances[8] = {0.39, 0.723, 1.0, 1.524,
                           5.203, 9.539, 19.18, 30.07};
                           
    printf("Welcome to the solar system simulation, my dear Watson!\n\n");
    printf("We have here the following planets:\n");
    for(int i = 0; i < 8; i++) {
        printf("%s\n", planets[i]);
    }
    
    char answer;
    do {
        printf("\nWhich planet would you like to investigate, my dear Watson?\n");
        char planet[20];
        scanf("%s", planet);
        int index = -1;
        for(int i = 0; i < 8; i++) {
            if(strcmp(planets[i], planet) == 0) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            printf("\nI am sorry, my dear Watson, but I could not find the planet you are looking for.\n");
        } else {
            double distance_from_sun = distances[index];
            double mass = masses[index];
            double gravitational_constant = 6.6743e-11;
            double mass_of_sun = 1.989e30;
            double force_of_gravity = gravitational_constant * mass_of_sun * mass / (distance_from_sun * distance_from_sun);
            printf("\nThe planet %s is %.2f million kilometers away from the sun.\n", planet, distance_from_sun * 149.6);
            printf("It has a mass of %.2f times the mass of Earth.\n", mass);
            printf("The force of gravity between it and the sun is %.2f newtons.\n", force_of_gravity);
        }
        
        printf("\nDo you want to investigate another planet, my dear Watson? (Y/N)\n");
        scanf(" %c", &answer);
    } while(answer != 'N' && answer != 'n');
    
    printf("\nThank you for exploring the solar system with me, my dear Watson!\n");
    return 0;
}