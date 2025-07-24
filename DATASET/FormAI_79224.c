//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: statistical
#include<stdio.h>
#include<string.h>

int main() {
    char ccat[100], eng[100];
    char *ccat_phrases[] = {"Meow meow", "Purr purr", "Hiss hiss", "Scratch scratch", 
                        "Lick lick", "Nap nap", "Hunt hunt", "Sleep sleep", "Eat eat",
                        "Drink drink", "Jump jump", "Play play", "Run run", "Hide hide", 
                        "Climb climb", "Chase chase", "Sneak sneak", "Stalk stalk",
                        "Groom groom", "Roll roll", "Stretch stretch", "Wash wash",
                        "Watch watch", "Pounce pounce", "Bite bite", "Catch catch",
                        "Cuddle cuddle", "Hug hug", "Lay lay", "Lick face lick face", 
                        "Meow loudly meow loudly", "Nuzzle nuzzle", "Peek peek",
                        "Rub rub", "Snuggle snuggle", "Talk talk", "Yawn yawn", 
                        "Chirp chirp", "Follow follow", "Gaze gaze", "Howl howl", 
                        "Leap leap", "Rest rest", "Roam roam", "Sit sit", "Sprint sprint",
                        "Stare stare"};
    char *eng_translations[] = {"Hello there", "I am happy", "I am angry", "Please leave me alone",
                                "I am hungry", "I am thirsty", "Let's play", "I am tired",
                                "I want food", "I want water", "Jump with me", "Let's have fun",
                                "Let's run", "I am scared", "Climb higher", "Let's chase each other",
                                "I am sneaky", "Let's stalk", "I want to groom", "I want to roll around",
                                "Stretch with me", "I want to wash myself", "Let's watch",
                                "Let's pounce", "Do not bite me", "Catch the toy for me",
                                "Let's cuddle", "Let's hug", "I want to lay down", "I want to lick your face",
                                "I am annoyed", "I want to nuzzle", "Let's peek", "Rub against me",
                                "Let's snuggle", "Let's talk", "I am bored", "I am sleepy",
                                "Let's chirp", "Follow me", "Let's gaze at each other", "Howl with me",
                                "Let's leap", "Let's rest", "Let's roam", "Let's sit", "Let's sprint",
                                "Let's stare at something"};

    printf("Enter a phrase in C Cat Language:\n");
    fgets(ccat, 100, stdin);
    ccat[strcspn(ccat, "\n")] = 0; //removes the newline character

    for(int i=0; i<50; i++) {
        if(strcmp(ccat, ccat_phrases[i]) == 0) {
            strcpy(eng, eng_translations[i]);
            printf("The translation to English is: %s\n", eng);
            break;
        } else if(i == 49){
            printf("Sorry, I cannot translate that phrase.\n");
        }
    }

    return 0;
}