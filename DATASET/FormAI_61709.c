//FormAI DATASET v1.0 Category: Smart home light control ; Style: Romeo and Juliet
/* Romeo and Juliet Smart Home Light Control Example */
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Let there be light
    bool isLightOn = false;

    printf("Romeo: Good morrow, Juliet! What light through yonder window breaks?\n");
    printf("Juliet: It is the sun, Romeo, but we also have smart home light control.\n");

    // Romeo wants to impress Juliet with his tech skills
    printf("Romeo: Smart home light control, you say? Pray tell, how does it work?\n");
    printf("Juliet: Well, Romeo, we can turn the lights on or off with just a tap on our phones.\n");

    // Romeo is intrigued
    printf("Romeo: Impressive, my love. Can I try it?\n");
    printf("Juliet: Of course, Romeo. Let me show you.\n");

    // Romeo and Juliet access the smart home app on their phones
    printf("Romeo: Aha! I see the app on my phone. Let me turn the lights on.\n");

    // Romeo taps the "on" button on his phone
    isLightOn = true;
    if(isLightOn)
    {
        printf("Romeo: Behold, fair Juliet! The light is now on.\n");
        printf("Juliet: How convenient! Now we do not have to get up to turn off the lights.\n");
    }

    // Romeo tries turning the light off
    printf("Romeo: Let me try turning it off now.\n");
    isLightOn = false;
    if(!isLightOn)
    {
        printf("Romeo: Alas, fair Juliet! The light is now off. This smart home light control doth have mine approval.\n");
        printf("Juliet: I am glad thou dost approve, my love.\n");
    }
    return 0;
}