// ceaserCipher.cpp : Defines the entry point for the console application.
// Implementation of Ceaser Cipher, user can encrypt a message or decrpyt a message with a key

#include "stdafx.h"
#include <iostream> // I/O
#include <sstream> // for string stream
using namespace std;


const string encryptMessage(const string , int); // encrypts the string given, using the key
const string decryptMessage(const string, int); // decrypts the string given, using the key
bool checkKey(int); // to check if user entered a correct key

int main()
{

	char choice;
	int key;
	string orignalText, cipherText;

	cout << "------- CEASER CIPHER -------" << endl;
	cout << " Choose to Encrpyt a string or Decrpyt a string: " << endl;
	cout << " E - ENCRYPT A STRING			" << endl;
	cout << " D - DECRYPT A STRING			" << endl;
	cin >> choice;

	toupper(choice);

	switch (choice)
	{
		case 'E':

			cout << "Enter the text that needs to be encrypted: " << endl;
			cin.ignore();
			getline(cin, orignalText, '\n');
			cout << "Enter the key for the cipher (1-25): " << endl;
			cin >> key;
			
			if (checkKey(key)) {

				cipherText = encryptMessage(orignalText, key);
				cout << "The orignal text - > " + orignalText << endl;
				cout << "The key used - > " << key << endl;
				cout << "The new text - > " << cipherText << endl;
	


			}

			else
				cout << "ERROR, key has to be 1 - > 25 !!! try again." << endl;

			break;

		case 'D':

			cout << "Enter the encrypted text: " << endl;
			cin.ignore();
			getline(cin, cipherText, '\n');
			cout << "Enter the key to the encryption: " << endl;
			cin >> key;

			if (checkKey(key)) {
				
				orignalText = decryptMessage(cipherText, key);
				cout << "The encrypted text given -> " + cipherText << endl;
				cout << "The key given -> " << key << endl;
				cout << "The decrypted text - > " + orignalText << endl;
			
			}

			else 
				cout << "ERROR, key has to be 1 - > 25 !!! try again." << endl;

			break;

		default:
			cout << "ERROR, wrong choice!" << endl;
			break;
	}


	

    return 0;
}

const string encryptMessage(const string ogText, int key) {

	stringstream cipherStream;
	int x;
	
	for (auto &c : ogText) { // auto = intializes type automatically by what its init too 
		
		x = c + key; // shifts the char 

		if (c >= 'A' && c <= 'Z') {
		
			x = (x > 'Z') ? ('A' + (x - 1) - 'Z') : x; // for shifting, if shifted out of bounds , code re-adjusts to put back in A - Z range
		
		}

		else if (c >= 'a' && c <= 'z') { // sames as above but for lower case
			
			x = (x > 'z') ? ('a' + (x - 1) - 'z') : x;
		
		}
		
		cipherStream << char(x); // changes x to char then inserts into string stream object
	
	}

	return cipherStream.str(); // returns the string 

}

const string decryptMessage(const string encText, int key) {

	stringstream plainStream;
	int x;

	for (auto &c : encText) {
		
		x = c - key; // flipped of enc because we are shifting back to og char
	
		if (c >= 'A' && c <= 'Z') { // check if in range
		
			x = (x < 'A') ? ('Z' - ('A' - (x + 1))) : x; // re-adjusting x if after shifing makes it less than A/a 
		
		}
		
		else if (c >= 'a' && c <= 'z') { // same as above but for lower case
			
			x = (x < 'a') ? ('z' - ('a' - (x + 1))) : x;
		
		}
		
		plainStream << char(x); 
	
	}


	return plainStream.str();

}




bool checkKey(int key)
{

	if (key >= 1 && key <= 25) {
		
		return true;
	
	}

	else
	{
		return false;
	}


}

