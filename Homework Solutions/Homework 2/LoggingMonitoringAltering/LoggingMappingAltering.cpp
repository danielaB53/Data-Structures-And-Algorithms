#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Log_Data 
{
	int id_number;
	int hour;
	int minutes;
	int seconds;
	int date;
	int month;
	int year;
};

bool compare_data(Log_Data& log1, Log_Data& log2)
{
	if (log1.year != log2.year)
	{
		return log1.year < log2.year;
	}
	else
	{
		if (log1.month != log2.month)
			return log1.month < log2.month;
		else
		{
			if (log1.date != log2.date)
				return log1.date < log2.date;
			else
			{
				if (log1.hour != log2.hour)
					return log1.hour < log2.hour;
				else
				{
					if (log1.minutes != log2.minutes)
						return log1.minutes < log2.minutes;
					else
					{
						if (log1.seconds != log2.seconds)
							return log1.seconds < log2.seconds;
						else
							return log1.id_number < log2.id_number;
					}
				}
			}
		}
	}
}

int main()
{
	int number_of_logs;
	cin >> number_of_logs;

    vector <Log_Data> logs;

	int id = 1;
	for (size_t i = 0; i < number_of_logs; i++)
	{
		string current_time, current_date;
		cin >> current_time >> current_date;
		
		Log_Data current_log;
		
		current_log.id_number = id;
		current_log.hour = (current_time[0] - '0') * 10 + (current_time[1] - '0');
		current_log.minutes = (current_time[3] - '0') * 10 + (current_time[4] - '0');
		current_log.seconds = (current_time[6] - '0') * 10 + (current_time[7] - '0');
		current_log.date = (current_date[0] - '0') * 10 + (current_date[1] - '0');
		current_log.month= (current_date[3] - '0') * 10 + (current_date[4] - '0');
		current_log.year = (current_date[6] - '0') * 1000 + (current_date[7] - '0')*100
			+ (current_date[8] - '0') * 10 + (current_date[9] - '0');

		logs.push_back(current_log);
		id++;
	}

	sort(logs.begin(), logs.end(), compare_data);

	for (size_t i = 0; i < logs.size(); i++)
	{
		cout << logs[i].id_number << "\n";
	}

    return 0;
}
