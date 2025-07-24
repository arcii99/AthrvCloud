//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

int main()
{
    float massA, massB, velocityA, velocityB, momentumA, momentumB, totalMomentum;
    float coefficientOfRestitution, finalVelocityA, finalVelocityB;
    float kineticEnergyInitial, kineticEnergyFinal, energyLost;
    
    printf("Enter the mass of object A: ");
    scanf("%f", &massA);
    
    printf("Enter the mass of object B: ");
    scanf("%f", &massB);
    
    printf("Enter the velocity of object A: ");
    scanf("%f", &velocityA);
    
    printf("Enter the velocity of object B: ");
    scanf("%f", &velocityB);
    
    printf("Enter the coefficient of restitution: ");
    scanf("%f", &coefficientOfRestitution);
    
    momentumA = massA * velocityA;
    momentumB = massB * velocityB;
    totalMomentum = momentumA + momentumB;
    
    printf("\nInitial momentum of the system: %.2f kg m/s", totalMomentum);
    
    finalVelocityA = ((coefficientOfRestitution * massB * (velocityB - velocityA)) + (massA * velocityA) + (massB * velocityB)) / (massA + massB);
    
    finalVelocityB = ((coefficientOfRestitution * massA * (velocityA - velocityB)) + (massA * velocityA) + (massB * velocityB)) / (massA + massB);
    
    kineticEnergyInitial = (0.5 * massA * pow(velocityA, 2)) + (0.5 * massB * pow(velocityB, 2));
    
    kineticEnergyFinal = (0.5 * massA * pow(finalVelocityA, 2)) + (0.5 * massB * pow(finalVelocityB, 2));
    
    energyLost = kineticEnergyInitial - kineticEnergyFinal;
    
    printf("\nFinal velocity of object A: %.2f m/s", finalVelocityA);
    
    printf("\nFinal velocity of object B: %.2f m/s", finalVelocityB);
    
    printf("\nEnergy lost during collision: %.2f J", energyLost);
    
    return 0;
}