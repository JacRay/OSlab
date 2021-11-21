#include<stdio.h>
int burst[20],arrival[20],quant,wait[20],turnaround[20],r;
int name[20],compli[20],pr[50],spr[20];
float avgwait, avgtat;

void Input(int ch){
	printf("Enter No of Job:");
	scanf("%i",&r);
	for(int i=0;i<r;i++)
	{
		printf("\n Enter Burst Time:");
		scanf("%i",&burst[i]);
		printf("\n Enter Arrival Time:");
		scanf("%i",&arrival[i]);
		if(ch == 3)
		{
			printf("\n Enter Priority:");
			scanf("%i",&pr[i]);
		}
	}
	if(ch == 4)
	{
		printf("\n Enter Time Quantum:");
		scanf("%i",&quant);
	}
	for(int i =0; i<r; i++)
	{
	name[i] = i+1;
	}
	if(ch == 1)
	{
		fcfs();
		display(1);
	}
	else if(ch == 2) 
	{
		sjf();
		display(2);
	}
	else if(ch == 3)
	{
		prior();
		display(3);
	}
	else if(ch == 4)
	{
		RoundRobin();
		display(4);
	}
}

int main()
{
	int ch;
	do{
		printf("\n MENU");
		printf("\n 1.FCFS");
		printf("\n 2.SJF");
		printf("\n 3.Non Preemptive Priority");	
		printf("\n 4.Round Robin");
		printf("\n 5.Exit");
		printf("\n Enter Choice:");
		scanf("%i", &ch);
		if(ch<5)
			Input(ch);
	}while(ch<5);
}