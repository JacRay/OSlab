#include<stdio.h>

int used = 0;
int Free = 5;
int nop =0;

void producer()
{
	used++;
	Free--;
	nop++;
	printf("\n Producer Produced Item %i", nop);
}

void consumer()
{
	used--;
	Free++;
	printf("\n Consumer Consumed Item %i", nop);
	nop--;
}

int main()
{
	int ch;
	do
	{
		printf("\n MENU \n 1.Producer");
		printf("\n 2.Consumer\n 3.Exit");
		printf("\n Enter a Choice:");
		scanf("%i", &ch);
		switch(ch)
		{
			case 1:
				if(Free != 0)
				{
					producer();
				}
				else
				{
					printf("\n Buffer is Full");
				}
				break;
			case 2:
				if(used != 0)
				{
					consumer();
				}
				else
				{
					printf("\n Buffer is Empty");
				}
				break;
			case 3:
				printf("\n Exiting!! \n");
				return(0);
			default:
				printf("\n Wrong Choice ");
				printf("\n Exiting!! \n");
				return(0);
				
		}
	}while(ch<3);
}
