#include<stdio.h>
#include<conio.h>
int f[50], i, st, len, j, c, k, count = 0;
void allocate(){
    count=0;
    printf("Enter starting block and length of files: ");
    scanf("%d%d", &st,&len);
    for(k=st;k<(st+len);k++)
        if(f[k]==0)
            count++;
    if(len==count)
    {
        for(j=st;j<(st+len);j++)
            if(f[j]==0)
            {
            f[j]=1;
            printf("%d\t%d\n",j,f[j]);
            }
        if(j!=(st+len-1))
        printf("The file is allocated to disk\n");
    }
    else
    printf("The file is not allocated \n");
}
int main()
{
for(i=0;i<50;i++)
    f[i]=0;
int r;
printf("Enter Total No of Files :");
scanf("%d", &r);
for(i=0;i<r;i++)
    allocate();
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
if(c==1)
    allocate();
else
    return 0;
getch();
}
