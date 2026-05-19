#include <iostream>
using namespace std;

int queueSize = 9;
int queueHead,queueTail = 0;

bool queueIsFull(int queueHead,int queueSize,int queueTail){
    if((queueHead == 0 && queueTail == queueSize ) || queueHead == queueTail + 1){
        return true;
    }
    return false;
}

bool queueIsEmpty(int queueHead,int queueTail){
    if(queueHead == queueTail){
        return true;
    }
    return false;
}

void enqueue( int sampleQueue[],int elementAdded){
    if(queueIsFull(queueHead,queueSize,queueTail)){
        cout<<"Queue is full \n";
        return;   
    }
    sampleQueue[queueTail] = elementAdded;
    if(queueTail == queueSize){
        queueTail = 0;
    }
    queueTail += 1;
}

int dequeue(int sampleQueue[]){
      if(queueIsEmpty(queueHead,queueTail)){
        cout<<"Queue is empty \n";
        return 0;   
    }
    int returnedElement = sampleQueue[queueHead];
    if(queueHead == queueSize){
        queueHead = 0;
    }
    queueHead += 1;
    return returnedElement;
}

int main(){
    int sampleQueue[9] = {};
    enqueue(sampleQueue,8);
    enqueue(sampleQueue,1);
    enqueue(sampleQueue,89);
    
    cout<<dequeue(sampleQueue)<<" removed from queue \n";
    cout<<dequeue(sampleQueue)<<" removed from queue \n";
    

    return 0;
}