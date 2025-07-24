//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *conspiracy[10] = {"The government is hiding evidence of aliens","The moon landing was fake","Bigfoot is a government experiment gone wrong",
                            "The Illuminati is controlling the world","The earth is flat","9/11 was an inside job",
                            "Chemtrails are poisoning us","The Bermuda Triangle is a portal to another dimension","Elvis is still alive",
                            "The Loch Ness Monster is a dinosaur"};

    char *evidence[10] = {"Top secret documents leaked to WikiLeaks","A whistleblower from the government","Eyewitness accounts",
                          "Crop circles","Mysterious disappearances of individuals","Unexplained technology",
                          "The Bible predicts it","Ancient prophecies from various cultures","Predictive programming in movies and TV shows",
                          "Suppressed scientific research"};

    char *explanation[10] = {"To distract from the failing economy","To promote a New World Order","To create chaos and confusion",
                             "To cover up the existence of other beings","To instill fear in the population","To further the agenda of a secret society",
                             "To exert control over the masses","To gain power and influence","To maintain the status quo",
                             "To prepare for an impending apocalypse"};

    srand(time(0));
    int rand_conspiracy = rand() % 10;
    int rand_evidence = rand() % 10;
    int rand_explanation = rand() % 10;

    printf("The conspiracy theory of the day is: \n");
    printf("%s\n", conspiracy[rand_conspiracy]);
    printf("Supported by evidence such as:\n");
    printf("%s\n", evidence[rand_evidence]);
    printf("Which could mean that:\n");
    printf("%s\n", explanation[rand_explanation]);

    return 0;
}