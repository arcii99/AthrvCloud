//FormAI DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include<stdio.h>

// Romeo and Juliet - A Tale of Matrix Operations

int main() {
    printf("Romeo:\n");
    
    // Creating and initializing the matrices
    int a[2][2] = {{1,2}, {3,4}}, b[2][2] = {{5,6}, {7,8}}, c[2][2] = {{0,0}, {0,0}};
    
    printf("Oh Juliet! My love for matrices is like my love for you!\n");
    
    printf("Juliet:\n");
    printf("Why Romeo, what do you mean?\n");
    
    printf("Romeo:\n");
    printf("Just as I can add and subtract matrices, I can add and subtract my love for you!\n");
    
    printf("Juliet:\n");
    printf("Oh Romeo! You are too silly!\n");
    
    printf("Romeo:\n");
    printf("But wait! Let me show you the magic of matrix multiplication!\n");
    
    // Multiplying the matrices
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            c[i][j] = 0;
            for(int k=0; k<2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    printf("Juliet:\n");
    printf("Wow Romeo! That is indeed magical!\n");
    
    printf("Romeo:\n");
    printf("And just as we can transpose matrices, we can transpose our feelings for each other!\n");
    
    // Transposing matrix b
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            int temp = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = temp;
        }
    }
    
    printf("Juliet:\n");
    printf("Oh Romeo! You always know how to make me smile!\n");
    
    printf("Romeo:\n");
    printf("And finally, just as we can find the determinant of a matrix, we can find the determinant of our fate together!\n");
    
    // Calculating determinant of matrix a
    int determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    
    printf("Juliet:\n");
    printf("Romeo, my heart swells with joy when I think of our future together!\n");
    
    printf("Romeo:\n");
    printf("And my love for you, Juliet, will never be divided or reduced by any matrix operation!\n");
    
    return 0;
}