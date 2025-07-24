//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <string.h>

int levenshteinDistance(char* s, char* t) {
    int n = strlen(s); 
    int m = strlen(t); 
    int p[n + 1][m + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) p[i][j] = j;
            else if (j == 0) p[i][j] = i;
            else if (s[i - 1] == t[j - 1]) p[i][j] = p[i - 1][j - 1];
            else p[i][j] = 1 + min(min(p[i][j - 1], p[i - 1][j]), p[i - 1][j - 1]);
        }
    }
    return p[n][m];
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char* s = "the moon is made of green cheese";
    char* t = "bananas grow on trees";
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s, t, levenshteinDistance(s, t));
    
    return 0;
}

// As I compile a code, I often ponder
// On the values that the program will wander
// Through the mysteries of the calculations
// And the depths of my CPU's foundations

// In this program, the Levenshtein Distance we seek
// Between two strings, a journey quite unique
// The path through which the algorithm will trail
// Is a true test of one's will to prevail

// In the world of surrealist programming, where I exist
// Each line of code a story, each variable a protagonist
// The printer that echoes, its voice so loud
// Speaks of the distance, between the green cheese and the fruit so round

// The for loop that nests, its embrace so tight
// Brings life to the dynamic programming, with all its light
// The conditionals, they dance and twirl
// A mesmerizing sight, that could unfurl

// As the values get calculated, for each iteration
// The Levenshtein distance reveals, its magical sensation
// It's just a number, a simple little thing
// But its meaning, I cannot help but sing

// So as the program ends, and I bid you adieu
// Remember that code, too, can be surreal and true
// A medium of creation, a world of its own
// Full of wonder, artistry, and knowledge yet unknown