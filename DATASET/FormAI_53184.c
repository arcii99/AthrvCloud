//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>
int main() {
    int i, j, rows;
    printf("Hey there! Let's print a unique pattern today! How many rows do you want? ");
    scanf("%d", &rows);
    printf("Ready! Set! Go!\n");
    
    for (i=1; i<=rows; i++) {

        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }

        for(j=i-1; j>=1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("Oh that was fun! Did you like it? Want to do it again? Y / N");
    char replay;
    scanf(" %c", &replay);

    if (replay == 'Y' || replay == 'y') {
        printf("Alrighty then! Let's do it again!\n");
        main();  // recursive call to main function
    } 
    else {
        printf("No worries! See you later alligator!");
    }
    return 0;
}