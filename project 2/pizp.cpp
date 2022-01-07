#include <fstream>
#include <bits/stdc++.h>
#include <pthread.h>
#include <assert.h>
#include <signal.h>
#define sc second
#define ft first
using namespace std;

pthread_mutex_t lock1=PTHREAD_MUTEX_INITIALIZER;                                //initialize lock1
int pthread_mutex_lock(pthread_mutex_t*mutex);
int pthread_mutex_unlock(pthread_mutex_t*mutex);

pthread_t p[50];                                                                //array of threads
deque<pair<char,int> > ans[50];                                               //vector to store ans
struct q                                                                        //struct to give files to threads
{
    FILE *filename;
    int idx;
} st[50];
char c;                                                                         //to get char
string str;                                                                     //to store file
void* pzip(void *fileread)                                                      //WZip function
{
    int file_idx=0;                                                                    //to chech which thread works
    q f = *(q*)fileread;
    file_idx = f.idx;
    FILE *f1=f.filename;

    pthread_mutex_lock(&lock1);
    str.clear();
    while ((c = fgetc(f1)) != EOF)                                          //loop to store file at string str
    {
        if((c<='z'&&c>='a')||c==' '||c=='\n')
            str += c;
    }
    int i=1, j=1;
    for(; i<(int)str.size(); i++)                                                    //loop to store results of function
    {
        if(str[i]==str[i-1])
            j++;
        else{
            ans[file_idx].push_back({str[i-1],j});
            j=1;
        }
    }
    ans[file_idx].push_back({str[str.size()-1],j});                                   //push last char to vector

    pthread_mutex_unlock(&lock1);
    fclose(f1);
    return NULL;
}
int main(int argc,char** argv)
{
    if (argc ==1){
        printf("pzip: file1 [file2 ...]\n");
        return 1;
    }
    for(int k=1; k < argc;k++){                                                 //loop to store files at struct{
        st[k].filename = fopen(argv[k],"r");
        st[k].idx = k;
    }
    for(int i=1; i < argc; i++)                                                  //loop to create threads
        pthread_create(&p[i],NULL,pzip,&st[i]);

    for(int i=1; i<argc; i++)                                                  //loop to excute threads
        pthread_join(p[i],NULL);
    for(int i = 2; i < argc ;++i){
        if(ans[i-1].back().ft == ans[i].front().ft){
            ans[i].front().sc += ans[i-1].back().sc;
            ans[i-1].pop_back();
        }
    }
    for(int i = 1; i < argc; i++){                                                  //loop to print ans{
        for(auto it:ans[i]){
            fwrite(&it.sc,sizeof(int),1,stdout);                         // if you want to write in the file
            fwrite(&it.ft,sizeof(char),1,stdout);
        }
    }
}
