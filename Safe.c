#include<stdio.h>
#include<conio.h>
int main()
{
int p, allocation[10], max[10], need[10], available,i,j,flag[10],x=0,sequence[10],c=0;
printf("Enter the processes \n");
scanf("%d",&p);
for (i=0;i<p;i++)
{
    flag[i]=0;
}
for(i=0;i<p;i++)
{
    printf("Enter the allocation for process P[%d]\n",i);
    scanf("%d",(allocation+i));
    printf("Enter the max for process P[%d]\n",i);
    scanf("%d",(max+i));
}
printf("Enter the resources whether the resourses is avilable or not");
    scanf("%d",&available);
for(i=0;i<p;i++)
{
    need[i]=max[i]-allocation[i];
}
for(i=0;i<p;i++)
{
    printf("Need of P[%d] is %d\n",i,(need+i));
}
for(i=0;i<p;i++)
{
    for(j=0;j<p;j++)
    {
        if(flag[j]==0&&need[j]<=available)
        {
        available=available+allocation[j];
        flag[j]=1;
        printf("Process %d has been allocated resources\n",j);
        sequence[c]=j;
        c++;
        }
    }
}
for(i=0;i<p;i++)
{
    if((flag+i)==0)
    {
    printf("system is in unsafe state\n");
    x=1;
    break;
    }
}
if(x==0)
{
printf("System is in safe state\n");
printf("Safe sequence is \n");
for(i=0;i<p;i++)
{
    printf("P[%d],",(sequence+i));
}
}
printf("\n");
return 0;
}
