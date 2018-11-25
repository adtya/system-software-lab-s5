/* FSFS Disk Scheduling Algorithm
 */
#include<stdio.h>
#include<stdlib.h>

void main() {
	int n;
	printf("Enter the size of the Queue: ");
	scanf("%d", &n);
	int queue[n+1] /* Array for the queue */;
	int seek = 0; /* for total seek */;
	int head; // for head position
	int i; // control variable for various loops
	
	printf("Enter the locations to be accessed: ");
	for(i = 1;i < n+1; i++) {
		scanf("%d", &queue[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	queue[0] = head; // in FCFS, start from head location
	for(i = 0; i <= n-1; i++) {
		printf("Location %d accessed with a seek time of %d\n", queue[i+1], abs(queue[i]-queue[i+1]));
		seek += abs(queue[i] - queue[i+1]); // add diff. b/w adjescent locations to seek
	}
	printf("Total seek time: %d\n", seek);
	printf("Average seek time: %d\n", seek/n);
}
