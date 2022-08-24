
#include<stdio.h>
#include<stdlib.h>


int check(char **arr,int st,int gr);//function that checks if the block is valid
void destroy(char **arr,int st,int gr,int k);//function destroys blocks when matched
void slide(char **arr,int st,int gr,int counter);//function that slides when there is a gap

int main(void)

{
	int N,M,C,i,j,c=49,r=49,flag,gr,st,ch;
	char **arr;
        char command[5];
	printf("Welcome !!\n");
	printf("The minimum dimensions you can give are 5*5 and the maximum dimensions you can give are 26*9\n");
	printf("Give Dimensions:");
	scanf("%d%d",&N,&M);
	
	if(N>=5 && M>=5)
		if(N<=26 && M<=9)
			printf("the height is %d and the length is %d \n",N,M);
	if((N<5 || N>26) || (M<5 || M>9))
		{
			do
			{
			printf("give again the dimensions:");
			scanf("%d%d",&N,&M);	
			}while((N>26 || N<5) && (M>9 || M<5));		
			printf("to upsos einai %d kai to mhkos einai %d \n",N,M);		
		}
	N=N+2;
   	M=M+2;
	printf("Give the number of colors:");
	do
	{
		scanf("%d",&C);
	}while(C>9);
	arr=(char**)malloc(N * sizeof(int*));
	for(i=0;i<N;i++)
		arr[i]=(char*)malloc(M*sizeof(int));
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
		{
			if(i==0 && j>=2)
			{
				arr[i][j]=c;
				c++;
			}
			else if(i==1)
				arr[i][j]='-';
			else if(j==0 && i>1)
			{
				arr[i][j]=r;
				r++;
			}
			else if(j==1 && i>1)
				arr[i][j]='|';
			else if(i>1 && j>1)
				arr[i][j]=49+rand()%C;
		}
	printf(" ");
	printf(" ");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf(" %c",arr[i][j]);
		}	
		printf("\n");
	}





                  //GAMEPLAY BELLOW
       //do
        //{
          	printf("Give Command (H,h B or b followed by the coordinance seperated with , ");
          	
                 scanf("%s",command);
               printf("WORKS FINE CHIEF");
                if((command[0]=='h')||(command[0]=='H'))
                  {
                    st=command[2]+2;
                    gr=command[4]+2; 
                    //printf("gr %d     st %d",gr,st);
                    ch=check(arr,gr,st);
           
                      if(ch==1)
 			 {
                                int k=arr[gr][st];
                       		destroy(arr,st,gr,k);
                                slide(arr,gr,st,0);//FUNCTION TO SLIDE DOWNWARDS ON BROKEN TILES
                         }
                      else
                    		 printf("not valid since block is single :(");


                  }
                // else_if((command[0]=='b')||(command[0]=='B'))
                  //  {
                     //bomb function
                 //   }
                 else
                   printf("invalid command try again");
                 flag==0;
         	//}while(flag==1);
        
	
	return 0;
}


int check(char **arr,int st,int gr)
{
    int k;
    k=arr[gr][st];

	if(arr[gr-1][st]==k)
 		 return 1;
	else if(arr[gr][st-1]==k)
  		return 1;
	else if(arr[gr][st+1]==k)
  		return 1;
	else if(arr[gr+1][st]==k)
 		return 1;
	else
  		return 0;
}

void destroy(char **arr,int st,int gr,int k)
{
   if(arr[gr][st]==k)
       arr[gr][st]='.';

  destroy(arr,st-1,gr,k);
  
  destroy(arr,st+1,gr,k);

  destroy(arr,st+1,gr+1,k);

  destroy(arr,st+1,gr-1,k);
}

void slide(char **arr,int st,int gr,int counter)
 {
  int i;
  
  for(i=gr;i>2;i++)
    {
 
    char temp=arr[gr][st];
    arr[gr-counter][st]=arr[gr-1][st];
       counter ++;
    arr[gr-counter][st]=temp;
    slide(arr,st,gr,counter);
    }
}






