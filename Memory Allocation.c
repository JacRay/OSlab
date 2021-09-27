#include<stdlib.h>
#include <stdio.h>

int n,m, ind,i,j,allocate[10],block[10],process[10],memory[10];

void display ()
{
  printf ("Process\t Block allocated  \n");
  for (i = 0; i < n; i++)
    {
      if (allocate[i] == 0)
	printf ("  %d \t\tNot allocated \n", process[i]);
      else
	printf ("  %d \t\t%d\n", process[i], allocate[i]);
    }
}
void firstfit ()
{
    printf("\n\t\tFirst Fit\n\n");
  for (i = 0; i < n; i++)
    {
      ind = -1;
      for (j = 0; j < m; j++)
	{
	  if (memory[j] >= process[i])
	     {
	         ind = j;
	         break;
	     }

	}
      if (ind != -1)
	{
	  allocate[i] = ind + 1;
	memory[ind] -= process[i];
	    
	}
    }
  display ();
}
void bestfit ()
{
    printf("\n\t\tBest Fit\n\n");
  for (i = 0; i < n; i++)
    {
      ind = -1;
      for (j = 0; j < m; j++)
	{
	  if (memory[j] >= process[i])
	    if (ind == -1 || memory[ind] > memory[j])
	      ind = j;

	}
      if (ind != -1)
	{
	  allocate[i] = ind + 1;
	memory[ind] -= process[i];
	    
	}
    }
  display ();
}
void worstfit ()
{
    printf("\n\t\tWorst Fit\n\n");
  for (i = 0; i < n; i++)
    {
      ind = -1;
      for (j = 0; j < m; j++)
	{
	  if (memory[j] >= process[i])
	    if (ind == -1 || memory[ind] < memory[j])
	      ind = j;
	}
      if (ind != -1)
	{
	  allocate[i] = ind + 1;
	memory[ind] -= process[i];
	    
	}
    }
  display ();
}
void clear()
{
    for (i=0;i<n;i++)
        allocate[i]=0;
    for (i=0;i<m;i++)    
        memory[i]=block[i];
}

int main ()
{
      printf("Enter the no of processes \t");
      scanf("%d",&n);
      printf("Enter the processes \t");
      for(i=0;i<n;i++)
        scanf("%d",&process[i]);
      printf("Enter the no of blocks \t");
      scanf("%d",&m);
      printf("Enter the blocks \t");
      for(i=0;i<m;i++)
        scanf("%d",&block[i]);
        
  int x;
  do
    {
      clear();
      printf("Enter 1- First Fit \t2- Best Fit \t3- Worst Fit  \t0- Exit\t");
      scanf("%d",&x);
      switch (x)
	{
	case 1:
	  firstfit ();
	  break;
	case 2:
	  bestfit ();
	  break;
	case 3:
	  worstfit ();
	  break;
	case 0:
	  exit (0);
	default:
	  printf ("Invalid choice \n");
	}
    }
  while (x != 0);
  return 0;
}