//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    // Randomly generated phrases for the conspiracy theory
    char* phrase1[] = {"The government", "The Illuminati", "The Freemasons", "The aliens","The reptilians", "The Jews", "The Democrats", "The Republicans"};
    char* phrase2[] = {"have been", "are secretly", "have been caught", "are working to", "have successfully", "are manipulating us to", "have been planning to"};
    char* phrase3[] = {"control the world", "hide the truth about the moon landing", "prevent the apocalypse", "create a new world order", "bring about the end of days", "summon the Antichrist", "control the world's governments"};
    char* phrase4[] = {"by using", "with the help of", "through the manipulation of", "by implanting chips in", "by brainwashing", "by using a secret technology that", "with the cooperation of the UN that"};
    char* phrase5[] = {"the media", "the internet", "mass surveillance", "weather control", "the 5G network", "vaccines", "feminism and liberalism", "social justice warriors"};

    int phrase1_size = sizeof(phrase1)/sizeof(phrase1[0]);
    int phrase2_size = sizeof(phrase2)/sizeof(phrase2[0]);
    int phrase3_size = sizeof(phrase3)/sizeof(phrase3[0]);
    int phrase4_size = sizeof(phrase4)/sizeof(phrase4[0]);
    int phrase5_size = sizeof(phrase5)/sizeof(phrase5[0]);

    // Selecting random phrases for the conspiracy theory
    int random1 = rand() % phrase1_size;
    int random2 = rand() % phrase2_size;
    int random3 = rand() % phrase3_size;
    int random4 = rand() % phrase4_size;
    int random5 = rand() % phrase5_size;

    // Printing out the conspiracy theory
    printf("\nSherlock, I have discovered a conspiracy theory that might rock the foundations of our society!\n");
    printf("%s %s %s %s %s.\n", phrase1[random1], phrase2[random2], phrase3[random3], phrase4[random4], phrase5[random5]);
    printf("We must investigate further to uncover the truth!\n\n");

    return 0;
}