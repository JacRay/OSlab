#include <stdio.h>
#include <stdlib.h>

int arr[100] = { 98, 183, 41, 122, 14, 124, 65, 67 };

int diff[10][10], seekseq[50], lowq[50], uppq[50], l, u, head, scount;;
int n = 8, h = 53, dsize = 200;
char dir = 'l';

void
fcfs ()
{
  int i;
  head = h;
  scount = 0;

  printf ("\n\t\tFCFS\n");
  for (i = 0; i < n; i++)
    {
      scount += abs (arr[i] - head);
      head = arr[i];
    }

  printf ("The Seek Sequence \t%d -> ", h);
  for (i = 0; i < n - 1; i++)
    printf ("%d -> ", arr[i]);
  printf ("%d\n", arr[i]);
  printf ("Total seek operations\t%d\n", scount);
}

void
calcdiff (int head)
{
  for (int i = 0; i < n; i++)
    diff[i][0] = abs (arr[i] - head);
}

int
minindex ()
{
  int ind = -1;
  int min = 1e9;

  for (int i = 0; i < n; i++)
    {
      if (!diff[i][1] && min > diff[i][0])
	{
	  min = diff[i][0];
	  ind = i;
	}
    }
  return ind;
}

void
sstf ()
{
  int i, ind;
  head = h;
  scount = 0;

  printf ("\n\t\tSSTF\n");
  for (i = 0; i < n; i++)
    {
      seekseq[i] = head;
      calcdiff (head);
      ind = minindex ();

      diff[ind][1] = 1;
      scount += diff[ind][0];
      head = arr[ind];
    }
  seekseq[i] = head;

  printf ("The Seek Sequence \t");
  for (i = 0; i < n; i++)
    printf ("%d -> ", seekseq[i]);
  printf ("%d\n", seekseq[i]);
  printf ("Total seek operations\t%d\n", scount);
}

int
cmpfunc (const void *a, const void *b)
{
  return (*(int *) a - *(int *) b);
}

void
scan ()
{
  int i, j, y, ss = 1;
  head = h;
  scount = 0;
  l = u = 0;
  seekseq[0] = head;

  printf ("\n\t\tSCAN\n");

  if (dir == 'l')
    lowq[l++] = 0;
  else
    uppq[u++] = dsize - 1;

  for (i = 0; i < n; i++)
    {
      if (arr[i] < head)
	lowq[l++] = arr[i];
      else
	uppq[u++] = arr[i];
    }
  qsort (lowq, l, sizeof (int), cmpfunc);
  qsort (uppq, u, sizeof (int), cmpfunc);

  for (i = 0; i < 2; i++)
    {
      if (dir == 'l')
	{
	  for (j = ss, y = l - 1; y >= 0; y--, j++)
	    {
	      seekseq[j] = lowq[y];
	      scount += abs (lowq[y] - head);
	      head = lowq[y];
	    }
	  ss = j;
	  dir = 'r';
	}
      else if (dir == 'r')
	{
	  for (j = ss, y = 0; y < u; y++, j++)
	    {
	      seekseq[j] = uppq[y];
	      scount += abs (uppq[y] - head);
	      head = uppq[y];
	    }
	  ss = j;
	  dir = 'l';
	}
    }

  printf ("The Seek Sequence \t");
  for (i = 0; i < ss - 1; i++)
    printf ("%d -> ", seekseq[i]);
  printf ("%d\n", seekseq[i]);
  printf ("Total seek operations\t%d\n", scount);
}

void
cscan ()
{
  int i, j, y, ss = 1;
  head = h;
  scount = 0;
  l = u = 0;
  seekseq[0] = head;

  printf ("\n\t\tCSCAN\n");

  lowq[l++] = 0;
  uppq[u++] = dsize - 1;

  for (i = 0; i < n; i++)
    {
      if (arr[i] < head)
	lowq[l++] = arr[i];
      else
	uppq[u++] = arr[i];
    }
  qsort (lowq, l, sizeof (int), cmpfunc);
  qsort (uppq, u, sizeof (int), cmpfunc);

  if (dir == 'l')
    {
      for (j = ss, y = l - 1; y >= 0; y--, j++)
	{
	  seekseq[j] = lowq[y];
	  scount += abs (lowq[y] - head);
	  head = lowq[y];
	}
      for (y = u - 1; y >= 0; y--, j++)
	{
	  seekseq[j] = uppq[y];
	  scount += abs (uppq[y] - head);
	  head = uppq[y];
	}
      ss = j;
    }
  else if (dir == 'r')
    {
      for (j = ss, y = 0; y < u; y++, j++)
	{
	  seekseq[j] = uppq[y];
	  scount += abs (uppq[y] - head);
	  head = uppq[y];
	}
      for (y = 0; y < l; y++, j++)
	{
	  seekseq[j] = lowq[y];
	  scount += abs (lowq[y] - head);
	  head = lowq[y];
	}
      ss = j;
    }

  printf ("The Seek Sequence \t");
  for (i = 0; i < ss - 1; i++)
    printf ("%d -> ", seekseq[i]);
  printf ("%d\n", seekseq[i]);
  printf ("Total seek operations\t%d\n", scount);
}

void
look ()
{
  int i, j, y, ss = 1;
  head = h;
  scount = 0;
  l = u = 0;
  seekseq[0] = head;

  printf ("\n\t\tLOOK\n");

  for (i = 0; i < n; i++)
    {
      if (arr[i] < head)
	lowq[l++] = arr[i];
      else
	uppq[u++] = arr[i];
    }
  qsort (lowq, l, sizeof (int), cmpfunc);
  qsort (uppq, u, sizeof (int), cmpfunc);

  for (i = 0; i < 2; i++)
    {
      if (dir == 'l')
	{
	  for (j = ss, y = l - 1; y >= 0; y--, j++)
	    {
	      seekseq[j] = lowq[y];
	      scount += abs (lowq[y] - head);
	      head = lowq[y];
	    }
	  ss = j;
	  dir = 'r';
	}
      else if (dir == 'r')
	{
	  for (j = ss, y = 0; y < u; y++, j++)
	    {
	      seekseq[j] = uppq[y];
	      scount += abs (uppq[y] - head);
	      head = uppq[y];
	    }
	  ss = j;
	  dir = 'l';
	}
    }

  printf ("The Seek Sequence \t");
  for (i = 0; i < ss - 1; i++)
    printf ("%d -> ", seekseq[i]);
  printf ("%d\n", seekseq[i]);
  printf ("Total seek operations\t%d\n", scount);
}

void
clook ()
{
  int i, j, y, ss = 1;
  head = h;
  scount = 0;
  l = u = 0;
  seekseq[0] = head;

  printf ("\n\t\tCLOOK\n");

  for (i = 0; i < n; i++)
    {
      if (arr[i] < head)
	lowq[l++] = arr[i];
      else
	uppq[u++] = arr[i];
    }
  qsort (lowq, l, sizeof (int), cmpfunc);
  qsort (uppq, u, sizeof (int), cmpfunc);

  if (dir == 'l')
    {
      for (j = ss, y = l - 1; y >= 0; y--, j++)
	{
	  seekseq[j] = lowq[y];
	  scount += abs (lowq[y] - head);
	  head = lowq[y];
	}
      for (y = u - 1; y >= 0; y--, j++)
	{
	  seekseq[j] = uppq[y];
	  scount += abs (uppq[y] - head);
	  head = uppq[y];
	}
      ss = j;
    }
  else if (dir == 'r')
    {
      for (j = ss, y = 0; y < u; y++, j++)
	{
	  seekseq[j] = uppq[y];
	  scount += abs (uppq[y] - head);
	  head = uppq[y];
	}
      for (y = 0; y < l; y++, j++)
	{
	  seekseq[j] = lowq[y];
	  scount += abs (lowq[y] - head);
	  head = lowq[y];
	}
      ss = j;
    }

  printf ("The Seek Sequence \t");
  for (i = 0; i < ss - 1; i++)
    printf ("%d -> ", seekseq[i]);
  printf ("%d\n", seekseq[i]);
  printf ("Total seek operations\t%d\n", scount);
}

void
main ()
{
  fcfs ();
  sstf ();
  scan ();  cscan ();
  look ();
  clook ();
}
