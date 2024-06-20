#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef char* (*shiftChar_ptr_t)(char*, int);

class CaesarCifer
{
public:
    CaesarCifer();
    ~CaesarCifer();
    bool Encrypt(char* inputFile, char* outputFile, int shift);
    bool Decrypt(char* inputFile, char* outputFile, int shift);

private:
    HINSTANCE handle;
    shiftChar_ptr_t shiftChar_ptr;
    size_t size;
    bool shiftFileContents(char* inputFile, char* outputFile, int shift);

};