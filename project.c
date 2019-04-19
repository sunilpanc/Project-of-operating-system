#include<stdio.h>
int sorting();
int logic();
void show_result();
int max(int ar[], int size);

int total_process,i,ar_time[50],br_time[50],proc_s[50],j, k,ct=0, ct_a[50],br_time1[50],wt[50],tat[50],av_wt,av_tat;
float tat1, wt1;

int main()
{
	printf("#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**");
	printf("\n\n\nEnter total no of proccess: ");
	scanf("%d",&total_process);
	for(i=0; i<total_process; i++)
	{
		printf("\nEnter for process P%d :- ",(i+1));
		printf("\nEnter Arrival time: ");
		scanf("%d",&ar_time[i]);
		printf("Enter Burst time: ");
		scanf("%d",&br_time[i]);
		br_time1[i]=br_time[i];
		proc_s[i] = i+1;
	}
	
	// sorting of arival time and arrange the sequence of arrival time
	sorting();
	logic();
	show_result();		
	printf("#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**#**");
}


int sorting()
{
  int c, d, swap, temp, btemp;
 
  for (c = 0 ; c < total_process - 1; c++)
  {
    for (d = 0 ; d < total_process- c - 1; d++)
    {
      if (ar_time[d] > ar_time[d+1]) 
      {
      	//arival time sorting
        swap         = ar_time[d];
        ar_time[d]   = ar_time[d+1];
        ar_time[d+1] = swap;
        
        //for store the process numbers
        temp      = proc_s[d];
        proc_s[d] = proc_s[d+1];
        proc_s[d+1] = temp;
        
        //burst time's change the sequence as arival time
        btemp        = br_time[d];
        br_time[d]   = br_time[d+1];
        br_time[d+1] = btemp; 
        
      }
    }
  }
  
return 0;
}

int max(int ar[],int size)
{
  int maximum, c, loc = 1;
  maximum = ar[0];
 
  for (c = 1; c < size; c++)
  {
    if (ar[c] > maximum)
    {
       maximum  = ar[c];
       loc = c+1;
    }
  }
  return maximum;
}


void show_result()
{
	int c, d, swap, temp, btemp,ctemp;
	for (c = 0 ; c < total_process - 1; c++)
  {
    for (d = 0 ; d < total_process- c - 1; d++)
    {
      if (proc_s[d] > proc_s[d+1]) 
      {
      	//arival time sorting
        swap         = ar_time[d];
        ar_time[d]   = ar_time[d+1];
        ar_time[d+1] = swap;
        
        //for store the process numbers
        temp      = proc_s[d];
        proc_s[d] = proc_s[d+1];
        proc_s[d+1] = temp;
        
        //burst time's change the sequence as arival time
        btemp        = br_time[d];
        br_time[d]   = br_time[d+1];
        br_time[d+1] = btemp; 
        
        //for completion time
        ctemp        = ct_a[d];
        ct_a[d]      = ct_a[d+1];
        ct_a[d+1]    = ctemp;  
        
      }
    }
  }
  printf("Process No\tCT \tTAT\tWT\t");
  for(i=0; i<total_process; i++)
  {
  	tat[i] = ct_a[i]-ar_time[i]; 
  	wt[i]= tat[i]-br_time[i];
  	av_tat = av_tat + tat[i];
  	av_wt = av_wt + wt[i];
  }
  wt1 = av_wt/total_process;
  tat1 = av_tat/total_process;
  
  for(i=0; i<total_process; i++)
  {
  	printf("\n%d\t\t%d\t%d\t%d\t",(proc_s[i]),ct_a[i],tat[i],wt[i]);
  }
  printf("\nAverage waiting time = %f", wt1);
  printf("\nAverage Turn Around time is = %f ", tat1);
}


int logic()
{
	int d,n,swap, temp, btemp,ctemp;
	for(i = 0; i<total_process; i++)
	{
		
		if(ar_time[i] <= ar_time[i+1])
		{
				ct = ct + br_time[i];
			    ct_a[i]=ct;	
			
		}
		else if(max(ar_time,total_process)<=ct)
		{
		    break;
		}
	}
	
j=i;
k=j;	
for (i; i < total_process - 1; i++)
  {
    for (d = i ; d < total_process- i - 1; d++)
    {
      if (br_time[d] > br_time[d+1]) 
      {
      	//arival time sorting
        swap         = ar_time[d];
        ar_time[d]   = ar_time[d+1];
        ar_time[d+1] = swap;
        
        //for store the process numbers
        temp      = proc_s[d];
        proc_s[d] = proc_s[d+1];
        proc_s[d+1] = temp;
        
        //burst time's change the sequence as arival time
        btemp        = br_time[d];
        br_time[d]   = br_time[d+1];
        br_time[d+1] = btemp; 
      }
    }
  }
  
 for(j; j<total_process; j++)
    {
        ct = ct + br_time[j];
		ct_a[i]=ct;
	}
  
  
  for (k; k < total_process - 1; k++)
  {
    for (d = k ; d < total_process-k- 1; d++)
    {
      if (ar_time[d] > ar_time[d+1]) 
      {
      	//arival time sorting
        swap         = ar_time[d];
        ar_time[d]   = ar_time[d+1];
        ar_time[d+1] = swap;
        
        //for store the process numbers
        temp      = proc_s[d];
        proc_s[d] = proc_s[d+1];
        proc_s[d+1] = temp;
        
        //burst time's change the sequence as arival time
        btemp        = br_time[d];
        br_time[d]   = br_time[d+1];
        br_time[d+1] = btemp; 
        
        ctemp        = ct_a[d];
        ct_a[d]      = ct_a[d+1];
        ct_a[d+1]    = ctemp;  
        
      }
    }
  }
  
}


