#include <chrono>

using namespace std::chrono;
#pragma once
class Stopwatch
{
private:
	time_point<high_resolution_clock> start;
	time_point<high_resolution_clock> end;

public:
	void Start()
	{
		start = high_resolution_clock::now();
	}

	void Stop()
	{
		end = high_resolution_clock::now();
	}

	double Duration()
	{
		auto dur = duration_cast<microseconds>(end - start);
		return (double)dur.count() / (double)1000;
	}
};

