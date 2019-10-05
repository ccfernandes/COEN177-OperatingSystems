/*
    Chelsea Fernandes 
    file: readMe.txt
*/

Files: 
- helloworld.c
    - used as a demo program for lab1-1.c
    - output: prints "Hello world program"
- lab1-1.c
    - Creates a simple shell that can be used to run another program in a new thread depending on the user input.
    - output: prints "Command:" and waits for user to input a string. Exits program when inputted "exit" and runs executable if 
      given any string. 
- lab1-2.c
    - Creates exactly 6 child processes (not including the parent). The tree has 6 levels, with one node per level.
    - output: process identifier (PID) of root node, and PID and parent's PID of each following node. (PID used to help with debugging)
    - example of tree structure:  
        root 
        |   
        child 1
        | 
        child 2 
        |
        child 3
        |
        child 4
        | 
        child 5
        | 
        child 6 
- lab1-3.c
    - Creates a tree with exactly 14 processes. The tree has 6 levels with 2 children per level. 
      One of those 2 children have the next 2 children. 
    - output: PID and parent's PID of each node. (PID used to help with debugging)
    - example of tree structure: 
                              0
                            /   \
                           1     2
                         /   \
                        3     4
                      /   \
                     5     6 
                   /   \
                  7     8
                /   \
               9    10
             /   \
            11   12
           /        
         13

