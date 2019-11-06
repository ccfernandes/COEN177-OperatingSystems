//Chelsea Fernandes
//lab3_report.txt

The goal of this lab was to simulate and gain understanding of page replacement algorithms (and to a lesser extent, caching). 

Description of page replacement implementations:

First in first out (fifo.c):
For this algorithm, I created a queue using an array, where index 0 is the front (oldest) and index tableSize-1 is the back (newest). 
Whenever there is a page fault, the elements are shifted to the left so the oldest value leaves the queue and the newest one enters 
the queue at index tableSize-1.

Least Recently Used (lru2.c):
For this algorithm, I have an array with a parallel array ageTable which keeps track of the oldest/least recently used value using 
the numRequest counter. Whenever a value is added to the array, the ageTable at index corresponding to pageTable index receives the 
value of numRequest, which increases after every insert of a value. A smaller value in ageTable means the value is older, so the value 
with the smallest ageTable value is replaced with the new (larger, corresponding to younger) value. If the value is already present 
in the table, the ageTable value at that index is simply replaced with the updated numRequest value.


Second chance (sc2.c): 
For the second chance algorithm, I created a circular array using a counter variable that represents the head of the array for 
optimization. I also have a parallel array refTable that stores the bit value (0 or 1), which is used to determine if the value 
gets a second chance. Whenever there is a page fault with a value not already present in pageTable, I iterate through the refTable 
until I find a bit value of 0. When found, I replace the existing pageTable value at that index with the new value. If the ref bit 
of a value is 1 when iterating the array, I change its bit to 0, corresponding to giving it a second chance. If the value is already 
present in the array, I find the index using a simple for-loop and change the reference bit of that element in refTable to 1.

**put graph here**

Explaination of graph:
A Higher hit rate results in fewer disk I/O calls, which is the goal of a page replacement algorithm. A lower hit rate 
can result in disk thrashing, which slows down the performance of the system. Hence, the second chance algorithm is better since 
it generally has a higher hit rate compared to the other implemented algorithms. According to the data, as the task size increases, 
the hit rate plateaus. 
