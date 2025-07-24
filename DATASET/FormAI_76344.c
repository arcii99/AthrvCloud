//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char* positiveWords[10] = {"victory", "honorable", "brave", "chivalrous", "admirable", "valor", "just", "worthy", "noble", "gallant"};
    char* negativeWords[10] = {"treacherous", "cowardly", "dishonorable", "malice", "deceitful", "evil", "vile", "cruel", "tyrannical", "corrupt"};
    int positiveCount = 0;
    int negativeCount = 0;

    printf("Greetings traveler! I am a Sentiment Analysis tool, and I am here to judge the sentiments of your words.\n");
    printf("Enter your word or phrase:\n");
    scanf("%[^\n]", input);

    char* word = strtok(input, " ");
    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strstr(word, positiveWords[i]) != NULL) {
                positiveCount++;
                break;
            }
            else if (strstr(word, negativeWords[i]) != NULL) {
                negativeCount++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    if (positiveCount > negativeCount) {
        printf("\nThou art speaking in a positive manner, keep going and enjoy thy day!\n");
    }
    else if (positiveCount < negativeCount) {
        printf("\nThou art speaking in a negative manner, beware of thy words and have a care for those around thee.\n");
    }
    else {
        printf("\nThou art quite neutral in thy speech, but do not be afraid to express thyself.\n");
    }

    return 0;
}