#include <iostream>
#include <string>

using namespace std;

void replaceAllOccurences(string& text, const string& from, const string& to);
bool isPalindrome(const string text);

int main() {
	string text, searchTerm, replacementTerm;

	cout << "Enter the text you want to modify: ";
	getline(cin, text);
	cout << "Enter the search term: ";
	getline(cin, searchTerm);
	cout << "Enter the replacement term: ";
	getline(cin, replacementTerm);

	replaceAllOccurences(text, searchTerm, replacementTerm);

	cout << text << endl;

	if (isPalindrome(text)) {
		cout << "Input is a palindrome";
	}
	else {
		cout << "Input is a palindrome";
	}
	return 0;
}

// replaces all occurences within a string n times
void replaceAllOccurences(string& text, const string& from, const string& to) {
	// start offset
	size_t start_pos = 0;
	// as long as there are occurences
	while ((start_pos = text.find(from, start_pos)) != string::npos) {
		// replace
		text.replace(start_pos, from.length(), to);
		// and forward seek curor by word length 
		start_pos += to.length();
	}
}

// use two cursors to read from both ends, compare and return false in case of mismatch
bool isPalindrome(const string text) {
	int n = text.length(), j = n - 1;
	int i = 0;
	while (i < j) {
		// skip all non-alnum chars
		while (i < n && !isalnum(text[i])) {
			i++;
		}
		while (j >= 0 && !isalnum(text[j])) {
			j--;
		}
		// check for mismatch in chars (not a palindrome)
		if (i < j && tolower(text[i++]) != tolower(text[j--])) {
			return false;
		}
	}
	return true;
}