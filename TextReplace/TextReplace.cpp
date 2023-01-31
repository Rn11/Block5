#include <iostream>
#include <string>

using namespace std;

void replaceAllOccurences(string& text, const string& from, const string& to);
bool isPalindrome(const string& text);

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
	cout << "\n" << text << "\n\n";

	// test if text is palindrome
	cout << (isPalindrome(text) ? "Input is a palindrome" : "Input is not a palindrome") << endl;
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
		// and forward seek cursor by word length 
		startPos += to.length();
	}
}

// use two cursors to read from both ends, compare and return false in case of mismatch
bool isPalindrome(const string& text) {
	int right = text.length() - 1;
	int left = 0;
	while (left < right) {
		// skip all non-alnum chars
		while ((left < text.length() / 2) && !isalnum(text[left])) {
			left++;
		}
		while ((right > text.length() / 2) && !isalnum(text[right])) {
			right--;
		}
		// check for mismatch in chars (not a palindrome)
		if (left < right && tolower(text[left++]) != tolower(text[right--])) return false;
	}
	return true;
}