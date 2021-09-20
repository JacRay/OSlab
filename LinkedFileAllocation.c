#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int f[50], index[50],i, n, st, len, j, c, k, ind,count=0;
int check(int size)
{
    for (unsigned i = 0; i < size; i++)
    for (unsigned k = i + 1; k < size; k++)
        if (index[i] == index[k]){
            return 0;
        }
return 1;
}
void main()
{
for(i=0;i<50;i++)
f[i]=0;
x:printf("Enter the Starting block and length: ");
scanf("%d%d",&ind, &n);
if(f[ind]!=1)
{
    f[ind] = 1;
}
else
{
    printf("%d index is already allocated \n",ind);
    goto x;
}
y: count=0;
printf("Enter next links :");
for(i=0;i<n-1;i++)
{
    scanf("%d", &index[i]);
    if(f[index[i]]==0)
    count++;
}
if(count==n-1 && check(n-1))
{
    for(j=0;j<n-1;j++)
    f[index[j]]=1;
    printf("Allocated\n");
    printf("File Indexed\n");
    for(k=0;k<n-1;k++){
        if(k == 0){
            printf("%d-------->%d : %d\n",ind,index[k],f[index[k]]);
        }
        else{
            printf("%d-------->%d : %d\n",index[k-1],index[k],f[index[k]]);
        }
    }
}
else
{
printf("File in the index is already allocated \n");
printf("Enter another file indexed");
goto y;
}
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
if(c==1)
goto x;
else
exit(0);
getch();
}