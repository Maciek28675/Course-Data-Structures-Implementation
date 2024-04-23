
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
protected:
	int userChoice = 0;
	int index = 0;
	std::string path = "";

public:
	virtual void display() const = 0;
	virtual void run() = 0;
};

#endif