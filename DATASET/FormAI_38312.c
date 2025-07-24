//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initialize random seed

    // list of possible fortunes
    char* fortunes[] = {
        "You will find success in your future endeavors.",
        "Love is in the air. Keep your eyes open for new opportunities.",
        "Your hard work will pay off soon.",
        "Watch out for unexpected travel in your future.",
        "Good news is on the horizon. Keep your head up.",
        "A new chapter in your life is about to begin.",
        "Be careful of those around you. Trust your instincts.",
        "A financial windfall is coming your way.",
        "Your creativity will lead to great success.",
        "Take a risk. The rewards will be worth it."
    };
    int num_fortunes = 10; // number of possible fortunes

    // generate random fortune
    int index = rand() % num_fortunes;
    char* fortune = fortunes[index];

    // print fortune
    printf("Welcome to the Automated Fortune Teller\n");
    printf("Your fortune for today is:\n");
    printf("%s\n", fortune);

    return 0;
}