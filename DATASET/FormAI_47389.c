//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* theories[] = { //An array of conspiracy theories
    "The moon landing was fake",
    "The government controls the weather",
    "The world is run by lizard people",
    "The Earth is flat",
    "COVID-19 was created in a lab",
    "Area 51 is hiding extraterrestrial life",
    "The Illuminati secretly rule the world",
    "Vaccines cause autism",
    "Chemtrails are real",
    "The Titanic never sank"
};

char* names[] = { //An array of famous names associated with conspiracy theories
    "Alex Jones",
    "David Icke",
    "Jesse Ventura",
    "Donald Trump",
    "Bill Gates",
    "Roswell",
    "The Men in Black",
    "Big Pharma",
    "The New World Order",
    "The Deep State"
};

char* actions[] = { //An array of actions the conspirators supposedly took
    "planted evidence",
    "rigged elections",
    "bribed officials",
    "covered up evidence",
    "hijacked planes",
    "faked documents",
    "used mind control",
    "infiltrated governments",
    "controlled the media",
    "experimented on humans"
};

char* generateTheory(){ //Function to generate a random conspiracy theory
    int randomIndex = rand() % 10;
    return theories[randomIndex];
}

char* generateName(){ //Function to generate a name associated with a conspiracy theory
    int randomIndex = rand() % 10;
    return names[randomIndex];
}

char* generateAction(){ //Function to generate an action taken by conspirators
    int randomIndex = rand() % 10;
    return actions[randomIndex];
}

int main(){
    srand(time(NULL)); //Seed the random number generator with current time
    char input; //Variable to hold user input

    printf("Welcome to the Random Conspiracy Theory Generator.\n");
    printf("Press Enter to generate a random theory or Q to quit.\n");

    do{
        input = getchar(); //Read user input
        if(input == '\n'){ //Generate a theory if user inputs Enter
            char* theory = generateTheory();
            char* name = generateName();
            char* action = generateAction();
            printf("\n%s was behind the %s and %s.\n", name, theory, action);
        }
    }while(input != 'q' && input != 'Q');

    return 0;
}