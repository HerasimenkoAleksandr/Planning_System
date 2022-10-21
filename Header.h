#pragma once

using namespace std;


class Task
{
    string teg;
    int priority;
    SYSTEMTIME st;
public:
    Task(string tegP);
    void SetPriority();
    int GetPriority()const;
    string GetTeg()const;
    SYSTEMTIME GetTime();
    void ShowTime();
    void WriteF();
    virtual void ShowTask() = 0;
};

class ConcreteTask1 : public Task
{
public:
    ConcreteTask1();
    void ShowTask()override;

};


class ConcreteTask2 : public Task
{
public:
    ConcreteTask2(); 
    
    void ShowTask()override;
};



class ConcreteTask3 : public Task
{
public:
    ConcreteTask3();
    void ShowTask()override;

};


class ITask
{
public:
    virtual  void PushList() = 0;
    virtual void Delete(string tag) = 0;
    virtual void Edit(string s) = 0;
    virtual void Show() = 0;
};
class IFile
{
public:

    virtual void WriteFail() = 0;
};

class IFind
{
public:
    virtual  Task* Find(string s) = 0;
    virtual  void Find(int prior) = 0;
    virtual void  Find() = 0;
};

class ListOfTask :public ITask, public IFind, public IFile
{
    list<Task*> l;
public:
    void PushList() override;
    void Delete(string tag) override;
    void Show();
    void Edit(string s) override;
    void Find()override;
    Task* Find(string s);
    void Find(int prior);
    void WriteFail();



};


class Client
{
    ListOfTask A;
public:
    void CreateList();
    void Edit();
    void Delete();
    void WriteFile();

    void Find();
};

