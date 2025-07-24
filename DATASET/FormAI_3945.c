//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("What?! The file you want me to handle doesn't exist?!\n");
    printf("This is just unbelievable.\n");
    printf("Alright, let's just create it then.\n");

    FILE *fptr;
    fptr = fopen("myFile.txt", "w");

    if(fptr == NULL){
        printf("Seriously? I thought we just created the file...\n");
        printf("I'm just going to have to exit now.\n");
        exit(1);
    }

    printf("Phew! The file was created successfully.\n");
    printf("Now let's write something into it.\n");

    fprintf(fptr, "This is some text that I'm writing into the file.\n");
    fprintf(fptr, "I hope it works.\n");

    printf("Done!\n");
    printf("Now let's read what we just wrote.\n");

    fseek(fptr, 0, SEEK_SET);

    char c = fgetc(fptr);

    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }

    printf("\n");

    printf("Wow, that actually worked.\n");
    printf("Now let's close the file.\n");

    fclose(fptr);

    printf("Phew! That was a rollercoaster of emotions.\n");
    printf("But we did it! The file was successfully handled.\n");

    return 0;
}