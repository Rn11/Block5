#include <iostream>
#include <string>

using namespace std;

void replaceAllOccurences(string& text, const string& from, const string& to);
bool isPalindrome(const string text);

int main() {
	string text, searchTerm, replacementTerm;

	// read inputs
	cout << "Enter the text you want to modify: ";
	getline(cin, text);
	cout << "Enter the search term: ";
	getline(cin, searchTerm);
	cout << "Enter the replacement term: ";
	getline(cin, replacementTerm);

	// replace text and print result
	replaceAllOccurences(text, searchTerm, replacementTerm);
	cout << text << endl;

	// test if text is palindrome
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
	size_t startPos = 0;
	// as long as there are occurences
	while ((startPos = text.find(from, startPos)) != string::npos) {
		// replace
		text.replace(startPos, from.length(), to);
		// and forward seek curor by word length 
		startPos += to.length();
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