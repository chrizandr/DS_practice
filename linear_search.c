#include<stdio.h>
#include<stdlib.h>

int linear_search(int list[], int key, int size){
    /*
        Linearly search the list for the element
    */
    for(int i=0; i<size; i++){
        if(list[i] == key){
            return list[i];
        }
    }
    return -1;
}


int main(){
    int list[10] = {11, 22, 23, 33, 44, 55, 66, 77, 88, 99};
    int key = 22, answer;
    answer = linear_search(list, key, 9);
    printf("%d\n", answer);
}
