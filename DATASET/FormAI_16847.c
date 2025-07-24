//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: romantic
#include <stdio.h>

int main() {
    float sunX = 0, sunY = 0;
    float earthX = 150, earthY = 0;
    float moonX = 155, moonY = 0;
    float earthRadius = 10;
    float moonRadius = 5;
    float earthSpeed = 0.1;
    float moonSpeed = 0.2;
    
    printf("In a distant galaxy, there was a beautiful star called Sun\n");
    printf("It was surrounded by numerous planets and moons, but the most beautiful of all was Earth\n");
    printf("Earth was covered in lush green forests and blue oceans, making her the jewel of the Solar System\n");
    printf("And then, there was Moon, who was always by Earth's side, admiring her beauty\n\n");
    
    while(1) {
        // movement of Earth
        earthX = 150 * cos(earthSpeed) + sunX;
        earthY = 150 * sin(earthSpeed) + sunY;
        
        // movement of Moon
        moonX = 5 * cos(moonSpeed) + earthX;
        moonY = 5 * sin(moonSpeed) + earthY;
        
        // print the positions of Earth and Moon
        printf("Earth is at %.2f, %.2f\n", earthX, earthY);
        printf("Moon is at %.2f, %.2f\n", moonX, moonY);
        
        // update the speeds
        earthSpeed += 0.01;
        moonSpeed += 0.03;
    }
    
    return 0;
}