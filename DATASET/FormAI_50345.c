//FormAI DATASET v1.0 Category: Computer Biology ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

/* This program simulates the interactions between two species of organisms in a peaceful ecosystem */

struct organism{
    char* name; // The name of the organism
    int population; // Current population of the organism
    float reproduction_rate; // Rate at which the organism reproduces
    float predation_rate; // Rate at which the organism is preyed upon
};

void print_population(struct organism* org){
    printf("%s population: %d\n", org->name, org->population);
}

int main(){
    struct organism species1 = {"Rabbits", 1000, 0.1, 0.05};
    struct organism species2 = {"Foxes", 50, 0.05, 0.1};

    printf("Initial ecosystem population:\n");
    print_population(&species1);
    print_population(&species2);

    // Run the simulation for 10 years
    for(int year = 1; year <= 10; year++){
        printf("\nYear %d:\n", year);

        // Calculate new populations
        int old_species1_pop = species1.population;
        species1.population += species1.reproduction_rate * species1.population - species2.predation_rate * species1.population;
        species2.population += species2.reproduction_rate * species2.population - species1.predation_rate * species2.population;

        printf("New ecosystem population:\n");
        print_population(&species1);
        print_population(&species2);

        // Check if one species has gone extinct
        if(species1.population == 0){
            printf("The %s have gone extinct. The %s thrive in peace.\n", species1.name, species2.name);
            exit(0);
        }
        else if(species2.population == 0){
            printf("The %s have gone extinct. The %s thrive in peace.\n", species2.name, species1.name);
            exit(0);
        }

        // Check if one species has overtaken the other
        if(species1.population > old_species1_pop && species2.population <= old_species1_pop){
            printf("The %s are flourishing. The %s population has been reduced.\n", species1.name, species2.name);
        }
        else if(species2.population > old_species1_pop && species1.population <= old_species1_pop){
            printf("The %s are flourishing. The %s population has been reduced.\n", species2.name, species1.name);
        }
    }

    printf("\nThe %s and %s thrive in a peaceful ecosystem!\n", species1.name, species2.name);
    return 0;
}