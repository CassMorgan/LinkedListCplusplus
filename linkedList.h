//Cass Morgan II
//CSC 375 Data Structures Linked List
//Date 03/26/2016

using namespace std;

struct Profile{
    string name;
    string state;
};

template<class T>
struct Node {
    T info;
    Node<T> *next;
};

// overloaded ostream to print Profile info
ostream& operator<<(ostream &out, Profile &user){
out<< user.name;
return out;
}

// uses Node struct
template<class T>
class LinkedList {

public:
    LinkedList();
    void push(T element);
    void pop(T element);
    bool isEmpty();
    void make_empty();
    void peek();
    void print();

private:
    Node<T> *start;
};

// constructor
template<class T>
LinkedList<T>::LinkedList(){
    start = NULL;
}

// begin function definitions
template<class T>
void LinkedList<T>::push(T element)
{
    Node<T> *ptr = new Node<T>;
    ptr->info = element;
    ptr->next = start;
    start = ptr;
}

template<class T>
void LinkedList<T>::pop(T element)
{
    Node<T> *ptr = start;
    element = ptr->info;
    start = start->next;
    delete ptr;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    Node<T> *ptr = start;
    if(ptr->next == NULL){
        cout<< "The linked list IS empty!" <<endl;
        return true;
    } else {
        cout<< "The linked list IS NOT empty!" <<endl;
        return false;
    }
}

template<class T>
void LinkedList<T>::make_empty(){
    Node<T> *ptr = start;
    while(start->next != NULL){
        start = start->next;
        delete ptr;
    }
}

template<class T>
void LinkedList<T>::peek(){
    Node<T> *ptr = start;
    cout<< ptr->info.name << ", " << ptr->info.state <<endl;
}

template<class T>
void LinkedList<T>::print(){
    Node<T> *ptr = start;

    while(ptr != NULL){
        cout<< ptr->info.name << ", " << ptr->info.state <<endl;
        ptr = ptr->next;
    }
}

