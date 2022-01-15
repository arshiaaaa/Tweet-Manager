#include "headerA4.h"

void sortID(tweet **head, tweet **tail)
{
    if (isEmpty(*head))
    {
        printf("The queue has no tweets\n");
        return;
    }
    int num = 0;
    do
    {
        num = 0;
        tweet *currentNode = *head;
        tweet *lastNode = *head;

        if (currentNode->next == NULL) //checking if there is only 1 element
        {
            return;
        } 
        
        if ((currentNode->next)->id < currentNode->id)
        { 
            *head = currentNode->next; //comparing IDs

            currentNode->next = (*head)->next;
            (*head)->next = currentNode;

            num++;
            lastNode = *head; 
        }
        else
        {
            currentNode = currentNode->next;
        }

        while (currentNode->next != NULL) //comparing remaining Ids
        {
            if ((currentNode->next)->id < currentNode->id)
            {
                lastNode->next = currentNode->next;

                currentNode->next = (currentNode->next)->next;
                (lastNode->next)->next = currentNode;

                lastNode = lastNode->next;
                num++;
            }
            else
            {
                lastNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    } while (num != 0);

    while ((*tail)->next != NULL) //assigning tail
    {
        *tail = (*tail)->next;
    }
}

void sortUsername(tweet **head, tweet **tail)
{
    if (isEmpty(*head)) //if queue is empty
    {
        printf("The queue has no tweets.\n");
        return;
    }
    int num = 0;

    do
    {
        num = 0;
        tweet *currentNode = *head;
        tweet *lastNode = *head;

        if (currentNode->next == NULL) //checking if there is only 1 element
        {
            return;
        } 

        if (strcmp(currentNode->user, (currentNode->next)->user) > 0)
        { 
            *head = currentNode->next;

            currentNode->next = (*head)->next;
            (*head)->next = currentNode;

            num++;
            lastNode = *head; 
        }
        else
        {
            currentNode = currentNode->next;
        }

        while (currentNode->next != NULL) //comparing remaining Ids
        {
            if (strcmp(currentNode->user, (currentNode->next)->user) > 0)
            {
                lastNode->next = currentNode->next;

                currentNode->next = (currentNode->next)->next;
                (lastNode->next)->next = currentNode;

                lastNode = lastNode->next;
                num++;
            }
            else
            {
                lastNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    } while (num != 0);

    while ((*tail)->next != NULL)  //assigning tail
    {
        *tail = (*tail)->next; 
    }
}

void reverse(tweet **head, tweet **tail)
{
    tweet *lastNode = NULL, *currentNode = *head, *upNode = NULL;

    while (currentNode != NULL)
    {
        upNode = currentNode->next;
        currentNode->next = lastNode;

        lastNode = currentNode;
        currentNode = upNode;
    }

    *head = lastNode;
}
