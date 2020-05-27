#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int, int, int *);
void bubbleSort(int *, int);

int main(void) {
        int length, highest;
        int i;

        srand(time(NULL));
        printf("\nBubble Sort Program.\nEnter the number of array entries to generate: ");
        scanf("%d", &length);
        printf("\nEnter the highest value of any entry: ");
        scanf("%d", &highest);

        int array[length];
        generateArray(length, highest, array);

        printf("\nGenerated numbers:\n");
        for(i = 0; i < length; i++) {
                printf("%d ", *(array + i));
        }

        bubbleSort(array, length);

        printf("\nSorted numbers:\n");
        for(i = 0; i < length; i++) {
                printf("%d ", *(array + i));
        }

        return 0;

}

void generateArray(int length, int highest, int * array) {
        int i;

        for(i = 0; i < length; i++) {
                array[i] = (rand() % highest) + 1;
        }
}

void bubbleSort(int * array, int length) {
        //The following line doesn't work because the value of array has decayed to a pointer:
        //      size_t n = sizeof(*array) / sizeof(array[0]);

        int i, j;

        for(i = 0; i < length; i++) {
                for(j = 0; j < length - i - 1; j++) {
                        if(array[j] > array[j + 1]) {
                                int temp = array[j + 1];
                                array[j + 1] = array[j];
                                array[j] = temp;
                        }
                }
        }
}
