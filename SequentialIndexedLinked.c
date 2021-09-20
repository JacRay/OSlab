#include<stdio.h>
#include<conio.h>
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