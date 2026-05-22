#include <iostream> 
#include <algorithm>

using namespace std;
// creating a min heap
class Heap{
    private:
    static const int capacity = 10;
    int size = 0;
    public:
    int items [capacity] ; 
   
    private:
    int getLeftChildIndex (int parentIndex){return (2 * parentIndex);}
    int getRightChildIndex (int parentIndex){return((2*parentIndex)+1);}
    int getParentIndex (int childIndex){return(childIndex/2);}

    bool hasLeftChild (int index){return(getLeftChildIndex(index) < size);}
    bool hasRightChild (int index){return(getRightChildIndex(index) < size);}
    bool hasParent (int index){return(getParentIndex(index) >= 0);}

    int leftChild(int index){return items[getLeftChildIndex(index)];}
    int rightChild(int index){return items[getRightChildIndex(index)];}
    int parent(int index){return items[getParentIndex(index)];}

    void heapElementsSwap(int indexOne,int indexTwo){
        /*int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;*/
        swap(items[indexOne],items[indexTwo]);
    }
    bool heapIsFull(){
        if(size ==capacity){
            cout<<"Heap is full \n";
            return true;
        }
        return false;
    }
    public:
    void peek(){
        if(size == 0) throw invalid_argument ("Array is empty");
        cout<<"The top element is "<< items[0]<<"\n";
    }
    int poll(){
        if(size == 0) throw invalid_argument ("Array is empty");
        int item = items[0];
        items[0] = items[size-1];
        size --;
        heapifyDown();
        return item;
    }
    void insertElement(int element){
        if(heapIsFull()) return;
        items[size] = element;
        size ++;
        heapifyUp();
    }

    void heapifyDown(){
        int index = 0;
        while(hasLeftChild(index)){
            int smallerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && getRightChildIndex(index) < items[smallerChildIndex]){
                smallerChildIndex = getRightChildIndex(index);
            }
            if(items[index] < items[smallerChildIndex]){
                break;
            }
            else{
                heapElementsSwap(index,smallerChildIndex);   
            }
            index = smallerChildIndex;
        }
    }
    void heapifyUp(){
        int index = size-1;
        while(hasParent(index) && parent(index) > items[index]){
            heapElementsSwap(getParentIndex(index),index);
            index = getParentIndex(index);
        }
    }


};

int main(){

    Heap myHeap = Heap();

    myHeap.insertElement(23);
    myHeap.insertElement(12);
    myHeap.insertElement(3);
    myHeap.insertElement(13);
    myHeap.insertElement(1);
    myHeap.peek();


    return 0;
}