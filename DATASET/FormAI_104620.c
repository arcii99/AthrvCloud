//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int alien_invasion_probability, deaths, population;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Enter the current population of Earth: ");
    scanf("%d", &population);

    srand(time(0));
    alien_invasion_probability = rand() % 101; //generate a random number between 0-100
    
    printf("\nAlien invasion probability is %d%%\n", alien_invasion_probability);

    deaths = (alien_invasion_probability / 100.0) * population; //calculate the number of deaths
    
    printf("If an alien invasion occurs, approximately %d people will die.\n", deaths);

    if (deaths >= population) { //all humanity die
        printf("Unfortunately, the whole population will be wiped out. Humanity will cease to exist!\n");
    }
    else if (deaths >= (0.9 * population)) { //severe impact
        printf("The impact of the invasion will be severe. Our species will suffer greatly!\n");
    }
    else if (deaths >= (0.6 * population)) { //moderate impact
        printf("The impact of the invasion will be moderate. The human race will survive, but with significant losses.\n");
    }
    else if (deaths >= (0.3 * population)) { //minor impact
        printf("The impact of the invasion on the human population will be minor. Our species will recover quickly.\n");
    }
    else { //negligible impact
        printf("The impact of the invasion will be negligible, and humanity will continue to thrive as usual.\n");
    }

    return 0;
}