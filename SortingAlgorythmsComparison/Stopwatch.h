#pragma once
#include <chrono>

using namespace std::chrono;
class Stopwatch
{
private:
	time_point<high_resolution_clock> start;
	time_point<high_resolution_clock> end;

public:
	void Start();

	void Stop();

	double Duration();
};

