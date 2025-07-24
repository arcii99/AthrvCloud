//FormAI DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char suspect1[] = "John";
    char suspect2[] = "Peter";
    char suspect3[] = "Lisa";
    char suspect4[] = "Nancy";
    
    int ans1, ans2, ans3, ans4;
    
    printf("The game is afoot! You have four suspects - John, Peter, Lisa, and Nancy.\n");
    printf("Answer each question truthfully. The correctness of the case depends on it!\n\n");

    printf("First, does the suspect wear glasses? Type 1 for Yes or 0 for No: ");
    scanf("%d", &ans1);
    printf("\n");

    printf("Second question, how many tattoos does the suspect have? Enter a number between 0 and 10: ");
    scanf("%d", &ans2);
    printf("\n");

    printf("Third, is the suspect left-handed or right-handed? Type 1 for Left-handed or 0 for Right-handed: ");
    scanf("%d", &ans3);
    printf("\n");

    printf("Last question, does the suspect prefer coffee or tea? Type 1 for Coffee or 0 for Tea: ");
    scanf("%d", &ans4);
    printf("\n");

    // Check which suspect matches the given answers
    if(ans1 && ans2 == 3 && ans3 && !ans4){
        printf("Congratulations! You have successfully solved the mystery. The suspect is %s.\n", suspect1);
    }
    else if(ans1 && ans2 == 0 && !ans3 && ans4){
        printf("Congratulations! You have successfully solved the mystery. The suspect is %s.\n", suspect2);
    }
    else if(!ans1 && ans2 == 7 && ans3 && ans4){
        printf("Congratulations! You have successfully solved the mystery. The suspect is %s.\n", suspect3);
    }
    else if(ans1 && ans2 == 2 && !ans3 && !ans4){
        printf("Congratulations! You have successfully solved the mystery. The suspect is %s.\n", suspect4);
    }
    else{
        printf("Unfortunately, your answers did not match any of the suspects!\n");
    }
    return 0;
}