#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
class Storage
{
private:
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;


    int getLastID();
    int checkFile(string attempt, const char* p_fileName);
    long long encrypt(int p_letter);
    int decrypt(long long p_letter);

public:

    Storage();
    void login();
    void addUser();
    void saveFile(string p_line, const char* p_fileName, const int& id);
};

