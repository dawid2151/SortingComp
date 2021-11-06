#include "Stopwatch.h"

void Stopwatch::Start()
{
	start = high_resolution_clock::now();
}

void Stopwatch::Stop()
{
	end = high_resolution_clock::now();
}

double Stopwatch::Duration()
{
	auto dur = duration_cast<microseconds>(end - start);
	return (double)dur.count() / (double)1000;
}