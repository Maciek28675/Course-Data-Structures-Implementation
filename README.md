# Implementation of selected data structures in C++
In this project we've implemented singly linked list (with and without tail), doubly linked list and a dynamic array.  
Each structure has it's own set of basic operations like push back, pop back, find, etc.  
We've measured time of execution of every operation to compare data structures performance and determine which is best for every scenario. We've also verified whether time complexity of those operations matches the theory (and it does for almost all cases).  
  
The project follows basic OOP principles, which are encapsulation, polymorphism, inheritance and abstraction.  
  
## How to compile
The project uses cmake for compilation purposes.  
To compile it, follow this steps:

```cmd
mkdir build
cd build
cmake ..
cmake --build .
```

## How we measured performance  
To do that, we've filled a data structure with random generated data. Then performed an operation (for ex. push back) for a specified amonut of times and calculated the avarage time. We've then repeated the process for bigger data sets and created a chart.  
To measure time we've used chrono library

### Code snippet used to measure performance

```cpp
// measure time of operation
for (int i = 0; i < repetitions; i++)
{
	Timer timer;

	timer.start();
	l1->pushBack(dataSet[0]);
	timer.stop();

	duration = timer.getDuration();
	sum += duration;

	l1->popBack();
}

averageTime = sum / repetitions;
```

### Example chart

![chart 1](https://github.com/Maciek28675/Data-Structures-Implementation/blob/main/Images/chart1.png)

## Menu
The program features user friendly menu. The user can choose a data structure, it's data type and an operation to perform.  
Here is how it looks like:  

![menu example 1](https://github.com/Maciek28675/Data-Structures-Implementation/blob/main/Images/menuExample1.bmp)

![menu example 2](https://github.com/Maciek28675/Data-Structures-Implementation/blob/main/Images/menuExample2.bmp)

## Additional repository
This is the final, polished version of the program (still, can be improved). Below is a link to the first version of the repository that we've used to colaborate on the project. It's purpose was to test everything and learn GitHub.

[first version of repository](https://github.com/Maciek28675/Data-Structures-Project1)

