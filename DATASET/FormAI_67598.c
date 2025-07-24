//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

//Function to randomly generate the Wi-Fi signal strength
int rand_wifi_strength() {
    return rand() % 101;
}

//Function to print the Wi-Fi signal strength with appropriate bar chart
void print_wifi_strength(int strength) {
    int num_bars = strength / 10;
    printf("Signal Strength: [%-10.*s] %d%%\n", num_bars, "||||||||||", strength);
}

//Main Function
int main() {
    srand(time(NULL)); //Initialize random seed
    
    //Loop to generate Wi-Fi signal strength and print it
    while(1) {
        int strength = rand_wifi_strength();
        print_wifi_strength(strength);
        
        //Delay of 1 second
        sleep(1);
    }

    return 0; //Program finished successfully
}