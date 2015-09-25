/*
-------------------HOW IT WORKS--------
        Written by HITKUL
	1.when ever u get a zero, check the cell i its right and left if, both are one 
	  and left one is close and right one is open or right one is close and left 
	  one is open then it is a edge.
	2.one u have a 1's cell inside the figure u start a foure directional recurive
	  function to convert all 1 to zero in that figure.
 */

#include "stdio.h"

void getmatrix(int (*matrix)[25]);
void flood_fill( int (*matrix)[25],int flag1,int flag2);
int edge_found(int (*matrix)[25],int flag1,int flag2);

int main()
{
	int matrix[25][25],i,j;
	getmatrix(matrix);
	//check for the edge and then start recursive flood_fill function
	for (i = 0; i < 25; ++i)
	{
		for ( j = 0; j < 25; ++j)
		{
			if(matrix[i][j]==0&&matrix[i][j+1]==1&&matrix[i][j-1]==1&&edge_found(matrix,i,j+1)&&!edge_found(matrix,i,j-1))
			{
				
					matrix[i][j+1]=0;
					flood_fill(matrix,i,j+1);
			}
			if(matrix[i][j]==0&&matrix[i][j+1]==1&&matrix[i][j-1]==1&&!edge_found(matrix,i,j+1)&&edge_found(matrix,i,j-1))
			{
				
					matrix[i][j-1]=0;
					flood_fill(matrix,i,j-1);
			}
		}
	}


	for (i = 0; i < 25; ++i)
	{	printf("\n");
		for (j = 0; j < 25; ++j)
		{
			printf("%d ",matrix[i][j]);
		}
	}
	return 0;
}

void getmatrix(int (*matrix)[25]){
	FILE *fptr;
	int i,j,counter=25;

	fptr=fopen("test.txt","r");

	if(fptr==NULL)
		printf("unable to open this file\n");
	else{
		for ( i = 0; i < counter; ++i)
		{	
			for (j = 0; j < counter; ++j)
			{
				fscanf(fptr, "%d ",&matrix[i][j] );
				
			}
		}
		fclose(fptr);
	}
}

//starting a recursive function which convert 1 to 0 and then push a
//recursive function which start the same function for neighbouring cells  
void flood_fill( int (*matrix)[25],int flag1,int flag2){

	if(matrix[flag1-1][flag2]==1){
		matrix[flag1-1][flag2]=0;
		flood_fill(matrix,flag1-1,flag2);
	}

	if(matrix[flag1+1][flag2]==1){
		matrix[flag1+1][flag2]=0;
		flood_fill(matrix,flag1+1,flag2);
	}

	if(matrix[flag1][flag2-1]==1){
		matrix[flag1][flag2-1]=0;
		flood_fill(matrix,flag1,flag2-1);
	}

	if(matrix[flag1][flag2+1]==1){
		matrix[flag1][flag2+1]=0;
		flood_fill(matrix,flag1,flag2+1);
	}
}


int edge_found(int (*matrix)[25],int flag1,int flag2){

	int i,j,test[4]={0,0,0,0},check=1;
	//test all the 4 direction to see if coordinate is closed or not
	
	//test in dir up
	for ( i = flag1-1; i >= 0; i--)
	{
		if(matrix[i][flag2]==0){
			test[0]=1;
			break;
		}
	}

	//test in dir down
	for ( i = flag1+1; i < 25; i++)
	{
		if(matrix[i][flag2]==0){
			test[1]=1;
			break;
		}
	}

	//test in dir left
	for ( i = flag2-1; i >=0 ; i--)
	{
		if(matrix[flag1][i]==0){
			test[2]=1;
			break;
		}
	}

	//test in dir right
	for ( i = flag2+1; i < 25; i++)
	{
		if(matrix[flag1][i]==0){
			test[3]=1;
			break;
		}
	}

	//check if it is closed for all directions
	for ( i = 0; i < 4; ++i)
	{
		if(test[i]==0)
			check=0;
	}
 	 	return check;

}
