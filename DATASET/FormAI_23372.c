//FormAI DATASET v1.0 Category: Funny ; Style: curious
#include <stdio.h>

int main(){
    char letter[] = {'H','e','l','l','o',' ','W','o','r','l','d'};
    int i;

    printf("Here is my letter: ");
    for (i=0; i<11; i++){
        printf("%c", letter[i]);
    }
    printf("\n");

    printf("Now let's test your typing skills! Type this sentence:\n");
    printf("The quick brown fox jumps over the lazy dog. \n");

    char sentence[44];
    scanf("%43[^\n]", sentence);

    printf("You typed: %s\n", sentence);

    if (strcmp(sentence, "The quick brown fox jumps over the lazy dog.") == 0){
        printf("Congratulations! You typed the sentence perfectly.\n");
    } else {
        printf("Oops, looks like you made some mistakes. Please try again.\n");
    }

    printf("Here's a little twist to the program. Let's add some encryption to the sentence you typed.\n");
    for (i=0; i<44; i++){
        sentence[i] += 5;
    }
    printf("Encrypted sentence: %s\n", sentence);

    printf("Now let's decrypt it back to the original sentence.\n");
    for (i=0; i<44; i++){
        sentence[i] -= 5;
    }
    printf("Decrypted sentence: %s\n", sentence);

    printf("Thank you for playing with me! Hope you had fun.\n");

    return 0;
}