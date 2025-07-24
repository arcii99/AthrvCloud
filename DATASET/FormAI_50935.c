//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_SPAM_WORDS 100
#define SPAM_THRESHOLD 0.5

// function to calculate cosine similarity between two vectors
double cosineSimilarity(double A[], double B[], int vectorSize) {
    double dotProduct = 0.0, magA = 0.0, magB = 0.0;
    for(int i = 0; i < vectorSize; ++i) {
        dotProduct += A[i] * B[i];
        magA += A[i] * A[i];
        magB += B[i] * B[i];
    }
    if(magA == 0.0 || magB == 0.0) return 0.0;
    return dotProduct / (sqrt(magA) * sqrt(magB));
}

// function to preprocess email text, removing punctuation marks and converting to lowercase
void preprocessEmail(char *email) {
    for(int i = 0; email[i]; ++i) {
        if(email[i] >= 'A' && email[i] <= 'Z') {
            email[i] = email[i] - 'A' + 'a'; // converting uppercase to lowercase
        }
        // replacing punctuation marks with space
        if(email[i] == ',' || email[i] == '.' || email[i] == ';' || email[i] == ':' || 
        email[i] == '(' || email[i] == ')' || email[i] == '{' || email[i] == '}' || 
        email[i] == '<' || email[i] == '>' || email[i] == '\'' || email[i] == '\"' || 
        email[i] == '[' || email[i] == ']' || email[i] == '?' || email[i] == '!') {
            email[i] = ' ';
        }
    }
}

int main() {
    char email[MAX_EMAIL_SIZE];
    char spamWords[MAX_SPAM_WORDS][20] = {"loans", "viagra", "money", "lottery", "free", 
    "prize", "win", "cash", "urgent", "act now", "credit card", "offer", "lowest price", 
    "limited time", "risk-free", "apply now", "double your", "money back guarantee", 
    "meet singles", "teen sex"};

    int numSpamWords = sizeof(spamWords) / sizeof(spamWords[0]);
    double emailVector[MAX_SPAM_WORDS] = {0}, spamVector[MAX_SPAM_WORDS] = {0};

    while(1) {
        printf("\nEnter an email or 'q' to quit: ");
        fgets(email, MAX_EMAIL_SIZE, stdin);
        if(email[0] == 'q') break;

        preprocessEmail(email); // preprocess email text
        int emailLength = strlen(email);
        if(email[emailLength-1] == '\n') email[emailLength-1] = '\0';

        // calculate email vector and spam vector using occurrence of spam words
        for(int i = 0; i < numSpamWords; ++i) {
            char *word = spamWords[i];
            char *ptr = strstr(email, word);
            while(ptr != NULL) {
                emailVector[i]++;
                ptr = strstr(ptr + 1, word);
            }
            spamVector[i] = (double)100 / numSpamWords; // initializing spam vector with equal probability
        }

        double similarity = cosineSimilarity(emailVector, spamVector, numSpamWords);
        printf("Cosine similarity with spam vector: %lf\n", similarity);
        if(similarity > SPAM_THRESHOLD) {
            printf("This email is marked as SPAM!\n");
        } else {
            printf("This email is not SPAM.\n");
        }
    }
    return 0;
}