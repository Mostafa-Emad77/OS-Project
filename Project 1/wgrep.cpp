#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
using namespace std;

int main(int argc, char **arg)
{
    if (argc == 1)
    {
        cout << "wgrep: searchterm [file ...]" << endl;
        return 1;
    }
    FILE *file = freopen(arg[2], "r", stdin);
    if (argc == 3)
    {
        if (file == NULL)
        {
            cout << "wgrep: cannot open file" << endl;
            return 1;
        }
    }
    string cmp = arg[1];                                                            // get input(word)
    string line;
    char c;
    bool check=0;                                                                   //to check c isnot space to not add to the line
    while (c != EOF)
    {
        if (c == '\n'){
            c = getchar();
            continue;
        }
        getline(cin, line);                                                         //get line from the file 
        line = c + line;                                                            //add the character we get to the line again if isnot "\n"
        if (line.find(cmp) != string::npos)                                         //search the word we get in the line
      
        {
            line.erase(line.begin());                                               //erease firsst char in line
            if (check)                                                              //if char not space print the line that have the word
                cout << c;
            cout << line << endl;
        }
        c = getchar();
        check=1;
    }
    return 0;
}
