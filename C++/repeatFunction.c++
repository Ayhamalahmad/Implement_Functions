#include <iostream>
using namespace std;
/**
 * Function to repeat a given string a specified number of times, with optional separator and control over the final separator.
 *
 * @param toRepeat The string to be repeated.
 * @param numOfRepeat The number of times to repeat the string (default is 2).
 * @param separator The string to insert between repetitions (default is an empty string).
 * @param showEndSeparator A boolean to control whether to add the separator at the end of the final string (default is true).
 * @return A new string consisting of the repeated `toRepeat` string with the specified separator and end separator condition.
 */
string repeatString(string toRepeat,int numOfRepeat =2 , string sepreator ="", bool showEndSepreator = true) {
	string result;
	for (int i = 0; i < numOfRepeat; i++) {
		result += toRepeat;
		if (i < numOfRepeat - 1) {
			result += sepreator;
		}
	}
	if (showEndSepreator) {
		result += sepreator;
	}
	return result;
}
int main() {
	cout << repeatString("ayham") << endl;
	return 0;
}