//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define g 9.8 // acceleration due to gravity

int main(){
    float x0, y0, v0, angle, t, vx0, vy0, x, y;
    float pi = 3.14159265;
    
    printf("Enter the initial X position of the projectile (in meters): ");
    scanf("%f", &x0);
    
    printf("Enter the initial Y position of the projectile (in meters): ");
    scanf("%f", &y0);
    
    printf("Enter the initial velocity of the projectile (in meters per second): ");
    scanf("%f", &v0);
    
    printf("Enter the angle of projection of the projectile (in degrees): ");
    scanf("%f", &angle);
    
    angle = angle * pi / 180; //convert angle to radians
    
    vx0 = v0 * cos(angle);
    vy0 = v0 * sin(angle);
    
    t = 0; //initial time
    
    printf("\n\nTime\tX-coordinate\tY-coordinate\n"); //print table headers
    
    while(y >= 0){ // while projectile is above ground
        
        x = x0 + vx0 * t;
        y = y0 + vy0 * t - 0.5 * g * pow(t, 2);
        printf("%.2f\t\t%.2f\t\t%.2f\n", t, x, y); //print current values
        
        t += 0.1; //increment time by 0.1s
    }
    
    printf("\nProjectile hit the ground at %.2f meters from the initial position.\n", x); //print distance travelled
    
    return 0;
}