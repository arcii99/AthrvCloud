//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void printHeader() {
    printf("\n\n//******************************************************\\\n");
    printf("||  The Random Conspiracy Theory Generator: Sherlock Edition ||\n");
    printf("\\\\******************************************************//\n\n");
    sleep(1);
}

void generateTitle(char title[]) {
    char* start[] = {"The Mysterious Case of ", "The Shocking Revelation About ", "The Startling Discovery of "};
    char* middle[] = {"The Secret Society of ", "The Hidden Agenda of ", "The Missing Piece of the Puzzle for "};
    char* end[] = {"The Global Elite", "The Illuminati", "The New World Order"};

    int startCount = sizeof(start)/sizeof(start[0]);
    int midCount = sizeof(middle)/sizeof(middle[0]);
    int endCount = sizeof(end)/sizeof(end[0]);

    strcpy(title, start[rand()%startCount]);
    strcat(title, middle[rand()%midCount]);
    strcat(title, end[rand()%endCount]);

    printf("Title: %s\n\n", title);
    sleep(2);
}

void generateBody() {
    int paraCount = rand()%5 + 5;
    char* para[] = {"The truth is out there, my dear Watson!", "There is a conspiracy at work here.", "It all starts to make sense, doesn't it?", "Pay attention to the facts.", "As I suspected all along, Watson."};

    int paraLen = sizeof(para)/sizeof(para[0]);
    char body[2000] = "";
    printf("Body:\n");

    for(int i=0; i<paraCount; i++) {
        strcat(body, para[rand()%paraLen]);
        strcat(body, " ");
    }

    printf("%s\n\n", body);
    sleep(2);
}

void generateConclusion() {
    char* end[] = {"So, there you have it. The truth is stranger than fiction.", "The game is afoot, my dear Watson.", "I'll leave you to ponder upon that.", "The truth always comes out, in the end."};

    int endCount = sizeof(end)/sizeof(end[0]);
    printf("Conclusion: ");
    printf("%s\n\n", end[rand()%endCount]);
    sleep(2);
}

void generateTheory() {
    char title[200];
    generateTitle(title);
    generateBody();
    generateConclusion();
}

int main() {
    srand(time(NULL));
    printHeader();
    generateTheory();

    return 0;
}