//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <string.h>

// define ASCII art characters
char A[5] = {' ', '/', '_', '\\', ' '};
char B[5] = {'|', '_', '_', '_', '\\'};
char C[5] = {' ', '|', ' ', ' ', ' '};
char D[5] = {'/', ' ', '_', '_', '/'};
char E[5] = {'|', '_', '_', '_', ' '};
char F[5] = {'|', '_', '_', ' ', ' '};
char G[5] = {' ', '/', '_', '_', '\\'};
char H[5] = {'|', '_', ' ', '_', '|'};
char I[5] = {' ', ' ', '|', ' ', ' '};
char J[5] = {'\\', '_', ' ', ' ', ' '};
char K[5] = {'|', '_', ' ', '/', ' '};
char L[5] = {'|', ' ', ' ', ' ', ' '};
char M[5] = {'|', '_', '/', '_', '|'};
char N[5] = {'|', '_', '\\', '_', '|'};
char O[5] = {' ', '/', '_', '\\', ' '};
char P[5] = {'|', '_', '_', '/', ' '};
char Q[5] = {' ', '/', '_', '\\', ' ', '(', ')'};
char R[5] = {'|', '_', '_', '/', ' ', '\\'};
char S[5] = {' ', '\\', '_', '_', '/'};
char T[5] = {' ', ' ', '|', ' ', ' '};
char U[5] = {'|', ' ', '_', ' ', '|'};
char V[5] = {'/', ' ', '_', '\\', ' '};
char W[5] = {'|', ' ', '_', '/', '_', '|'};
char X[5] = {'\\', ' ', '/', ' ', '/'};
char Y[5] = {'\\', '_', '/', ' ', ' '};
char Z[5] = {'_', '_', '|', ' ', ' '};

char space[5] = {' ', ' ', ' ', ' ', ' '};
char comma[5] = {' ', '/', ' ', '\\', ' '};

// function to print ASCII art character array
void printChar(char c[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%c", c[i]);
    }
    printf("\n");
}

int main() {
    // get user input string
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        // print ASCII art for each character
        switch(input[i]) {
            case 'A':
                printChar(A);
                break;
            case 'B':
                printChar(B);
                break;
            case 'C':
                printChar(C);
                break;
            case 'D':
                printChar(D);
                break;
            case 'E':
                printChar(E);
                break;
            case 'F':
                printChar(F);
                break;
            case 'G':
                printChar(G);
                break;
            case 'H':
                printChar(H);
                break;
            case 'I':
                printChar(I);
                break;
            case 'J':
                printChar(J);
                break;
            case 'K':
                printChar(K);
                break;
            case 'L':
                printChar(L);
                break;
            case 'M':
                printChar(M);
                break;
            case 'N':
                printChar(N);
                break;
            case 'O':
                printChar(O);
                break;
            case 'P':
                printChar(P);
                break;
            case 'Q':
                printChar(Q);
                break;
            case 'R':
                printChar(R);
                break;
            case 'S':
                printChar(S);
                break;
            case 'T':
                printChar(T);
                break;
            case 'U':
                printChar(U);
                break;
            case 'V':
                printChar(V);
                break;
            case 'W':
                printChar(W);
                break;
            case 'X':
                printChar(X);
                break;
            case 'Y':
                printChar(Y);
                break;
            case 'Z':
                printChar(Z);
                break;
            case ' ':
                printChar(space);
                break;
            case ',':
                printChar(comma);
                break;
            default:
                break;
        }
    }

    return 0;
}