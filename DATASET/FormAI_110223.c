//FormAI DATASET v1.0 Category: Computer Biology ; Style: synchronous
#include <stdio.h>

int main() {
    //declare variables
    int input;
    int counter = 0;
    int i, j, k;
    int n1, n2, n3;

    //prompt user for input
    printf("Enter a number: ");
    scanf("%d", &input);

    //create arrays to hold DNA strands and amino acids
    char DNA1[input];
    char DNA2[input];
    char DNA3[input];
    char AA[input];

    //generate random DNA strands
    srand(time(NULL));
    for (i = 0; i < input; i++) {
        DNA1[i] = rand() % 4;
        DNA2[i] = rand() % 4;
        DNA3[i] = rand() % 4;
    }

    //combine DNA strands to form codons
    for (j = 0; j < input/3; j++) {
        n1 = DNA1[counter];
        n2 = DNA2[counter];
        n3 = DNA3[counter];
        
        //determine corresponding amino acid
        if (n1 == 0 && n2 == 0 && n3 == 0) {
            AA[j] = 'A';
        }
        else if (n1 == 0 && n2 == 0 && n3 == 1) {
            AA[j] = 'R';
        }
        else if (n1 == 0 && n2 == 0 && n3 == 2) {
            AA[j] = 'N';
        }
        else if (n1 == 0 && n2 == 0 && n3 == 3) {
            AA[j] = 'K';
        }
        else if (n1 == 0 && n2 == 1 && n3 == 0) {
            AA[j] = 'M';
        }
        else if (n1 == 0 && n2 == 1 && n3 == 1) {
            AA[j] = 'I';
        }
        else if (n1 == 0 && n2 == 1 && n3 == 2) {
            AA[j] = 'T';
        }
        else if (n1 == 0 && n2 == 1 && n3 == 3) {
            AA[j] = 'V';
        }
        else if (n1 == 0 && n2 == 2 && n3 == 0) {
            AA[j] = 'S';
        }
        else if (n1 == 0 && n2 == 2 && n3 == 1) {
            AA[j] = 'P';
        }
        else if (n1 == 0 && n2 == 2 && n3 == 2) {
            AA[j] = 'A';
        }
        else if (n1 == 0 && n2 == 2 && n3 == 3) {
            AA[j] = 'T';
        }
        else if (n1 == 0 && n2 == 3 && n3 == 0) {
            AA[j] = 'Y';
        }
        else if (n1 == 0 && n2 == 3 && n3 == 1) {
            AA[j] = 'H';
        }
        else if (n1 == 0 && n2 == 3 && n3 == 2) {
            AA[j] = 'Q';
        }
        else if (n1 == 0 && n2 == 3 && n3 == 3) {
            AA[j] = 'N';
        }
        else if (n1 == 1 && n2 == 0 && n3 == 0) {
            AA[j] = 'D';
        }
        else if (n1 == 1 && n2 == 0 && n3 == 1) {
            AA[j] = 'E';
        }
        else if (n1 == 1 && n2 == 0 && n3 == 2) {
            AA[j] = 'C';
        }
        else if (n1 == 1 && n2 == 0 && n3 == 3) {
            AA[j] = 'W';
        }
        else if (n1 == 1 && n2 == 1 && n3 == 0) {
            AA[j] = 'R';
        }
        else if (n1 == 1 && n2 == 1 && n3 == 1) {
            AA[j] = 'G';
        }
        else if (n1 == 1 && n2 == 1 && n3 == 2) {
            AA[j] = 'A';
        }
        else if (n1 == 1 && n2 == 1 && n3 == 3) {
            AA[j] = 'S';
        }
        else if (n1 == 1 && n2 == 2 && n3 == 0) {
            AA[j] = 'C';
        }
        else if (n1 == 1 && n2 == 2 && n3 == 1) {
            AA[j] = 'P';
        }
        else if (n1 == 1 && n2 == 2 && n3 == 2) {
            AA[j] = 'T';
        }
        else if (n1 == 1 && n2 == 2 && n3 == 3) {
            AA[j] = 'A';
        }
        else if (n1 == 1 && n2 == 3 && n3 == 0) {
            AA[j] = 'G';
        }
        else if (n1 == 1 && n2 == 3 && n3 == 1) {
            AA[j] = 'H';
        }
        else if (n1 == 1 && n2 == 3 && n3 == 2) {
            AA[j] = 'Q';
        }
        else if (n1 == 1 && n2 == 3 && n3 == 3) {
            AA[j] = 'R';
        }
        else if (n1 == 2 && n2 == 0 && n3 == 0) {
            AA[j] = 'N';
        }
        else if (n1 == 2 && n2 == 0 && n3 == 1) {
            AA[j] = 'K';
        }
        else if (n1 == 2 && n2 == 0 && n3 == 2) {
            AA[j] = 'S';
        }
        else if (n1 == 2 && n2 == 0 && n3 == 3) {
            AA[j] = 'R';
        }
        else if (n1 == 2 && n2 == 1 && n3 == 0) {
            AA[j] = 'I';
        }
        else if (n1 == 2 && n2 == 1 && n3 == 1) {
            AA[j] = 'M';
        }
        else if (n1 == 2 && n2 == 1 && n3 == 2) {
            AA[j] = 'T';
        }
        else if (n1 == 2 && n2 == 1 && n3 == 3) {
            AA[j] = 'V';
        }
        else if (n1 == 2 && n2 == 2 && n3 == 0) {
            AA[j] = 'A';
        }
        else if (n1 == 2 && n2 == 2 && n3 == 1) {
            AA[j] = 'P';
        }
        else if (n1 == 2 && n2 == 2 && n3 == 2) {
            AA[j] = 'T';
        }
        else if (n1 == 2 && n2 == 2 && n3 == 3) {
            AA[j] = 'G';
        }
        else if (n1 == 2 && n2 == 3 && n3 == 0) {
            AA[j] = 'S';
        }
        else if (n1 == 2 && n2 == 3 && n3 == 1) {
            AA[j] = 'H';
        }
        else if (n1 == 2 && n2 == 3 && n3 == 2) {
            AA[j] = 'Y';
        }
        else if (n1 == 2 && n2 == 3 && n3 == 3) {
            AA[j] = 'C';
        }
        else if (n1 == 3 && n2 == 0 && n3 == 0) {
            AA[j] = 'K';
        }
        else if (n1 == 3 && n2 == 0 && n3 == 1) {
            AA[j] = 'N';
        }
        else if (n1 == 3 && n2 == 0 && n3 == 2) {
            AA[j] = 'K';
        }
        else if (n1 == 3 && n2 == 0 && n3 == 3) {
            AA[j] = 'N';
        }
        else if (n1 == 3 && n2 == 1 && n3 == 0) {
            AA[j] = 'T';
        }
        else if (n1 == 3 && n2 == 1 && n3 == 1) {
            AA[j] = 'S';
        }
        else if (n1 == 3 && n2 == 1 && n3 == 2) {
            AA[j] = 'T';
        }
        else if (n1 == 3 && n2 == 1 && n3 == 3) {
            AA[j] = 'S';
        }
        else if (n1 == 3 && n2 == 2 && n3 == 0) {
            AA[j] = 'R';
        }
        else if (n1 == 3 && n2 == 2 && n3 == 1) {
            AA[j] = 'H';
        }
        else if (n1 == 3 && n2 == 2 && n3 == 2) {
            AA[j] = 'R';
        }
        else if (n1 == 3 && n2 == 2 && n3 == 3) {
            AA[j] = 'H';
        }
        else if (n1 == 3 && n2 == 3 && n3 == 0) {
            AA[j] = 'Q';
        }
        else if (n1 == 3 && n2 == 3 && n3 == 1) {
            AA[j] = 'Q';
        }
        else if (n1 == 3 && n2 == 3 && n3 == 2) {
            AA[j] = 'E';
        }
        else if (n1 == 3 && n2 == 3 && n3 == 3) {
            AA[j] = 'E';
        }

        //increment counter
        counter += 3;
    }

    //print results
    printf("DNA strands: \n");
    for (k = 0; k < input; k++) {
        printf("%d ", DNA1[k]);
    }
    printf("\n");
    for (k = 0; k < input; k++) {
        printf("%d ", DNA2[k]);
    }
    printf("\n");
    for (k = 0; k < input; k++) {
        printf("%d ", DNA3[k]);
    }
    printf("\n");

    printf("Amino acids: \n");
    for (k = 0; k < input/3; k++) {
        printf("%c ", AA[k]);
    }
    printf("\n");

    return 0;
}