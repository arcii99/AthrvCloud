//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    srand(time(NULL));
    
    char subjects[10][50] = {"The government", "The Illuminati", "Big Pharma", "The Freemasons", "Aliens", "The NWO", "The Rothschilds", "The CIA", "The Vatican", "The Reptilians"};
    char actions[10][50] = {"is controlling", "is manipulating", "is brainwashing", "is conspiring with", "is hiding the truth about", "is experimenting with", "is behind", "is censoring", "is sabotaging", "is infiltrating"};
    char objects[10][50] = {"our minds", "the media", "our elections", "the economy", "our healthcare", "the education system", "the weather", "technology", "the food industry", "the entertainment industry"};

    int rand_subj = rand() % 10;
    int rand_act = rand() % 10;
    int rand_obj = rand() % 10;

    printf("%s %s %s!\n", subjects[rand_subj], actions[rand_act], objects[rand_obj]);

    printf("But that's not all...\n");
    
    char evidence[10][50] = {"There is indisputable proof", "Sources have confirmed", "Leaked documents reveal", "Whistleblowers have come forward", "Experts agree", "Researchers have discovered", "The internet is buzzing with rumors", "Insiders have revealed", "Journalists are investigating", "The ancient texts predict"};
    char claims[10][50] = {"a massive cover-up", "a sinister plot", "a secret agenda", "the end of the world", "a master plan", "a hidden truth", "a global conspiracy", "a shadow government", "a nefarious scheme", "an ominous prophecy"};

    int rand_evi = rand() % 10;
    int rand_clm = rand() % 10;

    printf("%s of %s involving %s!\n", evidence[rand_evi], claims[rand_clm], objects[rand_obj]);

    printf("What can we do about it? Keep spreading the truth, and most importantly,\n");
    
    char advice[10][50] = {"question everything", "stay vigilant", "take action", "educate others", "resist the lies", "prepare for the worst", "unite against the enemy", "expose the corruption", "fight for justice", "never give up"};

    int rand_adv = rand() % 10;

    printf("%s!\n", advice[rand_adv]);

    return 0;
}