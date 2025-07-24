//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_types[] = {
    "government cover-up",
    "alien invasion",
    "secret society",
    "time travel",
    "mind control",
    "subliminal messages",
    "ancient civilization",
    "false flag",
    "matrix simulation",
    "multiverse theory",
    "reptilian overlords",
    "celebrity cloning",
    "illuminati",
    "moon landing hoax",
    "magnetic pole shift",
};

char* conspiracy_verbs[] = {
    "hiding",
    "manipulating",
    "controlling",
    "infiltrating",
    "brainwashing",
    "programming",
    "erasing",
};

char* conspiracy_nouns[] = {
    "evidence",
    "information",
    "truth",
    "knowledge",
    "reality",
    "history",
    "science",
};

char* conspiracy_adjectives[] = {
    "hidden",
    "secret",
    "forbidden",
    "taboo",
    "dangerous",
    "unbelievable",
};

int rand_int(int max_value) {
    return rand() % max_value;
}

int main() {

    srand(time(NULL));
    
    int num_companies = 10;
    char* companies[num_companies];
    companies[0] = "Google";
    companies[1] = "Facebook";
    companies[2] = "Apple";
    companies[3] = "Amazon";
    companies[4] = "Microsoft";
    companies[5] = "Tesla";
    companies[6] = "IBM";
    companies[7] = "Twitter";
    companies[8] = "Netflix";
    companies[9] = "Uber";
    
    int num_celebrities = 10;
    char* celebrities[num_celebrities];
    celebrities[0] = "Beyonce";
    celebrities[1] = "Kanye West";
    celebrities[2] = "Lady Gaga";
    celebrities[3] = "Tom Cruise";
    celebrities[4] = "Angelina Jolie";
    celebrities[5] = "Justin Bieber";
    celebrities[6] = "Taylor Swift";
    celebrities[7] = "Ryan Reynolds";
    celebrities[8] = "Keanu Reeves";
    celebrities[9] = "Dwayne 'The Rock' Johnson";
    
    int num_countries = 10;
    char* countries[num_countries];
    countries[0] = "USA";
    countries[1] = "Russia";
    countries[2] = "China";
    countries[3] = "North Korea";
    countries[4] = "Iran";
    countries[5] = "Saudi Arabia";
    countries[6] = "Israel";
    countries[7] = "France";
    countries[8] = "United Kingdom";
    countries[9] = "Germany";
    
    int num_years = 10;
    int years[num_years];
    years[0] = 1969;
    years[1] = 1984;
    years[2] = 1999;
    years[3] = 2001;
    years[4] = 2012;
    years[5] = 2016;
    years[6] = 2019;
    years[7] = 2020;
    years[8] = 2024;
    years[9] = 2050;
    
    int num_people = 10;
    char* people[num_people];
    people[0] = "Mark Zuckerberg";
    people[1] = "Elon Musk";
    people[2] = "Jeff Bezos";
    people[3] = "Bill Gates";
    people[4] = "Steve Jobs";
    people[5] = "Edward Snowden";
    people[6] = "Julian Assange";
    people[7] = "Hillary Clinton";
    people[8] = "Donald Trump";
    people[9] = "Barack Obama";
    
    int i;
    for(i = 0; i < 10; i++) {
        int type_index = rand_int(15);
        int verb_index = rand_int(7);
        int noun_index = rand_int(7);
        int adjective_index = rand_int(6);
        int company_index = rand_int(10);
        int celebrity_index = rand_int(10);
        int country_index = rand_int(10);
        int year_index = rand_int(10);
        int person_index = rand_int(10);
        
        printf("There is a %s involving %s and %s %s %s by %s in %s in %d. %s is %s\n", 
               conspiracy_types[type_index], 
               companies[company_index], 
               celebrities[celebrity_index], 
               conspiracy_verbs[verb_index], 
               conspiracy_nouns[noun_index], 
               people[person_index], 
               countries[country_index], 
               years[year_index], 
               conspiracy_adjectives[adjective_index], 
               conspiracy_nouns[noun_index]);
    }
    
    return 0;
}