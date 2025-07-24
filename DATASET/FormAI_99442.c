//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>

int main(){
    int day, month, year;
    char entry[1000];

    printf("Welcome to your digital diary!\n");
    printf("What day is it today?\n");
    scanf("%d", &day);
    printf("What month is it?\n");
    scanf("%d", &month);
    printf("What year is it?\n");
    scanf("%d", &year);
    printf("\nEnter your entry for today:\n");
    scanf("%[^\n]", entry);

    printf("\n\n\tDear Diary,\n\n");
    printf("\tToday is %02d-%02d-%04d. Wow, time flies so fast!\n", day, month, year);
    printf("\tSo, what's new? Let me check... Oh my goodness, I just remembered that I wrote this program myself!\n");
    printf("\tI've been spending too much time staring at this screen, I think it's starting to affect my cognitive function...\n");
    printf("\tErr, right, back to the diary entry! Today was another boring day. I woke up, ate breakfast, and went to work.\n");
    printf("\tWork was pretty uneventful, as usual. I spent most of the day staring at my computer screen, wishing I was doing something more exciting.\n");
    printf("\tAfter work, I came home, had dinner, and started writing this diary entry. I'll probably watch some TV or play some video games for a bit before going to bed.\n");
    printf("\tWell, that's about it for today. Good night, Diary!\n\n");
    printf("\tYours truly,\n\tMr. C. Bot\n");
    
    return 0;
}