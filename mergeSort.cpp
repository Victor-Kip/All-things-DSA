#include <iostream>
#include <vector>

void merge(std::vector<int>& leftArray,std::vector<int>& rightArray,std::vector<int>& arr){
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();
    int l = 0,r = 0 ,i = 0;

    while(l < leftSize && r < rightSize){
        if (leftArray[l]< rightArray[r]){
            arr[i] = leftArray[l];
            l++;
            i++;
        }
        else{
            arr[i] = rightArray[r];
            r++;
            i++;
        }
    }
    while(l < leftSize){
        arr[i] = leftArray[l];
        l++;
        i++;
    }
    while(r < rightSize){
        arr[i] = rightArray[r];
        r++;
        i++;
    }
}

void mergeSort(std::vector<int>& arr){
    int length = arr.size();
    if (length <= 1) return;
    int midPoint = length/2;

    std::vector<int> leftArray ={};
    std::vector<int> rightArray = {};

    for(int i = 0 ;i < length;i++){
        if(i < midPoint){
            leftArray.push_back(arr[i]);
        }
        else{
            rightArray.push_back(arr[i]);
        }
    }
    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray,rightArray,arr);

}

int main(){
    std::vector<int> unsortedArray = {5, 2, 4, 6, 1, 3};
    mergeSort(unsortedArray);
    for(int ar:unsortedArray){
        std::cout<<ar<<" ";
    }
    
    return 0;
}