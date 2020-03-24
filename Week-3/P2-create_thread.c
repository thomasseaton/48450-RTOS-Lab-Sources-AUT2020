/*
   ----- 48450 -- week 3 lab handout 2 ------ 
This is a simple example to learn how to create a thread

Note: gcc P2-simple_threads.c -o P2 -pthread
*/
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum;/*this data is shared by the threads*/
void *runner(void *param);/*threads call this function*/

/****************Main**********************/
int main(int argc, char*argv[])
{
  pthread_t tid;/*the thread identifier*/
  pthread_attr_t attr;/*set of thread attributes*/

  if(argc!=2){
	fprintf(stderr,"usage: a.out <integer value>\n");
	return -1;
  }
  if(atoi(argv[1])<0){
	fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
	return -1;
  }
  /*get the default attributes*/
  pthread_attr_init(&attr);
  /*create the thread*/
  pthread_create(&tid,&attr,runner,argv[1]);

/************************/

 int i,j=atoi(argv[1]);
  int sum_main=0;

  for(i=0;i<=j;i++)
    sum_main+=2*i;

 printf("sum_main=%d\n",sum_main);

  /*wait for the thread to exit*/
  pthread_join(tid,NULL);

  printf("thread_sum=%d\n",sum);

}/* end of Main */

/********The thread will begin to run in this function******/
void *runner(void *param)
{
  int i,upper=atoi(param);
  sum=0;

  for(i=0;i<=upper;i++)
    sum+=i;

  pthread_exit(0);
}


