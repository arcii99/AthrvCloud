//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>

int main() {
    printf("*** Welcome to the Haunted House Simulator! ***\n");
    printf("You are standing outside a spooky old mansion. The wind is howling, and the trees are creaking.\n");
    printf("Do you want to enter the house? (y/n)\n");

    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {
        printf("You push open the creaky old door and step inside. The door slams shut behind you, and you hear it lock.\n");
        printf("You look around. The place is in shambles. The wallpaper is peeling, and there are cobwebs everywhere.\n");
        printf("Suddenly, you hear a low growl coming from the darkness. Do you want to investigate? (y/n)\n");

        scanf(" %c", &choice);

        if (choice == 'y') {
            printf("You slowly make your way down a dark hallway, the floorboards creaking under your feet.\n");
            printf("As you reach the end of the hallway, you see a figure standing in the shadows. You can't make out what it is.\n");
            printf("Do you want to approach the figure? (y/n)\n");

            scanf(" %c", &choice);

            if (choice == 'y') {
                printf("As you step closer, you see that the figure is a ghostly apparition. It turns and looks at you with empty eyes.\n");
                printf("Suddenly, it screams and rushes at you. You try to run, but your feet are stuck to the floor.\n");
                printf("You realize too late that you're trapped in this house forever, doomed to wander its halls as a lost soul.\n");
            } else {
                printf("You decide to turn around and run back the way you came. But as you run, you hear something chasing you.\n");
                printf("You don't make it very far before a ghoul grabs you and pulls you down into the darkness.\n");
                printf("You realize too late that you're trapped in this house forever, doomed to wander its halls as a lost soul.\n");
            }
        } else {
            printf("You decide you've had enough of this house. You turn around to leave, but the door won't budge.\n");
            printf("You're trapped here forever, doomed to wander its halls as a lost soul.\n");
        }
    } else {
        printf("You turn and leave, determined not to be fooled by a silly ghost story.\n");
        printf("The wind continues to howl, but you're relieved to be outside in the fresh air.\n");
    }

    return 0;
}