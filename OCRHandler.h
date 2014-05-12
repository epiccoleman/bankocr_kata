#ifndef OCRHANDLER_H
#define OCRHANDLER_H
#include <string>


class OCRHandler {

public:
	
	//OCRHandler();

	std::string convert( std::string linesToConvert[] );
	char digitToChar ( std::string DigitArray[] );
	std::string changeToLine (std::string DigitArray[] );
	char matchChar( std::string cell);

	bool validate (std::string numberToCheck);
	int calculateChecksum( std::string accountNumber);


private:


};


#endif