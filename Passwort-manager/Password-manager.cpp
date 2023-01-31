#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

/*
This code implements a password change functionality which will be checking the users current password first,
then prompting for and confirm a new password. The new password must meet specific requirements,
such as containing a certain number of upper-case letters, lower-case letters, digits, and special characters.
The code uses the regex library to validate the new password and updates it if it meets all requirements. The input buffer has a
fixed length of 80 characters and there are limitations to the accepted set of special characters.
*/

// prototype functions
bool isPasswordValid(const char inputBuffer[], const char currentPassword[]);
bool changePassword(char(&currentPassword)[80]);

int main() {
	// declare character arrays to store current password, input and confirmation input
	char currentPassword[80], inputBuffer[80], confirmationBuffer[80];
	// initialize the passwordInvalid flag with 1
	int passwordInvalid = 1;

	// copy default password into current password
	strcpy_s(currentPassword, "an0th3rD@yAn0th3r$");

	// read input and check for match with current password as long as the input does not match
	while (passwordInvalid) {
		// prompt user for the old password and write input into the inputBuffer
		cout << "Bitte geben Sie das alte Passwort ein. Hinweis - Passwort lautet: " << currentPassword << endl;
		cin.getline(inputBuffer, 80);

		// check if the content of the input buffer matches the current password
		if (isPasswordValid(inputBuffer, currentPassword)) {
			// if the passwords match, set the passwordInvalid flag to 0 so we can exit the loop and notify user
			passwordInvalid = 0;
			cout << "Passwort korrekt!" << endl;
		}
		else {
			// if the passwords do not match, prompt the user to try again and set flag
			cout << "Das Passwort stimmt nicht, bitte erneut versuchen!" << "\n\n";
			passwordInvalid = 1;
		}
	}

	// call function to update current password
	changePassword(currentPassword);
	// print out current password for confirmation
	cout << "Das Passwortet lautet nun " << currentPassword << endl;

	return 0;
}


// This function checks if the input buffer matches the current password
bool isPasswordValid(const char inputBuffer[], const char currentPassword[])
{
	// check if the content of the input buffer matches the current password
	if ((strcmp(inputBuffer, currentPassword) != 0)) {
		return false;
	}
	else {
		return true;
	}
}

// This function reads two inputs, checks if they match and satisfy the password rules defined in regex below. If so, update the current password with the value from the input
bool changePassword(char(&currentPassword)[80])
{
	// create an error message string to store all error messages used later on to determine if any rules were not satisfied
	string passwordError = "";
	// create regex patterns to match lowercase characters, uppercase characters, numbers, and special characters
	regex lower{ "[a-zä-ü]+" };
	regex upper{ "[A-ZÄ-Ü]+" };
	regex numeric{ "[0-9]+" };
	regex special{ "[!§\\$%&/\\(\\)=\\?#\\+'´`\\^°~\\*\\[\\]-_:<>;\\\\.\\\\|\\\"]+" };
	// create arrays to store inputs
	char inputBuffer[80], confirmationBuffer[80];
	// create passwordInvalid flag to determine if we need to continue the loop below
	int passwordInvalid = 1;
	do {
		// read inputs for new password
		cout << "Bitte geben Sie das neue Passwort ein: ";
		cin.getline(inputBuffer, 80);
		cout << "Bitte wiederholen Sie das neue Passwort: ";
		cin.getline(confirmationBuffer, 80);

		// reset the error message string that stores all error messages and that is used later on to determine if any rules were not satisfied
		passwordError = "";

		// check for password rules: alphanumeric mixed case with special char, min length 8, and equal inputs
		// check if the password contains an uppercase character
		passwordError.append((!regex_search(inputBuffer, upper)) ? "- Passwort braucht mindestens einen grossen Buchstaben\n" : "");
		// check if the password contains a lowercase character
		passwordError.append((!regex_search(inputBuffer, lower)) ? "- Passwort braucht mindestens einen kleinen Buchstaben\n" : "");
		// check if the password contains a number
		passwordError.append((!regex_search(inputBuffer, numeric)) ? "- Passwort braucht mindestens eine Zahl\n" : "");
		// check if the password contains a special character
		passwordError.append((!regex_search(inputBuffer, special)) ? "- Passwort braucht mindestens ein Sonderzeichen\n" : "");
		// check if the password length is at least 8 characters long
		passwordError.append((strlen(inputBuffer) < 8) ? "- Passwort muss mindestens 8 Zeichen lang sein\n" : "");
		// check if the password from both input buffers match
		passwordError.append((strcmp(inputBuffer, confirmationBuffer) != 0) ? "- Passwoerter sind nicht gleich\n" : "");

		// check if no errors occured. This condition is met when the password error message string is empty
		if (passwordError.empty()) {
			// if no errors occured copy input to password
			strcpy_s(currentPassword, inputBuffer);
			cout << "Das Passwort wurde erfolgreich aktualisiert!" << endl;
			// reset passwordInvalid flag
			passwordInvalid = 0;
			return true;
		}
		else {
			// output concatenated errors including all errors from each respective rule not satisfied
			cout << "\n\nFolgende Regeln wurden nicht erfuellt:\n" << passwordError << "\n\n\n";
			// set passwordInvalid flag to repeat procedure
			passwordInvalid = 1;
		}
	} while (passwordInvalid); // repeat as long as the password is invalid
}

