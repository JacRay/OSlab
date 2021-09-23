#include<stdio.h>
int burst[20],arrival[20],quant,wait[20],turnaround[20],r;
int name[20],compli[20],pr[50],spr[20];
float avgwait, avgtat;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int remain(int tburst[])
{
	int s = 0;
	for(int i =0; i<r ;i++)
	 	s+= tburst[i];
	return(s);
}
	 	
void display(int ch)
{
	printf("\nId\tArrival\tBurst\tWait\tTurnaround");
	if(ch==3)
	{
		printf("\tPriority");
	}
	for(int i =0;i<r;i++)
	{
		printf("\n%i\t%i\t%i\t%i\t%i",name[i],arrival[i],burst[i],wait[i],turnaround[i]);
		if(ch==3)
		{
			printf("\t\t%i",pr[i]);
		}
	}
	printf("\n Average Waiting Time: %f",avgwait);
	printf("\n Average Turnaround Time: %f", avgtat);
	if(ch == 4)
		printf("\n Time Quantum: %i", quant);
}
void arrivalsort()
{
	for(int i =0; i<r; i++)
		{
			for(int j =i+1;j<r;j++)
			{
				if(arrival[j] < arrival[i])
				{
					swap(&arrival[j],&arrival[i]);
					swap(&burst[j],&burst[i]); 
					swap(&name[j],&name[i]);
					swap(&pr[j],&pr[i]);
				}
					
			}
		}
}
void findavg()
{
	avgwait = 0;
	avgtat = 0;	
	for(int i=0;i<r;i++)
	{
	avgwait += wait[i];
	avgtat += turnaround[i];
	}
	avgwait = avgwait/r;
	avgtat = avgtat/r;
}
void fcfs()
{
	wait[0] = 0;
	int time =0;
	arrivalsort();
	for(int i=0;i<r;i++)
	{
		if(arrival[i] <= time)
		{
			wait[i] = time - arrival[i];
			time += burst[i];
		}
		else
		{
			time++;
			i--;
		}
	}
	for(int i =0;i<r;i++)
	{
		turnaround[i] = wait[i] + burst[i];
	}
	findavg();
}
int sort(int a[], int s)
{
		for(int i =0;i<s; i++)
		{
			for(int j=i+1;j<s;j++)
			{
				if(burst[a[j]]<burst[a[i]])
				{
					swap(&a[j],&a[i]);
				}
			}
		}
		return(a[0]);
}
int psort(int a[], int s)
{
		for(int i =0;i<s; i++)
		{
			for(int j=i+1;j<s;j++)
			{
				if(pr[a[j]]<pr[a[i]])
				{
					swap(&a[j],&a[i]);
				}
			}
		}
		return(a[0]);
}
void sjf()
{
	int temp, val;
	for(int i =0; i<r; i++)
	{
		for(int j =i+1;j<r;j++)
		{
			if(arrival[j] < arrival[i])
			{
				swap(&arrival[j],&arrival[i]);
				swap(&burst[j],&burst[i]); 
				swap(&name[j],&name[i]);
			}
			else if(arrival[j] == arrival[i])
			{
				if(burst[j]<burst[i])
				{
					swap(&burst[j],&burst[i]); 
					swap(&name[j],&name[i]);
				}
			}	
		}
	}
	compli[0] = arrival[0] + burst[0];
	turnaround[0] = compli[0] - arrival[0];
	wait[0] = turnaround[0] - burst[0];
	
	for(int i =1; i<r; i++)
	{
		temp = compli[i-1];
		int low = burst[i];
		for(int j =i;j<r;j++)
		{
			if(temp >= arrival[j] && low >= burst[j])
			{
				low = burst[j];
				val = j;
			}
		}
		compli[val] = temp + burst[val];
		turnaround[val] = compli[val] - arrival[val];
		wait[val] = turnaround[val] - burst[val];
		swap(&arrival[val],&arrival[i]);
		swap(&burst[val],&burst[i]);
		swap(&compli[val],&compli[i]);
		swap(&wait[val],&wait[i]);
		swap(&turnaround[val],&turnaround[i]);
		swap(&name[val],&name[i]);
		
	}
	findavg();
}
void prior()
{
	int sum = 0, tburst[20], p,time = 0,tpr[20], k,n=0,j =0,temp[20];
	//sorting based on arrival time
	arrivalsort();
	for(int i =0;i<r;i++)
	{
		sum += burst[i];
		wait[i] = -1;
		tburst[i] = burst[i];
	}
	time = 0;
	while(remain(tburst))
	{
		n =0;
		//finding all jobs with arrival time less than current time 
		for(k=0;k < r; k++)
		{
			if(time>=arrival[k] && tburst[k] > 0)
			{
				temp[n] = k;
				n++;
			
			}
		}
		// finding job with highest priority
		if(n>0)
		{
			if(n==1)
				j = temp[0];
			else
				j = psort(temp,n);
			
			wait[j] = time - arrival[j];
			turnaround[j] = wait[j] + burst[j];
			time += burst[j] ;
			tburst[j] = 0;
		}
		else
			time++;
	}	
	findavg();					
}

int front =-1, rear =-1,last[100];
void push(int item)
{
 if(front==-1)
 	front = 0;
 rear=rear+1;
 last[rear]=item;
}
int pop()
{
 int item=last[front];
 front=front+1;
 return(item);
 
}	
void RoundRobin()
{
	int time = 0,n=0,tburst[20],first[20], f =0,t = 0;
	arrivalsort();
	for(int i =0;i<r;i++)
	{
		wait[i] = -1;
		tburst[i] = burst[i];
		first[i] = -1;
	}
	while(remain(tburst) >0)
	{
		for(int k =0;k<r;k++)
		{
			if(time>= arrival[k]&& tburst[k] >0 && first[k] == -1)
			{
			push(k);
			first[k] = 0;
			n++;
			}
		}
		if(f==1)
			push(t);
		if(tburst[last[front]]<= quant && tburst[last[front]] >0 && n>0)
		{
			if(wait[last[front]]== -1)
			{
				time += tburst[last[front]];
				tburst[last[front]] = 0;
				turnaround[last[front]] = time - arrival[last[front]];
				wait[last[front]] = turnaround[last[front]] - burst[last[front]];
				t = pop();
				n--;
				f =0;
			}
			else
			{
				time += tburst[last[front]];
				tburst[last[front]] = 0;
				turnaround[last[front]] = time - arrival[last[front]];
				wait[last[front]] = turnaround[last[front]] - burst[last[front]];
				t = pop();
				n--;
				f =0;
			}
			
		}
		else if(tburst[last[front]] > 0 && n>0)
		{
			if(wait[last[front]]== -1)
			{
				time += quant;
				tburst[last[front]] -= quant;
				t = pop();
				f =1;
			}
			else
			{
				time += quant;
				tburst[last[front]] -= quant;
				t = pop();
				f=1;
			}
		}
		else
		{
			time++;
		}	 
		
	}
	findavg();
	
}
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
