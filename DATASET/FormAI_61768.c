//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void conspiracy_generator();

int main(){
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    conspiracy_generator();
    return 0;
}

void conspiracy_generator(){
    char *keywords[] = {"aliens", "government", "Illuminati", "secret societies", "Big Pharma", "Pleiadians", "Reptilians", "chemtrails", "HAARP", "Mandela Effect", "New World Order"};
    char *prefixes[] = {"The truth about ", "The hidden reality behind ", "The shocking conspiracy of ", "The sinister plot of ", "The secret plan of "};
    char *suffixes[] = {" will blow your mind!", " is hiding in plain sight.", " is out to get us all!", " is the real reason for everything.", ", and you're not supposed to know about it.", " has been manipulating us for years."};

    srand(time(NULL)); // Seed the random number generator
    
    for(int i=0; i<5; i++){
        int kw_index = rand() % 11;
        int pre_index = rand() % 5;
        int suf_index = rand() % 6;
        printf("%s%s%s\n", prefixes[pre_index], keywords[kw_index], suffixes[suf_index]);
    }
}