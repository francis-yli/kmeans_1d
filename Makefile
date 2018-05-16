all: kmeans1D.c

kmeans1D: kmeans1D.c
        gccx kmeans1D.c -o k1D

clean:
        rm -f k1D
