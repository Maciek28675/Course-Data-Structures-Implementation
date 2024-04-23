#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <fstream>
#include <sstream>
#include "DataStructure.hpp"

template <typename T>
class Node {
public:
    T value_;
    Node* next_;
    template <typename t> friend class SinglyLinkedListHead;
};

template <typename T>
class SinglyLinkedListHead : public DataStructure<T>
{
private:
    Node<T>* head_; 
    bool success_ = 1;
    int size_ = 0;

public:
    SinglyLinkedListHead();
    ~SinglyLinkedListHead();

    void pushFront(const T& value) override;
    void pushBack(const T& value) override;
    void insert(const T& value, const int& index) override;	

    void popFront() override;
    void popBack() override;
    void remove(const int& index) override;

    void clear();
    void show() const override;
    int find(const T& value) const override;
    T getValue(const int& index);

};

template <typename T>
SinglyLinkedListHead<T>::SinglyLinkedListHead() : head_(nullptr) {}

template <typename T>
SinglyLinkedListHead<T>::~SinglyLinkedListHead()
{
    Node<T>* temp = head_;
    while (temp) {
        Node<T>* next = temp->next_;
        delete temp;
        temp = next;
    }
}

// Add a node with value 'value' at the front
template <typename T>
void SinglyLinkedListHead<T>::pushFront(const T& value)
{
    Node<T>* newNode = new Node<T>{ value, head_ };
    head_ = newNode;
    size_++;
}

// Add a node with value 'value' at the back
template<typename T>
void SinglyLinkedListHead<T>::pushBack(const T& value) 
{
    Node<T>* newNode = new Node<T>{ value, nullptr };

    if (!head_) 
    {
        head_ = newNode;
    }
    else 
    {
        Node<T>* temp = head_;

        // Traverse to the end of the list
        while (temp->next_) 
        {
            temp = temp->next_;
        }

        temp->next_ = newNode;
    }
    size_++;
}

// Add a node with value 'value' at index 'index'
template<typename T>
void SinglyLinkedListHead<T>::insert(const T& value, const int& index) 
{
    // Handle index out of range
    if (index < 0 || index >= size_)
    {
        std::cerr << "error: index out of range\n";
        this->success_ = 0;
        return;
    }

    if (index == 0) 
    {
        pushFront(value); // Add at the front if index is 0
        return;
    }

    Node<T>* temp = head_;
    Node<T>* newNode = new Node<T>;

    for (int i = 0; i < index - 1; i++) 
       temp = temp->next_;
    
    newNode->value_ = value;
    newNode->next_ = temp->next_;
    temp->next_ = newNode;
   
    size_++;
}

// Remove the front node
template<typename T>
void SinglyLinkedListHead<T>::popFront() 
{
    if (!head_)
    {
        this->success_ = 0;
        std::cerr << "error: list is empty\n";
        return;
    }

    Node<T>* temp = head_;
    head_ = head_->next_; 

    delete temp;

    size_--;
}

// Remove the back node
template<typename T>
void SinglyLinkedListHead<T>::popBack() 
{
    if (!head_)
    {
        this->success_ = 0;
        std::cerr << "error: list is empty\n";
        return;
    }

    if (!head_->next_) 
    {
        delete head_;
        head_ = nullptr;
        return;
    }

    Node<T>* temp = head_;

    // Find the second-to-last node
    while (temp->next_->next_) 
    { 
        temp = temp->next_;
    }

    delete temp->next_;
    temp->next_ = nullptr;

    size_--;
}

// Remove the node at index 'index'
template<typename T>
void SinglyLinkedListHead<T>::remove(const int& index) 
{
    // Handle index out of range
    if (index < 0 || index >= size_)
    {
        std::cerr << "error: index out of range\n";
        this->success_ = 0;
        return;
    }

    if (this->isEmpty())
    {
        std::cerr << "error: list is empty";
        this->success_ = 0;
        return;
    }

    if (index == 0) 
    {
        popFront();
        return;
    }

    Node<T>* temp = head_;

    // Traverse to one node before the desired position
    for (int i = 0; temp != nullptr && i < index - 1; i++) 
    {
        temp = temp->next_;
    }

    // If position is out of bounds, do nothing
    if (!temp || !temp->next_)
    {
        return;
    }

    Node<T>* toDelete = temp->next_;
    temp->next_ = temp->next_->next_;

    delete toDelete;

    size_--;
}

template<typename T>
void SinglyLinkedListHead<T>::show() const{
    Node<T>* temp = head_;
    while (temp) 
    {
        std::cout << temp->value_ << " ";
        temp = temp->next_;
    }

    std::cout << "\n";
}

template <typename T>
int SinglyLinkedListHead<T>::find(const T& value) const
{
    Node<T>* current = head_;
    int index = 0;

    while (current != nullptr)
    {
        if (current->value_ == value)
            return index;

        current = current->next_;
        index++;
    }

    return -1;
}

template <typename T>
void SinglyLinkedListHead<T>::clear()
{
    Node<T>* temp = head_;

    while (temp) 
    {
        Node<T>* next = temp->next_;

        delete temp;	
        temp = next;
    }

    head_ = nullptr;
}

// get element at index
template <typename T>
T SinglyLinkedListHead<T>::getValue(const int& index)
{
    // Handle index out of range
    if (index < 0 || index >= size_)
    {
        std::cerr << "error: index out of range\n";
        this->success_ = 0;
        return T{};
    }

    if (index == 0)
        return this->head_->value_;

    Node<T>* current_node = head_;

    for (int i = 0; i < index; i++)
        current_node = current_node->next_;

    return current_node->value_;
}

#endif