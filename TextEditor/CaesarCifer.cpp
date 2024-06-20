#include "CaesarCifer.h"

CaesarCifer::CaesarCifer()
{
    /*handle = LoadLibrary(TEXT("CaesarCifer.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) 
    {
        std::cout << "DLL not found\n";
        return;
    }

    shiftChar_ptr = (shiftChar_ptr_t)GetProcAddress(handle, "shiftChars");
    if (shiftChar_ptr == nullptr) 
{
        std::cout << "Function not found\n";
        return;
    }*/
    size = 1024;
}

CaesarCifer::~CaesarCifer() 
{
    FreeLibrary(handle);
}

bool CaesarCifer::Encrypt(char* inputFile, char* outputFile, int shift) 
{
    return shiftFileContents(inputFile, outputFile, shift);
}

bool CaesarCifer::Decrypt(char* inputFile, char* outputFile, int shift) 
{
    return shiftFileContents(inputFile, outputFile, -shift);
}

char* CaesarCifer::shiftChars(char* text, int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        int shiftedChar = (int)text[i];
        if ((shiftedChar >= 'a' && shiftedChar <= 'z') || (shiftedChar >= 'A' && shiftedChar <= 'Z'))
        {
            shiftedChar += shift;

            if ((shiftedChar > 'Z' && text[i] < 'a') || shiftedChar > 'z')
            {
                shiftedChar -= 26;
            }
            else if ((shiftedChar < 'a' && text[i] >= 'a') || shiftedChar < 'A')
            {
                shiftedChar += 26;
            }
            text[i] = (char)shiftedChar;
        }
    }
    return text;
}

bool CaesarCifer::shiftFileContents(char* inputFile, char* outputFile, int shift)
{
    char* chunk = new char[size];
    char* newText = new char[size];

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open() || !fout.is_open())
	{
		cout << "Error opening file\n";
		return false;
	}

    while (fin)
    {
        fin.read(chunk, size);
        size_t count = fin.gcount();
        if (!count)
            break;
        newText = shiftChars(chunk, shift);
        fout.write(newText, count);
    }

    return true;
}