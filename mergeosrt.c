#include<stdio.h>
#include<conio.h>

//PROGRAM TO PERFORM MERGE SORT USING ARRAY

void merge(int *arr, int s, int e){
    
    int mid = s+(e-s)/2;
    
    int l1 = mid -s+1;
    int l2 = e-mid;

    int first[l1];
    int second[l2];

    int mainArrayIndex = s;
    for(int i = 0; i<l1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid +1;
    for(int i =0; i<l2; i++){
        second[i] = arr[mainArrayIndex++];
    }


    //merge two sorted array
    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;
    while(index1 < l1 && index2 < l2){
        
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    } 

    while(index1 < l1){
        arr[mainArrayIndex++] = first[index1++];
    }       

    while(index2 < l2){
        arr[mainArrayIndex++] = second[index2++];
    }
}


void mergesort(int arr[], int s, int e){

    //base case
    if(s>=e)
    return;


    int mid = s+(e-s)/2;

    //left part sorting 
    mergesort(arr, s, mid);

    //right part sorting 
    mergesort(arr, mid+1, e);

    //merge two sorted array 
    merge(arr, s, e);

}


void main(){

    int i, n, arr[20];
    printf("enter the array size: ");
    scanf("%d", &n);

    printf("enter array element :  ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
}