//FormAI DATASET v1.0 Category: Movie Rating System ; Style: secure
#include<stdio.h>
#include<string.h>

//Function declaration
int get_rating_index(char *rating);
void print_ratings();

//Global variables
const char *ratings[] = {"G", "PG", "PG-13", "R", "NC-17"};

int main(){
    char rating[10];
    printf("Welcome to the Unique C Movie Rating System\n");
    printf("Please enter the movie rating (G, PG, PG-13, R, NC-17): ");
    scanf("%s", rating);
    int index = get_rating_index(rating);
    if(index == -1){
        printf("Invalid movie rating entered\n");
        print_ratings();
        return 0;
    }
    printf("The movie rating is %s\n", ratings[index]);
    return 0;
}

//Function definition to get index of rating from array
int get_rating_index(char *rating){
    for(int i=0; i<5; i++){
        if(strcmp(rating, ratings[i])==0){
            return i;
        }
    }
    return -1;
}

//Function definition to print all possible ratings
void print_ratings(){
    printf("Possible movie ratings are:\n");
    for(int i=0; i<5; i++){
        printf("%s\n", ratings[i]);
    }
}