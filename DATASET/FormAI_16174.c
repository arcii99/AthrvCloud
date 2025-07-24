//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // define arrays of conspiracy theories
    char *theories[] = {
        "The moon landing was faked.",
        "Vaccines cause autism.",
        "The government controls the weather.",
        "9/11 was an inside job.",
        "Chemtrails are poisoning us.",
        "The Illuminati controls everything."
    };
    char *proofs[] = {
        "There are no stars in the moon landing footage.",
        "Some children develop autism shortly after being vaccinated.",
        "The government has patents for weather manipulation technology.",
        "Building 7 collapsed without any obvious reason.",
        "Airplane contrails stay in the sky for long periods of time.",
        "Numerous public figures have been photographed making Illuminati hand gestures."
    };
    char *facts[] = {
        "NASA is known for doctoring photos.",
        "Scientific studies have shown no link between vaccines and autism.",
        "There is no conclusive evidence that the government controls the weather.",
        "Some experts believe that the collapse of Building 7 was caused by controlled demolition.",
        "Contrails are simply composed of water vapor.",
        "There is no evidence that the Illuminati exists."
    };

    // generate random index
    int index = rand() % 6;

    // print random conspiracy theory and supporting "proof" and "fact"
    printf("Did you know that... %s\nThis is proven by the fact that... %s\nBut the real truth is that... %s\n",
           theories[index], proofs[index], facts[index]);

    return 0;
}