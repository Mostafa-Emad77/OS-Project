# Wcat 
> This progarm is used read the files and print its contents when user request the file 
> code file is compileed into c/c++ by unix system (g++ -o wcat wcat.cpp -Wall -Werror).
> After doing so, we can run the tests by write this in the terminal (test-wcat.sh). 
> If the code is right as intended, we will see all test have been passed
## simple test:-
### input:
> file have :
> + "hello world hello worl hel worlb" 
### output:
> + "hello world hello worl hel worlb"  

# Wgrep
> This progarm print lines where it hase the words which the user is trying to find it.
> code file is compileed into c/c++ by unix system (g++ -o wgrep wgrep.cpp -Wall -Werror). 
> After doing so, we can run the tests by write this in the terminal (test-wgrep.sh). 
> If the code is right as intended, we will see all test have been passed
## simple test:-
# We want to search the word "youssef" and output the line that contain this word 
### input: 
> file have :
> + hello youssef
> + hello mostafa 
> + bye youssef
> + bye mostafa
### output:
> + hello youssef 
> + bye youssef 


# Wzip
> This progarm is using run length encoding in compression of files.
> the run length encoding :when file read n times of character of the same character print n and the character as it shows in the following tests
## simple test:-
### input:
>file have :
> + aaawwwdddaaa
### output:
> + 3a3w3d3a 


# Wunzip
> This progarm is using run length encoding in decompression of files.
> it takes the compressed file and find n of each of character and print the n times of the characters as showing in the following tests.file 
## simple test:-
### input:
> file have :
> + 5e5c5s
### output:
> + eeeeecccccsssss 

