
# Create a 10GB file
dd if=/dev/zero of=large-file-10gb.txt count=1024 bs=10000000
#head  -c 10G </dev/urandom >random10.c

# Create a 5GB file
dd if=/dev/zero of=random5.txt count=1024 bs=5000000
#head  -c 5GB </dev/urandom >random5.txt

# Create a 1GB file
dd if=/dev/zero of=random1.txt count=1024 bs=1000000
#head  -c 1GB </dev/urandom >random1.txt

# Create a 0.5GB file
dd if=/dev/zero of=random0_5.txt  count=1024 bs=500000
#head  -c 500MB </dev/urandom >random0_5.txt


# Create a 0.1GB file
dd if=/dev/zero of=random0_1.txt  count=1024 bs=100000
#head  -c 100MB </dev/urandom >random0_1.txt

# Create a 0.01GB file 
dd if=/dev/zero of=random0_01.txt count=1024 bs=10000
#head -c 10MB </dev/urandom >random0_01.txt

