#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <windows.h>
using namespace std;

void Register(string action);
void writeTeacherInfo(string name, string lastname);
bool Search(string TenderNumber);
bool Check_h(string name);
bool SearchName(string Name);
void Edit(string action);
void MONTH2(string report1);
string CheckCode(string check);
void Reaplace(string name1);
void CheckChange(string name, bool b);
void Checking1(string action, bool b);
void checkEnter(string code, bool b);
void Checking(string code, string enter);
void Enter(string code);
void itsok2(string enter, string exit, string code, string year1, string year2, string month1, string month2, string day1, string day2, string action);
bool TimeTable(int hour1, int min1, int sec1, string khoroj, string month1, string day1, string year1, string month2, string day2, string year2);
void Exit(string Code);
void listExtra(string code, string action);
void Check_Enter();
void Report(string action);
void behtarin(bool check);
void Current();
void Current2(string Codep);
void mojod();
void bihodeh();
void CurrentTeacher();
void allTeachers();
void MONTH3(string report1);
void MONTH();
void MONTH1(string report1);
string CheckChange1(string name);
void bihodeh2(string cc);
void MONTH4(string code, string mon, string sal);
string generateRandomId();
HANDLE hconsol = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    Check_Enter();
    cout << "\nWelcom\n";
    cout << "if you want to use this program for the first time,read the help:)\n";
    while (true)
    {
        string action;
        bool b = true;
        cout << "What Can I Do For You ?\n";
        getline(cin >> ws, action, '\n');
        // taghir dadan be halat kochak harchizi ke migirim...
        transform(action.begin(), action.end(), action.begin(), ::tolower);
        if (action.find("register") != string ::npos)
        {
            Register(action);
        }
        else if (action.find("edit") != string ::npos)
        {
            Edit(action);
        }
        else if (action.find("enter") != string ::npos)
        {
            Checking1(action, b);
        }
        else if (action.find("exit") != string ::npos)
        {
            b = false;
            Checking1(action, b);
        }
        else if (action.find("report") != string ::npos)
        {
            Report(action);
        }
        else if (action.find("nothing") != string ::npos)
        {
            exit(-1);
        }
        else if (action.find("help") != string ::npos)
        {
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you want to register a master,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"register\"" << endl;
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you want to edit the master,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"edit\"" << endl;
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you want to enter,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"enter\"" << endl;
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you want to exit,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"exit\"" << endl;
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you want to get the master report,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"report\"" << endl;
            SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "The Keywords of the reports it has:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\n1.the best\n2.the worst\n3.present\n4.available\n5.number\n6.monthly attendance\n7.unused(enter without exit) "<< endl;
                SetConsoleTextAttribute(hconsol, FOREGROUND_INTENSITY);
            cout << "if you don't want to do anything!,Enter the keyword:";
            SetConsoleTextAttribute(hconsol, FOREGROUND_GREEN);
            cout << "\"nothing\"" << endl;
            SetConsoleTextAttribute(hconsol, 15);
        }
    }
}

// tolid ID baray karbar...
string generateRandomId()
{
    string id = "";
    srand(time(0));
    for (int i = 0; i < 6; i++)
    {
        id += to_string(rand() % 10);
    }
    return id;
}

// register kardan ostad...
void Register(string action)
{
    string check, first;
    string keyword = "register";
    // transform(action.begin(), action.end(), action.begin(), ::tolower);
    size_t found = action.find(keyword);
    if (found != string::npos)
    {
        action.erase(found, keyword.length() + 1);
    }
    if (action != "")
    {
        while (check != "yes" || check != "no")
        {
            cout << "Did you enter your last name? yes OR no :";
            getline(cin >> ws, check, '\n');
            transform(check.begin(), check.end(), check.begin(), ::tolower);
            if (check == "no")
            {
                int p = Check_h(action); // check lastname with out number..
                while (p == false)
                {
                    cout << "Enter your first name without numbers:";
                    getline(cin >> ws, action, '\n');
                    p = Check_h(action);
                }
                string famil = "";
                cout << "Enter your last name:";
                getline(cin >> ws, famil, '\n');
                int c = Check_h(famil); // check lastname with out number..
                while (c == false)
                {
                    cout << "Enter your last name without numbers:";
                    getline(cin >> ws, famil, '\n');
                    c = Check_h(famil);
                }
                string word = action + famil;
                // hazfe space ha...
                word.erase(::remove_if(word.begin(), word.end(), ::isspace), word.end());
                bool k = SearchName(word);
                if (k == true)
                {
                    string f;
                    cout << "Found user!\n";
                    while (f != "yes" || f != "no")
                    {
                        cout << "do you want register again?Yes Or No:";
                        getline(cin >> ws, f, '\n');
                        transform(check.begin(), check.end(), check.begin(), ::tolower);
                        if (f == "yes")
                        {
                            writeTeacherInfo(action, famil);
                            cout << "Registerd!\n";
                            break;
                        }
                        else if (f == "no")
                        {
                            cout << "Not Register!\n";
                            break;
                        }
                    }
                }
                else
                {
                    writeTeacherInfo(action, famil);
                    cout << "Registerd!\n";
                }
            }
            else if (check == "yes")
            {
                string famil = "";
                int c = Check_h(action); // check lastname with out number..
                while (c == false)
                {
                    cout << "Enter your first and last name without numbers:";
                    getline(cin >> ws, action, '\n');
                    c = Check_h(action);
                }
                string word = action;
                word.erase(::remove_if(word.begin(), word.end(), ::isspace), word.end());
                bool k1 = SearchName(word);
                if (k1 == true)
                {
                    string f;
                    cout << "Found user!\n";
                    while (f != "yes" || f != "no")
                    {
                        cout << "do you want register again?Yes Or No:";
                        getline(cin >> ws, f, '\n');
                        transform(check.begin(), check.end(), check.begin(), ::tolower);
                        if (f == "yes")
                        {
                            writeTeacherInfo(action, famil);
                            cout << "Registerd!\n";
                            break;
                        }
                        else if (f == "no")
                        {
                            cout << "Not Registerd!\n";
                            break;
                        }
                    }
                }
                else
                {
                    writeTeacherInfo(action, famil);
                    cout << "Registerd!\n";
                }
            }
            break;
        }
    }
    else
    {
        string famil = "";
        cout << "Enter your first name:";
        getline(cin >> ws, first, '\n');
        int a = Check_h(first); // check name with out number..
        while (a == false)
        {
            cout << "Enter your first name without numbers:";
            getline(cin >> ws, first, '\n');
            a = Check_h(first);
        }
        cout << "Enter your last name:";
        getline(cin >> ws, famil, '\n');
        int c = Check_h(famil); // check lastname with out number..
        while (c == false)
        {
            cout << "Enter your last name without numbers:";
            getline(cin >> ws, famil, '\n');
            c = Check_h(famil);
        }
        string word = first + famil;
        word.erase(::remove_if(word.begin(), word.end(), ::isspace), word.end());
        bool k = SearchName(word);
        if (k == true)
        {
            string f;
            cout << "Found user!\n";
            while (f != "yes" || f != "no")
            {
                cout << "do you want register again?Yes Or No:";
                getline(cin >> ws, f, '\n');
                transform(check.begin(), check.end(), check.begin(), ::tolower);
                if (f == "yes")
                {
                    writeTeacherInfo(first, famil);
                    cout << "registerd!\n";
                    break;
                }
                else if (f == "no")
                {
                    break;
                }
            }
        }
        else
        {
            writeTeacherInfo(first, famil);
            cout << "registerd!\n";
        }
    }
}
void writeTeacherInfo(string name, string lastname)
{
    ofstream file("teachers.txt", ios::app);
    file << name << " " << lastname << "\n";
    string b = generateRandomId();
    bool CheckId = Search(b);
    while (CheckId == true)
    {
        b = generateRandomId();
        CheckId = Search(b);
    }
    file << b << "\n";
    file.close();
}
bool Search(string TenderNumber)
{
    ifstream file("teachers.txt");
    string name;
    string id;
    while (getline(file >> ws, name, '\n'))
    {
        file >> id;
        if (id == TenderNumber)
            return true;
    }
    return false;
    file.close();
}
bool Check_h(string name)
{
    bool isNumber = true;
    for (int i = 0; i < name.length(); i++)
    {
        if (isdigit(name[i]))
        {
            isNumber = false;
            break;
        }
    }
    return isNumber;
}
// asm tekrari...
bool SearchName(string Name)
{
    ifstream file("teachers.txt");
    string name;
    string Duplicate;
    while (getline(file >> ws, name, '\n'))
    {
        file >> Duplicate;
        name.erase(::remove_if(name.begin(), name.end(), ::isspace), name.end());
        if (name == Name)
        {
            return true;
        }
    }
    return false;
    file.close();
}
// virayesh...
void Edit(string action)
{
    string keyword = "edit", check;
    size_t found = action.find(keyword);
    if (found != string::npos)
    {
        action.erase(found, keyword.length() + 1);
    }
    if (action != "")
    {
        string name1 = CheckCode(action);
        cin.ignore();
        if (name1 != "")
            Reaplace(name1);
    }
    else
    {
        string famil = "", first;
        cout << "Enter your Name Or Code:";
        getline(cin >> ws, first, '\n');
        string name1 = CheckCode(first);
        cin.ignore();
        if (name1 != "")
            Reaplace(name1);
    }
}
// jostjo baray edit..
string CheckCode(string check)
{
    int c = 0, count = 0;
    int option, index[100], index1[100];
    string first[100], Code[100], first1[100], last1[100], Code1[100];
    ifstream file("teachers.txt");
    if (!file)
    {
        cout << "can not open!";
        exit(-1);
    }

    while (getline(file >> ws, first[c], '\n'))
    {
        getline(file >> ws, Code[c], '\n');
        c++;
    }

    // jostejo dar halgheh for baray aray first..
    for (int i = 0; i < c; i++)
    {
        if ((first[i].find(check) != string ::npos) || (Code[i].find(check) != string ::npos))
        {
            index1[count] = i;
            index[count] = count;
            count++;
            cout << count << ". " << first[i] << '\t' << Code[i] << endl;
        }
        continue;
    }
    if (count == 0)
    {
        cout << "The desired teachers was not found..!\n";
        return "";
    }
    else
    {
        cout << count << " Number of teachers found.." << endl;
        cout << " Which option do you want?\nnone:-1" << endl;
        cin >> option;
        for (int i = 0; i < count; i++)
        {
            if ((index[i] + 1) == option)
                return Code[index1[i]];
        }
        if (option == -1)
            return "";
    }
    file.close();
}
void Reaplace(string code22)
{
    bool q = true;
    string numi, newName, Number, num;
    ifstream infile("teachers.txt");
    ofstream tempfile("temp.txt");

    while (getline(infile >> ws, newName, '\n'))
    {
        infile >> Number;
        if (code22 == Number)
        {
            num = newName;
        }
        if (num == newName && code22 == Number)
        {
            q = false;
            cout << "Enter your new first and last name: ";
            getline(cin, newName, '\n');
            transform(newName.begin(), newName.end(), newName.begin(), ::tolower);
            bool K = Check_h(newName);
            while (K == false)
            {
                cout << "Your name and lastname do not contain numbers!\n";
                cout << "Enter your new first and last name:";
                getline(cin, newName, '\n');
                transform(newName.begin(), newName.end(), newName.begin(), ::tolower);
                K = Check_h(newName);
            }
            if (K == true)
            {
                tempfile << newName << '\n'
                         << Number << endl;
            }
        }
        else
        {
            tempfile << newName << '\n'
                     << Number << endl;
        }
    }
    if (q == false)
        cout << "The edit was successful!" << endl;
    else
        cout << "The edit was not successful" << endl;
    infile.close();
    tempfile.close();
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
}

void Checking1(string action, bool b)
{
    string keyword = "enter", check;
    if (b == false)
    {
        keyword = "exit";
    }
    size_t found = action.find(keyword);
    if (found != string::npos)
    {
        action.erase(found, keyword.length() + 1);
    }
    if (action != "")
    {
        CheckChange(action, b);
    }
    else
    {
        string first;
        cout << "Enter your Name Or Code:";
        getline(cin >> ws, first, '\n');
        CheckChange(first, b);
    }
}

void CheckChange(string name, bool b)
{
    int c = 0, count = 0;
    int option, index[100], index1[100];
    string first[100], Code[100], first1[100], last1[100], Code1[100];
    ifstream file("teachers.txt");
    if (!file)
    {
        cout << "can not open!";
        exit(-1);
    }

    while (getline(file >> ws, first[c], '\n'))
    {
        getline(file >> ws, Code[c], '\n');
        c++;
    }

    // jostejo dar halgheh for baray aray first..
    for (int i = 0; i < c; i++)
    {
        if ((first[i].find(name) != string ::npos) || (Code[i].find(name) != string ::npos))
        {
            index1[count] = i;
            index[count] = count;
            count++;
            cout << count << ". " << first[i] << '\t' << Code[i] << endl;
        }
        continue;
    }
    if (count == 0)
    {
        cout << "The desired teachers was not found..!\n";
    }
    else
    {
        cout << count << " Number of teachers found.." << endl;
        cout << " Which option do you want?\nnone:-1" << endl;
        cin >> option;
        for (int i = 0; i < count; i++)
        {
            if ((index[i] + 1) == option)
                checkEnter(Code[index1[i]], b);
        }
        if (option == -1)
            return;
    }
    file.close();
}

/// copy project one
// check vorod khoroj*************
void checkEnter(string code, bool b)
{
    string exit;
    int count = 0;
    string name[100], Code[100], mah[100], qnam, day[100], sal[100], month1, day1, year1, tim[100], enter, month2, day2, year2;
    int c = 0;
    ifstream file("Enter.txt");
    while (getline(file, name[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');

        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Enter:") != string::npos)
            {
                if (Code[i] == code)
                {
                    count++;
                    enter = tim[i];
                    month1 = mah[i];
                    day1 = day[i];
                    year1 = sal[i];
                }
            }
            break;
        }

        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Exit:") != string::npos)
            {
                if (Code[i] == code)
                {
                    count--;
                    exit = tim[i];
                    month2 = mah[i];
                    day2 = day[i];
                    year2 = sal[i];
                }
            }
            break;
        }
    }
    file.close();
    if (b == true)
    {
        if (count == 1)
            Checking(code, enter); // check enter2
        else
        {
            Enter(code); // enter
            cout << " The user is entered..\n";
        }
    }
    else
    {
        string action = "Exit:";
        itsok2(enter, exit, code, year1, year2, month1, month2, day1, day2, action); // khoroj
    }
}

// enter dovom check
void Checking(string code, string enter)
{
    string name[100], Code[100], mah[100], tim[100], day[100], sal[100];
    int c = 0;
    string Center, Ccode, Cmah, Ctim, Cday, Csal;
    ifstream f("Enter.txt");
    while (getline(f, name[c], '\t'))
    {
        getline(f, Code[c], '\t');
        getline(f, tim[c], '\t');
        getline(f, mah[c], '/');
        getline(f, day[c], '/');
        getline(f, sal[c], '\n');
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        if (code == Code[i] && name[i] == "Enter:")
        {
            Center = name[i];
            Ccode = Code[i];
            Ctim = tim[i];
            Cmah = mah[i];
            Cday = day[i];
            Csal = sal[i];
            cout << " This user is already entered in today..!\n";
        }
    }

    // gharar dadan vorod aval dar sorat vojod
    ofstream h("extra.txt", ios::app);
    h << Center << "\t" << Ccode << "\t" << Ctim << '\t' << Cmah << "/" << Cday << "/" << Csal << "\n";
    h.close();

    for (int i = 0; i < c; i++)
    {
        if (code == Code[i] && tim[i] == Ctim)
        {
            int sec = 0, min = 0, hour = 0, day = 0, month = 0, year = 0;
            time_t now = time(0);
            tm *local = localtime(&now);

            sec = local->tm_sec;          // seconds (0-61)
            min = local->tm_min;          // minutes (0-59)
            hour = local->tm_hour;        // hours (0-23)
            day = local->tm_mday;         // day of the month (1-31)
            month = local->tm_mon + 1;    // month (1-12)
            year = local->tm_year + 1900; // year since 1900
            string tim2 = to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
            tim[i] = tim2;
        }
    }
    // beroz resani file enter.txt
    ofstream b("Enter.txt");
    for (int i = 0; i < c; i++)
        b << name[i] << "\t" << Code[i] << "\t" << tim[i] << '\t' << mah[i] << "/" << day[i] << "/" << sal[i] << "\n";
    b.close();
}
// Enter
void Enter(string code)
{
    ofstream file;
    if (!file)
    {
        cout << "Unable to open file";
        exit(-1);
    }
    int sec = 0, min = 0, hour = 0, day = 0, month = 0, year = 0;
    // gereftan zaman az system...
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day = local->tm_mday;         // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900

    file.open("Enter.txt", ios::app);
    file << "Enter:"
         << "\t" << code << "\t" << hour << ":" << min << ":" << sec << "\t" << month << "/" << day << "/" << year << "\n";
    file.close();
}

void itsok2(string enter, string exit, string code, string year1, string year2, string month1, string month2, string day1, string day2, string action)
{
    bool b;
    if (enter.empty())
    {
        listExtra(code, action);
        cout << "This user is not entered in before..!";
        // agar bar aval khoroj kard vorod nakard dobareh khoroj khast bokone nazareh....
    }
    else if (exit.empty())
    {
        cout << "This user is out..\n";
        Exit(code);
    }
    else
    {
        char *token = strtok(const_cast<char *>(enter.c_str()), ":");
        int hour1 = stoi(token);

        token = strtok(NULL, ":");
        int min1 = stoi(token);

        token = strtok(NULL, ":");
        int sec1 = stoi(token);

        b = TimeTable(hour1, min1, sec1, exit, month1, day1, year1, month2, day2, year2);

        if (b == false)
        {
            cout << "This user is out..";
            Exit(code);
        }
        else
        {
            cout << " This user is already exited in today..!\n";
            listExtra(code, action);
        }
    }
}

// mohasebeh zaman vorod khoroj....

bool TimeTable(int hour1, int min1, int sec1, string khoroj, string month1, string day1, string year1, string month2, string day2, string year2)
{
    char *token = strtok(const_cast<char *>(khoroj.c_str()), ":");

    int hour2 = stoi(token);

    token = strtok(NULL, ":");
    int min2 = stoi(token);

    token = strtok(NULL, ":");
    int sec2 = stoi(token);

    // tabdil mah sal roz be int..
    int mah1 = stoi(month1);
    int Day1 = stoi(day1);
    int Year1 = stoi(year1);

    int mah2 = stoi(month2);
    int Day2 = stoi(day2);
    int Year2 = stoi(year2);

    if ((Year2 > Year1) || (Year2 == Year1 && mah2 > mah1) || (Year2 == Year1 && mah2 == mah1 && Day2 > Day1) ||
        (Year2 == Year1 && mah2 == mah1 && Day2 == Day1 && hour2 > hour1) ||
        (Year2 == Year1 && mah2 == mah1 && Day2 == Day1 && hour2 == hour1 && min2 > min1) ||
        (Year2 == Year1 && mah2 == mah1 && Day2 == Day1 && hour2 == hour1 && min2 == min1 && sec2 > sec1))
        return true;
    else
        return false;
}

// Exit
void Exit(string Code)
{
    int sec = 0, min = 0, hour = 0, day = 0, month = 0, year = 0;
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day = local->tm_mday;         // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900

    ofstream file;
    file.open("Enter.txt", ios::app);

    file << "Exit:"
         << "\t" << Code << "\t" << hour << ":" << min << ":" << sec << '\t' << month << "/" << day << "/" << year << "\n";

    file.close();

    if (!file)
    {
        cout << "Unable to open file";
        exit(-1);
    }
}

///////////////////////////////////////////////// list extra ////////////////////////////////////////////////////
void listExtra(string code, string action)
{
    ofstream Y("extra.txt", ios::app);
    if (!Y)
    {
        cout << "Unable to open file";
        exit(-1);
    }
    int sec = 0, min = 0, hour = 0, day = 0, month = 0, year = 0;
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day = local->tm_mday;         // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900
    Y << action
      << "\t" << code << "\t" << hour << ":" << min << ":" << sec << "\t" << month << "/" << day << "/" << year << "\n";
    Y.close();
}

// Check kardan inke enter mandeh dar roz bad nabashad :)
void Check_Enter()
{
    string exit, code1;
    bool count;
    string action[100], Code[100], h[100], m[100], s[100], mah[100], day[100], sal[100], tim[100];
    int c = 0, month1, day1, year1;
    ifstream file("Enter.txt");
    while (getline(file, action[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, h[c], ':');
        getline(file, m[c], ':');
        getline(file, s[c], '\t');
        // getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');
        c++;
    }
    file.close();

    int sec = 0, min = 0, hour = 0, day22 = 0, month = 0, year = 0;
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day22 = local->tm_mday;       // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900

    string save[100];
    bool hasExited = false;
    ofstream b("Enter.txt");
    for (int i = 0; i < c; i++)
    {
        if (action[i] == "Enter:")
        {
            // in karbar vared shode
            //  barresi in ke aya karbar exit dashteh ya na
            hasExited = false;
            for (int j = i + 1; j < c; j++)
            {
                if (Code[i] == Code[j] && action[j] == "Exit:")
                {
                    // in karbar exit shode
                    hasExited = true;
                    break;
                }
            }
            if (!hasExited)
            {
                // in karbar exit nashode
                ifstream v("teachers.txt");
                string name;
                string Duplicate;
                code1 = Code[i];
                while (getline(v >> ws, name, '\n'))
                {
                    v >> Duplicate;
                    if (code1 == Duplicate)
                    {
                        save[i] = Duplicate;
                        break;
                    }
                }
                day1 = stoi(day[i]);
                if ((day1 != day22))
                {
                    ofstream p("extra.txt", ios::app);
                    p << action[i] << "\t" << save[i] << "\t" << h[i] << ":" << m[i] << ":" << s[i] << '\t' << mah[i] << "/" << day[i] << "/" << sal[i] << "\n";
                    p.close();
                }
                v.close();
            }
        }
        if (Code[i] != save[i])
        {
            b << action[i] << "\t" << Code[i] << "\t" << h[i] << ":" << m[i] << ":" << s[i] << '\t' << mah[i] << "/" << day[i] << "/" << sal[i] << "\n";
        }
    }
    b.close();
}
// end enter exit
// start report
void Report(string action)
{
    string keyword = "report";
    size_t found = action.find(keyword);
    if (found != string::npos)
    {
        action.erase(found, keyword.length() + 1);
    }
    if (action != "")
    {
        string key1 = "the best", key2 = "the worst";
        string key3 = "present", key4 = "available", key5 = "number", key6 = "monthly attendance", key7 = "unused";
        size_t found1 = action.find(key1);
        size_t found2 = action.find(key2);
        size_t found3 = action.find(key3);
        size_t found4 = action.find(key4);
        size_t found5 = action.find(key5);
        size_t found6 = action.find(key6);
        size_t found7 = action.find(key7);
        bool check;
        if (found1 != string::npos)
        {
            check = true;
            behtarin(check);
            // enter behtarin
        }
        else if (found2 != string::npos)
        {
            check = false;
            behtarin(check);
        }
        else if (found3 != string::npos && (found5 == string::npos))
        {
            Current();
        }
        else if (found4 != string::npos && (found5 == string::npos))
        {
            mojod();
        }
        else if ((found3 != string::npos) && (found5 != string::npos))
        {
            CurrentTeacher();
        }
        else if ((found4 != string::npos) && (found5 != string::npos))
        {
            allTeachers();
        }
        else if (found6 != string::npos)
        {
            action.erase(found6, key6.length() + 1);
            if (action == "")
                MONTH();
            else
                MONTH1(action);
        }
        else if (found7 != string::npos)
        {
            bihodeh();
        }
        else
        {
            size_t ff = action.find("in");
            if ((ff != string::npos))
            {
                string c = action.substr(0, (action.find("in") - 1));
                // cout<<c;
                string codename = CheckChange1(c);
                string key = "month";
                size_t found = action.find(key);
                if (found != string::npos)
                {
                    MONTH3(codename);
                }
                else
                {
                    string b = action.substr(action.find("in") + 3);
                    // sal mah// cout<<b<<"  ";
                    string k = b.substr(0, b.find("/"));
                    string s = b.substr(b.find("/") + 1, 2);
                    MONTH4(codename, s, k);
                }
            }
            else
            {
                // report ali or id
                string codename = CheckChange1(action);
                string report1;
                string key3 = "present", key6 = "monthly attendance", key7 = "unused";
                cin.ignore();
                cout << "What report do you want? ";
                getline(cin, report1);
                size_t found6 = report1.find(key6);
                size_t found7 = report1.find(key7);
                size_t found3 = report1.find(key3);
                if (found3 != string::npos)
                {
                    Current2(codename);
                    // cout hazer nis bezar
                }
                else if (found6 != string::npos)
                {
                    MONTH2(codename);
                }
                else if (found7 != string::npos)
                {
                    bihodeh2(codename);
                }
            }
        }
    }
    else
    {
        string report1, key1 = "the best", key2 = "the worst";
        string key3 = "present", key4 = "available", key5 = "number", key6 = "monthly attendance", key7 = "unused";
        cout << "What report do you want? ";
        getline(cin, report1);
        size_t found1 = report1.find(key1);
        size_t found2 = report1.find(key2);
        size_t found3 = report1.find(key3);
        size_t found4 = report1.find(key4);
        size_t found5 = report1.find(key5);
        size_t found6 = report1.find(key6);
        size_t found7 = report1.find(key7);
        bool check;
        if (found1 != string::npos)
        {
            check = true;
            behtarin(check);
            // enter behtarin
        }
        else if (found2 != string::npos)
        {
            check = false;
            behtarin(check);
        }
        else if (found3 != string::npos && (found5 == string::npos))
        {
            Current();
        }
        else if (found4 != string::npos && (found5 == string::npos))
        {
            mojod();
        }
        else if ((found3 != string::npos) && (found5 != string::npos))
        {
            CurrentTeacher();
        }
        else if ((found4 != string::npos) && (found5 != string::npos))
        {
            allTeachers();
        }
        else if (found6 != string::npos)
        {
            report1.erase(found6, key6.length() + 1);
            if (report1 == "")
                MONTH();
            else
                MONTH1(report1);
        }
        else if (found7 != string::npos)
        {
            bihodeh();
        }
    }
}
void behtarin(bool check)
{
    int numTeachers = 0;
    string teacherCodes[100], teacherNames[100];
    ifstream teacherFile("teachers.txt");
    while (getline(teacherFile >> ws, teacherNames[numTeachers], '\n'))
    {
        getline(teacherFile, teacherCodes[numTeachers], '\n');
        numTeachers++;
    }
    teacherFile.close();

    int total[100] = {0};
    ifstream enterFile("Enter.txt");
    int b = 0;
    int h1[100], m1[100];
    string action[100], teacherCode[100], TCode[100], h[100], m[100], s[100], date[100], action1[100];
    int teacherIndex[100] = {-1};
    while (getline(enterFile, action[b], '\t'))
    {
        getline(enterFile, teacherCode[b], '\t');
        getline(enterFile, h[b], ':');
        getline(enterFile, m[b], ':');
        getline(enterFile, s[b], '\t');
        getline(enterFile, date[b], '\n');
        h1[b] = stoi(h[b]);
        m1[b] = stoi(m[b]);
        b++;
    }

    for (int j = 0; j < b; j++)
    {
        for (int i = 0; i < numTeachers; i++)
        {
            if (teacherCode[j] == teacherCodes[i])
            {
                teacherIndex[j] = i;
            }
        }

        if (teacherIndex[j] != -2)
        {
            int hour, minute, totalMinutes;
            hour = h1[j];
            minute = m1[j];
            totalMinutes = hour * 60 + minute;

            if (action[j] == "Enter:")
            {
                total[teacherIndex[j]] -= totalMinutes;
                bool hasExited = false;
                for (int k = j + 1; k < b; k++)
                {
                    if (teacherCode[j] == teacherCode[k] && action[k] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }
                if (!hasExited)
                {
                    total[teacherIndex[j]] += totalMinutes;
                }
            }
            else
            {
                total[teacherIndex[j]] += totalMinutes;
            }
        }
    }

    enterFile.close();
    // moratab sazi arayeh********
    for (int i = 0; i < numTeachers - 1; i++)
    {
        for (int j = i + 1; j < numTeachers; j++)
        {
            if (total[i] < total[j])
            {
                swap(total[i], total[j]);
                swap(teacherNames[i], teacherNames[j]);
            }
        }
    }

    if (check == true)
    {
        // print top 5 teachers
        cout << "Top 5 teachers:\n";
        for (int i = 0; i < 5 && i < numTeachers; i++)
        {
            cout << i + 1 << ". " << teacherNames[i] << " _ " << total[i] << " minutes\n";
        }
    }
    else
    {
        // print botton 5 teachers
        cout << "Bottom 5 teachers:\n";
        for (int i = numTeachers - 1; i >= 0 && i >= numTeachers - 5; i--)
        {
            cout << numTeachers - i << ". " << teacherNames[i] << " _ " << total[i] << " minutes\n";
        }
    }
}
/////////////////////////////////////// list asatid hazer/////////////////////////////
void Current()
{
    string exit, code1;
    bool count;
    string action[100], Code[100], mah[100], day[100], sal[100], tim[100];
    int c = 0, month1, day1, year1;
    ifstream file("Enter.txt");
    while (getline(file, action[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');
        c++;
    }
    int sec = 0, min = 0, hour = 0, day22 = 0, month = 0, year = 0;
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day22 = local->tm_mday;       // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900

    bool hasExited = false;
    for (int i = 0; i < c; i++)
    {
        if (action[i] == "Enter:")
        {
            // in karbar vared shode
            //  barresi in ke aya karbar exit dashteh ya na
            hasExited = false;
            for (int j = i + 1; j < c; j++)
            {
                if (Code[i] == Code[j] && action[j] == "Exit:")
                {
                    // in karbar exit shode
                    hasExited = true;
                    break;
                }
            }
            if (!hasExited)
            {
                // in karbar exit nashode
                ifstream v("teachers.txt");
                string name;
                string Duplicate;
                code1 = Code[i];
                while (getline(v >> ws, name, '\n'))
                {
                    v >> Duplicate;
                    if (code1 == Duplicate)
                    {
                        cout << name << " ";
                        break;
                    }
                }
                month1 = stoi(mah[i]);
                day1 = stoi(day[i]);
                year1 = stoi(sal[i]);
                if ((day1 == day22) && (month == month1) && (year1 == year))
                {
                    cout << " with code " << code1 << " has entered but not exited." << endl;
                }
                v.close();
            }
        }
    }
    if (hasExited)
    {
        cout << "No one is in college..\n";
    }
    file.close();
}
/////////////////////////////////// list mojod ///////////////////////////////////////////////////////
void mojod()
{
    string name, code;
    int count = 0;
    ifstream file("teachers.txt");
    while (getline(file >> ws, name, '\n'))
    {
        getline(file, code, '\n');
        count++;
        cout << count << ". " << name << "\n";
    }
    cout << "good like.." << endl;
    file.close();
}

// CurrentTeacher... Tedad asatid hazer dar daneshgah
void CurrentTeacher()
{
    cout << "The number of teachers currently in the university : ";
    ifstream file("Enter.txt");
    int counter = 0;
    string name;
    while (file >> name)
    {
        if (name == "Enter:")
        {
            counter += 1;
        }
        if (name == "")
        {
            break;
        }
        if (name == "Exit:")
        {
            counter -= 1;
        }
    }
    cout << counter << endl;
}
// allTeachers////////////////////////////////////////////////////////
void allTeachers()
{
    string name;
    int counter = 0;
    int Code;
    ifstream file("teachers.txt");
    while (getline(file >> ws, name, '\n'))
    {
        file >> Code;
        counter++;
    }
    file.close();
    cout << "The number of teachers in the university : " << counter << endl;
}
// mahane

string CheckChange1(string name)
{
    int c = 0, count = 0;
    int option, index[100], index1[100];
    string first[100], last[100], Code[100], TCode[100], first1[100], last1[100], Code1[100];
    ;
    ifstream file("teachers.txt");
    if (!file)
    {
        cout << "can not open!";
        exit(-1);
    }

    while (getline(file >> ws, first[c], '\n'))
    {
        getline(file, Code[c], '\n');
        c++;
        // jostejo dar halgheh for baray aray first..
    }

    for (int i = 0; i < c; i++)
    {
        if ((first[i].find(name) != string ::npos) || (Code[i].find(name) != string ::npos))
        {
            TCode[i] = Code[i];
            index1[count] = i;
            index[count] = count;
            count++;
            cout << count << ". " << first[i] << " : " << Code[i] << endl;
        }
        continue;
    }
    if (count == 0)
    {
        cout << "The desired teachers was not found..!\n";
    }
    else
    {
        cout << count << " Number of teachers found.." << endl;
        cout << " Which option do you want?\nnone:-1" << endl;
        cin >> option;
        for (int i = 0; i < count; i++)
        {
            if ((index[i] + 1) == option)
                return TCode[index1[i]];
        }
    }
    file.close();
}

////////////////////////////////    HOZOR MAHANEH    ///////////////////////////////////////////////

void MONTH()
{
    string name, lastname, code;
    int cinmah;
    bool check = true, b;
    string last, Code, first;
    do
    {
        // readTeacherInfo(name, lastname, code);
        cout << "Enter Your name or code :";
        cin >> name;
        code = CheckChange1(name);
        cout << "Enter your month :\n";
        cin >> cinmah;
        cin.ignore();
        ifstream file("teachers.txt");
        while (getline(file >> ws, first, ' '))
        {
            getline(file >> ws, last, '\n');
            getline(file >> ws, Code, '\n');
            if (code == Code)
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "User is not found..!\n";
    } while (check);

    const int DAYS_IN_MONTH = 31;
    int totalend[DAYS_IN_MONTH] = {0};
    int c = 0;
    string Tcode2[100], action[100], Tcode[100], h[100], m[100], s[100], mah[100], day[100], sal[100];
    int hour[100], min[100], sec[100], mah1[100];
    ifstream enter("Enter.txt");
    while (getline(enter, action[c], '\t'))
    {
        getline(enter, Tcode[c], '\t');
        getline(enter, h[c], ':');
        getline(enter, m[c], ':');
        getline(enter, s[c], '\t');
        getline(enter, mah[c], '/');
        getline(enter, day[c], '/');
        getline(enter, sal[c], '\n');
        hour[c] = stoi(h[c]);
        min[c] = stoi(m[c]);
        sec[c] = stoi(s[c]);
        mah1[c] = stoi(mah[c]);
        Tcode2[c] = Tcode[c];
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        int dayIndex = stoi(day[i]) - 1;

        if (Tcode2[i] == code && mah1[i] == cinmah)
        {
            if (action[i] == "Enter:")
            {
                // in karbar vared shode
                totalend[dayIndex] -= hour[i] * 60 + min[i];

                // barresi inke in karbar kharej shode ya na
                bool hasExited = false;
                for (int j = i + 1; j < c; j++)
                {
                    if (Tcode2[i] == Tcode2[j] && action[j] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }

                // agar karbar khoroj nadashte bashad
                if (!hasExited)
                {
                    totalend[dayIndex] += hour[i] * 60 + min[i];
                }
            }
            else
            {
                totalend[dayIndex] += hour[i] * 60 + min[i];
            }
        }
    }
    int all = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++)
    {
        if (totalend[i] != 0)
        {
            all += totalend[i];
            cout << "User: " << first << " " << last << " WithCode " << code << " in the month of " << cinmah << " in the day of " << i + 1 << " min: " << totalend[i] << "has been present\n";
        }
    }
    if (all != 0)
    {
        cout << "This teachers has been present for a total of " << all << " minutes this month \n";
    }
    else
    {
        cout << "This teachers was not present this month \n";
    }
}

void MONTH1(string report1)
{
    string lastname, code;
    int cinmah;
    bool check = true, b;
    string last, Code, first;
    do
    {

        code = CheckChange1(report1);
        cout << "Enter your month :\n";
        cin >> cinmah;
        cin.ignore();
        ifstream file("teachers.txt");
        while (getline(file >> ws, first, ' '))
        {
            getline(file >> ws, last, '\n');
            getline(file >> ws, Code, '\n');
            if (code == Code)
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "User is not found..!\n";
    } while (check);

    const int DAYS_IN_MONTH = 31;
    int totalend[DAYS_IN_MONTH] = {0};
    int c = 0;
    string Tcode2[100], action[100], Tcode[100], h[100], m[100], s[100], mah[100], day[100], sal[100];
    int hour[100], min[100], sec[100], mah1[100];
    ifstream enter("Enter.txt");
    while (getline(enter, action[c], '\t'))
    {
        getline(enter, Tcode[c], '\t');
        getline(enter, h[c], ':');
        getline(enter, m[c], ':');
        getline(enter, s[c], '\t');
        getline(enter, mah[c], '/');
        getline(enter, day[c], '/');
        getline(enter, sal[c], '\n');
        hour[c] = stoi(h[c]);
        min[c] = stoi(m[c]);
        sec[c] = stoi(s[c]);
        mah1[c] = stoi(mah[c]);
        Tcode2[c] = Tcode[c];
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        int dayIndex = stoi(day[i]) - 1;

        if (Tcode2[i] == code && mah1[i] == cinmah)
        {
            if (action[i] == "Enter:")
            {
                // in karbar vared shode
                totalend[dayIndex] -= hour[i] * 60 + min[i];

                // barresi inke in karbar kharej shode ya na
                bool hasExited = false;
                for (int j = i + 1; j < c; j++)
                {
                    if (Tcode2[i] == Tcode2[j] && action[j] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }

                // agar karbar khoroj nadashte bashad
                if (!hasExited)
                {
                    totalend[dayIndex] += hour[i] * 60 + min[i];
                }
            }
            else
            {
                totalend[dayIndex] += hour[i] * 60 + min[i];
            }
        }
    }
    int all = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++)
    {
        if (totalend[i] != 0)
        {
            all += totalend[i];
            cout << "User: " << first << " " << last << " WithCode " << code << " in the month of " << cinmah << " in the day of " << i + 1 << " min: " << totalend[i] << "has been present\n";
        }
    }
    if (all != 0)
    {
        cout << "This teachers has been present for a total of " << all << " minutes this month \n";
    }
    else
    {
        cout << "This teachers was not present this month \n";
    }
}
// mahane name.

void MONTH2(string report1)
{
    string lastname, code;
    int cinmah;
    bool check = true, b;
    string last, Code, first;
    do
    {

        code = report1;
        cout << "Enter your month :\n";
        cin >> cinmah;
        cin.ignore();
        ifstream file("teachers.txt");
        while (getline(file >> ws, first, ' '))
        {
            getline(file >> ws, last, '\n');
            getline(file >> ws, Code, '\n');
            if (code == Code)
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "User is not found..!\n";
    } while (check);

    const int DAYS_IN_MONTH = 31;
    int totalend[DAYS_IN_MONTH] = {0};
    int c = 0;
    string Tcode2[100], action[100], Tcode[100], h[100], m[100], s[100], mah[100], day[100], sal[100];
    int hour[100], min[100], sec[100], mah1[100];
    ifstream enter("Enter.txt");
    while (getline(enter, action[c], '\t'))
    {
        getline(enter, Tcode[c], '\t');
        getline(enter, h[c], ':');
        getline(enter, m[c], ':');
        getline(enter, s[c], '\t');
        getline(enter, mah[c], '/');
        getline(enter, day[c], '/');
        getline(enter, sal[c], '\n');
        hour[c] = stoi(h[c]);
        min[c] = stoi(m[c]);
        sec[c] = stoi(s[c]);
        mah1[c] = stoi(mah[c]);
        Tcode2[c] = Tcode[c];
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        int dayIndex = stoi(day[i]) - 1;

        if (Tcode2[i] == code && mah1[i] == cinmah)
        {
            if (action[i] == "Enter:")
            {
                // in karbar vared shode
                totalend[dayIndex] -= hour[i] * 60 + min[i];

                // barresi inke in karbar kharej shode ya na
                bool hasExited = false;
                for (int j = i + 1; j < c; j++)
                {
                    if (Tcode2[i] == Tcode2[j] && action[j] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }

                // agar karbar khoroj nadashte bashad
                if (!hasExited)
                {
                    totalend[dayIndex] += hour[i] * 60 + min[i];
                }
            }
            else
            {
                totalend[dayIndex] += hour[i] * 60 + min[i];
            }
        }
    }
    int all = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++)
    {
        if (totalend[i] != 0)
        {
            all += totalend[i];
            cout << "User: " << first << " " << last << " WithCode " << code << " in the month of " << cinmah << " in the day of " << i + 1 << " min: " << totalend[i] << "has been present\n";
        }
    }
    if (all != 0)
    {
        cout << "This teachers has been present for a total of " << all << " minutes this month \n";
    }
    else
    {
        cout << "This teachers was not present this month \n";
    }
}
// bihode
void bihodeh()
{
    string check;
    cout << "Enter  Name Or Code :";
    cin >> check;
    cin.ignore();
    string name1 = CheckCode(check);
    int countenter = 0, countexit = 0;
    string name[100], Code[100], mah[100], day[100], sal[100], tim[100];
    int c = 0;
    ifstream file("extra.txt");
    while (getline(file, name[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');

        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Enter:") != string::npos)
            {
                if (Code[i] == name1)
                {
                    countenter++;
                }
            }
            break;
        }
        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Exit:") != string::npos)
            {
                if (Code[i] == name1)
                {
                    countexit++;
                }
            }
            break;
        }
    }
    int numTeachers = 0;
    string teacherCodes[100], teacherNames[100];
    ifstream teacherFile("teachers.txt");
    while (getline(teacherFile >> ws, teacherNames[numTeachers], '\n'))
    {
        getline(teacherFile, teacherCodes[numTeachers], '\n');
        numTeachers++;
    }
    teacherFile.close();
    for (int i = 0; i < numTeachers; i++)
    {
        if (teacherCodes[i] == name1)
        {
            cout << "User: " << teacherNames[i] << " with code " << teacherCodes[i] << " had " << countenter << " enter without exit  and " << countexit << " exit without  enter\n";
        }
    }
    file.close();
}
// bihode
void bihodeh2(string cc)
{
    string name1 = cc;
    int countenter = 0, countexit = 0;
    string name[100], Code[100], mah[100], day[100], sal[100], tim[100];
    int c = 0;
    ifstream file("extra.txt");
    while (getline(file, name[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');

        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Enter:") != string::npos)
            {
                if (Code[i] == name1)
                {
                    countenter++;
                }
            }
            break;
        }
        for (int i = 0; i <= c; i++)
        {
            if (name[i].find("Exit:") != string::npos)
            {
                if (Code[i] == name1)
                {
                    countexit++;
                }
            }
            break;
        }
    }
    int numTeachers = 0;
    string teacherCodes[100], teacherNames[100];
    ifstream teacherFile("teachers.txt");
    while (getline(teacherFile >> ws, teacherNames[numTeachers], '\n'))
    {
        getline(teacherFile, teacherCodes[numTeachers], '\n');
        numTeachers++;
    }
    teacherFile.close();
    for (int i = 0; i < numTeachers; i++)
    {
        if (teacherCodes[i] == name1)
        {
            cout << "User: " << teacherNames[i] << " with code " << teacherCodes[i] << " had " << countenter << " enter without exit  and " << countexit << " exit without  enter\n";
        }
    }
    file.close();
}
// current2
void Current2(string Codep)
{
    string exit, code1;
    bool count;
    string action[100], Code[100], mah[100], day[100], sal[100], tim[100];
    int c = 0, month1, day1, year1;
    ifstream file("Enter.txt");
    while (getline(file, action[c], '\t'))
    {
        getline(file, Code[c], '\t');
        getline(file, tim[c], '\t');
        getline(file, mah[c], '/');
        getline(file, day[c], '/');
        getline(file, sal[c], '\n');
        c++;
    }
    int sec = 0, min = 0, hour = 0, day22 = 0, month = 0, year = 0;
    time_t now = time(0);
    tm *local = localtime(&now);

    sec = local->tm_sec;          // seconds (0-61)
    min = local->tm_min;          // minutes (0-59)
    hour = local->tm_hour;        // hours (0-23)
    day22 = local->tm_mday;       // day of the month (1-31)
    month = local->tm_mon + 1;    // month (1-12)
    year = local->tm_year + 1900; // year since 1900

    bool hasExited = false;
    for (int i = 0; i < c; i++)
    {
        if (action[i] == "Enter:")
        {
            // in karbar vared shode
            //  barresi in ke aya karbar exit dashteh ya na
            hasExited = false;
            for (int j = i + 1; j < c; j++)
            {
                if (Code[i] == Code[j] && action[j] == "Exit:")
                {
                    // in karbar exit shode
                    hasExited = true;
                    break;
                }
            }
            if (!hasExited)
            {
                // in karbar exit nashode
                ifstream v("teachers.txt");
                string name;
                string Duplicate;
                code1 = Code[i];
                while (getline(v >> ws, name, '\n'))
                {
                    v >> Duplicate;
                    if (code1 == Duplicate && Codep == code1)
                    {
                        cout << name << " ";
                        break;
                    }
                }
                month1 = stoi(mah[i]);
                day1 = stoi(day[i]);
                year1 = stoi(sal[i]);
                if ((day1 == day22) && (month == month1) && (year1 == year) && (Codep == code1))
                {
                    cout << " with code " << code1 << " has entered but not exited." << endl;
                }
                v.close();
            }
        }
        else
        {
            cout << "The user is not entered..";
            break;
        }
    }
    file.close();
}
// month3

void MONTH4(string codename, string mon, string salii)
{
    string lastname, code, Sal;
    string cinmah;
    bool check = true, b;
    string last, Code, first;
    do
    {

        code = codename;
        cinmah = mon;
        Sal = salii;
        cin.ignore();
        ifstream file("teachers.txt");
        while (getline(file >> ws, first, ' '))
        {
            getline(file >> ws, last, '\n');
            getline(file >> ws, Code, '\n');
            if (code == Code)
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "User is not found..!\n";
    } while (check);

    const int DAYS_IN_MONTH = 31;
    int totalend[DAYS_IN_MONTH] = {0};
    int c = 0;
    string Tcode2[100], action[100], Tcode[100], h[100], m[100], s[100], mah1[100], mah[100], day[100], sal[100];
    int hour[100], min[100], sec[100];
    ifstream enter("Enter.txt");
    while (getline(enter, action[c], '\t'))
    {
        getline(enter, Tcode[c], '\t');
        getline(enter, h[c], ':');
        getline(enter, m[c], ':');
        getline(enter, s[c], '\t');
        getline(enter, mah[c], '/');
        getline(enter, day[c], '/');
        getline(enter, sal[c], '\n');
        hour[c] = stoi(h[c]);
        min[c] = stoi(m[c]);
        sec[c] = stoi(s[c]);
        mah1[c] = mah[c];
        Tcode2[c] = Tcode[c];
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        int dayIndex = stoi(day[i]) - 1;

        if (Tcode2[i] == code && mah1[i] == cinmah && sal[i] == Sal)
        {
            if (action[i] == "Enter:")
            {
                // in karbar vared shode
                totalend[dayIndex] -= hour[i] * 60 + min[i];

                // barresi inke in karbar kharej shode ya na
                bool hasExited = false;
                for (int j = i + 1; j < c; j++)
                {
                    if (Tcode2[i] == Tcode2[j] && action[j] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }

                // agar karbar khoroj nadashte bashad
                if (!hasExited)
                {
                    totalend[dayIndex] += hour[i] * 60 + min[i];
                }
            }
            else
            {
                totalend[dayIndex] += hour[i] * 60 + min[i];
            }
        }
    }
    int all = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++)
    {
        if (totalend[i] != 0)
        {
            all += totalend[i];
            cout << "User: " << first << " " << last << " WithCode " << code << " in the month of " << cinmah << " in the day of " << i + 1 << " min: " << totalend[i] << "has been present\n";
        }
    }
    if (all != 0)
    {
        cout << "This teachers has been present for a total of " << all << " minutes this month \n";
    }
    else
    {
        cout << "This teachers was not present this month \n";
    }
}
///////////mahane akhari

void MONTH3(string report1)
{

    int monthlocal = 0;
    time_t now = time(0);
    tm *local = localtime(&now);
    monthlocal = local->tm_mon + 1;
    string lastname, code;
    int cinmah;
    bool check = true, b;
    string last, Code, first;
    do
    {

        code = report1;
        cinmah = monthlocal;
        ifstream file("teachers.txt");
        while (getline(file >> ws, first, ' '))
        {
            getline(file >> ws, last, '\n');
            getline(file >> ws, Code, '\n');
            if (code == Code)
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "User is not found..!\n";
    } while (check);

    const int DAYS_IN_MONTH = 31;
    int totalend[DAYS_IN_MONTH] = {0};
    int c = 0;
    string Tcode2[100], action[100], Tcode[100], h[100], m[100], s[100], mah[100], day[100], sal[100];
    int hour[100], min[100], sec[100], mah1[100];
    ifstream enter("Enter.txt");
    while (getline(enter, action[c], '\t'))
    {
        getline(enter, Tcode[c], '\t');
        getline(enter, h[c], ':');
        getline(enter, m[c], ':');
        getline(enter, s[c], '\t');
        getline(enter, mah[c], '/');
        getline(enter, day[c], '/');
        getline(enter, sal[c], '\n');
        hour[c] = stoi(h[c]);
        min[c] = stoi(m[c]);
        sec[c] = stoi(s[c]);
        mah1[c] = stoi(mah[c]);
        Tcode2[c] = Tcode[c];
        c++;
    }

    for (int i = 0; i < c; i++)
    {
        int dayIndex = stoi(day[i]) - 1;

        if (Tcode2[i] == code && mah1[i] == cinmah)
        {
            if (action[i] == "Enter:")
            {
                // in karbar vared shode
                totalend[dayIndex] -= hour[i] * 60 + min[i];

                // barresi inke in karbar kharej shode ya na
                bool hasExited = false;
                for (int j = i + 1; j < c; j++)
                {
                    if (Tcode2[i] == Tcode2[j] && action[j] == "Exit:")
                    {
                        hasExited = true;
                        break;
                    }
                }

                // agar karbar khoroj nadashte bashad
                if (!hasExited)
                {
                    totalend[dayIndex] += hour[i] * 60 + min[i];
                }
            }
            else
            {
                totalend[dayIndex] += hour[i] * 60 + min[i];
            }
        }
    }
    int all = 0;
    for (int i = 0; i < DAYS_IN_MONTH; i++)
    {
        if (totalend[i] != 0)
        {
            all += totalend[i];
            cout << "User: " << first << " " << last << " WithCode " << code << " in the month of " << cinmah << " in the day of " << i + 1 << " min: " << totalend[i] << "has been present\n";
        }
    }
    if (all != 0)
    {
        cout << "This teachers has been present for a total of " << all << " minutes this month \n";
    }
    else
    {
        cout << "This teachers was not present this month \n";
    }
}