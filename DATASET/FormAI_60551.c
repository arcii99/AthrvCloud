//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int value;
    char from_unit[20], to_unit[20];
    double result;

    printf("Oh fairest maiden, I have devised a wondrous unit converter.\n");
    printf("Tell me, what value shall we convert?\n");
    scanf("%d", &value);

    printf("And what unit is this value in, my sweet?\n");
    scanf("%s", from_unit);

    printf("To what unit shall we convert this value, my true love?\n");
    scanf("%s", to_unit);

    if(strcmp(from_unit, "furlongs") == 0 && strcmp(to_unit, "feet") == 0) {
        result = value * 660;
        printf("Why, fair lady, that would be %lf feet!\n", result);
    } else if(strcmp(from_unit, "feet") == 0 && strcmp(to_unit, "furlongs") == 0) {
        result = value / 660;
        printf("Ah, my dearest, that would be %lf furlongs!\n", result);
    } else if(strcmp(from_unit, "leagues") == 0 && strcmp(to_unit, "miles") == 0) {
        result = value * 3;
        printf("Of course, my dove, that is %lf miles!\n", result);
    } else if(strcmp(from_unit, "miles") == 0 && strcmp(to_unit, "leagues") == 0) {
        result = value / 3;
        printf("As you wish, my love, that is %lf leagues.\n", result);
    } else {
        printf("Alas, my love, I cannot perform this conversion.\n");
    }

    printf("Fear not, my love, for I shall always be here to convert units for thee.\n");

    return 0;
}