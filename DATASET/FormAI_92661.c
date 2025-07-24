//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_WORD_LENGTH 30

typedef struct {
    char* word1;
    char* word2;
    uint32_t** distanceMatrix;
    uint32_t result;
    bool completed;
} LevenshteinRequest;

uint32_t calculateLevenshteinDistance(uint32_t** matrix, char* word1, uint32_t len1, char* word2, uint32_t len2) {
    for (uint32_t i = 1; i <= len1; i++) {
        for (uint32_t j = 1; j <= len2; j++) {
            uint32_t substitutionCost = (word1[i-1] == word2[j-1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i-1][j]+1, matrix[i][j-1]+1), matrix[i-1][j-1]+substitutionCost);
        }
    }
    return matrix[len1][len2];
}

void* calculateLevenshteinDistanceAsync(void* args) {
    LevenshteinRequest* request = (LevenshteinRequest*)args;
    request->result = calculateLevenshteinDistance(request->distanceMatrix, request->word1, strlen(request->word1), request->word2, strlen(request->word2));
    request->completed = true;
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t thread1, thread2;
    uint32_t matrix1[MAX_WORD_LENGTH+1][MAX_WORD_LENGTH+1];
    uint32_t matrix2[MAX_WORD_LENGTH+1][MAX_WORD_LENGTH+1];

    LevenshteinRequest request1 = {
        .word1 = "kitten",
        .word2 = "sitting",
        .distanceMatrix = (uint32_t**)matrix1,
        .result = 0,
        .completed = false
    };

    LevenshteinRequest request2 = {
        .word1 = "coffee",
        .word2 = "cafe",
        .distanceMatrix = (uint32_t**)matrix2,
        .result = 0,
        .completed = false
    };

    pthread_create(&thread1, NULL, &calculateLevenshteinDistanceAsync, (void*)&request1);
    pthread_create(&thread2, NULL, &calculateLevenshteinDistanceAsync, (void*)&request2);

    while (!request1.completed || !request2.completed) {
        printf("Calculating Levenshtein Distance...\n");
        sleep(1);
    }

    printf("The Levenshtein Distance between 'kitten' and 'sitting': %d\n", request1.result);
    printf("The Levenshtein Distance between 'coffee' and 'cafe': %d\n", request2.result);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS;
}