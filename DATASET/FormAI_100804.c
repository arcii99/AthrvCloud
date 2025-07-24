//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>

int main(){
    int rating;
    
    printf("Welcome to our Movie Rating System!\n");
    printf("Please rate the last movie you watched on a scale of 1-10: ");
    scanf("%d", &rating);
    
    if(rating>=1 && rating<=3){
        printf("Sorry to hear that you didn't enjoy the movie. We promise to do better next time!\n");
    }
    else if(rating>=4 && rating<=7){
        printf("Glad to hear that you enjoyed the movie, but we will strive to make it even better next time!\n");
    }
    else if(rating>=8 && rating<=10){
        printf("Wow, a perfect score! We are thrilled that you liked the movie and we will continue to make great films!\n");
    }
    else{
        printf("Invalid rating entered. Please rate the movie on a scale of 1-10.\n");
    }
    
    return 0;
}