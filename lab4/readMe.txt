lab 4 deliverable

Goal of lab: To determine the performance of a specific user workload on file system performance?

Files:
- sequential.c
    - reads a large file sequentially 
- random.c
    - reads a large file randomly using rand() 

Initial design: 
My initial design for both methods (sequential and random) was to read each byte one at a time, using a for-loop and fget().
Although simple to implement, it proved to take a long time to actually read the files. For example, the 5GB file read using 
random.c was projected to take more than 3 hours to complete, which is clearly not acceptable. 

Current design:
My current design is essentially the same as the initial design, the only difference coming from how the bytes are being 
read. Rather than one byte at a time, I decided to read in 1MB intervals, with the help of a buffer array. Doing so allows 
more data to be read in at a time, drastically reducing the time to read the entire file.

Data: 
Below is a table displaying the read times for each method, with varying file sizes. From the data, we can say that sequential 
reading is linear and randomized reading has an exponential trend. 
See FileSize_vs_readTime.png for a bar graph of the data to see the trends better. 


file size (GB)	read time (sec)
--------------------------------------
------------    sequential      random
0.01	        0.006078	    0.027851
0.02	        0.007088	    0.048857
0.1             0.013713	    0.215286
0.5             0.044366	    1.047543
1               0.079245	    2.081172
5               0.36685	        10.539091

