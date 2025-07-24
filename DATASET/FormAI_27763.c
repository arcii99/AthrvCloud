//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int rating;
    printf("Oh Romeo, how wouldst thou rate this movie on a scale of one to ten?\n");
    scanf("%d", &rating);
    
    if (rating < 5) {
        printf("Oh Juliet! Alack and alas! This movie is a tragedy as dire as ours!\n");
    }
    else if (rating >= 5 && rating < 7) {
        printf("Oh feisty Romeo! Thou hast mixed emotions, like thyself when you saw me at the masked ball. The movie is not entirely good nor bad.\n");
    }
    else if (rating >= 7 && rating < 9) {
        printf("Oh my sweet Romeo! Thy rating doth show great approval! 'Tis a fine movie indeed!\n");
    }
    else if (rating >= 9 && rating <= 10) {
        printf("Oh noble and kind Romeo! Thou hast given the highest rating possible! The movie doth deserve such high esteem!\n");
    }
    else {
        printf("Oh Romeo, thou hast entered a rating beyond the scale! Art thou trying to be humorous?\n");
    }
    
    return 0;
}