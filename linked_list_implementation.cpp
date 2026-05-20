#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){};
};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    ~LinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void displayListElements(){
        if(head == nullptr){
            cout<<"The list is empty \n";
        }
        Node* temp = head;
        while(temp->data != 0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->next->data;
    }
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while (temp -> next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void insertAtStart(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }
    void insertAnywhere(int value,int location){
        if(head == nullptr || location == 0){
           insertAtStart(value);
        }

        int count = 0;
        Node* newNode = new Node(value);
        Node* temp = head;

        while (count < location-1 && temp->next != nullptr){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;

}

    void deleteByValue(int value){
        if (head == nullptr) return;
        if (head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next && temp->next->data != value){
            temp = temp->next;
        }
        if(temp->next){
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

    }
    
};

int main (){
    LinkedList myLinkedList ;
    myLinkedList.insertAtEnd(32);
    myLinkedList.insertAtEnd(76);
    myLinkedList.insertAtStart(2);
    myLinkedList.displayListElements();
    return 0;
}