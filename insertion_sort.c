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

void insertion_sort(int list[], int size){
    /*
        Sort the list using insertion sort
    */
    for(int i=1; i<size; i++){
        int current = list[i];
        for(int j=0; j<i; j++){
            if(list[j] > current){
                for(int k=i; k>j; k--){
                    list[k] = list[k-1];
                }
                list[j] = current;
                break;
            }
        }
    }
}


int main(){
    int list[10] = {22, 11, 99, 55, 88, 33, 77, 66, 44, 23};
    insertion_sort(list, 10);
    for(int i=0; i<10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}
