#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <pthread.h>
#include <assert.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock1=PTHREAD_MUTEX_INITIALIZER;                                //initialize lock1

int pthread_mutex_lock(pthread_mutex_t*mutex);                                  
int pthread_mutex_unlock(pthread_mutex_t*mutex);

pthread_t p[10];                                                                //array of threads
vector<pair<char,int> > ans[500];                                               //vector to store ans
struct q{                                                                       //struct to give files to threads
     FILE *filename;
     int idx;
}st[10];

char c;                                                                         //to get char
string str;                                                                     //to store file

void* pzip(void *fileread)                                                      //WZip function
{
    int x=0;                                                                    //to chech which thread works
    
    q f = *(q*)fileread;
    x = f.idx;
    FILE *f1=f.filename;


    pthread_mutex_lock(&lock1);
        str.clear();
        while ((c = fgetc(f1)) != EOF)                                          //loop to store file at string str
        {
            if((c<='z'&&c>='a')||c==' '||c=='\n')
                str += c;
        }
    pthread_mutex_unlock(&lock1);
    pthread_mutex_lock(&lock1);
    int i=1;
    int j=1;    
    for(;i<str.size();i++){                                                     //loop to store results of function 
        if(str[i]==str[i-1]){
            j++;
        }else{
            ans[x].push_back({str[i-1],j});
            j=1;
        }
    }
    ans[x].push_back({str[str.size()-1],j});                                   //push last char to vector
  
    pthread_mutex_unlock(&lock1);
    fclose(f1);
}
int main(int argc,char** argv)
{
    if (argc ==1)
    {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    for(int k=1;k<argc;k++){                                                   //loop to store files at struct
        st[k].filename=fopen(argv[k],"r");
        st[k].idx=k;
    }
    for(int i=1;i<argc;i++){                                                   //loop to create threads
        pthread_create(&p[i],NULL,pzip,&st[i]);
    }
   
    for(int i=1;i<argc;i++){                                                   //loop to excute threads
        pthread_join(p[i],NULL);
    }
    for(int i=1;i<argc;i++){                                                   //loop to print ans
        for(auto e:ans[i]){
             cout<<e.second<<e.first;
             //fwrite(&e.second,sizeof(int),1,stdout);                         // if you want to write in the file
             //fwrite(&e.first,sizeof(char),1,stdout);
        }
        cout<<endl;
    }
}
