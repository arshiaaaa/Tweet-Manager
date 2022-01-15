#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct microtweet
{
    int id;                  //unique integer value
    char user[51];           // the userid / username of the person who wrote the tweet
    char text[141];          // the text of the tweet
    struct microtweet *next; //dynamic connection to the next tweet
} tweet;

void enqueue(tweet **head, tweet **tail, tweet *node); //adds a node to the queue
void dequeue(tweet **head, tweet **tail);              //deletes a node
int isEmpty(tweet *head);                              //checks if the given queue is empty- returns true if empty, 0 if not empty
void printQueue(tweet *head);                          //takes the front of the queue and prints every element of the queue

void sortID(tweet **head, tweet **tail);       //sort the queueu in ascending order by id
void sortUsername(tweet **head, tweet **tail); // sort the queue in ascending order be username
void reverse(tweet **head, tweet **tail);      //reverse the nodes of the queue

//Additional helper functions

tweet *createTweet(tweet *head);     //ceates a new tweet
int uniqueId(tweet *tweetList, int); //checks if the id is unique
char *lowercase(char p[]);           //converts to lowercase