
#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

template <typename T>
class SinglyLinkedList;

template <typename T>
class DoublyLinkedList;

template <typename T>
class DynamicArray;

template <typename T>
class DataStructure
{
protected:
	// Variable used to determine wether an operation has been succesful
	bool success_ = 1;
public:
	virtual void pushBack(const T& value) = 0;
	virtual void pushFront(const T& value) = 0;
	virtual void insert(const T& value, const int& index) = 0;

	virtual void popBack() = 0;
	virtual void popFront() = 0;
	virtual void remove(const int& index) = 0;

	virtual void show() const = 0;
	virtual int find(const T& value) const = 0;

	void loadFromFile(const std::string& fileName);

	virtual T getValue(const int& index) { return T{}; };
	virtual int getSize() const { return 0; };
	virtual bool getSuccess() const { return success_; };
	virtual void setSuccess(bool value) { success_ = value; };
	virtual bool isEmpty() const { return true; };
};

template <typename T>
void DataStructure<T>::loadFromFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	T value = T{};

	if (!file.is_open())
	{
		std::cerr << "Cannot open the file " << fileName << '\n';
		this->success_ = 0;
		return;
	}

	std::string line;

	while (std::getline(file, line)) {	// Read lines from the file
		std::stringstream ss(line);	// Use string stream for parsing

		if (ss >> value) {
			pushBack(value);	// Add parsed value to the list
		}

		else {
			std::cerr << "Wrong line in the file " << line << std::endl;	// Report lines that cannot be parsed
		}
	}
	file.close();
}

#endif