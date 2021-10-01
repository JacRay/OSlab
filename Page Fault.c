#include<stdlib.h>
#include <stdio.h>

int frames[50],available,f1,f2,f3,max,ind,temp[50],min,np,nf,pages[50],i, j, k, fault;
void fifo ()
{
  j = 0;
  for (i = 0; i < np; i++)
    {
      available = 0;
       for (k = 0; k < nf; k++)
       {
	if (frames[k] == pages[i])
	 {
	     available = 1;
	     break;
	 }	 }
      if (available == 0)
	{
	  frames[j] = pages[i];
	  j = (j + 1) % nf;
	  fault++;
	}
  printf ("Page Faults is  %d\n\n", fault);
}

void optimal ()
{
  for (i = 0; i < np; i++)
    {
      f1=f2=0;
      for (j = 0; j < nf; j++)
        if(frames[j]==pages[i])
            {
                f1=f2=1;
                break;
            }
     if(f1==0)
        {
            for (j = 0; j < nf; j++)
        if(frames[j]==-1)
            {
                frames[j]=pages[i];
                fault++;
                f2=1;
                break;
            }
        }
       if(f2==0){
            f3=0;
            for (j = 0; j < nf; j++)
            {
                temp[j]=-1;
                for (k = i+1; k < np; k++)
                    if(frames[j]==pages[k])
                    {
                        temp[j]=k;
                        break;
                    }
            }   
            for (j = 0; j < nf; j++)
                if(temp[j]==-1)
                {
                    ind=j;
                    f3=1;
                }
            if (f3==0)
            {
                max=temp[0];
                ind=0;
            for (j = 1; j < nf; j++)
                if(temp[j]>max)
                {
                    max=temp[j];
                    ind=j;
                }
            }
            frames[ind]=pages[i];
            fault++;
        }
    }
  printf ("Page Faults is  %d\n\n", fault);
}

void lru ()
{
  for (i = 0; i < np; i++)
    {
      f1=f2=0;
      for (j = 0; j < nf; j++)
        if(frames[j]==pages[i])
            {
                f1=f2=1;
                break;
            }
            
        if(f1==0)
        {
            for (j = 0; j < nf; j++)
        if(frames[j]==-1)
            {
                frames[j]=pages[i];
                fault++;
                f2=1;
                break;
            }
        }
        
        if(f2==0){
            min=i;
            for (j = 0; j < nf; j++)
            {
                for (k = i-1; k >=0; k--)
                    if(frames[j]==pages[k])
                    {
                        if(k<min)
                        {
                            min=k;
                            ind=j;
                        }
                        break;
                    }
            }
            frames[ind]=pages[i];
            fault++;
    }
    }
  printf ("Page Faults is  %d\n\n", fault);
}

void clear ()
{
    fault = 0;
  for (i = 0; i < nf; i++)
    frames[i] = -1;
}


int main ()
{
    printf ("Enter the no of pages\t");
      scanf ("%d", &np);
    printf ("Enter the reference string\t");
    for(i=0;i<np;i++)  
        scanf ("%d", &pages[i]);
    printf ("Enter the no of frames\t");
      scanf ("%d", &nf);
  int x;
  do
    {
      clear ();
      printf ("Enter 1- FIFO \t2- Optimal \t3- LRU \t0- Exit\t");
      scanf ("%d", &x);
      switch (x)
	{
	case 1:
	  fifo ();
	  break;
	case 2:
	  optimal ();
	  break;
	case 3:
	  lru ();
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
