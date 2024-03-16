#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/sysinfo.h>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <openssl/evp.h>

using namespace std;

void initWslShell(bool& isWslMode) {
    isWslMode = !isWslMode;
    cout << "WSL Shell " << (isWslMode ? "activated." : "deactivated.") << endl;
}

bool runCommand(const string& cmd, bool& isWslMode) {
    int result = system(cmd.c_str());
    if (result != 0) {
        cerr << "Command failed: " << cmd << endl;
        return false;
    }
    return true;
}

bool checkPurpleExeExists() {
    cout << "On Linux, checking for purple.exe is not necessary. Skipping..." << endl;
    return true;
}

void runGitShell(bool& isWslMode) {
    string gitCmd;
    cout << "Entering git-shell mode. Type 'exit' to leave." << endl;
    while (true) {
        cout << "coolshell@git" << "> ";
        getline(cin, gitCmd);

        if (gitCmd == "exit") {
            break;
        }
        else if (gitCmd == "help") {
            cout << "Commands:" << endl;
            cout << "exit - Exit git-shell mode" << endl;
            cout << "help - Show this help message" << endl;
        }

        runCommand("git " + gitCmd, isWslMode);
    }
}

void runpurpleShell(bool& isWslMode) {
    cout << "On Linux, purple-shell now is not supported. Exiting..." << endl;
}

void scanShell() {
    cout << "On Linux, scan-shell now is not supported. Exiting..." << endl;
}

void installchocolatey() {
    cout << "On Linux, Chocolatey now is not available. Exiting..." << endl;
}

void printComputerName(bool& isWslMode) {
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        cout << "Computer Name: " << buffer.nodename << endl;
    }
}

void printSystemInfo() {
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        cout << "Operating System: " << buffer.sysname << " " << buffer.release << " " << buffer.version << endl;
    }
    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        cout << "Total RAM: " << fixed << setprecision(2) << si.totalram / (1024 * 1024) << " MB" << endl;
        cout << "Number of Processors: " << si.procs << endl;
    }
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

vector<string> splitString(const string& str) {
    istringstream iss(str);
    vector<string> tokens;
    string token;
    while (iss >> quoted(token)) {
        tokens.push_back(token);
    }
    return tokens;
}

string calcHash(const string& file_path, const EVP_MD* md_type) {
    cout << "Calculating hash on Linux is not implemented. Exiting..." << endl;
    return "";
}

void removeComments(const std::string& inputFile, const std::string& outputFile) {
    cout << "Removing comments on Linux is not implemented. Exiting..." << endl;
}

void downloadPackage(const string& packageName, bool& isWslMode) {
    cout << "On Linux, package management is handled differently. Skipping..." << endl;
}

void printCurrentPath() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        cout << "Current Path: " << cwd << endl;
    }
}

void printCurrentDate() {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    cout << "Current Date: " << put_time(timeinfo, "%d-%m-%Y") << endl;
}

void printCurrentTime() {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    cout << "Current Time: " << put_time(timeinfo, "%H:%M:%S") << endl;
}

void echoText(const vector<string>& tokens) {
    for (size_t i = 1; i < tokens.size(); i++) {
        cout << tokens[i] << " ";
    }
    cout << endl;
}

string formatFileSize(uintmax_t size) {
    const char* sizes[] = { "B", "KB", "MB", "GB", "TB" };
    int order = 0;
    double dblSize = static_cast<double>(size);

    while (dblSize >= 1024 && order < (sizeof(sizes) / sizeof(sizes[0])) - 1) {
        order++;
        dblSize /= 1024;
    }

    stringstream fileSizeStream;
    fileSizeStream << fixed << setprecision(2) << dblSize << " " << sizes[order];
    return fileSizeStream.str();
}

string getFileIcon(const string& extension) {
    cout << "Getting file icon on Linux is not implemented. Returning default." << endl;
    return "🗁";
}

void readFile(const string& filepath) {
    ifstream file(filepath);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cerr << "Unable to open file: " << filepath << endl;
    }
}

void listFilesInDirectory() {
    for (const auto& entry : filesystem::directory_iterator(filesystem::current_path())) {
        auto filepath = entry.path();
        auto filename = filepath.filename().string();
        auto filesize = entry.file_size();
        // size файла
        string readable_size = formatFileSize(filesize);
        // get file icon
        string icon = getFileIcon(filepath.extension().string());

        cout << icon << " " << filename << " | " << readable_size << endl;
    }
}
