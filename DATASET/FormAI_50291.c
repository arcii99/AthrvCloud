//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int main(){

    printf("Enter your code in Cat Language: \n");

    char cat[100];
    fgets(cat, 100, stdin);

    int len = strlen(cat);

    printf("Translated Code in Romeo and Juliet Style: \n");

    for(int i=0; i<len; i++){

        if(cat[i] == 'm')
            printf("Romeo: O happy dagger!\n");

        else if(cat[i] == 'e')
            printf("Juliet: What's in a name? That which we call a rose\nBy any other word would smell as sweet.\n");

        else if(cat[i] == 'o')
            printf("Romeo: But, soft! What light through yonder window breaks?\nIt is the east, and Juliet is the sun.\n");

        else if(cat[i] == 'w')
            printf("Juliet: My bounty is as boundless as the sea,\nMy love as deep;\n");

        else if(cat[i] == 'a')
            printf("Romeo: See how she leans her cheek upon her hand!\nO that I were a glove upon that hand,\nThat I might touch that cheek!\n");

        else if(cat[i] == 'r')
            printf("Juliet: Good Night, Good night! Parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n");

        else if(cat[i] == 'u')
            printf("Romeo: Did my heart love till now? forswear it, sight! \nFor I ne'er saw true beauty till this night. \n");

        else if(cat[i] == 'y')
            printf("Juliet: O Romeo, Romeo! Wherefore art thou Romeo? \nDeny thy father and refuse thy name.\n");

        else if(cat[i] == 's')
            printf("Romeo: Love goes toward love, as schoolboys from their books,\nBut love from love, toward school with heavy looks.\n");

        else if(cat[i] == 't')
            printf("Juliet: Parting is such sweet sorrow, that I shall say good night till it be morrow.\n");

        else if(cat[i] == 'c')
            printf("Romeo: My love as deep; the more I give to thee,\nThe more I have, for both are infinite.\n");

        else
            printf("Invalid Cat Code!\n");
    }

    return 0;
}