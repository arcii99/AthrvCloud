//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
/* Enter Romeo */
int main() {
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    int love;
    printf("Do you love me? Enter 1 for Yes and 0 for No: ");
    scanf("%d", &love);
    if (love) {
        printf("My bounty is as boundless as the sea,\n");
        printf("My love as deep; the more I give to thee,\n");
        printf("The more I have, for both are infinite.\n");
    } else {
        printf("Alack, there lies more peril in thine eye\n");
        printf("Than twenty of their swords! Look thou but sweet,\n");
        printf("And I am proof against their enmity.\n");
    }

/* Enter Juliet */
    printf("And here comes Juliet...\n");
    int age;
    printf("How old are you? Enter your age: ");
    scanf("%d", &age);
    if (age < 13) {
        printf("What say you? can you love the gentleman?\n");
        printf("This night you shall behold him at our feast;\n");
        printf("Read o'er the volume of young Paris' face,\n");
        printf("And find delight writ there with beauty's pen;\n");
    } else {
        int money;
        printf("Do you have enough money to buy a ticket? Enter your amount: ");
        scanf("%d", &money);
        if (money < 50) {
            printf("My bounty is as boundless as the sea,\n");
            printf("My love as deep; the more I give to thee,\n");
            printf("The more I have, for both are infinite.\n");
        } else {
            printf("I cannot attend the play tonight, as I do not have enough money.\n");
            return 1;
        }
    }
    return 0;
}