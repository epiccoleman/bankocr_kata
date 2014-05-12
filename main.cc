#include <iostream>
#include <fstream>
#include "OCRHandler.h"

using std::string;
using std::cout;
using std::endl;


int main ( int argc, char **argv ) {
	
	OCRHandler ocrHandler;

	string accountNumberLines[4];
	string accountNumber;

	std::ifstream fileIn("data.txt");
	//std::ofstream fileOut;

	if ( fileIn.is_open() ){
		// cout << "file opened" << endl;
		while ( !fileIn.eof() ){

			// story 1
			for ( int i = 0; i < 4; i++ ){	// get an account number 
				getline( fileIn, accountNumberLines[i] );
				cout << accountNumberLines[i] << endl;
			}

			accountNumber = ocrHandler.convert( accountNumberLines );
			cout << endl << accountNumber << endl;

			// story 2

			cout << "Account #" << accountNumber << " is " << ((ocrHandler.validate(accountNumber) ? "valid." : "invalid.") ) << endl; 

		}
	
	}

	fileIn.close();

	// end main
	return 0;
}