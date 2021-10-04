#include<stdio.h>
int burst[20],arrival[20],wait[20],turnaround[20],r, tburst[20];
int remain(int tburst[])
{
	int s = 0;
	for(int i =0; i<r ;i++)
	 	s+= tburst[i];
	return(s);
}
srtf(){
    int time = 0;
for(int i = 0;i<r;i++)
{
    tburst[i] = burst[i];
}
while(remain(tburst)>0)
{
    for(int i = 0;i<r;i++)
    {
        if(time>= arrival[i]&&tburst[i]>0)
        {
            
        }
    }
}
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
    }
		srtf();
		display(2);
}
int main(){
   Input();
}