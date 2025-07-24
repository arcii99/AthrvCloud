//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char *subjects[] = {"the government", "aliens", "big pharma", "the illuminati", "the deep state", "the reptilians", "the Freemasons", "the CIA", "the FBI", "the NSA", "the New World Order"};
    char *verbs[] = {"is controlling", "is manipulating", "is experimenting on", "is brainwashing", "is monitoring", "is sabotaging", "is covering up", "is infiltrating", "is influencing", "is conspiring against"};
    char *objects[] = {"our thoughts", "the weather", "our food supply", "our water supply", "our elections", "our technology", "our media", "our education system", "our healthcare system", "our economy", "our social interactions", "our beliefs"};

    printf("Random Conspiracy Theory Generator\n\n");

    for(int i=0; i<10; i++){
        printf("%d. %s %s %s.\n", i+1, subjects[rand()%11], verbs[rand()%10], objects[rand()%12]);
    }

    printf("\nDon't believe everything you hear...\n");
    return 0;
}