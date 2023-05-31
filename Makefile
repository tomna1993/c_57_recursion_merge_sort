CC := gcc
#CFLAGS := 
DEST := ./build/

all: recursion_merge_sort.c
	mkdir -p build
	$(CC) recursion_merge_sort.c -lcs50 -o $(DEST)/recursion_merge_sort 