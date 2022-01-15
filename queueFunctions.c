#include "headerA4.h"

void enqueue(tweet **head, tweet **tail, tweet *node)
{
    if (*head == NULL) //if queue is empty
    {
        *head = node;
        *tail = node;
        return;
    }

    (*tail)->next = node; //attaching node to end of queue
    node->next = NULL;
    *tail = node; //assigning new tail
}

void dequeue(tweet **head, tweet **tail)
{
    if (*head == NULL) //if queue is empty
    {
        printf("No tweet to dequeue\n");
        return;
    }
    tweet *deq = *head;
    *head = deq->next;
    free(deq); // freeing deq
}

int isEmpty(tweet *head)
{
    if (head == NULL) //if queue is empty
    {
        return 1;
    }
    return 0;
}

void printQueue(tweet *head)
{
    if (head == NULL) //if queue is empty
    {
        return;
    }
    while (head != NULL)
    {
        printf("%i: Created by %s: %s\n", head->id, head->user, head->text); //printing nodes
        head = head->next;
    }
}