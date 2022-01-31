#include "Glue.h"


int Glue::GenerateNumber()
{
	std::random_device rd;
	std::default_random_engine gen{ rd() };
	std::uniform_int_distribution<> dist(0, 67773);

	return MaxStringLength = dist(gen);
}


void Glue::GetDesiredString(std::fstream& dictionary_file)
{
	char* desiredString = new char[MaxStringLength];
	dictionary_file.getline(desiredString, MaxStringLength);
	ConnectedWord = desiredString;

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

		GetDesiredString(dictionary_file);

		std::cout << ConnectedWord;

		dictionary_file.close();
	}
	else
	{
		std::cout << "FILE IS NOT OPEN!";
	}
}


void Glue::TruncateWord()
{

}