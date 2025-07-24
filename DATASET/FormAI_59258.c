//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESUME_LENGTH 10000  // Maximum length of resume to be parsed
#define MAX_WORD_LENGTH 30  // Maximum length of a word in resume
#define MAX_KEYWORD_LENGTH 50  // Maximum length of a keyword to be searched

// Structure to store keywords and their corresponding weightage
typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int weightage;
} Keyword;

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to parse a resume and return the frequency of each word found in it
WordFrequency* parseResume(char* resume) {
    WordFrequency* wordFreq = malloc(MAX_RESUME_LENGTH * sizeof(WordFrequency));  // Allocate memory for array to store words and their frequency
    char* word = strtok(resume, " ,\n");  // Get the first word in resume
    int count = 0;
    
    while (word != NULL) {
        bool isNewWord = true;
        for (int i = 0; i < count; i++) {  // Check if the word has already been found in resume
            if (strcmp(word, wordFreq[i].word) == 0) {
                isNewWord = false;
                wordFreq[i].frequency++;
                break;
            }
        }
        if (isNewWord) {  // If the word is a new word, add it to the wordFreq array
            strcpy(wordFreq[count].word, word);
            wordFreq[count].frequency = 1;
            count++;
        }
        word = strtok(NULL, " ,\n");  // Get the next word in resume
    }
    
    return wordFreq;
}

// Function to calculate the total weightage of keywords found in a resume
int calculateWeightage(char* resume, Keyword* keywords, int numKeywords) {
    int totalWeightage = 0;
    for (int i = 0; i < numKeywords; i++) {  // Check for each keyword in resume
        if (strstr(resume, keywords[i].keyword) != NULL) {  // If the keyword is found, add its weightage to total weightage
            totalWeightage += keywords[i].weightage;
        }
    }
    return totalWeightage;
}

int main() {
    char resume[MAX_RESUME_LENGTH] = "I am a software developer with experience in multiple programming languages including C, Java and Python. I have worked on various projects ranging from creating web applications to developing algorithms for data processing. I have strong analytical and problem solving skills. Currently, I am looking for a new challenge where I can apply my skills and learn new things.";
    Keyword keywords[3] = {{"software", 10}, {"developer", 20}, {"C", 5}};  // Keywords to be searched with their weightage
    int numKeywords = 3;
    
    WordFrequency* wordsFound = parseResume(resume);  // Get all the words and their frequency in the resume
    int totalWeightage = calculateWeightage(resume, keywords, numKeywords);  // Calculate the total weightage of all the keywords found in resume
    
    printf("Total weightage of keywords found in resume: %d\n", totalWeightage);
    printf("Words found in resume and their frequency:\n");
    for (int i = 0; i < MAX_RESUME_LENGTH; i++) {
        if (wordsFound[i].frequency == 0) {  // Stop printing words if their frequency is 0
            break;
        }
        printf("%s: %d\n", wordsFound[i].word, wordsFound[i].frequency);
    }
    
    free(wordsFound);  // Free the memory allocated for wordsFound array
    return 0;
}