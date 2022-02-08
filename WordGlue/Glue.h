#pragma once

#include <string>
#include <fstream>
#include <random>
#include <iostream>

class Glue
{
public:
	int GenerateNumber();
	void TruncateWord();
	void GetFirstWord();
	void GetSecondWord();
	void GetDesiredString(std::fstream& dictionary_file, std::string& Word);
	void print();
	void GLUEWORD();

private:
	int WordSize, ConnectedWordCuttedPartSize, ConnectingWordCuttedPartSize, MaxStringLength, MaxDictionaryLength, PassSigns;
	const int maxLength = 67773;

	std::string ConnectedWordCuttedPart, ConnectingWordCuttedPart, ConnectedWord, ConnectingWord;
};