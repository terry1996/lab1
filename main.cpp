#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n;
	n=atoi(argv[1]);
	srand(atoi(argv[2]));

	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	
	char **square=NULL;
	square= new char*[n];

	for(int i=0;i<n;i++)
	{
		square[i]=new char[n];

	}
	int i=0,j=0;
	for(; i<n; ((j+1)%n==0 ? (i++,j=0 ): j++ )) square[i][j]=	'a'+rand()%('z'-'a');

	return square;
}

void drawCharSquare(char **square, int n)
{

	for(int i=0, j=0;i<n; (j+1)%n==0 ? (i++,j=0 ): j++ ) {
	 printf("%c %.*s" ,square[i][j],	!((j+1)%n)	,"\n");
	}

	for(int i=0;i<n;i++) 
	{
		delete [] square[i];
		square[i]=NULL;

	}

	delete [] square;
	square=NULL;
	

}