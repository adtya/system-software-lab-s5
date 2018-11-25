/* FCFS CPU Scheduling Algorithm
 */

#include<stdio.h>
void main() {
	int n; // Number of processes
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int bt[n]; // Array storing burst times (of size n)
	int wt[n]; // Array storing waint times (of size n)
	int tat[n]; // Turn around times
	int awt = 0 /* Average waiting time*/, att = 0 /* Average turnaround time */;
	int i; // A control variable for various loops

	printf("Enter Burst times for the processes:\n");
	for(i = 0; i < n; i ++) {
		scanf("%d", &bt[i]);
	}

	// Wait time of first process is always 0
	wt[0] = 0;
	
	// Wait time for all other processes => sum of wait time and burst time of previous process
	for (i = 1; i < n; i ++) {
		wt[i] = wt[i - 1] + bt[i - 1];
	}
	
	// Turn Around Time => waiting time + burst time
	for(i = 0; i < n; i ++) {
		tat[i] = wt[i] + bt[i];
	}
	
	// Average waiting time = total waiting time / no. of processes
	for(i = 0; i < n; i ++) {
		awt = awt + wt[i];
	}
	awt = awt / n;

	// Average turnaround time  = total turnaround time / no. of proesses
	for(i = 0; i < n; i ++) {
		att = att + tat[i];
	}
	att = att / n;

	printf("Process\tBT\tWT\tTAT\n");
	for(i = 0; i < n; i ++) {
		printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
	}
	printf("\nAverage Waiting time: %d", awt);
	printf("\nAverage turnaround time: %d", att);

	printf("\n");
}

