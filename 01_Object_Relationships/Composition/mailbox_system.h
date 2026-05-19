#ifndef MAILBOX_SYSTEM_H_ 
#define MAILBOX_SYSTEM_H_ 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <ctime>
#include <vector> 
using namespace std; 
class Message { 
    private:     
        string recipient_; 
        string sender_; 
        string message_; 
    public: 
        Message(string sender, string recipient); 
        void append(const string& str); 
        string toString() const; 
        void print() const;}; 

class Mailbox { 
    private: 
        vector<Message> mail_; 
    public: 
        Mailbox(); 
        void addMessage(const Message& m); 
        Message getMessage(int i) const; 
        void removeMessage(int i);}; 
#endif