#include<iostream>
#include<ctime>
#include <windows.h>
using namespace std;
class CTimer
{
public:
	CTimer()
	{
		QueryPerformanceFrequency(&m_Frequency);
		//Start();
	}
	void Start()
	{
		QueryPerformanceCounter(&m_StartCount);
	}
	double End()
	{
		LARGE_INTEGER CurrentCount;
		QueryPerformanceCounter(&CurrentCount);
		return double(CurrentCount.LowPart - m_StartCount.LowPart) / (double)m_Frequency.LowPart;
	}
	void ShowNow()
	{
		LARGE_INTEGER CurrentCount;
		QueryPerformanceCounter(&CurrentCount);
		cout << "Timer Count is:" << double(CurrentCount.LowPart - m_StartCount.LowPart) / (double)m_Frequency.LowPart << endl;
	}
private:
	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_StartCount;
};