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
        vector<pair<char,int>> res;              /// save answer in res
        char c;                                  /// character to read each character from file
        int rep = 0;                             /// variable to count the no of repeation of each character 
        while(fread(&rep,4,1,file)){             /// reads the block of data (4byte) from the stream
            c = getchar();
            res.push_back({c,rep});              /// store the character and its repeation in res
        }
        for(auto it:res){                        /// loop to output the result
            for(int j = 0; j < it.second ;++j)
                cout << it.first;
        }
        fclose(file);                            /// close the opened file
    }
    return 0;
}