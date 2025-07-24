//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include<stdio.h>

int main() {
    // Printing a happy greeting message
    printf("Hi there! Let's draw a happy graph!\n");

    // Defining the size of the graph
    int size = 10;

    // Creating the vertical axis of the graph
    printf("\n");
    for(int i=size; i>=-size; i--) {
        printf(" ");
        for(int j=-size; j<=size; j++) {
            if(i==0) {
                printf("-");
            }
            else if(j==0) {
                printf("|");
            }
            else if(i*j<0) {
                printf("\\");
            }
            else {
                printf("/");
            }
        }
        printf("\n");
    }

    // Printing a happy message for the completed graph
    printf("\nYay! Our happy graph is complete.\n");

    return 0;
}