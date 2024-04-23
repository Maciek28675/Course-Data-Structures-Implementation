
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <iostream>
#include "Menu.hpp"
#include "DataStructureMenu.hpp"

class MainMenu : public Menu
{
public:
	void display() const override;
	void run() override;
};

void MainMenu::display() const
{
	std::cout << "----------\n";
	std::cout << "1. Int\n";
	std::cout << "2. Float\n";
	std::cout << "3. Char\n";
	std::cout << "4. String\n";
	std::cout << "----------\n";

	std::cout << "Choose a data type for a data structure: ";

}

void MainMenu::run()
{
	while (true)
	{
		this->display();
		std::cin >> userChoice;

		std::cout << "Press any key to continue";

		// Wait for a key presss
		std::cin.get();
		std::cin.get();

		system("cls");

		switch (userChoice)
		{
			case 1:
			{
				DataStructureMenu<int> m1;
				m1.run();
				break;
			}
			case 2:
			{
				DataStructureMenu<float> m2;
				m2.run();
				break;
			}
			case 3:
			{
				DataStructureMenu<char> m3;
				m3.run();
				break;
			}
			case 4:
			{
				DataStructureMenu<std::string> m4;
				m4.run();
				break;
			}
			default:
			{
				std::cerr << "error: choosen option does not exist\n";
				exit(1);
			}
		}
	}
}
#endif