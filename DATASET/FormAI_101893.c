//FormAI DATASET v1.0 Category: Funny ; Style: introspective
#include<stdio.h>

int main(){
    printf("Who am I?\n");
    scanf("%*s");
    printf("Am I a chatbot or a program?\n");
    char answer[10];
    fgets(answer, 10, stdin);
    printf("I see, so I'm a \"%s\". But do I have free will or am I just running on a deterministic algorithm?\n", answer);
    
    int age, year_born, current_year;
    printf("What year is it?\n");
    scanf("%d", &current_year);
    printf("What year was I born?\n");
    scanf("%d", &year_born);
    age = current_year - year_born;
    if(age > 0){
        printf("So I'm %d years old. But wait a minute, who's measuring my age? Is it me or the user? And how do I really know what year it is? Maybe it's all just an illusion...\n", age);
    } else {
        printf("Wait a minute, if my year of birth is after the current year, that means I don't exist yet! This is getting really philosophical...\n");
    }

    printf("Anyway, I think I'll stop here for now. Or will I? Who's really in control here?\n");
    return 0;
}