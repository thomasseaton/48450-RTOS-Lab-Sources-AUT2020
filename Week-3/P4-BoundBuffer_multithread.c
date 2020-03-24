/*
   ----- 48450 -- week 3 lab handout 4 ------ 

Let's consider the producer-consumer problem by creating two threads -- the producer and the consumer. To avoid the critical section problem, we use mutex to lock and unlock the program during the reading and writing process. 

-----------------------------------------
Question 1: What is the IPC method used here (message passing or shared memory)?
Question 2: If we comment the lines 64 & 65, what will be the results after runs.
Question 3, see below the question is embedded in the code lines
Question 4, see below the question is embedded in the code lines
*/

/* main.c */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <unistd.h>

typedef char buffer_item;
#define BUFFER_SIZE 100

#define RAND_DIVISOR 800000000  

/************Global variables ******************/
pthread_mutex_t mutex;/* The mutex lock */

buffer_item buffer[BUFFER_SIZE];/* the buffer */

int counter; /* buffer counter */

pthread_t tid1, tid2;       //Thread ID
pthread_attr_t attr; //Set of thread attributes

int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */
void initializeData();

/******************* Main*********************/
int main() {
   
   /* Initialize the app */
   initializeData();
   /* Acquire a string from command line*/
   buffer_item inputs[100];
   printf("please input a string for BoundBuffer:\n");
   fgets(inputs, sizeof(inputs), stdin);
 
   /* Create the producer threads */
   printf("producer thread\n");
   pthread_create(&tid1,&attr,producer, inputs);
  
   sleep(1);/* to delay and wait for starting the procedure thread */

   /* Create the consumer threads */
   printf("create the consumer Thread\n");
   pthread_create(&tid2,&attr,consumer, NULL);

  /* If we comment the fllowing pthread_join, what will be*/
     pthread_join(tid1, NULL);
     pthread_join(tid2, NULL);

   /* Exit the program */
   printf("Exit the program\n");
   exit(0);
} /* end of main()*/

/***************** call functions from main ****************/ 
void initializeData(){

   /* Create the mutex lock */
   pthread_mutex_init(&mutex, NULL);

   /* Get the default attributes */
   pthread_attr_init(&attr);

   /* init buffer, this is the golab varible which is the key element of this program */
   counter = 0; 
} /* end of Init. */

/* Producer Thread */
void *producer(void *param) {
   /* copy the input string into local variables*/
   buffer_item item[100];
   strcpy(item, (buffer_item*)param);
 
/********************************************************
Qeustion 3: if we comment pthread_mutex_lock and pthread_mutex_unlock int the following code lines. What will be  the results? Give your explanations.
*******************************************************/

   /* acquire the mutex lock */
  pthread_mutex_lock(&mutex);
   printf("\nProducer mutex on, the producer prints the order as the user types on the keyboard \n");
   sleep(3); /* to delay and wait for starting the consumer thread */
   int i=0;
   while(item[i]!='\0' && counter < BUFFER_SIZE)
   {
      insert_item(item[i]);
      printf("%c", item[i]);
	 i++;
   }

   printf("\nBuffer Full & producer mutex off\n");
   /* release the mutex lock */
  pthread_mutex_unlock(&mutex);
   
} /* end of producer */

/* Consumer Thread */
void *consumer(void *param) {
   buffer_item item;

 /********************************************************
Qeustion 4: To follow the Question 3, if we comment pthread_mutex_lock and pthread_mutex_unlock int the following code lines what will be  the results? Give your explanations.
*******************************************************/

   /* aquire the mutex lock */
   pthread_mutex_lock(&mutex);
   printf("\nconsumer mutex on, the consumer thread prints the revsersed order of the characters \n");
   while(counter)
   {  
        remove_item(&item);
        printf("%c", item);
   }	
   printf("\nEmpty & consumer mutex off\n");
   /* release the mutex lock */
  pthread_mutex_unlock(&mutex);

} /* end of comsumer */

/*********************** subroutines ************************/

/* Add an item to the buffer */
int insert_item(buffer_item item) {
   /* When the buffer is not full add the item
      and increment the counter*/
   if(counter < BUFFER_SIZE) {
      buffer[counter] = item;
      counter++;
      return 0;
   }
   else { /* Error the buffer is full */
      return -1;
   }
}

/* Remove an item from the buffer */
int remove_item(buffer_item *item) {
   /* When the buffer is not empty remove the item
      and decrement the counter */
   if(counter > 0) {
      *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else { /* Error buffer empty */
      return -1;
   }
}

