#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>


template <typename T>
class List {

    public:
        List();
        ~List();
    public:
        void push_front(T data);
        void push_back(T data);
        void pop_front();
        void pop_back();
        T& operator[](const int index);
        int getSize() {return this->size;}
        void clear();
        void insert(const int index,T data);
        void erase(const int index);
    private:
    template <typename N>
    class Node {
        public:
        Node(N data = N(),Node* pNext = nullptr)
        {
           this-> data = data;
           this->pNext = pNext;
        }

        N data;
        Node* pNext;
        
    };
    int size;
    Node<T>* head;
};
template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}
template <typename T>
void List<T>::push_back(T data){
    if(this->head == nullptr){
        head = new Node<T>(data);
    }else{
        Node<T>* current = this->head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}
template <typename T>
List<T>::~List(){
    std::cout << "dtor is called";
    clear();
}
template <typename T>
T&  List<T>::operator[](const int index)
{
    Node<T>* current = this->head;
    int counter = 0;
    while(current!= nullptr){
        if(counter == index){
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}
template <typename T>
void List<T>::push_front(T data){
    if(this->head == nullptr){
        head = new Node<T>(data);
    }else{
        Node<T>* current = this->head;
        head = new Node<T>(data);
        head->pNext = current;
    }
    ++size;
}
template <typename T>
void List<T>::pop_front(){
    Node<T>* temp = this->head;
    this->head = head->pNext;
    delete temp;
    --size;
}
template <typename T>
void List<T>::pop_back(){
    Node<T>* temp = this->head;
    while (temp != nullptr)
    {
        temp = temp->pNext;
    }
    delete temp;
    --size;
}
template <typename T>
void List<T>::clear(){
    while (this->size)
    {
        pop_front();
    }
    
}
template<typename T>
void List<T>::insert(const int index, T data){
    if(index == 0){
        push_front(data);
    }else{
        Node<T>* prev = this->head;
        for(int i = 0; i < index-1;++i){
            prev = prev->pNext;
        }
        Node<T>* NewNode = new Node<T>(data,prev->pNext);
        prev->pNext = NewNode;
    }
    ++size;
}
template <typename T>
void List<T>::erase(const int index){
    if(index == 0){
        pop_front();
    }else{
        Node<T>* prev = this->head;
        for(int i = 0; i < index-1; ++i){
            prev = prev->pNext;
        }
        Node<T>* temp = prev->pNext;
        prev->pNext = temp->pNext;
        delete temp;
    }
    --size;
}





#endif /* LIST */