//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to find minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    else if (b <= a && b <= c) {
        return b;
    }
    else {
        return c;
    }
}

// Dynamic Programming function to calculate Levenshtein Distance
int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int arr[len1+1][len2+1]; // Create a 2D array to store results

    // Fill the 2D array with initial values
    for (int i=0; i<=len1; i++) {
        for (int j=0; j<=len2; j++) {
            if (i == 0) {
                arr[i][j] = j;
            }
            else if (j == 0) {
                arr[i][j] = i;
            }
            else if (s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1];
            }
            else {
                arr[i][j] = 1 + min(arr[i][j-1], arr[i-1][j], arr[i-1][j-1]);
            }
        }
    }

    return arr[len1][len2]; // Return the final result
}

int main() {
    char str1[100], str2[100];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    printf("Levenshtein Distance: %d", levenshtein_distance(str1, str2));

    return 0;
}