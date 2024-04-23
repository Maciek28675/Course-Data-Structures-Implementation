
#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

using namespace std::chrono;

class Timer
{
public:
	void start();
	void stop();
	double getDuration();

private:
	high_resolution_clock::time_point start_time, end_time;
	duration<double> duration;
};

void Timer::start()
{
	start_time = high_resolution_clock::now();
}

void Timer::stop()
{
	end_time = high_resolution_clock::now();
}

double Timer::getDuration()
{
	duration = end_time - start_time;
	double duration_ns = duration_cast<nanoseconds>(duration).count();
	return duration_ns;
}

#endif