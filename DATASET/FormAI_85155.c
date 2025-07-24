//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // Gravitational constant
#define M1 6e24     // Mass of Planet 1
#define M2 7.3e22   // Mass of Planet 2

#define ENTER_KEY 10
#define PAUSE_TIME 1000 // Sleep Time

double distance(double x1, double y1, double x2, double y2){
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

void clear_buffer(){
    while(getchar() != ENTER_KEY);
}

int main(){
    double x1, y1;  // Position of Planet 1
    double x2, y2;  // Position of Planet 2
    
    double vx1 = 0, vy1 = 0;  // Velocity of Planet 1
    double vx2 = 0, vy2 = 0;  // Velocity of Planet 2
    
    printf("Enter position of Planet 1 (x y): ");
    scanf("%lf %lf", &x1, &y1);
    clear_buffer();
    
    printf("Enter velocity of Planet 1 (vx vy): ");
    scanf("%lf %lf", &vx1, &vy1);
    clear_buffer();
    
    printf("\nEnter position of Planet 2 (x y): ");
    scanf("%lf %lf", &x2, &y2);
    clear_buffer();
    
    printf("Enter velocity of Planet 2 (vx vy): ");
    scanf("%lf %lf", &vx2, &vy2);
    clear_buffer();
    
    double t = 0;  // Simulation Time
    
    while(1){
        double r = distance(x1, y1, x2, y2);
        double F = G * M1 * M2 / (r * r);  // Gravitational Force
        
        double theta = atan2(y2 - y1, x2 - x1);
        double Fx = F * cos(theta);
        double Fy = F * sin(theta);
        
        double ax1 = Fx / M1, ay1 = Fy / M1;  // Acceleration of Planet 1
        double ax2 = -1 * Fx / M2, ay2 = -1 * Fy / M2;  // Acceleration of Planet 2
        
        vx1 += ax1, vy1 += ay1;  // Update Velocity of Planet 1
        vx2 += ax2, vy2 += ay2;  // Update Velocity of Planet 2
        
        x1 += vx1, y1 += vy1;  // Update Position of Planet 1
        x2 += vx2, y2 += vy2;  // Update Position of Planet 2
        
        printf("\nTime: %lf seconds\n\n", t);
        printf("Planet 1: (%lf, %lf)\n", x1, y1);
        printf("Velocity: (%lf, %lf)\n\n", vx1, vy1);
        
        printf("Planet 2: (%lf, %lf)\n", x2, y2);
        printf("Velocity: (%lf, %lf)\n\n", vx2, vy2);
        
        t += 1;  // Increase time by 1 second
        sleep(PAUSE_TIME);  // Wait for PAUSE_TIME seconds
    }
    
    return 0;
}