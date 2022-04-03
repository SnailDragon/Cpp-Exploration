This project can be implemeted in a few ways.
1. Default (use this one for grading) - ./boxgen - generates 3x3 word boxes using the included file words.txt and prints them to the terminal. 
2. Specify dimensions - ./boxgen 3 - argument specifies dimension of boxes.
3. Specify dimensions and destination file - ./boxgen 3 box3.txt - additional argument specifies the name of the text file that the generated boxes will be saved to in addition to printing them out. 

Other considerations: while all dimensions of box work, only 3x3 executes in a reasonable amount of time. I have gotten 4x4 to finish (results stored in box4.txt) but it took hours and my 5x5 attempt is still running on my old laptop -- it's been a few days. 

Notes for me:
* faster vetting - check for combos that could never make words no matter what is cycled in after them
* add uneven dimensions - 3x4 wordbox
* multithreaded? maybe?