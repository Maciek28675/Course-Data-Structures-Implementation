
#ifndef OPERATION_MENU_HPP
#define OPERATION_MENU_HPP

#include <iostream>
#include "Menu.hpp"
#include "DataStructureMenu.hpp"
#include "DataStructure.hpp"

template <typename T>
class OperationMenu : public Menu
{
protected:
	T value;
	DataStructure<T>* dataStructure = nullptr;
	const int exitOption = 10;
public:
	void display() const override;
	void run() override;
	template <typename T> friend class DataStructureMenu;
};

template <typename T>
void OperationMenu<T>::display() const
{
	std::cout << "------ Operation Menu ------\n";
	std::cout << "1. Add to the back\n";
	std::cout << "2. Add to the front\n";
	std::cout << "3. Insert at index\n";
	std::cout << "4. Delete first element\n";
	std::cout << "5. Delete last element\n";
	std::cout << "6. Delete element at index\n";
	std::cout << "7. Find element\n";
	std::cout << "8. Display all elements\n";
	std::cout << "9. Import data from file\n";
	std::cout << "10. Exit structure menu\n";
	std::cout << "----------------------------\n";

	std::cout << "Choose an operation to perform: ";
}

template <typename T>
void OperationMenu<T>::run()
{
	//DataStructureMenu<T> m1;

	while (userChoice != exitOption)
	{
		this->display();
		std::cin >> userChoice;

		dataStructure->setSuccess(1);

		switch (userChoice)
		{
			case 1:
			{
				std::cout << "Enter value to be added: ";
				std::cin >> value;

				dataStructure->pushBack(value);
		
				std::cout << value << " has been added to the back\n";
				break;
			}
			case 2:
			{
				std::cout << "Enter value to be added: ";
				std::cin >> value;

				dataStructure->pushFront(value);

				std::cout << value << " has been added to the front\n";
				break;
			}
			case 3:
			{
				std::cout << "Enter value to be added: ";
				std::cin >> value;

				std::cout << "At which position: ";
				std::cin >> index;

				dataStructure->insert(value, index);

				if(dataStructure->getSuccess())
					std::cout << value << " has been added at " << index << "\n";

				break;
			}
			case 4:
			{
				dataStructure->popFront();

				if (dataStructure->getSuccess())
					std::cout << "First value has been deleted\n";

				break;
			}
			case 5:
			{
				dataStructure->popBack();

				if (dataStructure->getSuccess())
					std::cout << "Last value has been deleted\n";

				break;
			}
			case 6:
			{
				std::cout << "Enter position from which you want to delete value: ";
				std::cin >> index;

				dataStructure->remove(index);
				
				if (dataStructure->getSuccess())
					std::cout << "Value at " << index << " has been removed\n";

				break;
			}
			case 7:
			{
				std::cout << "Enter a value that you want to search for: ";
				std::cin >> value;

				int wasFound = -1;

				if (dataStructure != nullptr)
					wasFound = dataStructure->find(value);

				if (wasFound == -1)
					std::cout << value << " hasn't been found\n";

				else
					std::cout << value << " has been found at " << wasFound << "\n";

				break;
			}
			case 8:
			{
				dataStructure->show();
				break;
			}
			case 9:
			{
				std::cout << "Enter a path to the file: ";
				std::cin >> path;

				dataStructure->loadFromFile(path);

				if (dataStructure->getSuccess())
					std::cout << "Data from " << path << " has been loaded\n";

				break;
			}
			case 10:
			{
				break;
			}
			default:
			{
				std::cerr << "error: choosen option does not exist\n";
				exit(1);
			}
		}

		std::cout << "Press enter to continue";

		// Wait for a key presss
		std::cin.get();
		std::cin.get();

		system("cls");
	}
}
#endif