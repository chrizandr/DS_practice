#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    /*
        Swap two integers by address
    */
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_min_index(int list[], int start, int end){
    /*
        Find the index of the minimum number in the sub array
    */
    int min_index = start;
    for(int i=start; i<end; i++){
        if(list[i] < list[min_index]){
            min_index = i;
        }
    }
    return min_index;
}


void selection_sort(int list[], int size){
    /*
        Sort the list using selection sort
    */
    for(int i=0; i<size; i++){
        int min_index = find_min_index(list, i, size);
        swap(&list[i], &list[min_index]);
    }
}


int main(){
    int list[10] = {22, 11, 99, 55, 88, 33, 77, 66, 44, 23};
    selection_sort(list, 10);
    for(int i=0; i<10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}
