# Set the compiler to intel's
CC=icpc

# Set the flags for the compilers
CFLAGS= -O2


all:
	$(CC) $(CFLAGS) Decomp.cpp -o decomp
fast:
	$(CC) -fast Decomp.cpp -o decomp
omp:
	$(CC) $(CFLAGS) -qopenmp Decomp.cpp -o decomp
fast_omp:
	$(CC) -fast -qopenmp Decomp.cpp -o decomp
