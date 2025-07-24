//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller\n\n");
    printf("Think of a question and I will tell you your fortune!\n\n");

    //Declare arrays for responses
    char* responses[20];
    char* good_responses[10];
    char* bad_responses[10];
    int i, j, k;

    //Good responses
    good_responses[0] = "The stars say that your future looks bright!";
    good_responses[1] = "You will soon be blessed with good fortune!";
    good_responses[2] = "Your wishes will soon come true!";
    good_responses[3] = "The future looks promising for you!";
    good_responses[4] = "Positive energy surrounds you. Good things are coming!";
    good_responses[5] = "You are destined for success!";
    good_responses[6] = "Your dreams will soon become a reality!";
    good_responses[7] = "The universe is working in your favor!";
    good_responses[8] = "You have a bright future ahead of you!";
    good_responses[9] = "You are loved and supported by those around you!";

    //Bad responses
    bad_responses[0] = "Sorry, the outlook is not good.";
    bad_responses[1] = "The signs point to disappointment ahead.";
    bad_responses[2] = "You may face challenges and obstacles in the near future.";
    bad_responses[3] = "Negative energy surrounds you. Be prepared for hardships.";
    bad_responses[4] = "Unfortunately, things may not go your way.";
    bad_responses[5] = "You may experience a setback or delay in your plans.";
    bad_responses[6] = "The road ahead may be bumpy. Stay strong.";
    bad_responses[7] = "Unforeseen circumstances may disrupt your path.";
    bad_responses[8] = "It may take some time, but things will get better in the end.";
    bad_responses[9] = "Stay positive and keep pushing forward. The hard times will pass.";

    //Fill responses array with good_responses and bad_responses
    k = 0;
    for(i = 0; i < 10; i++) {
        responses[k] = good_responses[i];
        k++;
        responses[k] = bad_responses[i];
        k++;
    }

    //Seed random number generator
    srand(time(NULL));

    //Press enter to continue
    printf("Press enter to see your fortune...");
    getchar();

    //Generate random index for responses array
    int rand_index = rand() % 20;

    //Print response
    printf("%s\n", responses[rand_index]);

    return 0;
}