/* Round Robin CPU Scheduling
 */
#include<stdio.h>

int main()
{
  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n; // No. of processes which are incomplete at the moment
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); // Arrival Time
    scanf("%d",&bt[count]); // Burst Time
    rt[count]=bt[count]; // Remaining Time
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum); 

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];   // if remaining time is less than quantum just add rem time to time
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum; // subtact quantum from burst time(remaining burst time will get smaller)
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;  // no of processes remaining is decreased by one since it is complete
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
