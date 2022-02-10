#pragma once

#include <string>
#include <fstream>
#include <random>
#include <iostream>

class Glue
{
public:
	Glue() 
	{
		GetFirstWord();
		GetSecondWord();
	}

	void GLUEWORD();
private:
	int GenerateNumber();
	void GetFirstWord();
	void GetSecondWord();
	void GetDesiredString(std::fstream& dictionary_file, std::string& Word);
	void TruncateWord(std::string& Word, std::string& WordShort, int& WordShotSize);

	int WordSize, ConnectedWordCuttedPartSize, ConnectingWordCuttedPartSize, MaxStringLength, MaxDictionaryLength, PassSigns;
	const int maxLength = 67773;

	std::string ConnectedWordCuttedPart, ConnectingWordCuttedPart, ConnectedWord, ConnectingWord;
};