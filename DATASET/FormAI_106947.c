//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h> 

int main(void) 
{ 
    int num_bags, max_weight; 
    float bag_weight, total_weight = 0; 
    
    printf("Welcome to the airport baggage handling system simulation.\n"); 
    
    printf("Please enter the maximum allowed weight for a bag: "); 
    scanf("%d", &max_weight); 
    
    printf("How many bags do you want to simulate? "); 
    scanf("%d", &num_bags); 
    
    for(int i = 1; i <= num_bags; i++) 
    { 
        printf("Enter weight of bag %d in kg: ", i); 
        scanf("%f", &bag_weight); 
        
        if(bag_weight > max_weight) 
        { 
            printf("Sorry, the maximum allowed weight is %d kg.\n", max_weight); 
            printf("The bag could not be added to the system.\n"); 
        } 
        else 
        { 
            total_weight += bag_weight; 
            
            printf("Added bag %d to the system.\n", i); 
            printf("Total weight of bags in the system is now: %.2f kg.\n", total_weight); 
        } 
    } 
    
    printf("Simulation complete. Total weight of bags handled: %.2f kg\n", total_weight); 
    
    return 0; 
}