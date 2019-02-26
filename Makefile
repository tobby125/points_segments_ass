CC = gcc
CFLAGS = -Wall -std=c99

all: test

naive_points_segments.o: naive_points_segments.c points_segments.h 
	$(CC) $(CFLAGS) -c naive_points_segments.c

good_points_segments.o: good_points_segments.c points_segments.h
	$(CC) $(CFLAGS) -c good_points_segments.c
	
test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c
	
test: naive_points_segments.o good_points_segments.o test.o
	$(CC) $(CFLAGS) -o test naive_points_segments.o good_points_segments.o test.o

clean:
	rm *.o test