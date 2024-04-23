
#ifndef DATA_STRUCTURE_MENU_HPP
#define DATA_STRUCTURE_MENU_HPP

#include "DataStructure.hpp"
#include "SinglyLinkedList.hpp"
#include "SinglyLinkedListHead.hpp"
#include "DoublyLinkedList.hpp"
#include "DynamicArray.hpp"
#include "Menu.hpp"
#include "OperationMenu.hpp"

template <typename T>
class DataStructureMenu : public Menu
{
protected:
	DataStructure<T>* dataStructure = nullptr;
	const int exitOption = 5;

public:
	void display() const override;
	void run() override;

	template <typename T> friend class OperationMenu;
};

template <typename T>
void DataStructureMenu<T>::display() const
{
	std::cout << "------------------- Menu -------------------\n";
	std::cout << "1. Create a dynamic array\n";
	std::cout << "2. Create a singly linked list\n";
	std::cout << "3. Create a singly linked list with tail\n";
	std::cout << "4. Create a doubly linked list\n";
	std::cout << "5. Exit program\n";
	std::cout << "--------------------------------------------\n";

	std::cout << "Choose one option from the menu: ";
}

template <typename T>
void DataStructureMenu<T>::run()
{
	while (userChoice != exitOption)
	{
		this->display();
		std::cin >> userChoice;

		switch (userChoice)
		{
			case 1:
			{
				DynamicArray<T>* arr = new DynamicArray<T>;
				dataStructure = arr;

				std::cout << "An empty dynamic array has been created\n";
				break;
			}
			case 2:
			{
				SinglyLinkedListHead<T> l1;
				dataStructure = &l1;
				
				std::cout << "An empty singly linked list has been created\n";
				break;
			}
			case 3:
			{
				SinglyLinkedList<T> l2;
				dataStructure = &l2;

				std::cout << "An empty singly linked list with tail has been created\n";
				break;
			}
			case 4:
			{
				DoublyLinkedList<T> l3;
				dataStructure = &l3;

				std::cout << "An empty doubly linked list has been created\n";
				break;
			}
			case 5:
			{
				exit(0);
			}
			default:
			{
				std::cerr << "error: choosen option does not exist\n";
				exit(1);
			}
		}

		std::cout << "Press any key to continue";

		// Wait for a key presss
		std::cin.get();
		std::cin.get();

		system("cls");

		OperationMenu<T> m1;
		m1.dataStructure = dataStructure;
		m1.run();
	}

}

#endif