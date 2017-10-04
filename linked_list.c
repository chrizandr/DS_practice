#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct link{
    /* Struct for node */
    int data;
    struct link *next;
} node;


typedef struct sll{
    /* Struct for list */
    node * first;
    node * last;
} list;


node * NewNode(int element){
    /*
        Function for new node
    */
    node * newnode = (node *) malloc(sizeof(node));
    newnode->data = element;
    newnode->next = NULL;
    return newnode;
}


list * NewList(int first_element, int last_element){
    node * first = NewNode(first_element);
    node * last = NewNode(last_element);
    list * l = (list *) malloc(sizeof(list));
    first->next = last;
    l->first = first;
    l->last = last;
    return l;
}


void displayList(list *l){
    /*
        Function for displaying the elements of the list
    */
    if(l->first == NULL){
        printf("The list is empty \n");
    }
    else{
        for(node *f=l->first; f != NULL; f = f->next){
            printf("%d, ", f->data);
        }
        printf("\n");
    }
}


node * findFirstNode(list *l, int element){
    /*
        Function for finding first occurence of a given node
    */
    if(l->first == NULL){
        printf("The list is empty \n");
    }
    else{
        for(node *f=l->first; f != NULL; f = f->next){
            if(f->data == element){
                return f;
            }
        }
    }
    printf("Node not found\n");
    return NULL;
}


void insertBegin(list *l, int element){
    /*
        Insert at the beginning of the list
    */
    node * newnode = NewNode(element);
    node *f = l->first;
    newnode->next = f;
    l->first = newnode;
}


void insertEnd(list *l, int element){
    /*
        Insert at the end of the list
    */
    node * newnode = NewNode(element);
    node * f = l->last;
    f->next = newnode;
    l->last = newnode;
}


void insertAfter(list *l, int position_element, int new_element){
    /*
        Insert after a given element
    */
    node * f = findFirstNode(l, position_element);
    node * newnode = NewNode(new_element);
    node * temp = f->next;
    f->next = newnode;
    newnode->next = temp;
}


void insertAt(list *l, int index, int element){
    /*
        Insert at a given index in the list
    */
    if(index == 0)
        insertBegin(l, element);
    else{
        int  i = 0;
        for(node *f=l->first; f != NULL; f = f->next, i++){
            if(i+1 == index){
                node * newnode = NewNode(element);
                node * temp = f->next;
                f->next = newnode;
                newnode->next = temp;
            }
        }
    }
}



bool deleteBegin(list *l){
    /*
        Delete at the beginning of the list
    */
    if(l->first == NULL){
        return false;
    }
    else{
        node * f = l->first;
        node * newnode = f->next;
        l->first = newnode;
        free(f);
        return true;
    }
}


bool deleteEnd(list *l){
    /*
        Delete at the end of the list
    */
    if(l->first == NULL){
        return false;
    }
    else{
        node * f = l->first;
        while(f != NULL){
            node * next_node = f->next;
            if(next_node->next == NULL){
                f->next = NULL;
                free(next_node);
                break;
            }
            f = f->next;
        }
        return true;
    }
}


bool deleteAfter(list *l, int position_element){
    /*
        Delete after a given element
    */
    node * f = findFirstNode(l, position_element);
    if(f == NULL || f->next == NULL)
        return false;

    node * next_node = f->next;
    f->next = next_node->next;
    free(next_node);
    return true;
}


bool deleteAt(list *l, int index){
    /*
        Delete at a given index in the list
    */
    if(index == 0)
        return deleteBegin(l);
    else{
        int  i = 0;
        for(node *f=l->first; f != NULL; f = f->next, i++){
            if(i+1 == index){
                if(f->next == NULL)
                    return false;

                node * temp = f->next;
                f->next = temp->next;
                free(temp);
                return true;
            }
        }
    }
    return false;
}

int main(){
    list * L1 = NewList(10, 10);
    displayList(L1);

    insertBegin(L1, 1);
    displayList(L1);

    insertBegin(L1, 2);
    displayList(L1);

    insertBegin(L1, 3);
    displayList(L1);

    insertEnd(L1, 4);
    displayList(L1);

    insertAfter(L1, 10, 7);
    displayList(L1);

    insertAt(L1, 7, 9);
    displayList(L1);

    deleteAt(L1, 3);
    displayList(L1);

    deleteAfter(L1, 10);
    displayList(L1);

    return 0;
}
