#include "headerA4.h"

int main(void)
{
    srand(time(0));
    tweet *head = NULL;       //head for storing tweets
    tweet *tail = NULL;       //tail for storing tweets
    tweet *freeMemory = NULL; //to free memory
    int id = 10000;

    printf("Beginning A4 program testing...\nCreating initial queue list...\n");

    for (int i = 0; i < 5; i++) //creating tweets
    {
        tweet *node = createTweet(head);

        if (node == NULL) //if tweet is not created
        {
            printf("Error creating tweet\n");
            return 1;
        }
        else
            enqueue(&head, &tail, node); //enqueued tweet if created successfully
    }

    printf("\n\nVerifying queue contents via printQueue\n");
    printQueue(head); //printing the queue

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //enqueue thrice
    printf("Testing [Enqueue] function\n");
    for (int a = 0; a < 3; a++)
    {
        tweet *node = malloc(sizeof(tweet));
        if (node == NULL)
        {
            printf("Error creating static node\n");
            return 1;
        }
        node->next = NULL;

        switch (a) //switch case for inputting queue
        {
        case 0:
            strcpy(node->user, "HarryPotter");
            strcpy(node->text, "I am Harry.");
            break;
        case 1:
            strcpy(node->user, "HermioneGranger");
            strcpy(node->text, "I am Hermione.");
            break;
        case 2:
            strcpy(node->user, "RonWeasley");
            strcpy(node->text, "I am Ron.");
            break;
        }

        node->id = id;
        id = id + 50;

        while (uniqueId(head, node->id) == 0) //checking if the id is unique
        {
            node->id = node->id + (rand() % 999 + 1); //if not, giving unique id by adding random imt btw 1 to 999
        }

        node->id = id;
        printf("Iteration [%d]: [Node]: %d: Created by %s: %s\n\n", a + 1, node->id, node->user, node->text);

        enqueue(&head, &tail, node); //enqueuing node
        printf("After enqueue, queue looks like:\n");
        printQueue(head);

        //waiting for Enter
        fgetc(stdin);
        fflush(stdin);
    }

    //dequeue thrice
    printf("Testing [Dequeue] function\n");
    for (int i = 0; i < 3; i++)
    {
        dequeue(&head, &tail);
        printf("Iteration [%d]\nAfter dequeue, queue looks like:\n", i + 1);
        printQueue(head);

        //waiting for Enter
        fgetc(stdin);
        fflush(stdin);
    }

    //isEmpty
    printf("Testing [isEmpty] function\nTesting with list, expecting !isEmpty\n");
    if (!isEmpty(head)) //if list is not empty
    {
        printf("SUCCESS: list is not empty\n");
    }
    else //list is empty
    {
        printf("FAILURE: list is empty\n");
        return 1;
    }
    printf("Using printQueue to verify queue contents\n");
    printQueue(head); //printing queue

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //isEmpty-2
    dequeue(&head, &tail); //dequeueing queue
    dequeue(&head, &tail);
    printf("Testing with list after 2 dequeues, expecting !isEmpty\n");
    if (!isEmpty(head)) //if list is not empty
    {
        printf("SUCCESS: list is not empty\n");
    }
    else //list is empty
    {
        printf("FAILURE: list is empty\n");
        return 1;
    }
    printf("Using printQueue to verify queue contents\n");
    printQueue(head); //printing queue

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //isEmpty-3
    tweet *emptyQ = NULL;
    printf("Testing with another empty list, expecting isEmpty\n");
    if (isEmpty(emptyQ)) //if list is empty
    {
        printf("SUCCESS: Empty list is declared as empty\n");
    }
    else //if list is not empty
    {
        printf("FAILURE: list should be empty\n");
        return 1;
    }
    printf("\nUsing printQueue to verify queue contents\n");
    printQueue(head); //printing queue

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    printf("Testing [printQueue] function\nprintQueue was used through the verification process already...\n\n");

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //sortID
    printf("Testing [sortID] function\n");
    sortID(&head, &tail);
    printQueue(head);

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //Testing sortUsername
    printf("Testing [sortUsername] function\n");
    sortUsername(&head, &tail);
    printQueue(head);

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    //Testing reverse
    printf("Testing [reverse] function\n");
    reverse(&head, &tail);
    printQueue(head);

    //waiting for Enter
    fgetc(stdin);
    fflush(stdin);

    while (head != NULL)
    {
        freeMemory = head;
        head = head->next;
        free(freeMemory);
    }

    return 0;
}