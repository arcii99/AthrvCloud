//FormAI DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
// A Romeo and Juliet inspired C matrix operations example program

#include <stdio.h>

int main() {
    int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int m3[3][3];
    
    // Romeo declares his undying love for Juliet
    printf("My Juliet, my love for thee is like a matrix that is never ending.\n");
    printf("It goes on and on, forever.\n\n");

    // Juliet responds with a blush
    printf("Oh Romeo, your words are sweet like honey.\n");
    printf("But what do matrices have to do with love?\n\n");

    // Romeo explains his analogy 
    printf("My love, matrices are like a pair of twins in my eyes.\n");
    printf("Individually, they may be distinct. But together, they make something special.\n\n");

    // Juliet nods in understanding
    printf("I see now, Romeo. Show me what you mean with an example.\n");
    printf("I do not understand matrices very well, so teach me, my love.\n\n");

    // Romeo smiles and begins to teach Juliet matrix addition and multiplication
    printf("Let me start by showing you how two matrices can be added.\n\n");
    
    // Matrix addition
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("Now, let me show you how to multiply two matrices together.\n\n");
    
    // Matrix multiplication
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            m3[i][j] = sum;
            sum = 0;
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    // Juliet marvels at the power of matrices
    printf("\n");
    printf("Oh Romeo, matrices are truly a wonder.\n");
    printf("Thank you for showing me their power.\n\n");
    
    // Romeo beams with pride and they walk away hand in hand
    printf("Let us go now, my love\n");
    printf("And let us use the power of matrices to create something beautiful together.\n");
    
    return 0;
}