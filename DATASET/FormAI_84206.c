//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_theories[] = {
    "The moon landing was faked",
    "The government is controlled by shape-shifting lizards",
    "Vaccines cause autism",
    "The earth is flat",
    "Climate change is a hoax",
    "9/11 was an inside job",
    "The Illuminati controls everything",
    "Chemtrails are a form of mind control",
    "GMOs are killing us",
    "The Vatican is hiding ancient knowledge",
    "Area 51 is hiding proof of extra-terrestrial life",
    "The Bermuda Triangle is a portal to another dimension"
};

char* government_agencies[] = {
    "CIA",
    "NSA",
    "FBI",
    "CDC",
    "EPA",
    "NASA",
    "DHS",
    "FDA",
    "DOJ",
    "IRS",
    "USPS"
};

char* celebrities[] = {
    "Beyonce",
    "Kanye West",
    "Tom Cruise",
    "Angelina Jolie",
    "Taylor Swift",
    "Brad Pitt",
    "Lady Gaga",
    "Justin Bieber",
    "Oprah Winfrey",
    "Dwayne 'The Rock' Johnson"
};

char* locations[] = {
    "Washington D.C.",
    "New York City",
    "Los Angeles",
    "Paris",
    "London",
    "Moscow",
    "Hong Kong",
    "Tokyo",
    "Berlin",
    "Sydney",
    "Cairo",
    "Rio de Janeiro"
};

int main() {
    srand(time(NULL));
    int num_of_theories = sizeof(conspiracy_theories) / sizeof(char*);
    int num_of_agencies = sizeof(government_agencies) / sizeof(char*);
    int num_of_celebrities = sizeof(celebrities) / sizeof(char*);
    int num_of_locations = sizeof(locations) / sizeof(char*);

    printf("Shape-shifting Conspiracy Theory Generator:\n");
    printf("--------------------------------------------\n");
    printf("The %s %s is behind the %s in %s\n", 
        government_agencies[rand() % num_of_agencies], 
        celebrities[rand() % num_of_celebrities], 
        conspiracy_theories[rand() % num_of_theories], 
        locations[rand() % num_of_locations]);  
    printf("--------------------------------------------\n");
    printf("Stay woke!\n");
    return 0;
}