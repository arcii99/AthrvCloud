//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

int main()
{
    double massA = 5.0; // Mass of object A in kg
    double massB = 10.0; // Mass of object B in kg
    double velocityA = 15.0; // Velocity of object A in m/s
    double velocityB = -10.0; // Velocity of object B in m/s
    double restitution = 0.5; // Coefficient of restitution
    
    double momentumA = massA * velocityA; // Calculate the momentum of object A
    double momentumB = massB * velocityB; // Calculate the momentum of object B
    
    double totalMomentum = momentumA + momentumB; // Calculate the total momentum of the system
    
    // Calculate the velocities of the objects after collision
    double velocityAAfter = ((massA - restitution*massB)*velocityA + (1 + restitution)*massB*velocityB)/ (massA + massB);
    double velocityBAfter = ((massB - restitution*massA)*velocityB + (1 + restitution)*massA*velocityA)/ (massA + massB);
    
    // Calculate the kinetic energy of the system before collision
    double kineticEnergyBefore = 0.5 * massA * velocityA * velocityA + 0.5 * massB * velocityB * velocityB;
    
    // Calculate the kinetic energy of the system after collision
    double kineticEnergyAfter = 0.5 * massA * velocityAAfter * velocityAAfter + 0.5 * massB * velocityBAfter * velocityBAfter;
    
    // Print the results
    printf("Mass of object A: %fkg\n", massA);
    printf("Mass of object B: %fkg\n", massB);
    printf("Velocity of object A before collision: %fm/s\n", velocityA);
    printf("Velocity of object B before collision: %fm/s\n", velocityB);
    printf("Coefficient of restitution: %f\n", restitution);
    printf("Total momentum of the system before collision: %fkgm/s\n", totalMomentum);
    printf("Velocity of object A after collision: %fm/s\n", velocityAAfter);
    printf("Velocity of object B after collision: %fm/s\n", velocityBAfter);
    printf("Kinetic energy of the system before collision: %fJ\n", kineticEnergyBefore);
    printf("Kinetic energy of the system after collision: %fJ\n", kineticEnergyAfter);
    
    return 0;
}