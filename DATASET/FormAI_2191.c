//FormAI DATASET v1.0 Category: Computer Biology ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Declare variables
    int i;
    char name[20];
    char answer;

    // Welcome message
    printf("Hi! I'm a computer biology program! What's your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s!\n\n", name);

    // Ask user if they want to learn about DNA
    printf("%s, do you want to learn about DNA? (y/n)\n", name);
    scanf(" %c", &answer);

    // If user says yes, print fun facts about DNA
    if (answer == 'y' || answer == 'Y') {
        printf("\nGreat! Here are some fun facts about DNA:\n\n");
        printf("1. DNA stands for deoxyribonucleic acid.\n");
        printf("2. DNA is made up of four nitrogenous bases: adenine, guanine, cytosine, and thymine.\n");
        printf("3. The structure of DNA was discovered by James Watson and Francis Crick in 1953.\n");
        printf("4. DNA stores all of the genetic information for an organism.\n");
        printf("5. The human genome contains approximately 3 billion base pairs of DNA.\n\n");
    }

    // Ask user if they want to learn about protein synthesis
    printf("%s, do you want to learn about protein synthesis? (y/n)\n", name);
    scanf(" %c", &answer);

    // If user says yes, print fun facts about protein synthesis
    if (answer == 'y' || answer == 'Y') {
        printf("\nAwesome! Here are some fun facts about protein synthesis:\n\n");
        printf("1. Protein synthesis occurs in two steps: transcription and translation.\n");
        printf("2. Transcription is the process of copying the DNA code to RNA.\n");
        printf("3. Translation is the process of converting the RNA code to amino acids and building a protein.\n");
        printf("4. Proteins are essential for the structure and function of cells.\n");
        printf("5. The longest protein ever discovered is called Titin and has over 38,000 amino acids!\n\n");
    }

    // Thank user for using the program and say goodbye
    printf("Thank you for using my program, %s! Have a great day!\n", name);

    return 0;
}