#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//player 0=max;
//player 1=min;
//your symbol=X;
//comp symbol=O;

struct pair{
int move;
int result;
};


struct pair minimax(int a[9],int player)
{
	int i,j;
	int k;
	int max,min;
	struct pair fres;
	
	int status=check(a);
	//base case
	//printf("%d",status);
	if(status!=-1)
	{
		fres.move=-1;
		fres.result=status;
		return fres;
	}
	//for max player
	else if(player==0){
		struct pair res;
		k=0;
		max=-20;
		int index;
		
		for(i=0;i<9;i++)
		{
			if(a[i]==2)
			{
				a[i]=0;
				res=minimax(a,1);
				if(max < res.result)
				{
					max=res.result;
					index=i;
				}
				a[i]=2;
			}	
		}
				 
		fres.move=index;
		fres.result=max;
	
		return fres;
	}
	//for min player
	else if (player==1){
		struct pair res;
		k=0;
		max=20;
		int index;
		
		for(i=0;i<9;i++)
		{
			
			if(a[i]==2)
			{
				
				
				a[i]=1;
				res=minimax(a,0);
				if(max > res.result)
				{
					max=res.result;
					index=i;
				}
				a[i]=2;
			}	
		}
				
		fres.move=index;
		fres.result=max;
		return fres;
	}
	
	
}

void compturn(int a[9])
{
struct pair ans;
ans=minimax(a,0);
//printf("%d\n",ans.move);
int num=ans.move;
a[num]=0;
}


void itoc(int a[9],char t[3][3])
{
    int i,j,k;

    for(k=0;k<9;k++)
    {
        i=k/3;
        j=k%3;
        if(a[k]==1)
            t[i][j]='X';
        else if(a[k]==0)
            t[i][j]='O';
        else if(a[k]==2)
            t[i][j]='-';
    }
}


void printa(int a[9])
{

    char t[3][3];
    memset(t,'-',sizeof(t));
    itoc(a,t);
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{

			printf("%c|",t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int check(int a[9])
{
    
    //checking rows
    if(a[0]==a[1] && a[1]==a[2] && a[0]!=2)
    	{
    		if (a[0]==0)
    			return 10;
    		else 
    			return -10;
		}
    if(a[3]==a[4] && a[3]==a[5] && a[3]!=2)
    	{
    		if (a[3]==0)
    			return 10;
    		else 
    			return -10;
		}
    if(a[6]==a[7] && a[6]==a[8] && a[6]!=2)
    	{
    		if (a[6]==0)
    			return 10;
    		else 
    			return -10;
		}
    
    //checking column
    if(a[0]==a[3] && a[0]==a[6] && a[0]!=2)
    	{
    		if (a[0]==0)
    			return 10;
    		else 
    			return -10;
		}
    if(a[1]==a[4] && a[1]==a[7] && a[1]!=2)
    	{
    		if (a[1]==0)
    			return 10;
    		else 
    			return -10;
		}
    if(a[2]==a[5] && a[2]==a[8] && a[2]!=2)
    	{
    		if (a[2]==0)
    			return 10;
    		else 
    			return -10;
		}
    	
    //checking diagonal
    if(a[0]==a[4] && a[0]==a[8] && a[0]!=2)
		{
    		if (a[0]==0)
    			return 10;
    		else 
    			return -10;
		}
	if(a[2]==a[4] && a[2]==a[6] && a[2]!=2)
		{
    		if (a[2]==0)
    			return 10;
    		else 
    			return -10;
		}
	int i;
	//checking is it draw or game is incomplete
	int flag=0;
	for(i=0;i<9;i++)
	{
		if(a[i]==2)
			flag++;
	}
	return flag==0 ? 0:-1;
}


void playermove(int a[9])
{
    int inp;
    int i,j;
    re:
    printf("Enter your choise between 1 to 9");
    scanf("%d",&inp);
    inp--;
    if(a[inp]!=2)
        goto re;
    a[inp]=1;

}
main()
{
	char t[3][3];
	int a[9]={2,2,2,2,2,2,2,2,2};
	int inp;
	int x,y;
	int i,j;
	int win;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[i][j]='-';
		}
	}
	int count=9;

	while(count)
	{
		
	playermove(a);
	printa(a);

	win=check(a);
	//printf("%d\n",win);
	if(win==-10)
		{	printf("you win.\n");
				break;
		}
	count--;
	if(count==0)
	break;
	/*repeat:
		inp=rand()%9;
		//j=rand()%3;
		if(a[inp] != 2)
		goto repeat;
	a[inp]=0;*/
	compturn(a);

	printa(a);
	win=check(a);
	//printf("%d\n",win);
	if(win==10)
	{
		printf("comp win.\n");
		break;
	}

	count--;
	}
	if(count==0)
	{
		win=check(a);
		if(win==0)
		{
			printf("match draw\n");
		}
	}
}
