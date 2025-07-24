//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to calculate probability of an alien invasion
double alien_invasion_prob(int n, int m, int k, double p) {
    double prob = 0.0; //initializing probability to be zero
    int i, j;
    //looping over all possible invasion scenarios
    for(i=0; i<k; i++) {
        double temp_prob = 1.0;
        for(j=0; j<n; j++) {
            double q = (double)rand()/RAND_MAX; //generating random number between 0 and 1
            if(q<p) { //alien invasion happens
                temp_prob *= m; //probability of invasion in this scenario is m
            }
            else { //alien invasion does not happen
                temp_prob *= (1-m); //probability of no invasion is 1-m
            }
        }
        prob += temp_prob; //updating probability of invasion 
    }
    return prob;
}

int main() {
    int n, m, k; //variables to take input values from user
    double p;
    //taking input values from user
    printf("Enter the number of planets in galaxy (n): ");
    scanf("%d", &n);
    printf("Enter the probability of alien invasion (p): ");
    scanf("%lf", &p);
    printf("Enter the probability of success of any invasion attempt (m): ");
    scanf("%d", &m);
    printf("Enter the number of times to repeat the invasion scenarios (k): ");
    scanf("%d", &k);
    //setting seed value for random number generator
    srand(time(0));
    //calling function to calculate probability of alien invasion
    double prob = alien_invasion_prob(n, m, k, p);
    //printing the calculated probability
    printf("Probability of alien invasion = %lf\n", prob);
    return 0;
}