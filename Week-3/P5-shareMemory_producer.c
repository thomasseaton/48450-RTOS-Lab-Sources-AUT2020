/*
   ----- 48450 -- week 2 lab handout 5 Share-memory for Producer------ 

To illustrate the concept of cooperating processes -- IPC, let us consider the producer-consumer problem, which is a common paradigm for cooperating processes. A producer process produces information that is consumed by a consumer process

A Shared-Memory Example for Producer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h> /* For O_* constants */ 

int main()
{
 /* the size (in bytes) of shared memory object */
  const int SIZE = 128;
 /* NAME OF THE SHARED MEMORY OBJECT */
  const char *name = "OS";
 /* strings written to shared memory */
  const char *message_0="Hello";
  const char *message_1="World\n";

 /* shared memory file descriptor */
  int shm_fd;
 /* pointer to shared memory object */
  void *ptr;

        /* What is the following code line doing? create a memory pointer->shm_fd*/
	shm_fd = shm_open(name,O_CREAT|O_RDWR, 0666);

	/* ******
	to configure the size of the shared memory object -- why we 		need this? Answer: if fildes refers to a regular file, the 		ftruncate() function shall cause the size of the file to be 		truncated to length
	******/
	ftruncate(shm_fd,SIZE);

	/* What is the following code line doing? Allocate the memory space*/
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	/* What is following code lines doing? write to the shared memory object */
	sprintf(ptr,"%s",message_0);
	ptr += strlen(message_0); // increase the pointer of address for writing the message_1
	sprintf(ptr,"%s",message_1);

	return 0;
}

/* when do you compile this program please type - gcc P5-shareMemory-producer.c -o P5-producer -lrt where 'rt' -- real time library
*/
