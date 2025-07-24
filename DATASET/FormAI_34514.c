//FormAI DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char movie[50], rating[10], choice;
    int userCount = 0, totalRating = 0;
    float avgRating = 0;
    
    printf("Welcome to the Unique C Movie Rating System!\n\n");
    
    do{     
        printf("Please Enter the Movie name: ");
        scanf("%s", movie);
        
        printf("Please Enter the Movie Rating [1-10]: ");
        scanf("%s", rating);
        
        totalRating += atoi(rating);
        userCount++;
        
        printf("\nThank you for rating the movie '%s' with '%s' rating!\n\n", movie, rating);
        
        printf("Do you want to rate another movie? [y/n]: ");
        scanf(" %c", &choice);
        printf("\n");
        
        while((choice != 'n') && (choice != 'y')){
            printf("Invalid input! Please Enter [y/n]: ");
            scanf(" %c", &choice);
            printf("\n");
        }
        
    }while(choice == 'y');
    
    if(userCount > 0){
        avgRating = (float)totalRating / userCount;
        printf("The average rating of the movies rated is: %.2f\n", avgRating);
    }else{
        printf("No Movies were rated yet!\n");
    }
    
    printf("\nThanks for using the Unique C Movie Rating System!");
    
    return 0;
}