//FormAI DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the random seed
    
    // surreal weather variables
    int raindrops = rand() % 1000;
    int snowflakes = rand() % 1000;
    int sunrays = rand() % 1000;
    int clouds = rand() % 1000;

    printf("You wake up to a strange day...\n\n");
    printf("The sky is a mix of colors you've never seen before, and the air smells like cotton candy on fire.\n");
    printf("You look outside and see...\n\n");
    
    // determine the weather
    if (raindrops > 500) {
        printf("Raindrops are falling from the sky like razors. You don't want to go outside today.\n");
    }
    else if (snowflakes > 500) {
        printf("Snowflakes are falling from the sky as big as dinner plates. You better bundle up if you have to go out.\n");
    }
    else if (sunrays > 500) {
        printf("The sun is shining brighter than a million light bulbs. You might need some sunglasses today.\n");
    }
    else if (clouds > 500) {
        printf("The clouds are swirling in the sky like giant cotton candy machines. You might want to stay inside today.\n");
    }
    else {
        printf("There's no telling what the weather is going to be like today. Better bring an umbrella just in case.\n");
    }

    printf("\nYou decide to venture outside anyway...\n\n");

    // random surreal events happen
    int event = rand() % 10;
    switch (event) {
        case 0:
            printf("You see a giant garden gnome eating a hotdog on the side of the road.\n");
            break;
        case 1:
            printf("A group of penguins are walking down the street in top hats and bow ties.\n");
            break;
        case 2:
            printf("You trip over a rock and find yourself in a secret garden full of talking rabbits.\n");
            break;
        case 3:
            printf("A fish falls from the sky and lands in your pocket. It's still alive.\n");
            break;
        case 4:
            printf("A rainbow colored unicorn flies over your head, leaving behind a trail of glitter and rainbows.\n");
            break;
        case 5:
            printf("You see a man walking his pet cactus on a leash. The cactus waves at you.\n");
            break;
        case 6:
            printf("A group of flying llamas swoop down and give you a ride to your destination.\n");
            break;
        case 7:
            printf("A tree uproots itself and walks across the street in front of you.\n");
            break;
        case 8:
            printf("A swarm of bees flies around you forming the shape of an eye. You blink and they're gone.\n");
            break;
        case 9:
            printf("A man dressed as a giant clam gives you a brochure on 'how to be a better unicorn'.\n");
            break;
    }

    printf("\nYou start to feel like you're in a dream. Maybe you are. Everything is just too surreal.\n");

    printf("\nAs the day goes on, the weather changes again and again. It's impossible to keep track of what's happening.\n");
    printf("Tornadoes, hurricanes, and earthquakes come and go like visitors from another planet.\n");
    printf("But somehow, you feel safe and alive. This is a day you'll never forget.\n");

    return 0;
}