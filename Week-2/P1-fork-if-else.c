/*
   ----- 48450 -- week 2 lab handout 2 ------ 

fork() creates a new process by duplicating the calling process. The new process, referred to as the child, is an exact duplicate of the calling process.

On success, the PID of the child process is returned in the parent, and 0 is returned in the child. On failure, -1 is returned in the parent, in which case, no child process is created, and errno is set appropriately.
                                            
    This program creates two child processes displaying some lines
 The parent waits until all child processes are done and exits.    
----------------------------------------------------------------- */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define   MAX_COUNT  2
#define   BUF_SIZE   1

void  ChildProcess(char [], char []);    /* child process prototype  */

void  main(void)
{
     pid_t   pid1, pid2, pid;
     int     status;
     int     i;
     char    buf[BUF_SIZE];
     
     printf("*** Parent is about to fork process 1 ***\n");
     if ((pid1 = fork()) < 0) {
          printf("Failed to fork process 1\n");
          exit(1);
     }
     else if (pid1 == 0) {
	printf("the current pid1=%d\n", pid1);
          ChildProcess("First", "   ");
	}

     printf("*** Parent is about to fork process 2 ***\n");
     if ((pid2 = fork()) < 0) {
          printf("Failed to fork process 2\n", pid2);
          exit(1);
     }
     else if (pid2 == 0) {
	printf("the current pid2=%d\n");
          ChildProcess("Second", "      ");
}
	printf("---- Parent enters waiting status.....\n");     
     pid = wait(&status);
 

     printf("*** Parent detects process %d was done ***\n", pid);
    pid = wait(&status);

     printf("*** Parent detects process %d is done ***\n", pid);
     printf("*** Parent exits ***\n");
   exit(0);
}


void  ChildProcess(char *number, char *space)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];
     
     pid = getpid();
     printf("%s%s child process starts (pid = %d)\n", space, number, pid);
     
     for (i = 1; i <= MAX_COUNT; i++) {
          printf(buf, "%s%s child's output, value = %d\n", space, number, i); 
          
     }
     printf("%s%s child (pid = %d) is about to exit\n", space, number, pid);
        
  exit(0);
}

