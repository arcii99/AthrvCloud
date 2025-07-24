//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char spamWords[30][100] = {"make money fast", "earn cash online", "work from home", "discount", "credit card", "free trial", "money-back guarantee", "make / earn $", "As Seen On", "Double your", "Get out of debt", "One-time", "Opportunity", "Risk-free", "Stock alert", "Stop snoring", "Prescription", "Weight", "Cash", "Loan", "Refinance", "Hidden", "Limited time", "Meet Singles"};
    char text[10000];
    printf("Enter the text: ");
    fgets(text, 10000, stdin);

    int i, j, count, n = strlen(text);
    for(i = 0; i < n; i++) {
        if(text[i] > 'A' && text[i] < 'Z') {
            text[i] += 32;
        }
    }

    char words[30][100];
    int index = 0, start = 0;

    for(i = 0; i < n; i++) {
        if(text[i] == ' ' || text[i] == '\n') {
            int length = i - start;
            for(j = 0; j < length; j++) {
                words[index][j] = text[start + j];
                if(words[index][j] > 'A' && words[index][j] < 'Z') {
                    words[index][j] += 32;
                }
            }
            words[index][j] = '\0';
            index++;
            start = i+1;
        }
    }

    count = 0;
    for(i = 0; i < index; i++) {
        for(j = 0; j < 25; j++) {
            if(strcmp(words[i], spamWords[j]) == 0) {
                count++;
                printf("'%s' is a spam word.\n", words[i]);
                break;
            }
        }
    }

    if(count > 0) {
        printf("\nThis is a spam message.\n");
    } else {
        printf("\nThis is not a spam message.\n");
    }

    return 0;
}