//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_fortune(){
    int num = rand() % 10;
    
    switch(num){
        case 0:
            printf("You will find great success in your endeavors.\n");
            break;
        case 1:
            printf("Your kindness will bring you great happiness.\n");
            break;
        case 2:
            printf("Your life will be filled with love and joy.\n");
            break;
        case 3:
            printf("You will face difficult challenges, but will come out stronger.\n");
            break;
        case 4:
            printf("Your creativity will lead to great things.\n");
            break;
        case 5:
            printf("Your hard work will pay off in the end.\n");
            break;
        case 6:
            printf("Your positive attitude will bring positivity into your life.\n");
            break;
        case 7:
            printf("Your determination will lead to success.\n");
            break;
        case 8:
            printf("You will meet new people who will change your life for the better.\n");
            break;
        case 9:
            printf("You will find great satisfaction in helping others.\n");
            break;
    }
}

int main(){
    srand(time(NULL));
    int option;
    
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    while(1){
        printf("Please choose an option:\n");
        printf("1. Seek fortune\n");
        printf("2. Exit\n\n");
        scanf("%d", &option);
        
        if(option == 1){
            print_fortune();
            printf("\n");
        }
        else if(option == 2){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Invalid option! Please try again.\n\n");
        }
    }
    
    return 0;
}