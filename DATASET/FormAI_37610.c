//FormAI DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<time.h> 

int main() 
{ 
    srand(time(NULL)); 
  
    // Initializing variables for firewall 
    int firewall_strength = 100; 
    int attack_strength = rand() % 100 + 1; 
    int defence_strength = rand() % 100 + 1; 
    int attack_chance = rand() % 10 + 1; 
    int defence_chance = rand() % 10 + 1; 
    int attacker_status, defender_status; 
    int rounds = 1; 
  
    // Game Loop 
    while (firewall_strength > 0) 
    { 
        printf("Round %d :\n", rounds); 
  
        // Attack 
        if (attack_chance > defence_chance) 
        { 
            printf("Attack is successful!\n"); 
            firewall_strength -= attack_strength; 
            printf("Firewall Strength : %d\n", firewall_strength); 
            attacker_status = 1; 
            defender_status = 0; 
        } 
        else 
        { 
            printf("Attack is blocked by firewall!\n"); 
            printf("Firewall Strength : %d\n", firewall_strength); 
            attacker_status = 0; 
            defender_status = 1; 
        } 
  
        // Defensive Mechanism 
        if (defence_chance > attack_chance) 
        { 
            printf("Defensive Mechanism is successful!\n"); 
            if (defence_strength >= attacker_status) 
            { 
                printf("Hackers are blocked successfully!\n"); 
            } 
            else 
            { 
                printf("Hackers are successful in attacking!\n"); // modifying the software 
                firewall_strength = firewall_strength - (2 * attack_strength); 
                printf("Firewall Strength : %d\n", firewall_strength); 
            } 
        } 
        else 
        { 
            printf("Defensive Mechanism failed!\n"); 
            if (defence_strength >= attacker_status) 
            { 
                printf("Hackers are blocked successfully!\n"); 
            } 
            else 
            { 
                printf("Hackers are successful in attacking!\n"); // modifying the software 
                firewall_strength = firewall_strength - (2 * attack_strength); 
                printf("Firewall Strength : %d\n", firewall_strength); 
            } 
        } 
  
        // Checking the final status 
        if (firewall_strength <= 0) 
        { 
            printf("\nFirewall is down!\n"); 
        } 
        else 
        { 
            printf("\nFirewall is safe!\n"); 
        } 
        rounds += 1;
    } 

    return 0; 
}