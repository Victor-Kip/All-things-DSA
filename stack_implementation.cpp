#include <iostream>
using namespace std;


int sampleStackSize = 9;
int stackTop = 0;

bool stackIsFull(int stackTop){
    if (stackTop == sampleStackSize){
        return true;
    }
    return false;
}

bool stackIsEmpty(int stackTop){
    if (stackTop == 0){
        return true;
    }
    return false;    
}

void push (int sampleStack[],int stackElement ){
    if(stackIsFull(stackTop)){
        cout<<"Overflow \n";
        return;
    }
    sampleStack[stackTop] = stackElement;
    stackTop += 1;
    cout<<stackElement<<" added to the stack \n"; 
}

int pop (int sampleStack[]){
    if(stackIsEmpty(stackTop)){
        cout<<"Stack is empty \n";
        return 0;
    }
    stackTop -= 1;
    int poppedElement = sampleStack[stackTop];
    return poppedElement;
}

int main(){
    int sampleStack[9] = {};
    push(sampleStack,9);
    push(sampleStack,7);
    push(sampleStack,2);
    cout << pop(sampleStack) << " popped from the stack \n";
    cout << pop(sampleStack) << " popped from the stack \n";
    return 0;
}
