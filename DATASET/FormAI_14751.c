//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the automated fortune teller!\n");
    printf("Type 'quit' to exit.\n\n");
    srand(time(0));
    char* fortunes[] = {"You will achieve great things!", "A new opportunity will arise soon.",
                        "Your hard work will pay off in the near future.", "Love is in your future.",
                        "You will work through a difficult problem and come out on top.",
                        "A new friend will enter your life.", "An unexpected windfall is coming your way.",
                        "Take a risk, it will be worth it."};
                        
    char input[10];
    while(1){
        printf("Enter 'fortune' to receive your fortune: ");
        scanf("%s", input);
        if(strcmp(input, "fortune") == 0){
            int num = rand() % 8;
            printf("Your fortune is: %s\n\n", fortunes[num]);
        }
        else if(strcmp(input, "quit") == 0){
            printf("Thanks for coming! Goodbye!\n");
            break;
        }
        else{
            printf("Invalid command. Try again.\n\n");
        }
    }
    return 0;
}