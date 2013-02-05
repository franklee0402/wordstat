#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <regex.h>
#include <sys/types.h>
#include "node.h"

#define IN 1
#define OUT 0

void main(int argc , char *argv[] ) {

   /*check arguments */	
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
    int bufflen = 1024;
    char *wordbuff;
    wordbuff = (char *) malloc(bufflen);
    int wordlen = 0;
    struct node * root = NULL;
    memset(wordbuff,0,bufflen);

    while ((x=fgetc(pFile)) != EOF)
    {
      if(isalnum(x) == 0){ /*word ended */
            status = OUT;
            printf(" %s\n", wordbuff);
/*            insert(*root, *wordbuff);*/
            bzero(wordbuff,wordlen);
        }
        else{
            if(status == OUT){   /*start of a new word */
                if(isalpha(x) == 0){ /*word can't start with number*/
                    continue;
                }
                wordlen = 0;
                status = IN;
                wordbuff[wordlen] = x;
                wordlen++;
            }
            else{   /*already inside a word */
               /* if(wordlen >= bufflen){ realloc(*wordbuff, 1000);}*/
                wordbuff[wordlen] = x;
                wordlen++;
            }
        }
    }	
	int wordcount = 0;
    fclose(pFile);
    free(wordbuff);
}
