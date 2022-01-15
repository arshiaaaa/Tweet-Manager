a) MADE BY: Arshia Sandhu
PROJECT NAME: Tweet Manager 
DATE OF LAST REVISION: 07/03/2021

b) To compile: make 
To run: ./a4

c) i) Enqueue: This function goes to the end of the queue and then adds a new node to the queue. 

ii) Dequeue: This function deletes a node from the queue by placing a pointer at the first element and then, the head will be pointing to the second element. A pointer is used to store the dequeued tweet in order to free it later. 

iii) isEmpty: This function checks if the given queue is empty. It checks if the pointer is pointing to NULL and then it returns 1 i.e., true if the queue is empty, else, it returns 0 for non-empty.  

iv) printQueue: This function takes the front of the queue and then prints out every element of the queue. If the list is empty, the function will print nothing. Otherwise, a loop is iterated till it reaches NULL i.e. the end of the list and prints the id, username and the tweet of the particular user. 

v) sortID: this function sorts the queue in the ascending order of their IDs. For this, I have used Bubble sort. Bubble sort swaps adjacent elements according to their right order with each number of pass. 

vi) sortUsername: This function sorts the queue in the ascending order of their username. For this, I have again used bubble sort just like sortID.

vii) reverse: this function reverses the nodes of the queue. It uses three pointers and then changes their positions. 

d) Limitations of the program: The values in the code are hard coded and else I have tried to tackle all the edge cases. 

e) Future improvements: trying to make the code more efficient and having better space-time aspects.  


