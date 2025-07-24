//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayIntro(){
    printf("Welcome to Procedural Space Adventure Game\n");
    printf("You are the captain of a spaceship searching for new planets to colonize.\n");
    printf("Your mission is to explore a new galaxy and find a habitable planet for human settlement \n");
    printf("Be careful! There are many dangers in space\n\n");
}

void planetSearch(){
    int planet_chance = rand()%100;
    if(planet_chance<40){
        printf("No habitable planet found in this sector. Keep searching...\n\n");
    }else{
        printf("Habitable planet found!! Landing on planet surface...\n\n");
    }
}

void alienEncounter(){
    int alien_chance = rand()%100;
    if(alien_chance<20){
        printf("Alien attack!!!\n");
        printf("The aliens have boarded your ship and taken the crew captive.\n");
        printf("Game over.\n");
        exit(0);
    }else{
        printf("Alien encounter, but they pose no threat. Moving on...\n\n");
    }
}

void blackholeEvent(){
    int blackhole_chance = rand()%100;
    if(blackhole_chance<10){
        printf("Black hole ahead!!\n");
        printf("Navigating around the black hole....\n\n");
    }else{
        printf("No black holes in this sector. Keep moving...\n\n");
    }
}

void finalOutcome(){
    printf("Congratulations! You have found a habitable planet and saved the future of human race in this new galaxy.\n\n");
    printf("Thank you for playing Procedural Space Adventure Game.\n");
}

int main(){
    srand(time(0));
    displayIntro();
    for(int i=0;i<10;i++){
        printf("---Sector %d---\n",i+1);
        planetSearch();
        alienEncounter();
        blackholeEvent();
    }
    finalOutcome();
    
    return 0;
}