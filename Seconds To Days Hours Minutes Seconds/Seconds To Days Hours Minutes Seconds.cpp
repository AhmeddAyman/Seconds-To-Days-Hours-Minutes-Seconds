#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// #Course_4_Solution_43
// Seconds To Days Hours Minutes Seconds.


struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

strTaskDuration SecondToTaskDuration(int TotalSeconds)
{
	strTaskDuration TaskDuration;
	const int SecondPerDay = 24 * 60 * 60;
	const int SecondPerHour = 60 * 60;
	const int SecondsPerMinutes = 60;

	int Remainder = 0;
	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondPerDay);
	Remainder = TotalSeconds % SecondPerDay;
	TaskDuration.NumberOfHours = floor(Remainder / SecondPerDay);
	Remainder = Remainder % SecondPerHour;
	TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinutes);
	Remainder = Remainder % SecondsPerMinutes;
	TaskDuration.NumberOfSeconds = Remainder;


	return TaskDuration;
}

void PrintTaskDurationDetails(strTaskDuration TaskDuration)
{

	cout << "\n";
	cout << TaskDuration.NumberOfDays << ":"
		<< TaskDuration.NumberOfHours << ":"
			<< TaskDuration.NumberOfMinutes << ":"
		<< TaskDuration.NumberOfSeconds << ":" << "\n";
} 


int main()
{

	int TotalSeconds = ReadPositiveNumber("Please Enter Total Seconds?");
	PrintTaskDurationDetails(SecondToTaskDuration(TotalSeconds));
	
}
