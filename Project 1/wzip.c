#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


  int times;
  char ch;

int main(int argc,char** argv)
{
int x=0;
char* str =(char*)malloc(1);
if (argc ==1) {
printf("wzip: file1 [file2 ...]\n");
return 1;
}
int k;
for(k=1;k<argc;k++){
FILE *fileread=fopen(argv[k],"r");
if(fileread==NULL){
    printf("ERROR FILE OPENING\n");
    exit(1);
}
else{

      // reading line by line, max 256 bytes

	char c;
    while ((c = fgetc(fileread)) != EOF){
    	x++;
    	str=realloc(str,x+1);
    	str[x-1]=c;
    	str[x]='\0';
    }
    
    fclose(fileread);

    }

}
       	
     int i;
    int j=1;
    for(i=0;((str[i]) != '\0'); i++){
    	
        if((str[i])!=(str[i+1])){
            times=j;
            ch=str[i];
            fwrite(&times,sizeof(int),1,stdout);
            fwrite(&ch,sizeof(char),1,stdout);
            j=1;
            }

    else j++;
    }
	

}








