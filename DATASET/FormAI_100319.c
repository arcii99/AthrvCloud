//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function declaration */
void generate_conspiracy_theory();

/* Main function */
int main()
{   
    // Initialize random seed
    srand(time(NULL));

    // Generate 5 conspiracy theories
    for(int i=0; i<5; i++){
        generate_conspiracy_theory();
    }

    return 0;
}

/* Function definition */
void generate_conspiracy_theory(){
    // Arrays containing conspiracy theory elements
    char *company[5] = {"Microsoft", "Apple", "Google", "Amazon", "Facebook"};
    char *activity[5] = {"monitoring our phones", "infiltrating our dreams", "reading our minds", "controlling our emotions", "spying on our thoughts"};
    char *coverup[5] = {"aliens", "Illuminati", "Bigfoot", "time-travelers", "shape-shifters"};

    // Generate random indexes for each array
    int comp_idx = rand() % 5;
    int act_idx = rand() % 5;
    int cov_idx = rand() % 5;

    // Print the conspiracy theory
    printf("The %s is %s to cover up their involvement with %s. Stay woke!\n", company[comp_idx], activity[act_idx], coverup[cov_idx]);
}