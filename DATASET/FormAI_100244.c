//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Romeo and Juliet C Image Editor

int main(){

    char image[10][10];
    int r,c,i,j;
    char command[20];
    char color;

    // Initialize image to 'w'
    for(r=0;r<10;r++){
        for(c=0;c<10;c++){
            image[r][c]='w';
        }
    }

    // Display welcome message
    printf("\n\nWelcome to Romeo and Juliet C Image Editor.\n");
    printf("Your current image is:\n\n");
    for(r=0;r<10;r++){
        for(c=0;c<10;c++){
            printf("%c ", image[r][c]);
        }
        printf("\n");
    }

    // Ask for user input
    printf("\n\nEnter a command: ");
    scanf("%s", command);

    // Continue to process commands until user types "end"
    while(strcmp(command,"end")!=0){

        if(strcmp(command,"brush")==0){

            // Get brush color and position
            printf("Enter the brush color (b/w): ");
            scanf(" %c", &color);
            printf("Enter the row and column position: ");
            scanf("%d %d", &i, &j);

            // Update image with brush stroke
            image[i][j]=color;

            // Display updated image
            printf("Your current image is:\n\n");
            for(r=0;r<10;r++){
                for(c=0;c<10;c++){
                    printf("%c ", image[r][c]);
                }
                printf("\n");
            }

            // Ask for user input
            printf("\n\nEnter a command: ");
            scanf("%s", command);

        } else if(strcmp(command,"clear")==0){

            // Clear the image
            for(r=0;r<10;r++){
                for(c=0;c<10;c++){
                    image[r][c]='w';
                }
            }

            // Display cleared image
            printf("Your current image is:\n\n");
            for(r=0;r<10;r++){
                for(c=0;c<10;c++){
                    printf("%c ", image[r][c]);
                }
                printf("\n");
            }

      

            // Ask for user input
            printf("\n\nEnter a command: ");
            scanf("%s", command);

        } else {

            // Display error message and ask for user input
            printf("\n\nInvalid command. Please enter a valid command.\n");
            printf("Your current image is:\n\n");
            for(r=0;r<10;r++){
                for(c=0;c<10;c++){
                    printf("%c ", image[r][c]);
                }
                printf("\n");
            }
            printf("\n\nEnter a command: ");
            scanf("%s", command);

        }

    }

    // Display goodbye message
    printf("\n\nThank you for using Romeo and Juliet C Image Editor!\n\n");

    return 0;
}