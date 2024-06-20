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
    ChunkLoad loader(inputFile, 1024);
    ChunkSave saver(outputFile);

    char* textChunk;
    while ((textChunk = loader.LoadChunk()) != NULL) 
    {
        //char* shiftedText = shiftChar_ptr(textChunk, shift);
        char* shiftedText = shiftChars(textChunk, shift);
        if (!saver.SaveChunk(shiftedText)) 
        {
            std::cout << "Error saving chunk.\n";
            return false;
        }
    }
    return true;
};