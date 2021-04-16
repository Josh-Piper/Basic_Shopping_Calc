#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include "splashkit.h"
#include <string>

using std::to_string;

string read_string(string prompt) 
{
    write(prompt);
    return read_line();
}

int read_integer(string prompt) 
{
    string result;
    do
    {
        result = read_string(prompt);
        if ( not is_integer (result) ) write_line("[INFO] Please enter a whole number");
    } while ( not is_integer (result) );

    return convert_to_integer(result);
}

int read_integer (string prompt, int min, int max) 
{
    int result { read_integer( prompt ) };

    while ( result < min || result > max ) {
        write_line("[INFO] Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }

    return result;
}

long int read_long_integer(string prompt)
{
    string result;
    do
    {
        result = read_string(prompt);
        if ( not is_integer (result) ) write_line("[INFO] Please enter a whole number");
    } while ( not is_integer (result) );

    return convert_to_integer(result);
}

double read_double(string prompt) 
{  
    string result;

    do 
    {
        result = read_string(prompt);
        if  ( not is_double(result) ) write_line("[INFO] Please enter a decimal number");
    } while ( not is_double(result) );

    return convert_to_double(result);
}

double read_double_range(string prompt, double min, double max) 
{
    double result { read_double(prompt) };

    while ( result < min || result > max ) {
        write_line("The number must be between " + to_string(min).substr(0, 3) + " and " + to_string(max).substr(0, 3));
        result = read_double(prompt);
    }

    return result;
}

int read_integer_with_length(string prompt, int length)
{
    int result;
    int size_of_string;

    do
    {
        result = read_long_integer(prompt);
        size_of_string = to_string(result).length();
        if ( size_of_string != length ) write_line("The amount of digits must be " + to_string(length));
    } while ( size_of_string != length );

    return result;
}

bool read_boolean(string prompt) 
{
    string line;
    bool result;

    do {
        line = to_lowercase(trim(read_string(prompt)));

        if (line == "y" || line == "yes") 
        {
            result = true;
            break;
        }
        else if (line == "n" || line == "no") 
        {
            result = false;
            break;
        } else 
        {
            write_line("Please only enter y/yes or n/no");
        }
        
    } while ( line != "n" || line != "no" || line != "y" || line != "yes");

    return result;

}

string convert_to_string(double val)
{
    string str = to_string(val);
    int dp = str.find(".");
    return str.substr(0, dp + 3);
}

 #endif
