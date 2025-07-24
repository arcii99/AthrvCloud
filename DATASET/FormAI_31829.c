//FormAI DATASET v1.0 Category: Smart home light control ; Style: Romeo and Juliet
#include<stdio.h>

int main(void)
{
    int love = 1;
    int hatred = 0;
    printf("Two households, both alike in dignity,\nIn fair Verona, where we lay our scene,\nFrom ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.\n");

    while (love)
    {
        int balcony = 0;
        int light_control = 0;
        printf("But, soft! what light through yonder window breaks?\nIt is the east, and Juliet is the sun.\n");

        while (!balcony) 
        {
            printf("Shall I hear more, or shall I speak at this?\n");
            printf("Enter 1 to hear more. Enter 0 to exit.\n");
            scanf("%d", &balcony);
        }

        if (balcony)
        {
            printf("Her eyes are like stars, and her lips like roses!\n");
            printf("What light is she using? Let me control it!\n");
            printf("Enter 1 to turn on the light. Enter 0 to turn off the light.\n");
            scanf("%d", &light_control);
            if (light_control)
            {
                printf("Goodnight, goodnight! Parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n");
            }
            else
            {
                printf("O, swear not by the moon, the inconstant moon,\nThat monthly changes in her circled orb,\nLest that thy love prove likewise variable.\n");
            }
        }
        else
        {
            printf("But, soft! what light through yonder window breaks?\nIt is the east, and Juliet is the sun.\n");
        }

        printf("Enter 1 to continue controlling the light. Enter 0 to quit.\n");
        scanf("%d", &love);
    }

    printf("These violent delights have violent ends,\nAnd in their triumph die, like fire and powder,\nWhich as they kiss consume: the sweetest honey\nIs loathsome in his own deliciousness,\nAnd in the taste confounds the appetite:\nTherefore love moderately; long love doth so;\nToo swift arrives as tardy as too slow.\n");
    return 0;
}