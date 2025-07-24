//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));  //intialize random number generator with NULL

    //Arrays of conspiracy theories
    char *theories[] = {"The moon landing was faked",
                        "9/11 was an inside job",
                        "Area 51 is hiding UFOs",
                        "The JFK assassination was a government cover-up",
                        "Chemtrails are a form of mind control",
                        "The Illuminati secretly run the world",
                        "COVID-19 is a bioweapon",
                        "The Earth is flat",
                        "Bill Gates is implanting microchips in vaccines",
                        "The Titanic never sank and was switched with its sister ship",
                        "The government is hiding the cure for cancer"};

    char *evidence[] = {"There are no stars in the background of moon landing photos",
                        "The planes that hit the Twin Towers were actually controlled by the government",
                        "Multiple witnesses claim to have seen alien technology and bodies at Area 51",
                        "There are inconsistencies in the official story about JFK's assassination",
                        "Tests have shown high levels of chemicals in the air from planes leaving contrails",
                        "Sightings of the 'all-seeing eye' and other Illuminati symbols in pop culture are evidence of their influence",
                        "The COVID-19 virus shares similarities with other known bioweapons",
                        "The curvature of the Earth is not visible from high altitudes",
                        "Bill Gates has publicly spoken about the need for digital vaccine records",
                        "The Titanic's sister ship the Britannic was sunk and passed off as the Titanic",
                        "Pharmaceutical companies make more money from treatments than from cures, so a cure for cancer would be bad for business"};

    char *motives[] = {"To win the Space Race against Russia",
                        "To justify going to war in the Middle East",
                        "To study and exploit alien technology",
                        "To cover up a larger government conspiracy",
                        "To control and manipulate the population",
                        "To consolidate power and influence",
                        "To weaken other countries and gain a competitive advantage",
                        "To keep the population obedient and unquestioning",
                        "To create a totalitarian society",
                        "To profit off of sick people",
                        "To distract and entertain the public"};

    int num_theories = sizeof(theories)/ sizeof(theories[0]); //get size of theories array
    int num_evidence = sizeof(evidence) / sizeof(evidence[0]); //get size of evidence array
    int num_motives = sizeof(motives) / sizeof(motives[0]); //get size of motives array

    //Generate random conspiracy theory
    int theory_index = rand() % num_theories; //choose a random index from theories array
    char* theory = theories[theory_index];

    //Generate random evidence for the conspiracy theory
    int evidence_index = rand() % num_evidence; //choose a random index from evidence array
    char* evidence_text = evidence[evidence_index];

    //Generate random motive for the conspiracy theory
    int motive_index = rand() % num_motives; //choose a random index from motives array
    char* motive = motives[motive_index];

    //Print out the conspiracy theory
    printf("Conspiracy Theory: %s\n", theory);
    printf("Evidence: %s\n", evidence_text);
    printf("Motive: %s\n", motive);

    return 0;
}