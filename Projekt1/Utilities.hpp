
#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <cstdlib>
#include <ctime>
#include <vector>
#include "Timer.hpp"

std::vector<int> generateIntDataSet(int size, int seed = time(NULL), int start = 0, int end = 10000)
{
	srand(seed);
	std::vector<int> dataSet;

	for (int i = 1; i<=size; i++)
	{
		int random = (rand() % end) + start;
		dataSet.push_back(random);
	}

	return dataSet;
}


void measurePerformance(int repetitions, int dataSetSize)
{
	// Generate random data set and create empty linked list dynamicly
	std::vector<int> dataSet = generateIntDataSet(dataSetSize, 1);
	DynamicArray<int>* l1 = new DynamicArray<int>;

	double averageTime = 0.0;
	double sum = 0.0;
	double duration = 0.0;
	int valueToFind = -1;

	dataSet[dataSetSize / 2] = valueToFind;

	// Fill linked list with generated data
	for (int i = 0; i < dataSet.size(); i++)
		l1->pushFront(dataSet[i]);
	
	// measure time of operation
	for (int i = 0; i < repetitions; i++)
	{
		Timer timer;

		timer.start();
		l1->find(valueToFind);
		timer.stop();

		duration = timer.getDuration();
		sum += duration;
	}

	averageTime = sum / repetitions;

	std::cout << "Average time: " << averageTime << "ns\n";

	delete l1;
}

#endif