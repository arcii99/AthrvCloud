//FormAI DATASET v1.0 Category: Physics simulation ; Style: excited
//Hey there, physics enthusiasts! Are you ready for a mind-blowing simulation program? Let's dive in!

#include <stdio.h>
#include <math.h>

int main()
{
    float v_initial, v_final, time, acceleration, position;
    int choice;
    
    printf("Welcome to the physics simulator! Let's solve some cool problems today!\n\n");
    
    printf("Choose the problem you want to simulate:\n");
    printf("1. Motion with constant acceleration\n2. Projectile motion\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Good choice! Let's simulate a body in motion with constant acceleration!\n");
            printf("Enter the initial velocity (in m/s):\n");
            scanf("%f", &v_initial);
            printf("Enter the acceleration (in m/s^2):\n");
            scanf("%f", &acceleration);
            printf("Enter the time (in seconds):\n");
            scanf("%f", &time);
            
            v_final = v_initial + (acceleration * time);
            position = (v_initial * time) + (0.5 * acceleration * pow(time, 2));
            
            printf("\nThe final velocity of the body is %.2f m/s.\n", v_final);
            printf("The position of the body is %.2f m.\n", position);
            break;
            
        case 2:
            printf("Great choice! Let's simulate a projectile motion!\n");
            printf("Enter the initial velocity (in m/s):\n");
            scanf("%f", &v_initial);
            printf("Enter the angle of projection (in degrees):\n");
            float angle_degrees;
            scanf("%f", &angle_degrees);
            
            //converting degrees to radians
            float angle_radians = angle_degrees * M_PI / 180;
            printf("Enter the time of flight (in seconds):\n");
            scanf("%f", &time);
            
            float velocity_x = v_initial * cos(angle_radians);
            float velocity_y = v_initial * sin(angle_radians);
            
            float range = velocity_x * time;
            float height = (velocity_y * time) - (0.5 * 9.81 * pow(time, 2));
            
            printf("\nThe range of the projectile is %.2f m.\n", range);
            printf("The maximum height of the projectile is %.2f m.\n", height);
            break;
            
        default:
            printf("Oops! Invalid choice. Try again.\n");
    }
    
    printf("\nThank you for using the physics simulator!\n");
    printf("Keep exploring the amazing world of physics!\n");
    return 0;
}