#include <string>

using std::string;

/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as a string
 * 
 * @param prompt    the message display to the user
 * @returns         the text the user enters
 */ 
string read_string ( string prompt );


/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as an integer if it is a valid integer
 * 
 * @param prompt    the message display to the user
 * @returns         the number the user enters
 */ 
int read_integer ( string prompt );

long int read_long_integer(string prompt);

/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as an double if it is a valid double
 * 
 * @param prompt    the message display to the user
 * @returns         the double the user enters
 */ 
double read_double(string prompt);

/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as an integer. Note, the value must be between the minimum and maximum
 * 
 * @param prompt    the message display to the user
 * @param min       minimum number
 * @param max       maximum number
 * @returns         the integer the user enters between min and max
 */ 
int read_integer (string prompt, int min, int max);

/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as an double if the double is between min and max
 * 
 * @param prompt    the message display to the user
 * @param min       minimum value the user can enter
 * @param max       the maximum value the user can enter
 * @returns         the double the user enters
 */ 
double read_double_range(string prompt, double min, double max);


/**
 * Prompts the user for input and reads the text that the user enters
 * at the Terminal. This will read in a line of text and return this
 * as an boolean
 * 
 * @param prompt    the message display to the user
 * @returns         the boolean the user enters dependent on y/n yes/no
 */ 
bool read_boolean(string prompt);



/**
 * --TO DO--
 * Enter information here
 * 
 */ 
int read_integer_with_length(string prompt, int length);

/**
 * --TO DO--
 * Enter information here
 * 
 */ 
string convert_to_string(double val);
