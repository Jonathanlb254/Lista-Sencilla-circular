#include <iostream>
#include <limits>

using namespace std;


struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
  
    CircularLinkedList() : head(NULL) {}

    ~CircularLinkedList() {
        if (head == NULL) return;
        
        Node* current = head;
        Node* temp;
        
        do {
            temp = current->next;
            delete current;
            current = temp;
        } while (current != head);
    }

  
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

   
    int sum() {
        if (head == NULL) return 0;

        int total = 0;
        Node* temp = head;
        do {
            total += temp->data;
            temp = temp->next;
        } while (temp != head);
        
        return total;
    }


    int findMax() {
        if (head == NULL) return std::numeric_limits<int>::min();

        int maxNum = head->data;
        Node* temp = head->next;
        do {
            if (temp->data > maxNum) {
                maxNum = temp->data;
            }
            temp = temp->next;
        } while (temp != head);

        return maxNum;
    }

    int findMin() {
        if (head == NULL) return std::numeric_limits<int>::max();

        int minNum = head->data;
        Node* temp = head->next;
        do {
            if (temp->data < minNum) {
                minNum = temp->data;
            }
            temp = temp->next;
        } while (temp != head);

        return minNum;
    }
};

int main() {

    CircularLinkedList list;


    list.insert(5);
    list.insert(10);
    list.insert(3);
    list.insert(8);

 
    cout << "Suma de todos los nodos: " << list.sum() << endl;

  
    cout << "Numero mayor de la lista: " << list.findMax() << endl;
    cout << "Numero menor de la lista: " << list.findMin() << endl;

    return 0;
}


