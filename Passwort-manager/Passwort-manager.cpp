#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

int main() {
	char altesPasswort[80], inputBuf[80], confBuf[80];
	int passwordInvalid = 0;
	strcpy_s(altesPasswort, "an0th3rD@yAn0th3r$");
	regex lower{ "[a-zä-ü]+" };
	regex upper{ "[A-ZÄ-Ü]+" };
	regex numeric{ "[0-9]+" };
	regex special{ "[!§\\$%&/\\(\\)=\\?#\\+'´`\\^°~\\*\\[\\]-_:<>;\\\\.\\\\|\\\"]+" };


	// read and compare old password
	do {
		cout << "Bitte geben Sie das alte Passwort ein: ";
		cin.getline(inputBuf, 80);

		// check if password is invalid
		if ((strcmp(inputBuf, altesPasswort) != 0)) {
			cout << "Das Passwort stimmt nicht, bitte erneut versuchen" << "\n\n";
			passwordInvalid = 1;
		}
		else {
			passwordInvalid = 0;
			cout << "Passwort korrekt!" << endl;
		}

	} while (passwordInvalid);

	do {
		// read inputs for new password
		cout << "Bitte geben Sie das neue Passwort ein: ";
		cin.getline(inputBuf, 80);
		cout << "Bitte wiederholen Sie das neue Passwort: ";
		cin.getline(confBuf, 80);

		// check for password rules, alphanumeric mixed case 
		// with special char, min length 8 and equal inputs
		string passwordError = (!regex_search(inputBuf, upper)) ? "- Passwort braucht mindestens einen grossen Buchstaben\n" : "";
		passwordError.append((!regex_search(inputBuf, lower)) ? "- Passwort braucht mindestens einen kleinen Buchstaben\n" : "");
		passwordError.append((!regex_search(inputBuf, numeric)) ? "- Passwort braucht mindestens eine Zahl\n" : "");
		passwordError.append((!regex_search(inputBuf, special)) ? "- Passwort braucht Sonderzeichen\n" : "");
		passwordError.append((strlen(inputBuf) < 8) ? "- Passwort muss mindestens 8 Zeichen lang sein\n" : "");
		passwordError.append((strcmp(inputBuf, confBuf) != 0) ? "- Passwoerter sind nicht gleich\n" : "");
		// output concatenated errors
		cout << "\n\nFEHLER:\n" << passwordError << "\n\n\n";
		
		// check if errors occured
		if (passwordError.empty()) {
			// if no errors occured copy input to password
			strcpy_s(altesPasswort, inputBuf);
			cout << "Das Passwort wurde erfolgreich aktualisiert!" << endl;
			cout << "Das Passwortet lautet nun " << altesPasswort << endl;
			passwordInvalid = 0;
		}
		else {
			passwordInvalid = 1;
		}
	} while (passwordInvalid);
	return 0;
}