//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>

// Defining our recursive function
int solve_case(int suspects_left, int guilty_person) {

    // If there's only one suspect left, return them as the guilty person
    if(suspects_left == 1) {
        return guilty_person;
    }

    // Otherwise, we eliminate a suspect using the recursive function
    int new_suspects = suspects_left - 1;
    int new_guilty_person = (guilty_person + 1) % suspects_left;
    return solve_case(new_suspects, new_guilty_person);
}

int main() {

    int num_suspects = 5; // Change this number to fit your case
    int guilty_suspect = 2; // Change this number to fit your case

    int guilty_person = solve_case(num_suspects, guilty_suspect);

    // Finding the guilty person using our recursive function
    printf("The guilty person is: %d\n", guilty_person);

    return 0;
}