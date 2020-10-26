#include <stdio.h>
#include <malloc.h>

struct Node{
    char * data;
    struct Node * next;
};

void inBegin(struct Node **startRef, char * data){
    struct Node * ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1 -> data;
    ptr1 -> next = *startRef;
    *startRef = ptr1;
}

void printList(struct Node * start){
    struct Node * temp = start;
    printf("\n");
    while(temp != NULL){
        printf("%d", temp -> data);
        temp = temp -> next;
    }
}

void bubbleSort(struct Node *start){
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (start == NULL){
        return;
        do{
            swapped = 0;
            ptr1 = start;
            while (ptr1 -> next != lptr){
                if (ptr1 -> data > ptr1 -> next -> data){
                    usrSwap(ptr1, ptr1 -> next);
                    swapped = 1;
                }
                ptr1 = ptr1 -> next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }
}

void usrSwap(struct Node * a, struct Node * b){
    char temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
}
int main() {
    FILE *wrdFile;
    char * string[50];
    char * ERR;

    wrdFile = fopen("/home/andrey/CLionProjects/TestingWordFiles/words.txt", "r");

    if (wrdFile == NULL){
        printf("ERROR");
        return -1;
    }else{
        printf("CORRECT");
    }

    printf("read strings are: \n");
    while(1){
        ERR = fgets(string, sizeof(string), wrdFile);
        if (ERR == NULL){
            if (feof(wrdFile) != 0){
                printf("\n Reading completed \n");
                break;
            }else {
                printf("\n Reading ERROR\n");
                break;
            }
        }
        printf("    %s", string);
    }

    printf("Closing file");
    if (fclose(wrdFile) == EOF){
        printf("ERROR\n");
    }else{
        printf("read correct");
    }

    struct Node * start = NULL;

    bubbleSort(start);

    printList(start);

    return 0;
}
