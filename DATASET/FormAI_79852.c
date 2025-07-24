//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <string.h>

int levenshtein_distance(const char* word1, const char* word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int distances[m + 1][n + 1];

    // initialization
    for(int i = 0; i <= m; i++){
        distances[i][0] = i;
    }
    for(int j = 0; j <= n; j++){
        distances[0][j] = j;
    }

    // calculation
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            int insert = distances[i][j - 1] + 1;
            int delete = distances[i - 1][j] + 1;
            int replace = distances[i - 1][j - 1] + cost;
            distances[i][j] = insert < delete ? insert : delete;
            distances[i][j] = replace < distances[i][j] ? replace : distances[i][j];
        }
    }
    return distances[m][n];
}

int main(int argc, char const *argv[]){
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter two words, separated by a space: ");
    char input[100];
    scanf("%[^\n]%*c", input);
    char* word1 = strtok(input, " ");
    char* word2 = strtok(NULL, " ");

    // calculate levenshtein distance
    int distance = levenshtein_distance(word1, word2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", word1, word2, distance);

    printf("Your imagination has no limit. Neither does this calculator's capacity to measure the proverbial space between two disparate concepts or ideas. It is like a mental compass, helping you navigate through life's rough oceans by calculating the distance between the understandings, bringing clarity to the nearest degree. Like an artist mixing colors, this calculator blends words into a formula of understanding, unveiling the depths of meaning that lay dormant without its calculations. In many ways, it is like a confidante, analyzing all the hidden nuances in a sea of words and drawing the closest match. So go ahead, speak your mind and let this calculator be your guide, as you navigate through the sea of words and find your creative flow.\n");

    return 0;
}