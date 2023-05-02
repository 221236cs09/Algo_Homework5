#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(){
        value = 0;
        next = nullptr;
    }
    Node(int x){
        value = x;
        next = nullptr;
    }
    Node(int x, Node *n){
        value = x;
        next = n;
    }
};

class List{
private:
    Node* head;
public:
    List(){
        head = nullptr;
    };
    
    Node* insert_front(int x){
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    Node* insert_back(int x){
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            return head;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
    
    Node* erase_front() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* erase_back() {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        return head;
    }
    
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
 
    int size() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        bool swapped;
        Node* current = nullptr;
        do {
            swapped = false;
            current = head;
            while (current->next != nullptr) {
                if (current->value > current->next->value) {
                    swap(current->value, current->next->value);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    void selectionSort() {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        Node* minNode = current;
        Node* innerCurrent = current->next;
        while (innerCurrent != nullptr) {
            if (innerCurrent->value < minNode->value) {
                minNode = innerCurrent;
            }
            innerCurrent = innerCurrent->next;
        }
        if (minNode != current) {
            int temp = current->value;
            current->value = minNode->value;
            minNode->value = temp;
        }
        current = current->next;
    }
}

    //ADDITIONAL POINTS
    //void quickSort();
    //void insertionSort();
};
int main(int argc, const char * argv[]) {
    List l;
    l.insert_back(2);
    l.insert_back(10);
    l.insert_back(1);
    l.insert_back(6);
    l.insert_back(7);
    l.insert_back(3);
    l.displayList();
    l.bubbleSort();
    l.displayList();
 
    List l1;
    l1.insert_back(34);
    l1.insert_back(1);
    l1.insert_back(90);
    l1.insert_back(61);
    l1.insert_back(57);
    l1.insert_back(9);
    l1.insert_back(7);
    l1.displayList();
    l1.selectionSort();
    l1.displayList();

    return 0;
}