#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomSayi(int dizi[], int n);
void diziyikopyala(int dizi[], int dizi1[], int n);

void insertionSort(int dizi[], int n);
void selectionSort(int dizi[], int n);
void bubbleSort(int dizi[], int n);


int timeinsertion;
int timeselection;
int timebubble;

void printArray(int dizi[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", dizi[i]);
	}
	printf("\n");
}
int main()
{
	int size = 2000;
	int *dizi = (int *)malloc(sizeof(int) * size);
	int *dizi2 = (int *)malloc(sizeof(int) * size);
	clock_t start, stop;
	srand(time(0));

	randomSayi(dizi, size);

	diziyikopyala(dizi, dizi2, size);
	start = clock();
	insertionSort(dizi2, size);
	timeinsertion += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

	diziyikopyala(dizi, dizi2, size);
	start = clock();
	selectionSort(dizi2, size);
	timeselection += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

	diziyikopyala(dizi, dizi2, size);
	start = clock();
	bubbleSort(dizi2, size);
	timebubble += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;


	printf("\n");
	printf("Insertion sort time:        %dms\n", timeinsertion);
	printf("Selection sort time:        %dms\n", timeselection);
	printf("Bubble sort time:           %dms\n", timebubble);

	
	system("PAUSE");
	return 0;
}

void diziyikopyala(int dizi[], int dizi1[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		dizi1[i] = dizi[i];
}

void randomSayi(int dizi[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		dizi[i] = rand() % 9999;
}

void yerdegis(int* a, int* b)
{
	int ata = *a;
	*a = *b;
	*b = ata;
}

void insertionSort(int dizi[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		for (j = i; j >= 0; j--)
			if (dizi[j] < dizi[j - 1])
				yerdegis(&dizi[j], &dizi[j - 1]);
			else
				break;
	}
}


void selectionSort(int dizi[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (dizi[j] < dizi[min])
				min = j;

		yerdegis(&dizi[min], &dizi[i]);
	}
}

void bubbleSort(int dizi[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (dizi[j] > dizi[j + 1])
				yerdegis(&dizi[j], &dizi[j + 1]);
}
