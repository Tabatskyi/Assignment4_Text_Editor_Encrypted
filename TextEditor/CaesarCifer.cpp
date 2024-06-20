#include "CaesarCifer.h"

CaesarCifer::CaesarCifer()
{
    handle = LoadLibrary(TEXT("CaesarCifer.dll"));
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
    }
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

bool CaesarCifer::shiftFileContents(char* inputFile, char* outputFile, int shift) 
{
    ChunkLoad loader(inputFile, 1024);
    ChunkSave saver(outputFile);

    char* textChunk;
    while ((textChunk = loader.LoadChunk()) != NULL) 
    {
        char* shiftedText = shiftChar_ptr(textChunk, shift);
        if (!saver.SaveChunk(shiftedText)) 
        {
            std::cout << "Error saving chunk.\n";
            return false;
        }
    }
    return true;
};