//read 2-x massiv

#include "stdio.h"
#include "string.h"
#define MAX_FILE_SIZE 1000

typedef unsigned char BYTE;
enum colors {blue, green, red};

typedef struct{BYTE blue ; BYTE green; BYTE red;} PIXEL;

main()
{
	
    char type[2];  
    int size;
    int res;
    int off;
    int ssz;
    int w;
    int h;
    int end[7];
    FILE * fin = fopen("1.bmp", "r");
    perror("Open file");

  

    fread(&type, 2, 1, fin);
    fread(&size, 4, 1, fin);
    fread(&res, 4, 1, fin);
    fread(&off, 4, 1, fin);
    fread(&ssz, 4, 1, fin);
    fread(&w, 4, 1, fin);
    fread(&h, 4, 1, fin);
    fread(end, 4, 7, fin);
  


    PIXEL rastr[MAX_FILE_SIZE][MAX_FILE_SIZE];
    
int padding=(size-off-h*w*3)/h;
BYTE pad[20];   
int i,j;
for(i=0; i<h ; i++)
{
	for(j=0; j<w ; j++)
		fread(&rastr[i][j], 3, 1, fin);
        fread(pad, padding, 1, fin);        
}	

int hj=0;
int lk=0,li=0;
for(i=0; i<h ; i++)
	for(j=0; j<w ; j++)
{
		if(rastr[li][lk].green!=rastr[i][j].green && rastr[li][lk].blue!=rastr[i][j].blue && rastr[li][lk].red!=rastr[i][j].red)
		{
			hj++;
			lk=j;
			li=i;
		}	
}
	
printf("%d\n",hj/2);

    
return 0; 
}
