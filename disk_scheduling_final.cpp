// Disk Scheduling program that contains 6 algorithm ( FCFS , SSTF , SCAN , C-SCAN , LOOK , C-LOOK )
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// functions are declared for above given algorithms 
void fcfs();
void sstf();
void scan();
void look();
void c_scan();
void c_look();

int cylinder,header,he,pre_request,*track_request,*track_request_original,request;  // different variables are globally declared for different purpouses

int main()
{
	int choice ;
	printf("\t\t\t\t\t\t*********************** \n");
	printf("\t\t\t\t\t\tDisk SCHEDULING PROGRAM \n");
	printf("\t\t\t\t\t\t*********************** ");
	printf("\nEnter the number of track requests: ");
	scanf("%d",&request);
	
	printf("\nEnter the number of total number of cylinders: ");
	scanf("%d",&cylinder);
	
	track_request=(int*)malloc(sizeof(int)*request);
	track_request_original=(int*)malloc(sizeof(int)*request);
	
	
	printf("\nPlease enter the Track Request: ");
		for(int i=0;i<request;i++)
	{
		printf("\nTrack Request[%d]:- ",i);
	    scanf("%d",&track_request_original[i]);
	    track_request[i]=track_request_original[i];
	}
	
	
	for(int i=0;i<request;i++)
	{
		for(int j=0;j<request;j++)
		{
			if(track_request[i]<track_request[j])
			{
				int t=track_request[i];
				track_request[i]=track_request[j];
				track_request[j]=t;
			}
		}
	}

  printf("\nEnter the header: ");
  scanf("%d",&header);
  
  printf("\nEnter the Pre Request: ");
  scanf("%d",&pre_request);
  
  
  for(int i=0;i<request;i++)
  {
  	if(header >= track_request[i] && header < track_request[i+1])
  	{
  		 he=i;
  	}
  }
  
	do
	{
	printf("\n Which algorithm you want to use for Disk Scheduling:- ");
	printf("\n\n1.First Come First Serve Algorithm \n 2. Shortest Seek Time First Algorithm\n 3. Scan Algorithm \n 4. C-Scan Algorithm \n 5. Look Algorithm \n 6. C-Look Algorithm \n-1. Exit\n");
	printf("Please enter your choice:- ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: fcfs();
		        break;
	   	case 2: sstf();
		        break;
		case 3: scan();
		        break;
		case 4: c_scan();
	        break;
		case 5: look();
		        break;
		case 6: c_look();
		        break;
		case 7: default:
		        printf("\n you have entered the wrong choice ");
		        break;
		        
	}
	}while(choice!=-1);
	
	return 0;
}
void fcfs()
{
	int sequence[100];
	int sum=0;
	int a=header;
	
		for(int i=0;i<request;i++)
	{
		
		sequence[i]=a-track_request_original[i];
		if(sequence[i]<0)
		{
			sequence[i]=track_request_original[i]-a;
		}
		a=track_request_original[i];
       sum=sum+sequence[i];
 }

 printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<request;i++)
	{
		if(track_request_original[i]>1000)
		{
			printf("+------");
		}
		else if(track_request_original[i]>100 && track_request_original[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<request;i++)
	{
		if(i==request-1)
		{
			printf("%d",track_request_original[i]);
		}
		else
		{
			printf("%d->",track_request_original[i]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<request;i++)
	{
		if(track_request_original[i]>1000)
		{
			printf("+------");
		}
		else if(track_request_original[i]>100 && track_request_original[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
printf("\n\t\t********Movement of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",sum);
}
void sstf()
{
int cheader;
bool inc[20];
int seq[20];

for(int i=0;i<request;i++)
{
	inc[i]=false;
}
	cheader=header;
		int sum=0;
	for(int i=0;i<request;i++)
	{
	int min=999;
	int index;
		for(int j=0;j<request;j++)
		{
			if(abs(cheader-track_request_original[j])<min && inc[j]==false)
			{
				min=abs(cheader-track_request_original[j]);
				index=j;
			}			
		}
		if(inc[index]==false)
		{
			seq[i]=index;
			inc[index]=true;
			sum=sum+min;
			cheader=track_request_original[index];
		}
	}

	
	printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<request;i++)
	{
		if(track_request_original[seq[i]]>1000)
		{
			printf("+------");
		}
		else if(track_request_original[seq[i]]>100 && track_request_original[seq[i]]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<request;i++)
	{
		if(i==request-1)
		{
			printf("%d",track_request_original[seq[i]]);
		}
		else
		{
			printf("%d->",track_request_original[seq[i]]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<request;i++)
	{
		if(track_request_original[seq[i]]>1000)
		{
			printf("+------");
		}
		else if(track_request_original[seq[i]]>100 && track_request_original[seq[i]]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
printf("\n\t\t********Sum of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",sum);
}

void scan()
{
	
	printf("\n\n   SCAN   :-");
	int current_header_scan[100];
	int k=1;
		current_header_scan[0]=header;
	if(header >= pre_request)
	{


		for(int i=he+1;i<request;i++)
		{
			current_header_scan[k]=track_request[i];
			k++;
			if(i==request-1)
			{
				current_header_scan[k]=cylinder-1;
				
				k++;
				break;
			}
		}
		for(int i=he;i>=0;i--)
		{
			current_header_scan[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	
    		for(int i=he;i>=0;i--)
		{
			current_header_scan[k]=track_request[i];
			k++;
			if(i==0)
			{
				current_header_scan[k]=0;
				k++;
				break;
			}
		}
        for(int i=he+1;i<request;i++)
		{
			current_header_scan[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<=request+1;i++)
	{
		if(current_header_scan[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_scan[i]>100 && current_header_scan[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<=request+1;i++)
	{
		if(i==request+1)
		{
			printf("%d",current_header_scan[i]);
		}
		else
		{
			printf("%d->",current_header_scan[i]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<=request+1;i++)
	{
		if(current_header_scan[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_scan[i]>100 && current_header_scan[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	 int seek_time=0;
    
    for(int i=0;i<request+1;i++)
    {
    	seek_time+=abs(current_header_scan[i]-current_header_scan[i+1]);
    	
    }
	printf("\n");
printf("\n\t\t********Seek Time of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",seek_time);
}
void look()
{
int k=1;
int current_header_look[100];
current_header_look[0]=header;
	if(header >= pre_request)
	{
	
		for(int i=he+1;i<request;i++)
		{
			current_header_look[k]=track_request[i];
			k++;
		
		}
		for(int i=he;i>=0;i--)
		{
			current_header_look[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    
    		for(int i=he;i>=0;i--)
		{
			current_header_look[k]=track_request[i];
			k++;
			
		}
        for(int i=he+1;i<request;i++)
		{
			current_header_look[k]=track_request[i];
			k++;
		}
		
    }
    printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<=request;i++)
	{
		if(current_header_look[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_look[i]>100 && current_header_look[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<=request;i++)
	{
		if(i==request)
		{
			printf("%d",current_header_look[i]);
		}
		else
		{
			printf("%d->",current_header_look[i]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<=request;i++)
	{
		if(current_header_look[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_look[i]>100 && current_header_look[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	 int seek_time=0;
    
    for(int i=0;i<request;i++)
    {
    	seek_time+=abs(current_header_look[i]-current_header_look[i+1]);
    	
    }
	printf("\n");
printf("\n\t\t********Seek Time of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",seek_time);
    

}
void c_scan()
{
int k=1;
int current_header_cscan[100];
current_header_cscan[0]=header;
	if(header >= pre_request)
	{

	
		for(int i=he+1;i<request;i++)
		{
			current_header_cscan[k]=track_request[i];
			k++;
			if(i==request-1)
			{
				current_header_cscan[k]=cylinder-1;
				k++;
				break;
			}
		}
		
		for(int i=0;i<=he;i++)
		{
			current_header_cscan[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	
    		for(int i=he;i>=0;i--)
		{
			current_header_cscan[k]=track_request[i];
			k++;
			if(i==0)
			{
				current_header_cscan[k]=0;
				k++;
				break;
			}
		}
        for(int i=request-1;i>=he;i--)
		{
			current_header_cscan[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<=request+1;i++)
	{
		if(current_header_cscan[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_cscan[i]>100 && current_header_cscan[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<=request+1;i++)
	{
		if(i==request+1)
		{
			printf("%d",current_header_cscan[i]);
		}
		else
		{
			printf("%d->",current_header_cscan[i]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<=request+1;i++)
	{
		if(current_header_cscan[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_cscan[i]>100 && current_header_cscan[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	 int seek_time=0;
    
    for(int i=0;i<request+1;i++)
    {
    	seek_time+=abs(current_header_cscan[i]-current_header_cscan[i+1]);
    	
    }
	printf("\n");
printf("\n\t\t********Seek Time of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",seek_time);
    
    

}
void c_look()
{

printf("\n\n  c-look  :-");
int k=1;
int current_header_clook[100];
current_header_clook[0]=header;
	if(header >= pre_request)
	{
	
		for(int i=he+1;i<request;i++)
		{
			current_header_clook[k]=track_request[i];
			k++;
		
		}
		for(int i=0;i<=he;i++)
		{
			current_header_clook[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	
    		for(int i=he;i>=0;i--)
		{
			current_header_clook[k]=track_request[i];
			k++;
			
		}
        for(int i=request-1;i>he;i--)
		{
			current_header_clook[k]=track_request[i];
			k++;
		}
		
    }
    
    
      printf("\n\t\t********The Seek Order is********\n");
 printf("\t\t");
 	 for(int i=0;i<request+1;i++)
	{
		if(current_header_clook[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_clook[i]>100 && current_header_clook[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	printf("\n");
	printf("\t\t  ");
for(int i=0;i<request+1;i++)
	{
		if(i==request)
		{
			printf("%d",current_header_clook[i]);
		}
		else
		{
			printf("%d->",current_header_clook[i]);
		}
	}
	printf("\n");
	printf("\t\t");
	 for(int i=0;i<request+1;i++)
	{
		if(current_header_clook[i]>1000)
		{
			printf("+------");
		}
		else if(current_header_clook[i]>100 && current_header_clook[i]<1000)
		{
			printf("+----");
		}
	else
	{
		printf("+---");
	}
	}
	 int seek_time=0;
    
    for(int i=0;i<request;i++)
    {
    	seek_time+=abs(current_header_clook[i]-current_header_clook[i+1]);
    	
    }
	printf("\n");
printf("\n\t\t********Seek Time of total cylinders********\n");	
printf("\t\t");
 printf("%d\n",seek_time);
 
 
    

}
