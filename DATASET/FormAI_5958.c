//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void adventure(char *name);

int main(){
    char name[20];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s",name);
    printf("Hello %s! Let's begin!\n",name);
    adventure(name);
    return 0;
}

void adventure(char *name){
    char choice[10];
    printf("You are standing in a dark room. There is a door on your left and right.\n");
    printf("Which one do you choose?\n");
    scanf("%s",choice);
    if(strcmp(choice,"left")==0){
        printf("You have entered a room full of treasure!\n");
        printf("Congratulations %s! You Win!\n",name);
        return;
    }
    else if(strcmp(choice,"right")==0){
        printf("You have entered a room full of monsters!\n");
        printf("Oh No! %s, You lose!\n",name);
        return;
    }
    else{
        printf("Invalid Choice! Please try again.\n");
        adventure(name); // recursive call
    }
}