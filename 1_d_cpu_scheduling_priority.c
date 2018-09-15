/* Priority CPU Scheduling Algorithm
 */

#include<stdio.h>

void main() {
	int n; // Number of processes
        printf("Enter the number of processes: ");
        scanf("%d",&n);
	int prt[n]; // Array for storing priority of processes
        int pn[n]; // Stores process numbers
        int bt[n]; // Array storing burst times (of size n)
        int wt[n]; // Array storing waint times (of size n)
        int tat[n]; // Turn around times
        int awt = 0 /* Average waiting time*/, att = 0 /* Average turnaround time */;
        int i, j; // control variables for various loops

        printf("Enter Burst times and priorities for the processes:\n");
        for(i = 0; i < n; i ++) {
		printf("Burst time: ");
                scanf("%d", &bt[i]);
		printf("Priority: ");
		scanf("%d", &prt[i]);
                pn[i] = i;
        }
	// Sorting by Priority
        for(i = 0; i < n; i ++) {
                for(j = i + 1; j < n; j ++) {
                        if(prt[i] > prt[j]) {
                                bt[j] = bt[i] + bt[j];
                                pn[j] = pn[i] + pn[j];
				prt[j] = prt[i] + prt[j];
                                bt[i] = bt[j] - bt[i];
                                pn[i] = pn[j] - pn[i];
				prt[i] = prt[j] - prt[i];
                                bt[j] = bt[j] - bt[i];
                                pn[j] = pn[j] - pn[i];
				prt[j] = prt[j] - prt[i];
                        }       
                }
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

        printf("Process\tPRT\tBT\tWT\tTAT\n");
        for(i = 0; i < n; i ++) {
                printf("%d\t%d\t%d\t%d\t%d\n", pn[i], prt[i], bt[i], wt[i], tat[i]);
        }
        printf("\nAverage Waiting time: %d", awt);
        printf("\nAverage turnaround time: %d", att);
        printf("\n");
}
