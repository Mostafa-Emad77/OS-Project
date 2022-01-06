#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
     
      return 0;
    }
    int i;
    FILE* fp;
    char ch;
    for(i = 1; i < argc; i++){
      fp = fopen(argv[i], "r");        // case of issue opening file
      if(fp == NULL){
        printf("wcat: cannot open file\n");
        return 1;
      }
     
      while((ch = fgetc(fp)) != EOF){ // case that file has been opened, iterate through file and output contents
        printf("%c", ch);             // print each char in the file
      }

      fclose(fp);
    }

    return 0;
}
