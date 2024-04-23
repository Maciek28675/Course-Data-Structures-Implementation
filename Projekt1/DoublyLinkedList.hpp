
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "DataStructure.hpp"

template <typename T>
class DoublyNode
{
private:
	T value_;
	DoublyNode<T>* previous_;
	DoublyNode<T>* next_;
	template <typename T> friend class DoublyLinkedList;
};

template <class T>
class DoublyLinkedList : public DataStructure<T>
{
private:
	DoublyNode<T>* head_;
	DoublyNode<T>* tail_;
	int size_;
	bool success_ = 1;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void pushBack(const T& value) override;
	void pushFront(const T& value) override;
	void insert(const T& value, const int& index) override;

	void popBack() override;
	void popFront() override;
	void remove(const int& index) override;

	T getValue(const int& index) override;
	int getSize() const override;
	void show() const override;
	bool isEmpty() const override;
	int find(const T& value) const override;
};


// Create an empty list
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while (!isEmpty())
		popFront();
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
	if (head_ == nullptr && tail_ == nullptr)
		return true;
	return false;
}

template <typename T>
int DoublyLinkedList<T>::getSize() const
{
	return size_;
}

// Add element to the front of the list
template <typename T>
void DoublyLinkedList<T>::pushFront(const T& value)
{
	DoublyNode<T>* node = new DoublyNode<T>;

	node->value_ = value;
	node->previous_ = nullptr;
	node->next_ = head_;

	if (isEmpty())
		tail_ = node;
	else
		head_->previous_ = node;

	head_ = node;

	size_ += 1;
}

// Add element to the back of the list
template <typename T>
void DoublyLinkedList<T>::pushBack(const T& value)
{
	if (isEmpty())
	{
		pushFront(value);
	}
	else
	{
		DoublyNode<T>* node = new DoublyNode<T>;

		node->value_ = value;
		node->next_ = nullptr;

		tail_->next_ = node;
		node->previous_ = tail_;
		tail_ = node;

		size_ += 1;
	}
}

// Add element at specifed index
template <typename T>
void DoublyLinkedList<T>::insert(const T& value, const int& index)
{
	// Handle index out of range
	if (index < 0 || index >= size_)
	{
		std::cerr << "error: index out of range\n";
		this->success_ = 0;
		return;
	}

	if (index == 0)
		pushFront(value);

	else
	{
		DoublyNode<T>* node = new DoublyNode<T>;
		DoublyNode<T>* current_node = head_;
		
		node->value_ = value;

		for (int i = 0; i < index - 1; i++)
			current_node = current_node->next_;

		node->next_ = current_node->next_;
		current_node->next_ = node;
		node->previous_ = current_node;
		node->next_->previous_ = node;

		size_ += 1;
	}
}

// delete first element
template <typename T>
void DoublyLinkedList<T>::popFront()
{
	DoublyNode<T>* temporary_node = head_;

	if (isEmpty())
	{
		std::cerr << "error: list is empty";
		this->success_ = 0;
		return;
	}

	head_ = temporary_node->next_;
	
	if (head_ == nullptr)
		tail_ = temporary_node->next_;

	else if (head_ != nullptr)
		head_->previous_ = nullptr;


	delete temporary_node;
	size_ -= 1;
}

// delete last element
template <typename T>
void DoublyLinkedList<T>::popBack()
{
	if (isEmpty())
	{
		std::cerr << "error: list is empty";
		this->success_ = 0;
		return;
	}

	if (head_->next_ == nullptr)
		popFront();

	else
	{	
		DoublyNode<T>* previous_node = tail_->previous_;
		DoublyNode<T>* temporary_node = tail_;

		previous_node->next_ = nullptr;
		tail_ = previous_node;

		delete temporary_node;

		size_ -= 1;
	}
}

// delete element at index
template <typename T>
void DoublyLinkedList<T>::remove(const int& index)
{
	// Handle index out of range
	if (index < 0 || index >= size_)
	{
		std::cerr << "error: index out of range\n";
		this->success_ = 0;
		return;
	}

	if (index == 0)
		popFront();

	else if (index == size_ - 1)
		popBack();

	else
	{
		DoublyNode<T>* current_node = head_;
		DoublyNode<T>* temporary_node = nullptr;

		for (int i = 0; i < index - 1; i++)
			current_node = current_node->next_;

		temporary_node = current_node->next_;
		current_node->next_ = current_node->next_->next_;
		current_node->next_->previous_ = temporary_node->previous_;

		delete temporary_node;
		size_ -= 1;
	}
}

// get element at index
template <typename T>
T DoublyLinkedList<T>::getValue(const int& index)
{
	// Handle index out of range
	if (index < 0 || index >= size_)
	{
		std::cerr << "error: index out of range\n";
		this->success_ = 0;
		return T{};
	}

	if (index == 0)
		return head_->value_;

	else if (index == size_ - 1)
		return tail_->value_;

	DoublyNode<T>* current_node = head_;

	for (int i = 0; i < index; i++)
		current_node = current_node->next_;

	return current_node->value_;
}

// Display entire list in a user friendly format
template <typename T>
void DoublyLinkedList<T>::show() const
{
	DoublyNode<T>* current_node = head_;

	while (current_node != nullptr)
	{
		std::cout << current_node->value_ << '\n';
		current_node = current_node->next_;
	}
}

// Return an index of a first occurence of a specified value. In case of failure return -1
template <typename T>
int DoublyLinkedList<T>::find(const T& value) const
{
	DoublyNode<T>* current_node = head_;
	int index = 0;

	while (current_node != nullptr)
	{
		if (current_node->value_ == value)
			return index;

		current_node = current_node->next_;

		index++;
	}

	return -1;
}

#endif