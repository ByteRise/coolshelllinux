#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <openssl/types.h>
#include <cmath>

enum class Color {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 0,
    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97
};

void initWslShell(bool& isWslMode);

bool runCommand(const std::string& cmd, bool& isWslMode);
bool checkPurpleExeExists();
void runGitShell(bool& isWslMode);
void installchocolatey();
void runpurpleShell(bool& isWslMode);
void scanShell();
void removeComments(const std::string& inputFile, const std::string& outputFile);
void downloadPackage(const std::string& packageName, bool& isWslMode);
void printComputerName(bool& isWslMode);
bool changeDirectory(const std::string& path);
void removeFile(const std::string& filename);
void printCurrentPath();
void printCurrentDate();
void printCurrentTime();
void echoText(const std::vector<std::string>& tokens);
std::string formatFileSize(uintmax_t size);
std::string getFileIcon(const std::string& extension);
void readFile(const std::string& filepath);
void listFilesInDirectory();
void printSystemInfo();
void clearScreen();
std::string calcHash(const std::string& file_path, const EVP_MD* md_type);
std::vector<std::string> splitString(const std::string& str);

#endif // FUNCTIONS_H
