//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand(time(NULL));
    
    char* companies[] = {"Microsoft", "Google", "Apple", "Amazon", "Facebook"};
    char* actions[] = {"is controlled by aliens", "spies on its users", "is plotting world domination", "caused the pandemic", "is hoarding vaccines"};
    char* people[] = {"Bill Gates", "Elon Musk", "Mark Zuckerberg", "Jeff Bezos", "Steve Jobs"};
    
    int i, j, k;
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            for(k=0; k<5; k++){
                int compIndex = rand() % 5;
                int actIndex = rand() % 5;
                int persIndex = rand() % 5;
                
                printf("%s %s because %s.\n", companies[compIndex], actions[actIndex], people[persIndex]);
            }
        }
    }
    
    return 0;
}