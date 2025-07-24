//FormAI DATASET v1.0 Category: Data structures visualization ; Style: funny
#include<stdio.h>

typedef struct car{
    char brand[10];
    char color[10];
    int year;
} Car;

int main(){
    Car vehicles[3];
    
    printf("Welcome to the Crazy Car Mart!\n");
    printf("We have a great selection of vehicles for you.\n");
    
    for(int i=0; i<3; i++){
        printf("Please tell me the brand of vehicle number %d: ", i+1);
        scanf("%s", &vehicles[i].brand);
        
        printf("What color is it? ");
        scanf("%s", &vehicles[i].color);
        
        printf("And in what year it was produced? ");
        scanf("%d", &vehicles[i].year);
        
        printf("\n");
    }
    
    printf("Thank you for your help. We have the following vehicles:\n");
    
    for(int i=0; i<3; i++){
        printf("Vehicle number %d:\n", i+1);
        printf("Brand: %s\n", vehicles[i].brand);
        printf("Color: %s\n", vehicles[i].color);
        printf("Year of production: %d\n", vehicles[i].year);
        printf("\n");
    }
    
    printf("Come back soon to the Crazy Car Mart!\n");
    
    return 0;
}