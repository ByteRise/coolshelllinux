#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <thread>
#include <sstream>
#include <regex>
#include <iomanip>
#include "functions.h"


using namespace std;

bool isWslMode = false;


int main() {
    string input;
    while (true) {
        string path = filesystem::current_path().generic_string();
        replace(path.begin(), path.end(), '\\', '/');

        if (isWslMode) {
            cout << "coolshell@wsl>" << "" << path << "> ";
        }
        else {
            cout << "coolshell@main>" << path << "> ";
        }
        getline(cin, input);

        auto tokens = splitString(input);
        if (tokens.empty()) continue;

        string command = tokens[0];
        if (command == "help") {
            cout << "Available commands:\n";
            cout << "  git         Inits a git-shell\n";
            cout << "  cd          Changes path\n";
            cout << "  rm          Removes the file without annoying /s /q\n";
            cout << "  ls          Lists files in current directory\n";
            cout << "  rf          Prints the content of the file\n";
            cout << "  clear       Clears the screen\n";
            cout << "  pwd         Prints current path\n";
            cout << "  date        Prints current date\n";
            cout << "  time        Prints current time\n";
            cout << "  dc          Deletes comments in code\n";
            cout << "  hostname    Prints current computer name\n";
            cout << "  echo        Prints text\n";
            cout << "  download    Downloads a package\n";
            cout << "  takeowner   Changes owner of file and give full perms\n";
            cout << "  wsl         Inits a wsl-shell\n";
            cout << "  chocoinst   Installs chocolatey packages\n";
            cout << "  purple      Inits a purple-shell\n";
            cout << "  sudo        Sudo mode\n";
            cout << "  hash        Prints hashes of the file\n";
            cout << "  info        Prints info about system\n";
            cout << "  help        Prints this help message\n";
            cout << "  scan        Scanning network utility\n";
            cout << "  exit        Exits the shell\n";
        }
        else if (command == "exit") {
            break;
        }
        else if (command == "git") {
            runGitShell(isWslMode);
        }
        else if (command == "chocoinst") {
            installchocolatey();
        }
        else if (command == "purple") {
            runpurpleShell(isWslMode);
        }
        else if (command == "scan") {
            scanShell();
        }
        else if (command == "dc") {
            removeComments(tokens[1], tokens[2]);
        }
        else if (command == "shifr") {

        }
        else if (command == "rf" && tokens.size() > 1) {
            string tokenString = "";
            for (const auto& token : tokens) {
                if (token != "rf") {
                    tokenString += token + " ";
                }
            }
            readFile(tokenString);
        }
        else if (command == "ls") {
            listFilesInDirectory();
        }
        else if (command == "clear") {
            clearScreen();
        }
        else if (command == "pwd") {
            printCurrentPath();
        }
        else if (command == "date") {
            printCurrentDate();
        }
        else if (command == "time") {
            printCurrentTime();
        }
        else if (command == "hostname") {
            printComputerName(isWslMode);
        }
        else if (command == "echo") {
            echoText(tokens);
        }
        else if (command == "download" && tokens.size() > 1) {
            downloadPackage(tokens[1], isWslMode);
        }
        else if (command == "wsl") {
            initWslShell(isWslMode);
        }
        else if (command == "info") {
            printSystemInfo();
        }
        else {
            string tokenString = "";
            for (const auto& token : tokens) {
                tokenString += token + " ";
            }
            runCommand(tokenString, isWslMode);
        }
    }
    return 0;
}