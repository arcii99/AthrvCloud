//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RESIDUES 20
#define NUM_TRIALS 1000

float energies[NUM_RESIDUES][NUM_RESIDUES] = {
    /* energies[i][j] is the energy to move from state i to state j. 
    In real proteins, this is a function of the position, orientation, and 
    neighboring residue identities. */
    // In this example, we set each energy to be a random number between 0 and 1.
};

void sample_conformation(int conformation[NUM_RESIDUES]){
    /* Generate a random conformation by selecting a random starting state,
    and then randomly selecting the next state using the energy matrix. */

    int i, current_state;
    float energy_cutoff;
    float prob_dist[NUM_RESIDUES] = {0};
    float energy_sum = 0;
    srand(time(NULL));

    // Choose a random starting state
    current_state = rand() % NUM_RESIDUES;
    conformation[0] = current_state;

    // Sample the rest of the conformation
    for (i = 1; i < NUM_RESIDUES; i++){
        // Compute the probability distribution over possible next states
        energy_cutoff = (float) rand() / RAND_MAX;
        for (int j=0; j < NUM_RESIDUES; j++){
            prob_dist[j] = energies[current_state][j];
            energy_sum += prob_dist[j];
        }
        for (int j=0; j < NUM_RESIDUES; j++){
            prob_dist[j] /= energy_sum;
        }

        // Choose the next state at random using the probability distribution
        energy_cutoff *= energy_sum;
        energy_sum = 0;
        for (int j=0; j < NUM_RESIDUES; j++){
            energy_sum += prob_dist[j];
            if (energy_cutoff <= energy_sum){
                current_state = j;
                break;
            }
        }

        // Record the new state
        conformation[i] = current_state;
    }
}

int main(){
    int i, conformation[NUM_RESIDUES];
    float total_energy = 0;

    // Generate NUM_TRIALS conformations randomly and compute their energies
    for (i = 0; i < NUM_TRIALS; i++){
        sample_conformation(conformation);
        for (int j=1; j < NUM_RESIDUES; j++){
            total_energy += energies[conformation[j-1]][conformation[j]];
        }
    }

    // Report the average energy per residue
    printf("The average energy per residue is %.2f\n", total_energy / (NUM_TRIALS * NUM_RESIDUES));
    return 0;
}