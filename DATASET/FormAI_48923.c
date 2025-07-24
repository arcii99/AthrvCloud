//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * This program reads a file named "jokes.txt" and prints the jokes in a funny way
 */

int main(){

    FILE *fp;
    fp = fopen("jokes.txt", "r");
    char line[100];
    int jokeCount = 0;

    if(fp == NULL){

        printf("Oops! There was an error opening the file.\n");
        printf("I think the file ran away with the spoon...\n");
        printf("But don't worry, I will find it!\n");
        exit(1);
    }
    else{

        printf("I found the file!\n");
        printf("Searching for jokes...\n\n");

        while(fgets(line, 100, fp)){

            if(strncmp(line, "Joke:", 5) == 0){

                printf("Hahaha! Here's a good one...\n");
                printf("%s", line+5);
                jokeCount++;

                if(jokeCount % 2 == 0){

                    printf("\nWhy did the chicken cross the road?\n");
                    printf("To get to the other side!\n");
                }
            }
        }

        printf("\nI hope you enjoyed the jokes!\n");
        printf("Don't worry, I have more in store for you...\n");

    }

    fclose(fp);

    printf("\nDo you want to add an extra joke to the file?\n");
    printf("Just type in the joke below:\n");

    char newJoke[100];
    fgets(newJoke, 100, stdin);
    strcat(newJoke, "\n");

    fp = fopen("jokes.txt", "a");

    if(fp == NULL){

        printf("Oops! There was an error opening the file.\n");
        printf("I think the file is scared of your joke...\n");
        printf("But don't worry, I will console it!\n");
        exit(1);
    }
    else{

        printf("Adding your joke to the file...\n");
        fprintf(fp, "Joke:%s", newJoke);
        printf("Your joke was successfully added to the file!\n");
        printf("Thank you for contributing to the fun!\n");

    }

    fclose(fp);

    return 0;
}