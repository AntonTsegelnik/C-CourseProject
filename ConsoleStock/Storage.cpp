#include "Storage.h"
int Storage::getLastID()
{
    fstream file;
    file.open("users.dat", ios::in);
    file.seekg(0, ios::end);

    if (file.tellg() == -1)
        return 0;

    string s;

    for (int i = -1; s.find("#") == string::npos; i--)
    {
        file.seekg(i, ios::end);
        file >> s;
    }

    file.close();
    s.erase(0, 4);

    int id;
    istringstream(s) >> id;

    return id;
}
int Storage::checkFile(string attempt, const char* p_fileName)
{
    string line;
    fstream file;

    string currentChar;
    long long eChar;

    file.open(p_fileName, ios::in);

    while (1)
    {
        file >> currentChar;
        if (currentChar.find("#ID:") != string::npos)
        {
            if (attempt == line)
            {
                file.close();
                currentChar.erase(0, 4);
                int id;
                istringstream(currentChar) >> id;
                return id;
            }
            else
            {
                line.erase(line.begin(), line.end());
            }
        }
        else
        {
            istringstream(currentChar) >> eChar;
            line += (char)decrypt(eChar);
            currentChar = "";
        }

        if (file.peek() == EOF)
        {
            file.close();
            return 0;
        }
    }
}
long long Storage::encrypt(int p_letter)
{
    return powf(p_letter, 5) * 4 - 14;
}
int Storage::decrypt(long long p_letter)
{
    return powf((p_letter + 14) / 4, 1 / 5.f);
}
Storage::Storage()
{
    accessGranted = 0;
}
void Storage::login()
{
    cout << "Логин:";
    cin >> userNameAttempt;

    int usrID = checkFile(userNameAttempt, "users.dat");
    if (usrID != 0)
    {
        cout << "Пароль:";
        cin >> passwordAttempt;

        int pwdID = checkFile(passwordAttempt, "pswds.dat");
        if (usrID == pwdID)
        {
            cout << "Добро Пожаловать! \n" << endl;;
            //login();

        }
        else
        {
            cout << "Неверный пароль" << endl;
            login();
        }
    }
    else
    {
        cout << "Хорошая попытка:)\n Такого пользователя не существует" << endl;
        login();
    }
}
void Storage::addUser()
{
    string username;
    string password;
    cout << "Создать логин:";
    cin >> username;
    cout << endl;
    cout << "Создать пароль:";
    cin >> password;
    if (checkFile(username, "users.dat") != 0)
    {
        cout << "Это имя пользователя недоступно." << endl;
        return;
    }

    int id = 1 + getLastID();
    saveFile(username, "users.dat", id);
    saveFile(password, "pswds.dat", id);
}
void Storage::saveFile(string p_line, const char* p_fileName, const int& id)
{
    fstream file;
    file.open(p_fileName, ios::app);
    file.seekg(0, ios::end);

    if (file.tellg() != 0) {
        file << "\n";
    }

    file.seekg(0, ios::beg);

    for (int i = 0; i < p_line.length(); i++)
    {
        file << encrypt(p_line[i]);
        file << "\n";
    }

    file << "#ID:" << id;
    file.close();
}