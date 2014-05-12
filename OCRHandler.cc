#include "OCRHandler.h"
#include <iostream>

/*
OCRHandler::OCRHandler() {

}*/

std::string OCRHandler::convert( std::string linesToConvert[] ) {
	char convertedAccountNum[10];
	std::string oneDigit[4];

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 4 ; j++){
			oneDigit[j] = linesToConvert[j].substr(i*3, 3);
		}
		convertedAccountNum[i] = digitToChar(oneDigit);
	}

	convertedAccountNum[9] = '\0';
	return std::string(convertedAccountNum);

}

char OCRHandler::digitToChar( std::string digitArray[] ){
	std::string oneLine = changeToLine(digitArray); 
	return matchChar(oneLine);
}

std::string OCRHandler::changeToLine( std::string digitArray[] ){
	
	std::string aLine = "";
	for (int i = 0; i < 3; i++){
		aLine += digitArray[i];
	}

	return aLine;
}

char OCRHandler::matchChar( std::string cell ) {
	if        ( cell == " _ | ||_|") {
		return '0';
	} else if ( cell == "     |  |") {
		return '1';
	} else if ( cell == " _  _||_ ") {
		return '2';
	} else if ( cell == " _  _| _|") {
		return '3';
	} else if ( cell == "   |_|  |") {
		return '4';
	} else if ( cell == " _ |_  _|") {
		return '5';
	} else if ( cell == " _ |_ |_|") {
		return '6';
	} else if ( cell == " _   |  |") {
		return '7';
	} else if ( cell == " _ |_||_|") {
		return '8';
	} else if ( cell == " _ |_| _|") {
		return '9';
	} else {
		return '?';
	}
}


bool OCRHandler::validate( std::string numberToCheck ) {
	
	return (calculateChecksum( numberToCheck ) % 11 == 0);
}

int OCRHandler::calculateChecksum( std::string accountNumber ) {

	int checksum = 0;

	// reverses accountNumber
	accountNumber = std::string ( accountNumber.rbegin(), accountNumber.rend());

	for ( int i = 0; i < 9; i++ ) {
		int convertedChar = accountNumber[i] - '0'; //converts char to int

		checksum += (i + 1) * convertedChar;
	}

	return checksum;
}