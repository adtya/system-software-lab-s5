/* SCAN Disk Scheduling Algorithm
 */

#include<stdio.h>

void main() {
	int n;
	printf("Enter the no. size of queue: ");
	scanf("%d", &n);
	int queue[n];
	int new_queue[n+1];
	int head;
	int head_pos;
    int disk_size;
	int seek = 0;
	int i, j;
	int step;
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);
	printf("Enter the elements of the queue: ");
	for(i = 0;i < n; i ++) {
		scanf("%d", &queue[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(queue[i]>queue[j]) {
				queue[j] += queue[i];
				queue[i] = queue[j] - queue[i];
				queue[j] = queue[j] - queue[i];
			}
		}
	}
	for(i=0;queue[i]<=head;i++) {
		new_queue[i] = queue[i];
	}
	new_queue[i] = head;
	head_pos = i;
	for(;i<n;i++) {
		new_queue[i+1] = queue[i];
	}
	if((new_queue[head_pos]-new_queue[head_pos-1]) < (new_queue[head_pos+1]-new_queue[head_pos])) {
		step = -1;
	}
	if(step==-1) {
		for(i=head_pos;i>0;i--) {
			seek+=new_queue[i]-new_queue[i-1];
		}
		seek+=new_queue[i];
		seek+=new_queue[head_pos+1];
		for(i=head_pos+1;i<n;i++) {
			seek+=new_queue[i+1]-new_queue[i];
		}
	}
	else {
		for(i=head_pos;i<n;i++) {
			seek+=new_queue[i+1]-new_queue[i];
		}
		seek+=disk_size-new_queue[i];
		seek+=disk_size-new_queue[head_pos-1];
		for(i=head_pos-1;i>0;i--) {
			seek+=new_queue[i]-new_queue[i-1];
		}
	}

	printf("Seek time: %d\n", seek);
	printf("Average seek time: %d\n", seek/n);
}
