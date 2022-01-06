#include <bits/stdc++.h>
using namespace std;
#define ll long long
char letter ;
int char_rep ;
int main(int argc, char** argv)
{
    if(argc==1)
    {
        cout<<"wunzip: file1 [file2 ...]\n";
        return 1;
    }
    for(int i=1; i<argc; i++)
    {
        FILE *file ;
        file = freopen(argv[i],"r",stdin);
        vector<pair<char,int>> res;
        char c;
        int rep = 0;
        while(fread(&rep,1,4,file)){
            c = getchar();
            res.push_back({c,rep});
        }
        for(auto it:res){
            for(int j = 0; j < it.second ;++j)
                cout << it.first;
        }
        fclose(file);
    }
    return 0;
}