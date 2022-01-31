#pragma once

#include <string>
#include <fstream>
#include <random>
#include <iostream>

class Glue
{
public:
	//glue(){}

	//void OpenFile();
	//void CloseFile();
	int GenerateNumber();
	void TruncateWord();
	void GetFirstWord();
	void GetDesiredString(std::fstream& dictionary_file);

private:
	int WordSize, CuttedPartSize, MaxStringLength, MaxDictionaryLength;

	std::string CuttedPart, ConnectedWord, ConnectingWord;

	//std::fstream dictionary_file;

};