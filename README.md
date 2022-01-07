# Parallel Zip Project
> The aim of the project was to zip multiple files (alpha-numeric text) 
### Sequential-Zip
> First we build a sequential zip using one encoding scheme(Run Length).
> All the code files related to sequential zip are included in the project1 folder. 
> This was followed by optimizing the encoding schemes to get better performnace in terms of compression time and compressed file size.
### Parallel-Zip
> In our appraoch of adding concurrency to sequential zip, we gave one file to each thread This is better than the Sequential approach.
> We used locks in reading and writing the file since the race condition can occur in them so locks make sure that wont happen.
#### simple test:-
+ Input: multiple files have different characters
+ we can put the output in the termial or in a output file if we use fwrite.
