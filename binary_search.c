#include<stdio.h>
#include<stdlib.h>


int search_recursive(int list[], int high, int low, int key){
    /*
        Recursive binary search
    */
    if(high-low == 1){
        if(list[high]==key || list[low]==key){
            return key;
        }
        return -1;
    }
    int mid = (high+low)/2;
    if(list[mid] == key){
        return list[mid];
    }
    else if(list[mid] > key){
        return search_recursive(list, mid, low, key);
    }
    else{
        return search_recursive(list, high, mid, key);
    }
}


int search_normal(int list[], int size, int key){
    /*
        Ordinary loop binary search
    */
    int mid, low = 0, high = size-1;

    while(high-low != 1){
        mid = (low + high)/2;
        if(list[mid] == key)
            return key;
        else if(list[mid] > key)
            high = mid;
        else
            low = mid;
    }
    if(list[high]==key || list[low]==key){
        return key;
    }
    return -1;
}


int main(){
    int list[10] = {11, 22, 23, 33, 44, 55, 66, 77, 88, 99};
    int key = 22, answer;
    answer = search_recursive(list, 9, 0, key);
    printf("%d\n", answer);
    answer = search_normal(list, 10, key);
    printf("%d\n", answer);

    return 0;
}
