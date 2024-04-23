#include <iostream>
#include "SinglyLinkedList.hpp"

// Create an empty list
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { std::cout << "List deleted\n"; }

template <typename T>
SinglyNode<T>::SinglyNode(T value) : value_(value), next_(nullptr) {}

template <typename T>
SinglyNode<T>::~SinglyNode() { std::cout << "Node deleted\n"; }


template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
	if (head_ == nullptr && tail_ == nullptr && size_ == 0)
		return true;
	return false;
}

template <typename T>
int SinglyLinkedList<T>::getSize() const
{
	return size_;
}

// Add element to the front of the list
template <typename T>
void SinglyLinkedList<T>::pushFront(const T& value)
{
	SinglyNode<T>* node = new SinglyNode(value);

	node->next_ = head_;

	head_ = node;

	size_ += 1;

	if (this->isEmpty)
		tail_ = node;
}

// Add element to the back of the list
template <typename T>
void SinglyLinkedList<T>::pushBack(const T& value)
{
	if (this->isEmpty)
	{
		this->pushFront;
	}
	else
	{
		SinglyNode<T>* node = new SinglyNode(value);

		node->next_ = nullptr;

		tail_ = node;
	}
}

// Add element at specifed index
template <typename T>
void SinglyLinkedList<T>::insert(const T& value)
{

}
