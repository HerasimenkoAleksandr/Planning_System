#include <iostream>
#include <windows.h>
#include < fstream>
#include <list>
#include"Header.h"
using namespace std;






int main()
{
   
    Client G;

    
    G.CreateList();
    G.CreateList();
    cout <<"=================================================="<< endl << endl;
    G.Delete();
    cout << "==================================================" << endl << endl;
    G.Edit();
    cout << "==================================================" << endl << endl;
    G.Find();
    cout << "==================================================" << endl << endl;
    G.WriteFile();
   
     return 0;
}



Task::Task(string tegP) : teg{ tegP }
{
    GetSystemTime(&st);

    priority = 0;
}
void Task::SetPriority()
{
    cout << "Enter number of priority" << endl;
    cin >> priority;
}
int Task::GetPriority()const
{
    return priority;
}
string Task::GetTeg()const
{
    return teg;
}
SYSTEMTIME Task::GetTime()
{
    return st;
}
void Task::ShowTime()
{
    cout << st.wDay << "." << st.wMonth << "." << st.wYear << endl;
}
void Task::WriteF()
{
    string a("Tasks.txt");
    fstream fs;
    fs.open(a, fstream::out);
    if (!fs.is_open())
    {
        cout << "Error open file" << endl; //Error open file
    }
    else
    {
        fs << teg << "\n";
        fs << priority << "\n";
        fs << st.wMonth << "\n";
        fs << st.wYear << "\n";
    }
    fs.close();
}


ConcreteTask1::ConcreteTask1() : Task("Task1")
{
    cout << "Create Concrete Task-1 " << endl;
    cout << " Teg: " << GetTeg() << endl;
    cout << " Date: ";
    ShowTime();
    SetPriority();
}
void ConcreteTask1::ShowTask()
{
    cout << " Concrete Task-1 " << endl;
    cout << " Teg: " << GetTeg() << endl;
}

ConcreteTask2::ConcreteTask2() :Task("Task2")
{
    cout << "Create Concrete Task-2 " << endl;
    cout << " Teg: " << GetTeg() << endl;
    cout << " Date: ";
    ShowTime();
    SetPriority();
}
void ConcreteTask2::ShowTask()
{
    cout << "Concrete Task-2 " << endl;
    cout << " Teg: " << GetTeg() << endl;
    cout << " Date: ";
    ShowTime();
}

ConcreteTask3::ConcreteTask3() :Task("Task3")
{
    cout << "CreateConcrete Task-3 " << endl;
    cout << " Teg: " << GetTeg() << endl;
    cout << " Date: ";
    ShowTime();
    SetPriority();
}
void ConcreteTask3::ShowTask()
{
    cout << "Concrete Task-3 " << endl;
    cout << " Teg: " << GetTeg() << endl;
    cout << " Date: ";
    ShowTime();
}

void  ListOfTask::PushList()
{
    int a;
    cout << "select a task" << endl;
    cout << "enter 1 if you want to add ConcreteTask1 to the list " << endl;
    cout << "enter 2 if you want to add ConcreteTask2 to the list " << endl;
    cout << "enter 3 if you want to add ConcreteTask3 to the list" << endl;
    cin >> a;
    switch (a)
    {
    case(1):
    {
        l.push_back(new ConcreteTask1());
        break;
    }
    case(2):
    {
        l.push_back(new ConcreteTask2());

        break;
    }
    case(3):
    {
        l.push_back(new ConcreteTask3());
        break;
    }
    default:
        break;
    }

}
void  ListOfTask::Delete(string tag)
{
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        if ((*iter)->GetTeg() == tag)
        {
            l.remove(*iter);

            break;
        }

    }
    cout << "Deleted" << endl;


}
void ListOfTask::Show()
{
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        (*iter)->ShowTask();


    }
}
void ListOfTask::Edit(string s)
{
    int g = 0;
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {

        if ((*iter)->GetTeg() == s)
        {
            g++;
            break;
        }
    }
    if (g == 0)
        cout << "No task found with this tag" << endl;
    else
    {
        int a;
        //obj= nullptr;
        cout << "selecting a new task " << endl;
        cout << "enter 1 if you want to use ConcreteTask1 " << endl;
        cout << "enter 2 if you want to use ConcreteTask2 " << endl;
        cout << "enter 3 if you want to use ConcreteTask3 " << endl;
        cin >> a;
        switch (a)
        {
        case(1):
        {

            *iter = new ConcreteTask1();

            break;
        }
        case(2):
        {
            *iter = new ConcreteTask2();

            break;
        }
        case(3):
        {
            *iter = new ConcreteTask3();

            break;
        }
        default:
            break;
        }
    }
}
void ListOfTask::Find()
{
    SYSTEMTIME s;

    cout << "Enter number month of year:";
    cin >> s.wMonth;
    cout << "Enter year:";
    cin >> s.wYear;
    int g = 0;
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {

        if (((*iter)->GetTime().wMonth) == s.wMonth && ((*iter)->GetTime().wYear) == s.wYear)
        {
            (*iter)->ShowTask();
            g++;
        }



    }
    if (g == 0)
        cout << "No task found with this date" << endl;
}
Task* ListOfTask::Find(string s)
{
    int g = 0;
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {

        if ((*iter)->GetTeg() == s)
        {
            (*iter)->ShowTask();
            g++;
            break;
        }
    }
    if (g == 0)
        cout << "No task found with this tag" << endl;
    return *iter;
}
void ListOfTask::Find(int prior)
{
    int g = 0;
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {

        if (((*iter)->GetPriority()) == prior)
        {
            (*iter)->ShowTask();
            g++;
            //   break;
        }


    }
    if (g == 0)
        cout << "No task found with this priority number" << endl;
}
void ListOfTask::WriteFail()
{
    list  <Task*>::iterator iter = l.begin();
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        (*iter)->WriteF();


    }
}

void Client::CreateList()
{
    A.PushList();

}
void  Client::Edit()
{
    string a;
    cout << "enter the tag of the task you want to change" << endl;
    cin >> a;
    cout << "Now you can change the selected task to another!" << endl;
    A.Edit(a);
}
void  Client::Delete()
{
    string a;
    cout << "enter the tag of the task you want to delete" << endl;
    cin >> a;
    A.Delete(a);
}
void  Client::WriteFile()
{
    A.WriteFail();
}

void  Client::Find()
{
    int d;
    cout << "How to search for a task by priority or by date or by tag ?" << endl;
    cout << "Enter 1 - for priority" << endl;
    cout << "Enter 2 - for  date" << endl;
    cout << "Enter 3 - for tag " << endl;
    cin >> d;
    switch (d)
    {
    case(1):
    {
        int a;
        cout << "enter the priority of the task you want to find" << endl;
        cin >> a;
        A.Find(a);
        break;
    }
    case(2):
    {

        A.Find();
        break;
    }
    case(3):
    {
        string a;
        cout << "enter the tag of the task you want to find" << endl;
        cin >> a;
        A.Find(a);
        break;
    }
    default:
        break;
    }
}