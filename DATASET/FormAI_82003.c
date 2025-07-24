//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {

    printf("Let's print a unique C pattern, shall we?\n");
    printf("How many rows do you want to print? Enter a positive integer:\n");
    int rows;
    scanf("%d", &rows);

    if(rows <= 0){
        printf("Seriously? A positive number please.\n");
    }
    else{
        printf("Great! Here's your pattern:\n\n");

        for(int i = 1; i <= rows; i++){

            // first and last row should have all C's
            if(i == 1 || i == rows) {
                for(int j = 1; j <= rows; j++){
                    printf(" C ");
                }
            }
            // rest of the rows should have C's at the beginning and end only
            else {
                for(int j = 1; j <= rows; j++){
                    if(j == 1 || j == rows) {
                        printf(" C ");
                    }
                    else {
                        printf("   ");
                    }
                }
            }
            printf("\n\n");
        }
    }

    printf("Voila! I hope you're satisfied. Goodbye!\n");
}