
#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "DataStructure.hpp"

template <typename T>
class SinglyNode
{
private:
	T value_;
	SinglyNode<T>* next_;
	template <typename T> friend class SinglyLinkedList;
};

template <typename T>
class SinglyLinkedList : public DataStructure<T>
{
private:
	SinglyNode<T>* head_;
	SinglyNode<T>* tail_;
	int size_;

public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void pushBack(const T& value) override;
	void pushFront(const T& value) override;
	void insert(const T& value, const int& index) override;

	// TODO: Prohibit user from removing a node from an empty list
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
SinglyLinkedList<T>::SinglyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	while (!isEmpty())
		popFront();
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
	if (head_ == nullptr && tail_ == nullptr)
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
	SinglyNode<T>* node = new SinglyNode<T>;

	node->value_ = value;
	node->next_ = head_;

	if (this->isEmpty())
	{
		tail_ = node;
	}

	head_ = node;

	size_ += 1;
}

// Add element to the back of the list
template <typename T>
void SinglyLinkedList<T>::pushBack(const T& value)
{
	if (this->isEmpty())
	{
		this->pushFront(value);
	}

	else
	{
		SinglyNode<T>* node = new SinglyNode<T>;

		node->value_ = value;
		node->next_ = nullptr;

		tail_->next_ = node;
		tail_ = node;

		size_ += 1;
	}
}

// Add element at specifed index
template <typename T>
void SinglyLinkedList<T>::insert(const T& value, const int& index)
{
	// Handle index out of range
	if (index < 0 || index >= size_)
	{
		std::cerr << "error: index out of range\n";
		this->success_ = 0;
		return;
	}

	if (index == 0)
		this->pushFront(value);

	else
	{
		SinglyNode<T>* current_node = head_;
		SinglyNode<T>* new_node = new SinglyNode<T>;

		// get to the element at index-1 position
		for (int i = 0; i < index - 1; i++)
			current_node = current_node->next_;

		new_node->value_ = value;
		new_node->next_ = current_node->next_;
		current_node->next_ = new_node;

		size_ += 1;
	}
}

// delete first element
template <typename T>
void SinglyLinkedList<T>::popFront()
{
	if (this->isEmpty())
	{
		std::cerr << "error: list is empty\n";
		this->success_ = 0;
		return;
	}

	SinglyNode<T>* temporary_node = head_;
	head_ = temporary_node->next_;

	if (head_ == nullptr)
		tail_ = temporary_node->next_;

	delete temporary_node;
	size_ -= 1;
}

// delete last element
template <typename T>
void SinglyLinkedList<T>::popBack()
{
	if (this->isEmpty())
	{
		std::cerr << "error: list is empty";
		this->success_ = 0;
		return;
	}

	if (head_->next_ == nullptr)
		this->popFront();

	else
	{
		SinglyNode<T>* current_node = head_;
		SinglyNode<T>* temporary_node = tail_;

		int index = size_ - 2;

		for (int i = 0; i < index; i++)
			current_node = current_node->next_;

		current_node->next_ = nullptr;
		tail_ = current_node;

		delete temporary_node;
		size_ -= 1;
	}
}

// delete element at index
template <typename T>
void SinglyLinkedList<T>::remove(const int& index)
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
		this->popFront();

	else if (index == size_ - 1)
		this->popBack();

	else
	{
		SinglyNode<T>* current_node = head_;
		SinglyNode<T>* temporary_node = nullptr;

		for (int i = 0; i < index - 1; i++)
			current_node = current_node->next_;

		temporary_node = current_node->next_;
		current_node->next_ = current_node->next_->next_;

		delete temporary_node;
		size_ -= 1;
	}
}

// get element at index
template <typename T>
T SinglyLinkedList<T>::getValue(const int& index)
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

	else if (index == size_ - 1)
		return this->tail_->value_;

	SinglyNode<T>* current_node = head_;

	for (int i = 0; i < index; i++)
		current_node = current_node->next_;

	return current_node->value_;
}

// Display entire list in a user friendly format
template <typename T>
void SinglyLinkedList<T>::show() const
{
	SinglyNode<T>* current_node = head_;

	while (current_node != nullptr)
	{
		std::cout << current_node->value_ << '\n';
		current_node = current_node->next_;
	}
}

// Return an index of a first occurence of a specified value. In case of failure return -1
template <typename T>
int SinglyLinkedList<T>::find(const T& value) const
{
	SinglyNode<T>* current_node = head_;
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