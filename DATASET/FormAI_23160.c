//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>

void apocalypse(int count);

int main() 
{
    printf("The world has ended. \n");
    printf("The sky is a murky red. The air is thick with smoke. \n");
    printf("But there is still hope. There are still survivors. \n");

    printf("How many survivors do we have?\n");
    int count;
    scanf("%d", &count);

    apocalypse(count);

    printf("The end is near. The survivors are dwindling. \n");
    printf("But we won't give up. We will keep fighting. \n");

    return 0;
}

void apocalypse(int count) 
{
    if (count <= 0) 
    {
        printf("No one survived the apocalypse.\n");
        return;
    }

    printf("There are still %d survivors.\n", count);
    printf("Food and resources are scarce. But we will persevere.\n");

    int new_count = count - 1;

    printf("We have lost one of our own. There are now %d of us left.\n", new_count);

    apocalypse(new_count);
}