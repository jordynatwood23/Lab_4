/*
Jordyn Atwood
C++ FA2025
Due: Oct 24th
Description: Create a program that reads hourly temperature from a file and generates a bar chart with the temperature on the left.
*/
// precondition: read temperature from a file and output a bar chart to the screen
//postcondition: it should read the temp values from the file and output them to the screen on a bar chart with stars

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
 

// constants
const int min_temp = -30;
const int max_temp = 120;
const int degree_per_symbol = 3;
const string input_filename = "temps.text";
const int max_bar_width = (max_temp - min_temp) / degree_per_symbol;

// function to validate temperature
bool isValidTemperature(int temp) 
{
    return temp >= min_temp && temp <= max_temp;
}

//print the chart heading
void printChartHeading()
{
    cout << "Centered Temperature Bar Chart (Each '*' = " << degree_per_symbol << " degrees)" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Temp | Bar" << endl;
    cout << "------------------------------------------------------------" << endl;
}

//print bar chart
void printTemperatureBar(int temp) 
{
    int symbolCount = abs(temp) / degree_per_symbol;
    cout << setw(4) << temp << " F | ";
    if (temp < 0) 
    {
        
        for (int i = 0; i < max_bar_width / 2 - symbolCount; ++i) cout << " ";
        for (int i = 0; i < symbolCount; ++i) cout << "*";
        cout << "|";
    }
    else if (temp > 0) 
    {
       
        for (int i = 0; i < max_bar_width / 2; ++i) cout << " ";
        cout << "|";
        for (int i = 0; i < symbolCount; ++i) cout << "*";
    }
    else 
    {
   
        for (int i = 0; i < max_bar_width / 2; ++i) cout << " ";
        cout << "|";
    }

    cout << endl;
}

int main() 
{
    ifstream inputFile(input_filename);
    int temperature;
    int hour = 0;

    if (!inputFile)
    {
        cerr << "Error: Unable to open file '" << input_filename << "'." << endl;
        return 1;
    }

    printChartHeading();

    while (inputFile >> temperature) 
    {
        ++hour;
        if (isValidTemperature(temperature)) 
        {
            printTemperatureBar(temperature);
        }
        else
        {
            cout << "Hour " << hour << ": Invalid temperature (" << temperature << " F) skipped." << endl;
        }
    }

    inputFile.close();
    return 0;
}
