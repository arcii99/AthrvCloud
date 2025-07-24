//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include <stdio.h>

// Function to simulate the circuit
void simulate_circuit(int voltage, int current) {
    int resistance = voltage/current;

    printf("The resistance of the circuit is %d ohms!\n", resistance);

    if (resistance < 10) {
        printf("The circuit is so easy, even a kitten could understand it!\n");
    } else if (resistance >= 10 && resistance < 50) {
        printf("The circuit is pretty simple, but it's no walk in the park!\n");
    } else {
        printf("The circuit is complex, but nothing we can't handle!\n");
    }

    printf("Let's fire it up and see what happens...\n");

    if (voltage > 5) {
        printf("Wow, this thing really packs a punch! The voltage is %d volts!\n", voltage);
    } else {
        printf("Hmm, something seems off... the voltage is only %d volts.\n", voltage);
    }

    printf("Thanks for using our circuit simulator! Have a happy day!\n");
}

// Main function to execute the program
int main() {
    int voltage, current;

    printf("Welcome to our happy circuit simulator! Please enter the voltage (in volts) and current (in amps) of your circuit:\n");

    scanf("%d %d", &voltage, &current);

    printf("Great! Let's get started...\n");

    simulate_circuit(voltage, current);

    return 0;
}