#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int sequential(){
    int f[100], i, st, len, j, c, k, count = 0;
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
int indexed(){
    int f[100], index[100],i, n, st, len, j, c, k,store[100][100],storesize=0, ind,count=0;
    int check(int size)
    {
        for (unsigned i = 0; i < size; i++)
        for (unsigned k = i + 1; k < size; k++)
            if (index[i] == index[k]){
                return 0;
            }
    return 1;
    }
    for(i=0;i<50;i++)
        f[i]=0;

    x:printf("Enter the index block: ");
    scanf("%d",&ind);
    if(f[ind]!=1)
    {
        f[ind] = 1;
        store[storesize][0] = ind;
        printf("Enter No of files for the index %d on the disk : \n", ind);
        scanf("%d",&n);
    }
    else
    {
        printf("%d index is already allocated \n",ind);
        goto x;
    }
    y: count=0;
    printf("Enter index of each file:");
    for(i=0;i<n;i++)
    {
        scanf("%d", &index[i]);
        if(f[index[i]]==0)
        count++;
    }
    if(count==n && check(n))
    {
        for(j=0;j<n;j++){
            f[index[j]]=1;
            store[storesize][j+1] = index[j];
        }
        storesize++;
        printf("Allocated\n");
        printf("File Indexed\n");
        for(k=0;k<n;k++)
            printf("%d-------->%d : %d\n",ind,index[k],f[index[k]]);
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
        return 0;
    getch();
}
int linked(){

}
int main(){
    do{
        int ch;
        printf("\n MENU");
        printf("\n 1. Sequential");
        printf("\n 2. Indexed");
        printf("\n 3. Linked");
        printf("\n 4. Exit");
        printf("\n Enter your Choice:");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                sequential();
                break;
            case 2:
                indexed();
                break;
            case 3:
                linked();
                break;
            default:
                printf("\n Exiting!!!!!");
        }
    }while(ch<4);

}