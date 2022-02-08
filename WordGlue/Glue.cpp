#include "Glue.h"


int Glue::GenerateNumber()
{
	std::random_device rd;
	std::default_random_engine gen{ rd() };
	std::uniform_int_distribution<> dist(0, 67773);

	return MaxStringLength = dist(gen);
}


void Glue::GetDesiredString(std::fstream& dictionary_file, std::string& Word)
{
	char* desiredString = new char[MaxStringLength];
	dictionary_file.getline(desiredString, MaxStringLength);
	Word = desiredString;

	delete[] desiredString;
}


void Glue::GetFirstWord()
{
	std::fstream dictionary_file(L"dictionary.txt", std::ios::in);

	GenerateNumber();

	if (dictionary_file.is_open())
	{
		int StringsToSkip = MaxStringLength - 1;

		for (int i = 0; i < StringsToSkip; i++)
		{
			char* temp = new char[MaxStringLength];
			dictionary_file.getline(temp, MaxStringLength);
			delete[] temp;
		}

		GetDesiredString(dictionary_file, ConnectedWord);

		dictionary_file.close();
	}
	else
	{
		std::cout << "FILE IS NOT OPEN!";
	}
}


void Glue::TruncateWord()
{
	WordSize = ConnectedWord.size();

	if (WordSize < 10)
	{
		ConnectedWordCuttedPartSize = WordSize / 2;
	}
	else
	{
		ConnectedWordCuttedPartSize = 4;
	}

	PassSigns = WordSize - ConnectedWordCuttedPartSize;
	ConnectedWordCuttedPart = ConnectedWord.substr(PassSigns);
}

//In progress
void Glue::GetSecondWord()
{
	std::fstream dictionary_file(L"dictionary.txt", std::ios::in);

	if (dictionary_file.is_open())
	{
		std::cout << "File is open!\n";

		for (int i = 0; i != maxLength; i++)
		{
			GetDesiredString(dictionary_file, ConnectingWord);
			
			ConnectingWordCuttedPart = ConnectingWord.substr(0, ConnectedWordCuttedPartSize);
			
			if (ConnectedWordCuttedPart.std::string::compare(ConnectingWordCuttedPart))
			{
				continue;
			}
			else if (!ConnectedWordCuttedPart.std::string::compare(ConnectingWordCuttedPart))
			{
				break;
			}
		}


		WordSize = ConnectingWord.size();

		if (WordSize < 10)
		{
			ConnectingWordCuttedPartSize = WordSize / 2;
		}
		else
		{
			ConnectingWordCuttedPartSize = 4;
		}

		PassSigns = WordSize - ConnectingWordCuttedPartSize;
		ConnectingWordCuttedPart = ConnectingWord.substr(PassSigns);
		//ConnectingWordCuttedPart = ConnectingWord.substr(ConnectedWordCuttedPartSize);
	}
	else
	{
		std::cout << "File is not open!\n";
	}
}


void Glue::print()
{
	std::cout << ConnectedWord << "\t" << ConnectedWordCuttedPart << std::endl;

	std::cout << ConnectingWord << "\t" << ConnectingWordCuttedPart << std::endl;
	
}



void Glue::GLUEWORD()
{
	ConnectedWord += ConnectingWordCuttedPart;

	print();
}