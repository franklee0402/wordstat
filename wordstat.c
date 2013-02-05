#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <regex.h>
#include <sys/types.h>


#define IN 1
#define OUT 0

void main(int argc , char *argv[] ) {

i   /*check arguments */	
	if(argc != 2){
		printf("invalid arguments-SS\n");
		return;
	}
	if(strcmp(argv[1],"-h") == 0){ 
		printf("Enter the file name\n");
		return;
	}




    int status = OUT;
	FILE *pFile=fopen(argv[1], "r");
    char x;
    int buflen = 1024;
    char *wordbuff;
    wordbuff = (char *) malloc(buflen);
    int wordlen = 0;
    memset(wordbuf,0,bufsize);

    while ((x=fgetc(pFile)) != EOF)
    {
            bzero(wordbuf,wordlen);
        if(!isalnum(x)){
            status = OUT;
        }
        else{
            if(status == OUT){   /*start of a new word */
                wordlen = 0;
            }
            else{   /*still inside a word */
                if(wordlen >= bufflen
                wordbuff[wordlen] = x;
                wordlen++;
            }
        }
   printf("%c", x);

    }	
        printf("\n");
		int wordcount = 0;
        fclose(pFile);
}
