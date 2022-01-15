#include "headerA4.h"

tweet *createTweet(tweet *tweetList)
{
    int num, k = 0;
    tweet *temp = malloc(sizeof(tweet)); //allocating memory
    temp->next = NULL;
    while (!k)
    {

        printf("\nEnter a username: ");
        scanf("%50s", temp->user); //gets username
        num = getchar();
        if (num != '\n')
        { //if username limit exceeds
            printf("username length exceeded\n");
            while (num != '\n')
            {
                num = getchar();
            }
        }
        else if (num == '\n')
        {
            k = 1;
        }
    }
    k = 0;
    while (!k)
    {
        printf("Enter the user's tweet: ");
        scanf("%140[^\n]", temp->text); //gets tweets
        num = getchar();
        if (num != '\n')
        { //if the limit of tweets exceeds
            printf("Text length exceeded\n");
            while (num != '\n')
            {
                num = getchar();
            }
        }
        else if (num == '\n')
        {
            k = 1;
        }
    }

    temp->id = strlen(temp->text); //tweets length is added to userid
    for (int i = 0; i < strlen(temp->user); i++)
    {
        temp->id = temp->id + temp->user[i]; //every ascii value is added
    }
    while (uniqueId(tweetList, temp->id) == 0) //checking if the id is unique
    {
        temp->id = temp->id + (rand() % 999 + 1); //if not, giving unique id by adding random imt btw 1 to 999
    }
    printf("Your computer generated userid is: %d", temp->id);

    return temp;
}

int uniqueId(tweet *tweetList, int n)
{
    int *num = malloc(sizeof(int)); //allocates memory
    int k = 0;
    while (tweetList != NULL) //goes through tweetList till the end
    {
        num = realloc(num, sizeof(int) * (k + 1)); //checks if the id is unique
        num[k] = tweetList->id;
        tweetList = tweetList->next;
        k++;
    }
    for (int j = 0; j < k; j++)
    {
        if (num[j] == n)
        {
            free(num);
            return 0; //returns 0 if id is not unique
        }
    }
    free(num);
    return 1; //retuns 1 if id is unique
}

char *lowercase(char l[])
{
    char *lower = malloc(sizeof(char) * (strlen(l) + 1));
    for (int j = 0; j < strlen(l); j++)
    {
        lower[j] = tolower(l[j]);  //converting to lowercase
    }
    lower[strlen(l)] = '\0';
    return lower;
}
