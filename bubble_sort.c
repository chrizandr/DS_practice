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

void bubble_sort(int list[], int size){
    /*
        Sort the list using bubble sort
    */
    for(int j=0; j<size; j++){
        for(int i=0; i<size-1; i++){
            if(list[i] > list[i+1]){
                swap(&list[i], &list[i+1]);
            }
        }
    }
}


int main(){
    int list[10] = {22, 11, 99, 55, 88, 33, 77, 66, 44, 23};
    bubble_sort(list, 10);
    for(int i=0; i<10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}
