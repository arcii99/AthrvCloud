//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Surrealist browser plugin that displays random art*/

static const char ART_LIST[][50] = {
    "A melting clock on a barren landscape",
    "A tree with leaves made of feathers",
    "A giant spoon crushing a city skyline",
    "A snake made of neon lights",
    "A human heart inside a fishbowl",
    "A piano floating in outer space",
    "A bicycle with no wheels",
    "A typewriter with keys made of teeth",
    "A flower blooming from a shoe",
    "A bird flying backwards",
    "A breaking wave made of fire",
    "A rainbow in the shape of a question mark"
};

void display_random_art(void){
    int random_index = rand() % (sizeof(ART_LIST)/sizeof(ART_LIST[0]));
    printf("The surreal art being displayed is: %s\n", ART_LIST[random_index]);
}

int main(){
    display_random_art();
    return 0;
}