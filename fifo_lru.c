#include<stdio.h>
#include<stdlib.h>

void fcfs(){


  int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
  printf("Enter total number of processes(maximum 20): ");
  scanf("%d",&n);

  printf("\nEnter Process Burst Time\n");

  for(i=0;i<n;i++)
  {
      printf("P%d: ",i+1);
      scanf("%d",&bt[i]);
  }

  wt[0]=0;    //waiting time for first process is 0

  //calculating waiting time
  for(i=1;i<n;i++)
  {
      wt[i]=0;
      for(j=0;j<i;j++)
          wt[i]+=bt[j];
  }

  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

  //calculating turnaround time
  for(i=0;i<n;i++)
  {
      tat[i]=bt[i]+wt[i];
      avwt+=wt[i];
      avtat+=tat[i];
      printf("\nP%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
  }

  avwt/=i;
  avtat/=i;
  printf("\n\nAverage Waiting Time: %d",avwt);
  printf("\nAverage Turnaround Time: %d\n\n",avtat);


}

void priority(){


  int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
  printf("Enter Total Number of Process: ");
  scanf("%d",&n);

  printf("\nEnter Burst Time and Priority\n");


  for(i=0;i<n;i++)
  {
      printf("\nP%d\n",i+1);
      printf("Burst Time: ");
      scanf("%d",&bt[i]);
      printf("Priority: ");
      scanf("%d",&pr[i]);
      p[i]=i+1;           //contains process number
  }

  //sorting burst time, priority and process number in ascending order using selection sort
  for(i=0;i<n;i++)
  {
      pos=i;
      for(j=i+1;j<n;j++)
      {
          if(pr[j]<pr[pos])
              pos=j;
      }

      temp=pr[i];
      pr[i]=pr[pos];
      pr[pos]=temp;

      temp=bt[i];
      bt[i]=bt[pos];
      bt[pos]=temp;

      temp=p[i];
      p[i]=p[pos];
      p[pos]=temp;
  }

  wt[0]=0;    //waiting time for first process is zero

  //calculate waiting time
  for(i=1;i<n;i++)
  {
      wt[i]=0;
      for(j=0;j<i;j++)
          wt[i]+=bt[j];

      total+=wt[i];
  }

  avg_wt=total/n;      //average waiting time
  total=0;

  printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

  for(i=0;i<n;i++)
  {
      tat[i]=bt[i]+wt[i];     //calculate turnaround time
      total+=tat[i];
      printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
  }

  avg_tat=total/n;     //average turnaround time
  printf("\n\nAverage Waiting Time = %d",avg_wt);
  printf("\nAverage Turnaround Time = %d\n\n",avg_tat);




}

void rr(){



  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

  printf("Enter Total Process: ");
  scanf("%d",&n);
  remain=n;

  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for P%d : ",count+1);
    scanf("%d",&at[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }

  printf("Enter Time Quantum: ");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

  for(time=0,count=0;remain!=0;)
  {

    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }

    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }

    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P%d\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }

    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }

  printf("\nAverage Waiting Time = %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f\n\n",turnaround_time*1.0/n);





}

void sjf(){



  int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
  float avg_wt,avg_tat;
  printf("Enter number of process : ");
  scanf("%d",&n);

  printf("\nEnter Burst Time : ");

  for(i=0;i<n;i++)
  {
      printf("P%d : ",i+1);
      scanf("%d",&bt[i]);
      p[i]=i+1;           //contains process number
  }

  //sorting burst time in ascending order using selection sort
  for(i=0;i<n;i++)
  {
      pos=i;
      for(j=i+1;j<n;j++)
      {
          if(bt[j]<bt[pos])
              pos=j;
      }

      temp=bt[i];
      bt[i]=bt[pos];
      bt[pos]=temp;

      temp=p[i];
      p[i]=p[pos];
      p[pos]=temp;
  }

  wt[0]=0;            //waiting time for first process will be zero

  //calculate waiting time
  for(i=1;i<n;i++)
  {
      wt[i]=0;
      for(j=0;j<i;j++)
          wt[i]+=bt[j];

      total+=wt[i];
  }

  avg_wt=(float)total/n;      //average waiting time
  total=0;

  printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

  for(i=0;i<n;i++)
  {
      tat[i]=bt[i]+wt[i];     //calculate turnaround time
      total+=tat[i];
      printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
  }

  avg_tat=(float)total/n;     //average turnaround time
  printf("\n\nAverage Waiting Time = %f",avg_wt);
  printf("\nAverage Turnaround Time = %f\n\n\n",avg_tat);




}

int main(){
  int choice;
  while(1){
    printf("1.First Come First Serve Scheduling Algorithm\n2.Priority Wise Scheduling Algorithm\n3.Round Robin Scheduling Algorithm\n4.Shortest Job First Scheduling Algorithm\n5.Exit");
    printf("Enter Choice\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        fcfs();
      break;

      case 2:
        priority();
      break;

      case 3:
        rr();
      break;

      case 4:
        sjf();
      break;

      case 5:
        exit(0);
      break;

    }
  }

  return 0;
}
