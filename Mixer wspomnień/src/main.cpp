#include <iostream>
#include <random>
#include <ctime>
#include "FilesManagment.h"

using namespace std;

int main()
{
	try
	{
		vector<wstring> files;

		fm::ReadDirectoryWS(fm::GetExecutablePathW(), files, {}, fm::ReadDir_e::fullDir | fm::ReadDir_e::allFiles);

		//cout << "plikow: "<< files.size() << endl;

		wstring wylosowany;
		std::mt19937 silnik{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		std::uniform_int_distribution<> losowacz{ 0, static_cast<int>(files.size() - 1) };
		int losowa = losowacz(silnik);
		wylosowany = files[losowacz(silnik)];
		//cout << "Nr wylosowanego: " << losowa << endl;
		//cout << "wylosowany: " << sm::WSTS(wylosowany) << endl;
		//system("pause");
		
		fm::OpenFileW(wylosowany);
	}
	catch (...)
	{
		cout<< "Wystapil niezydentifikowany problem!" << endl
			<< "Niezydentyfikowany tylko i wylacznie dlatego ze Danielowi nie chcialo sie robic catchy i teraz wiemy tylko ze jest error" << endl
			<< "DZIEKI DANIEL." << endl;
		system("pause");
	}

	return 0;
}