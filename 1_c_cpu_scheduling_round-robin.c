/* Round Robin CPU Scheduling
 */

#include<stdio.h>

void main() {
	int n; // Number of processes
        printf("Enter the number of processes: ");
        scanf("%d",&n);
        int bt[n]; // Array storing burst times (of size n)
	int rem_bt[n]; // Array for storing remaining burst time (of size n)
        int wt[n]; // Array storing wait times (of size n)
        int tat[n]; // Turn around times
        int awt = 0 /* Average waiting time */, att = 0 /* Average turnaround time */;
        int i; // A control variable for various loops
	int time = 0; // Time elapsed
	int quantum = 5; // Time quantum for round robin
	int flag = 0; // flag to keep track of terminalted proccesses

        printf("Enter Burst times for the processes:\n");
        for(i = 0; i < n; i ++) {
                scanf("%d", &bt[i]);
		rem_bt[i] = bt[i];
		wt[i] = 0;
        }
	
	for(i = 0; i < n; i ++) {
		if(wt[i] == 0) { // If the wait time is zero, set it add I times the quantum to it.
			wt[i] = wt[i] + (i * quantum);
		}
		if(rem_bt[i] != 0) { // If the process is not already complete
			if(rem_bt[i] > quantum) { // If the remaining burst time is greater than quantum
				time = time + quantum; // add qauntum to elapsed time
				rem_bt[i] -= quantum; // decrease remaining time by quantum;
			}
			if( (rem_bt[i] < quantum) && (rem_bt[i] != 0) ) {
			// If the remaining burst time is less than quantum and not equal to zero
				time += rem_bt[i]; // add process's remaining time to elapsed time;
				rem_bt[i] = 0; // set remaining time as zero
			}
			if(rem_bt[i] == 0) { // If the process is complete in previous steps.
				tat[i] = time; // set turn around time to elapsed time;
				flag += 1;
			}
		}
		if(flag == n) break; // flag = n means all processes are over
		if(i == n-1) {
			i = -1; // to start from begining after one cycle
		}

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
