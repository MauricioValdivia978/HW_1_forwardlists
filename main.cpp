#include <iostream>
using namespace std;

/*Integrantes:
 *Mauricio Valdivia
 *Anthony Chavez Ayme
 *Bladimir Alferez
*/

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T x) : data(x), next(nullptr) {}
};


template <typename T>
class ForwardList {
private:
    Node<T>* head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        clear();
    }

    T front() {
        if (head == nullptr) {
            return T();
        }
        return head->data;
    }

    T back() {
        if (head == nullptr) {
            return T();
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front() {
        if (head == nullptr) {
            return T();
        }
        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }

    T pop_back() {
        if (head == nullptr) {
            return T();
        }
        if (head->next == nullptr) {
            return pop_front();
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        T value = current->data;
        prev->next = nullptr;
        delete current;
        return value;
    }
    T operator[](int index) {
        if (empty()) {
            cout << "Lista vacia";
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            if (current == nullptr) {
                cout << "Indice fuera de rango";
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Indice fuera de rango";
        }
        return current->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int temp_l = 1;
        Node<T> *temp =this->head;
        while(temp->next!= nullptr){

            temp = temp->next;
            temp_l = temp_l + 1;
        }
        return temp_l;
    }

    void clear() {
        Node<T> *temp = head;
        while(temp != NULL){
            head = temp ->next;
            temp = temp->next;
        }
    }

    void sort() {
        Node<T> *temp = head;
        int size= 1;
        while(temp->next!= nullptr){

            temp = temp->next;
            size= size + 1;
        }
        temp = head;
        Node<T> *temp2 = temp->next;

        for(int i = 0; i<size-1 ; i++){
            int aux;
            for(int j = 0 ; j < size ; j++){
                if((temp != nullptr && temp2 != nullptr) && temp->data>temp2->data){
                    aux = temp->data;
                    temp->data = temp2->data;
                    temp2->data = aux;

                }
                if(temp2 -> next != nullptr){
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
            temp2 = temp->next;
        }

    }


    void reverse() {

        Node<T> *temp = head;
        Node<T> *btemp = nullptr;
        Node<T> *aux ;
        while(temp != nullptr){

            aux = temp->next;
            temp->next = btemp;
            btemp = temp;
            temp= aux;

        }
        head = btemp;
    }


    void print_list(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main() {
    ForwardList<int> forward_list;
    forward_list.push_back(1);
    forward_list.push_back(2);
    forward_list.push_back(3);
    forward_list.push_back(4);
    forward_list.push_back(5);

    cout<< "Lista despues de push_back: "<<endl;
    forward_list.print_list();

    cout<<"size:"<<endl;
    cout<<forward_list.size()<<endl;

    cout<<endl;

    forward_list.push_front(0);
    forward_list.push_front(6);

    cout<< "Lista despues de push_front: "<<endl;
    forward_list.print_list();

    cout<<"size:"<<endl;
    cout<<forward_list.size()<<endl;

    cout<<endl;

    cout << "Front: " << forward_list.front() << endl;
    cout << "Back: " << forward_list.back() << endl;

    cout<<endl;

    forward_list.pop_back();
    cout<< "Lista despues de pop_back: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.pop_front();
    cout<< "Lista despues de pop_front: "<<endl;
    forward_list.print_list();

    cout<<endl;

    cout << "Front: " << forward_list.front() << std::endl;
    cout << "Back: " << forward_list.back() << std::endl;

    cout<<endl;

    forward_list.reverse();
    cout << "Lista despues de reverse: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.sort();
    cout << "Lista despues de sort: "<<endl;
    forward_list.print_list();

    cout<<endl;

    cout<< "Uso de operador '[]':"<<endl;
    cout<<"forward_list[0]: "<< forward_list[0]<<endl;
    cout<<"forward_list[1]: "<< forward_list[1]<<endl;

    cout<<endl;

    forward_list.clear();
    cout << "lista despues de clear: "<<endl;
    forward_list.print_list();

    cout<<endl;

    return 0;
}