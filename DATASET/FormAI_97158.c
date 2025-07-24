//FormAI DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {
    char text[1000];
    char options[4][50];
    int correctOption;
};

int main() {
    struct question questions[10];

    strcpy(questions[0].text, "What is the significance of the year 2077 in cyberpunk literature?");
    strcpy(questions[0].options[0], "It marks the advent of artificial intelligence.");
    strcpy(questions[0].options[1], "It marks the beginning of the end for humanity.");
    strcpy(questions[0].options[2], "It marks the year when corporations gain complete control over society.");
    strcpy(questions[0].options[3], "None of the above.");
    questions[0].correctOption = 2;

    strcpy(questions[1].text, "Who is the protagonist in the Cyberpunk 2077 game?");
    strcpy(questions[1].options[0], "Adam Jensen");
    strcpy(questions[1].options[1], "V");
    strcpy(questions[1].options[2], "Johnny Silverhand");
    strcpy(questions[1].options[3], "None of the above.");
    questions[1].correctOption = 1;

    strcpy(questions[2].text, "What is the main objective of the Deus Ex game series?");
    strcpy(questions[2].options[0], "To take down a corrupt government agency.");
    strcpy(questions[2].options[1], "To uncover a conspiracy theory.");
    strcpy(questions[2].options[2], "To explore a post-apocalyptic world.");
    strcpy(questions[2].options[3], "None of the above.");
    questions[2].correctOption = 0;

    strcpy(questions[3].text, "Which of the following is not a major theme in cyberpunk literature?");
    strcpy(questions[3].options[0], "The dangers of advanced technology");
    strcpy(questions[3].options[1], "The power of corporations");
    strcpy(questions[3].options[2], "The consequences of genetic engineering");
    strcpy(questions[3].options[3], "None of the above.");
    questions[3].correctOption = 2;

    strcpy(questions[4].text, "In the movie Blade Runner, what are replicants?");
    strcpy(questions[4].options[0], "Super soldiers created by the government");
    strcpy(questions[4].options[1], "Synthetic humans created by corporations");
    strcpy(questions[4].options[2], "Alien life forms");
    strcpy(questions[4].options[3], "None of the above.");
    questions[4].correctOption = 1;

    strcpy(questions[5].text, "What is a common element in most cyberpunk literature and games?");
    strcpy(questions[5].options[0], "The presence of artificial intelligence");
    strcpy(questions[5].options[1], "The use of advanced weaponry");
    strcpy(questions[5].options[2], "The presence of a mega-city");
    strcpy(questions[5].options[3], "None of the above.");
    questions[5].correctOption = 2;

    strcpy(questions[6].text, "What is the name of the city in which the Neuromancer novel takes place?");
    strcpy(questions[6].options[0], "Neo-Tokyo");
    strcpy(questions[6].options[1], "Night City");
    strcpy(questions[6].options[2], "Chiba City");
    strcpy(questions[6].options[3], "None of the above.");
    questions[6].correctOption = 2;

    strcpy(questions[7].text, "Who is the author of the Neuromancer novel?");
    strcpy(questions[7].options[0], "William Gibson");
    strcpy(questions[7].options[1], "Philip K. Dick");
    strcpy(questions[7].options[2], "Isaac Asimov");
    strcpy(questions[7].options[3], "None of the above.");
    questions[7].correctOption = 0;

    strcpy(questions[8].text, "What is the main objective of the Watch Dogs game series?");
    strcpy(questions[8].options[0], "To hack into and disrupt various systems to take down corrupt corporations");
    strcpy(questions[8].options[1], "To infiltrate a government agency and uncover a conspiracy");
    strcpy(questions[8].options[2], "To explore an open world and complete various missions");
    strcpy(questions[8].options[3], "None of the above.");
    questions[8].correctOption = 0;

    strcpy(questions[9].text, "Which of the following is not a major influence on cyberpunk literature and culture?");
    strcpy(questions[9].options[0], "Japanese anime and manga");
    strcpy(questions[9].options[1], "The punk movement of the 1970s and 1980s");
    strcpy(questions[9].options[2], "The writing of J.R.R. Tolkien");
    strcpy(questions[9].options[3], "None of the above.");
    questions[9].correctOption = 2;

    int score = 0;
    char ans[10];

    printf("Welcome to the Cyberpunk Online Examination System. You will be given 10 multiple choice questions related to the genre.\n");
    printf("Enter your answers in the format 'a', 'b', 'c' or 'd' and press enter.\n");

    for(int i=0; i<10; i++) {
        printf("\n\nQuestion %d: %s\n", i+1, questions[i].text);
        printf("a. %s\n", questions[i].options[0]);
        printf("b. %s\n", questions[i].options[1]);
        printf("c. %s\n", questions[i].options[2]);
        printf("d. %s\n", questions[i].options[3]);

        printf("Your answer: ");
        scanf("%s", ans);

        if(ans[0] >= 'A' && ans[0] <= 'Z') {
            ans[0] = ans[0] - 'A' + 'a';
        }

        if(ans[0] == 'a' || ans[0] == 'b' || ans[0] == 'c' || ans[0] == 'd') {
            if(ans[0] == 'a' && questions[i].correctOption == 0) {
                score++;
            }
            else if(ans[0] == 'b' && questions[i].correctOption == 1) {
                score++;
            }
            else if(ans[0] == 'c' && questions[i].correctOption == 2) {
                score++;
            }
            else if(ans[0] == 'd' && questions[i].correctOption == 3) {
                score++;
            }
        }
        else {
            printf("Invalid answer format. Please try again.\n");
            i--;
        }
    }

    printf("\n\nCongratulations! You have completed the Cyberpunk Online Examination System.\n");
    printf("Your score is: %d\n", score);

    return 0;
}