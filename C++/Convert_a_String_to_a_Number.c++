#include <iostream>
#include <string>
using namespace std;

int string_to_number(const string& s) {
	int result = 0;
	bool isPositive = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[0] == '-') {
			isPositive = true;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			result = result * 10 + (s[i] - '0');
		}
	}
	return isPositive ? -result : result;

}
int main() {
	cout << string_to_number("123456") << endl;
	cout << string_to_number("-123456") << endl;
	return  0;
}
