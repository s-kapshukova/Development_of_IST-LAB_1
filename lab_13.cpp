#include <iostream>
#include <string>
#include <memory>
using namespace std;

class ILogger //интерфейс
{
    public:
    virtual void Log(string& logText) = 0; // сохранить лог
};
class LoggerConsole: public ILogger
{
    public:
    void Log(string& logText) override
    {
        cout << "The message log is displayed on the console" << endl;
        return;
    }
};
class LoggerDatabase: public ILogger   //сохранение в базе данных
{
    public:
    void Log(string& logText) override
    {
        cout << "The message log is saved in the database" << endl;
        return;
    }
};

class LoggerFile: public ILogger //сохранение в файле
{
    public:
    void Log(string& logText) override
    {
        cout << "The message log is saved in the file" << endl;
        return;
    }
};

class SmtpMailer
{
    private:
    //ILogger *log = nullptr;
    
    shared_ptr <ILogger> log;
    
    public:
    SmtpMailer (shared_ptr <ILogger> _log)
    {
        log = _log;
    }

    void SetLog (shared_ptr <ILogger> _log)
    {
        log = _log;
        //return;
    }

    void SendMessage(string message)
    {
        
        string textLog;
        // отправка сообщения. В зависимости от успеха отправки в textLog записываются различные данные
        textLog = "the message 'I am a program that should work' was sent successfully"; 
        log->Log(textLog);//вызов logger'a

    }
};

int main ()
{
    
    shared_ptr <LoggerConsole> log1 = make_shared <LoggerConsole>();
    shared_ptr <LoggerFile> log2 = make_shared <LoggerFile>();
    shared_ptr <LoggerDatabase> log3 = make_shared <LoggerDatabase>();

    string textMessage ("I am the program that should work");
    SmtpMailer mailer(log2);

    mailer.SendMessage(textMessage);
    return 0;
}