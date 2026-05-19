#include "mailbox_system.h" 
Message::Message(string sender, string recipient): sender_(sender), recipient_(recipient){ 
    time_t now = time(0); 
    string timestamp = ctime(&now); 
    message_ = "Message created at " + timestamp + "\n";} 
void Message::append(const string& str){message_+= str + "\n";} 
string Message::toString() const{ 
    stringstream ss; 
    ss << "From: " << sender_ << "\nTo: " << recipient_ << "\n" << message_ << "\n"; 
    return ss.str();} 
void Message::print() const{cout << toString();} 

void Mailbox::addMessage(const Message& m){mail_.push_back(m);} 
Message Mailbox::getMessage(int i) const{ 
    if(i<0 || i>=mail_.size()) throw out_of_range("Index is out of border."); 
    return mail_[i];} 
void Mailbox::removeMessage(int i){ 
    if(i<0 || i>=mail_.size()) throw out_of_range("Index is out of border."); 
    mail_.erase(mail_.begin()+i);}