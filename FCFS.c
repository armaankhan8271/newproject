#include<stdio.h>
void findWaitingTime(int processes[], int n,int bt[], int wt[]){
	wt[0] = 0;
	for (int i = 1; i < n ; i++ ){ 
		wt[i]= bt[i-1] + wt[i-1] ;
	} 
}
void findTurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[]){
	for (int i = 0; i < n ; i++){
		tat[i] = bt[i] + wt[i];
	}
} 
void findavgTime( int processes[], int n, int bt[]){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(processes, n, bt, wt);
	findTurnAroundTime(processes, n, bt, wt, tat);
	printf("P=Process\nBT=Burst Time\nWT=Waiting time\nTat=Turn Around Time\n");
	printf("P\tBT\tWT\tTat\n");
	for (int i=0; i<n; i++){
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("%d\t%d\t%d\t%d\n",(i+1), bt[i],wt[i],tat[i] );
	}
	int s=(float)total_wt / (float)n; int
	t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d\n",t);
} 
int main() {
	int processes[] = { 1, 2, 3, 4, 5};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {5, 16, 2, 5, 12};
	findavgTime(processes, n, burst_time);
	return 0;
}
