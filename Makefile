all: mergesort bubblesort shellsort

mergesort: mergesort.c
	gcc mergesort.c -o mergesort

bubblesort: bubblesort.c
	gcc bubblesort.c -o bubblesort

shellsort: shellsort.c
	gcc shellsort.c -o shellsort

clean:
	rm mergesort bubblesort shellsort
