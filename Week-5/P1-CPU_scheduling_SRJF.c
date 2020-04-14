/*
	----- 48450 -- week 5 lab handout 1 ------ 
By programing the handout 1, you will follow the lecture notes to implement the SJF. Through this Lab sample. Please answer the following question that is embeded in the code lines. 

This is a program to do the shortest-remaning time frsit (SRJF) CPU scheduling 

                Process			Arrival Time		Burst Time
			P1			0			8
			P2 			1			4
		    	P3			2			9
		    	P4			3			5


Question-1: what does the sort function achieve? Give your analysis by commenting each code lines in the function call.

*/

#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>

/* a struct storing the information of each process */
typedef struct
{
     	int pid;//process id
     	float arrive_t, wait_t, burst_t, turnaround_t; 	
	float start_t; /* process time */
}process;

void sort(process p[], int start, int num);

/******************* Main function ******************/
void main()
{
     int i,k, j;//index
     int processNum=0;//process number

/* to declare variables 1)average waiting time,2) turnaround time and 3)global start time and set up initial value = 0.0*/    
float avg_wait_t = 0.0, avg_turnaround_t = 0.0; 
int Process_start = 0; 
float time_residue;

/* store process information using our struct(include id, four types of time) */
process *pro;

/*------initialize the data: process id and time -------*/     

	printf("This is a program to run example data to show shortest-remaining  job first (SRJF) CPU scheduling.\n\n");
     processNum=4;
     pro= malloc(sizeof(process)*processNum);/* allocate memory for variable process */
     pro[0].pid=1;pro[0].arrive_t=0;pro[0].burst_t=8;// Process 1
     pro[1].pid=2;pro[1].arrive_t=1;pro[1].burst_t=4;// Process 2
     pro[2].pid=3;pro[2].arrive_t=2;pro[2].burst_t=9;// Process 3
     pro[3].pid=4;pro[3].arrive_t=3;pro[3].burst_t=5;// Process 4


time_residue= pro[0].arrive_t+1;
 
/*----------- sort the existing processes ------------*/
     sort (pro,0,processNum); 
     
/*--- implementing the SRJF algorithm on burst time ---*/
     for (i = 0; i<processNum; i++)
     {
      if(pro[i].arrive_t<=Process_start){ //set the rest process' start time
	if(pro[i].arrive_t==0) Process_start-=time_residue;
	pro[i].start_t = Process_start; //set up the current process' start time

	}
          else
              {
pro[i].start_t = pro[i].arrive_t;//set the shortest burst process' start time

if (pro[i].arrive_t>0) Process_start +=time_residue;
}

/*-- set the global start time to the end of the process done time --*/
		Process_start += pro[i].burst_t; 
/*set the wait time as CPU start time minus process arrive time*/
          	pro[i].wait_t = pro[i].start_t - pro[i].arrive_t;
 
    /* set turn around time as bust time plus wait time */
 pro[i].turnaround_t = pro[i].burst_t + pro[i].wait_t; 
          avg_wait_t += pro[i].wait_t;
          avg_turnaround_t += pro[i].turnaround_t;
     }

/* --------------Display the results------------------ */
     avg_wait_t /= processNum;
     avg_turnaround_t /= processNum;
     printf("Process Schedule Table: \n");
     printf("\tProcess ID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
     for (i = 0; i<processNum; i++)
          printf("\t%d\t\t%f\t%f\t%f\t%f\n", pro[i].pid,pro[i].arrive_t, pro[i].burst_t, pro[i].wait_t, pro[i].turnaround_t);
     printf("\nAverage wait time: %f", avg_wait_t);
     printf("\nAverage turnaround time: %f\n", avg_turnaround_t);
}/* end of main */

/******************* Call function ******************/

void sort(process p[], int start, int num)
{
   int i,j;
   process temp;
   for (i = start; i<num; i++)
   {
        for (j = i+1; j<num; j++)
        {
 
if(p[i].burst_t > p[j].burst_t) 	
           {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
           }
        }
   }
}/* the sort reults in the end = P2, P4, P1, P3 */

