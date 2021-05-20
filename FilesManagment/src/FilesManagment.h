#ifndef FILESMANAGMENT_H
#define FILESMANAGMENT_H

#include <string>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <ostream>
#include <istream>
#include <optional>
#include <type_traits>

///-----------------------------------------------------------------------------------
//UWAGA ZEBY FILESMANAGMENT DZIALALO MUSISZ DODAC DO ROZWIAZANIA TEZ STRINGMANAGMENT!!!
///-----------------------------------------------------------------------------------
#include "StringManagment.h"

namespace fm
{
	constexpr uint_least8_t LOG_SLEEP = 100;

	struct Error_t
	{
		std::string what;
		std::string What()
		{	return what;	}
	};

	using ReadDirectoryFlag_t = uint_least16_t;

	enum class ReadDir_e : ReadDirectoryFlag_t
	{
		nothing = 0,
		fullDir = 1,
		includeDir = 2,
		allFiles = 4
	};

	fm::ReadDir_e operator|(const fm::ReadDir_e&, const fm::ReadDir_e&);
	fm::ReadDir_e operator&(const fm::ReadDir_e&, const fm::ReadDir_e&);

	/**
		Sluzy do filtrowania kontenerow z nazwami plikow podajac rozszerzenia jakie maja zostac
		Najlepiej utworzyc lamdbe ktora zwraca wywolanie tej funkcji dla stringa i wrzucic j¹ jako funkcje decyduj¹c¹ czy wyrzucic plik z kontenera
		@param nazwa do sprawdzenia poprawnosci
		@param wektor rozszerzen do zachowania | FORMAT: .*
		@return zwraca true jesli string [arg1] nie ma rozszerzenia z wektora [arg2]
	*/
	bool FilesFilter(const std::string& s,  const std::vector<std::string>& extension);
	bool FilesFilter(const std::wstring& s, const std::vector<std::string>& extension);


	/**
		OPIS W FMtemplates.h
	*/
	template<typename T>
	void ReadDirectory(const std::string, std::vector<T>&, const std::vector<std::string> & = {}, ReadDir_e = ReadDir_e::nothing);

	/**
		OPIS W FMtemplates.h
	*/
	template<typename T>
	void ReadDirectoryWS(const std::wstring, std::vector<T>&, const std::vector<std::string> & = {}, ReadDir_e = ReadDir_e::nothing);

	/**
		Otwiera binarnie plik i czyta jego zawartosc
		@param sciezka do pliku do otworzenia
		@param maksymalny rozmiar pliku [wielkosc bufora] | jesli plik jest wiekszy rzuci wyjatek
		@return zwraca dane binarne z pliku
	*/
	std::string ReadFile(std::string name, const unsigned long long rozmiar);

	/**
		OTworzy plik i wpisuje tam binarne dane
		@param sciezka do pliku do utworzenia
		@param binarne dane do wpisania do pliku
		@return nic nie zwraca
	*/
	void MakeFile(std::string name, std::string data);

	/**
		Otworzy plik za pomoca domyslnego programu dla tego typu plikow
		@param nazwa pliku do otworzenia
		@return nic nie zwraca
	*/
	void OpenFile(std::string name);
	/**
		OpenFile dla nazw plikow okreslonych jako wstringi
	*/
	void OpenFileW(std::wstring name);

	/**
		Kopiuje plik
		@param sciezka do pliku ktory mamy skopiowac
		@param sciezka do pliku ktory ma powstac
		@return nic nie zwraca
	*/
	void CopyFile(std::string nameIn, std::string nameOUT);
	/**
		CopyFile z opcja wypisania logow
	*/
	void CopyFileLog(std::string nameIn, std::string nameOUT, std::ostream&);
	/**
		CopyFile dla nazw plikow okreslonych jako wstringi
	*/
	void CopyFileW(std::wstring nameIn, std::wstring nameOUT);
	/**
		CopyFileW z opcja wypisania logow
	*/
	void CopyFileWLog(std::wstring nameIn, std::wstring nameOUT, std::wostream&);

	/**
		przenosi plik
		@param sciezka do pliku ktory mamy przenisc
		@param sciezka do pliku ktory ma powstac
		@return nic nie zwraca
	*/
	void MoveFile(std::string nameIn, std::string nameOUT);
	/**
		MoveFile z opcja wypisania logow
	*/
	void MoveFileLog(std::string nameIn, std::string nameOUT, std::ostream&);
	/**
		MoveFile dla nazw plikow okreslonych jako wstringi
	*/
	void MoveFileW(std::wstring nameIn, std::wstring nameOUT);
	/**
		MoveFileW z opcja wypisania logow
	*/
	void MoveFileWLog(std::wstring nameIn, std::wstring nameOUT, std::wostream&);

	/**
		Zmienia nazwe pliku
		@param sciezka do pliku
		@param nowa nazwa
		@return nic nie zwraca
	*/
	void RenameFile(std::string oldName, std::string newName);
	/**
		RenameFile z opcja wypisania logow
	*/
	void RenameFileLog(std::string oldName, std::string newName, std::ostream&);
	/**
		RenameFile dla nazw plikow okreslonych jako wstringi
	*/
	void RenameFileW(std::wstring oldName, std::wstring newName);
	/**
		RenameFileW z opcja wypisania logow
	*/
	void RenameFileWLog(std::wstring oldName, std::wstring newName, std::wostream&);

	/**
		pobiera aktualna sciezke w jakiej znajduje sie plik .exe
		@return sciezka w stringu
	*/
	std::string GetExecutablePath();

	/**
		pobiera aktualna sciezke w jakiej znajduje sie plik .exe
		@return sciezka w wstringu
	*/
	std::wstring GetExecutablePathW();


	#include "FMtemplates.h"
}


#endif
