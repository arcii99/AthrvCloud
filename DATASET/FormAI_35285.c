//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the super duper file handling program!\n");
    printf("We will be creating a file called 'funny.txt' and filling it with hilarious jokes.\n\n");
    
    FILE *fptr;
    fptr = fopen("funny.txt", "w");
    
    if(fptr == NULL)
    {
        printf("Error creating the file. Oops!\n");
        return 1;
    }
    
    fprintf(fptr, "Why did the chicken cross the playground? To get to the other slide!\n\n");
    fprintf(fptr, "Why did the tomato turn red? Because it saw the salad dressing!\n\n");
    fprintf(fptr, "Why was the math book sad? Because it had too many problems!\n\n");
    fprintf(fptr, "Why did the coffee file a police report? It got mugged!\n\n");
    fprintf(fptr, "Why did the bike fall over? Because it was two tired!\n\n");
    
    printf("Jokes successfully added to the file! Time to read them.\n\n");
    
    fptr = fopen("funny.txt", "r");
    
    if(fptr == NULL)
    {
        printf("Error reading the file. Sorry not sorry.\n");
        return 1;
    }
    
    char c = fgetc(fptr);
    
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    
    fclose(fptr);
    
    printf("\n\nThanks for using our file handling program. We hope you laughed as much as we did!\n");
    
    return 0;
}