#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

string to_string(int number)
{
    string num_str;
    ostringstream oss;
    oss << number;
    num_str += oss.str();
    return num_str;
}

struct Calender
{
    const int MONTHS = 12;
    int number_of_days;
    int day_counter = -1;
    string day_of_week;

    unordered_map<string, string> date;

    Calender()
    {
        buildCalender();
    }

    void buildCalender()
    {
        for(int i = 1; i <= MONTHS; i++)
        {
            for(int j = 1; j <= find_number_of_days(i); j++)
            {

                date.insert({create_date_str(i,j), day_of_week_return()});
            }
        }
    }

    string create_date_str(int month, int day)
    {
        string built_date;

        built_date = to_string(month) + '/' + to_string(day);

        return built_date;
    }

    string day_of_week_return()
    {
        string day;
        day_counter++;

        switch(day_counter)
        {
            case 1:
                day = "Monday";
                break;
            case 2:
                day = "Tuesday";
                break;
            case 3:
                day = "Wednesday";
                break;
            case 4:
                day = "Thursday";
                break;
            case 5:
                day = "Friday";
                break;
            case 6:
                day = "Saturday";
                break;
            case 7:
                day = "Sunday";
                break;
        }

        if(day_counter == 7)
        {
            day_counter = 0;
        }

        return day;
    }

    int find_number_of_days(int month)
    {
        switch (month)
        {
            case 1:
                return 31;

            case 2:
                return 28;

            case 3:
                return 31;

            case 4:
                return 30;

            case 5:
                return 31;

            case 6:
                return 30;

            case 7:
                return 31;

            case 8:
                return 31;

            case 9:
                return 30;

            case 10:
                return 31;

            case 11:
                return 30;

            case 12:
                return 30;

        }
    }

    string findDay()
    {
        string user_date;
        cout << "Please enter a date in int/int form or enter 'exit' to exit:" << endl;
        getline(cin, user_date);

        if(user_date == "exit")
        {
            return user_date;
        }
        else
        {
            auto a = date.find(user_date);
            return (a -> second);
        }

    }


};

int main()
{
    Calender calender;
    string date;

    while(true)
    {
        date = calender.findDay();

        if(date == "exit")
        {
            return 0;
        }
        else
        {
            cout << date << endl;
        }
    }
}
