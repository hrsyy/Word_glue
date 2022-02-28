#include "Glue.h"

/*TODO*/
/*
// Основные проблемы
 * Медленная работа 
 * Отсутствует описание работы некоторых модулей 
 * При усппешном выводе "съедается" первый  элемент второго слова
*/

//Generates a number from 0 to 67773
int Glue::GenerateNumber()
{
	std::random_device rd;
	std::default_random_engine gen{ rd() };
	std::uniform_int_distribution<> dist(0, 67773);

	return MaxStringLength = dist(gen);
}


//Skips the required number of lines in the file in GetFirstWord()
//Participates in the search for the required word in GetSecondWord()
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

	TruncateWord(ConnectedWord, ConnectedWordCuttedPart, ConnectedWordCuttedPartSize);
}


//Reduces the number of characters in a word depending on the size of the word
void Glue::TruncateWord(std::string& Word, std::string& WordShort, int& WordShotSize)
{
	WordSize = Word.size();

	if (WordSize < 10)
	{
		WordShotSize = WordSize / 2;
	}
	else
	{
		WordShotSize = 4;
	}

	PassSigns = WordSize - WordShotSize;
	WordShort = Word.substr(PassSigns);
}


//In progress
void Glue::GetSecondWord()
{
	std::fstream dictionary_file(L"dictionary.txt", std::ios::in);

	if (dictionary_file.is_open())
	{
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

		if (!dictionary_file.eof())
		{
			TruncateWord(ConnectingWord, ConnectingWordCuttedPart, ConnectingWordCuttedPartSize);

			GLUEWORD();

			dictionary_file.close();
		}
		else
		{
			std::cout << "No result let's try again!";
		}
	}
	else
	{
		std::cout << "File is not open!\n";
	}
}


void Glue::GLUEWORD()
{
	if (ConnectedWordCuttedPart.std::string::compare(ConnectingWord))
	{

		std::cout << ConnectedWord << "\t" << ConnectedWordCuttedPart << std::endl;
		std::cout << ConnectingWord << "\t" << ConnectingWordCuttedPart << std::endl;
		ConnectedWord += ConnectingWordCuttedPart;
		std::cout << ConnectedWord << std::endl << std::endl;
	}
}