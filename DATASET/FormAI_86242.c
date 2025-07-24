//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // list of fortunes
    char *fortunes[] = {
        "You will find happiness in unexpected places.",
        "A new opportunity will soon come your way.",
        "Your hard work will pay off in the near future.",
        "Expect a surprise in your love life.",
        "Your finances will improve greatly.",
        "You will make a new friend very soon.",
        "Take risks and you will be greatly rewarded.",
        "Your health will remain strong for years to come.",
        "A long-held dream will soon become a reality.",
        "Your life will be filled with joy and adventure.",
        "You will find success in all your endeavors.",
        "Now is the time to take charge of your life.",
        "Good things come to those who wait.",
        "Your future is very bright indeed.",
        "A loved one will bring you great happiness.",
        "Your creativity will lead to great success.",
        "You will overcome all obstacles in your path.",
        "A great opportunity for travel is coming your way.",
        "Your happiness is just around the corner.",
        "Now is the time to chase your dreams."
    };

    // get random index from list of fortunes
    int index = rand() % (sizeof(fortunes) / sizeof(char *));
    char *fortune = fortunes[index];

    // display fortune
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Here is your fortune:\n%s\n\n", fortune);

    return 0;
}