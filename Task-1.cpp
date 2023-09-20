#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//here the function is to register to new user
void registerUser(const string& username,const string& password)
{
    ofstream userFile(username + ".txt");
    userFile<<password;
    userFile.close();
    cout<<"Registration is Successful"<<endl;
}
//function to check user exists or not
bool doesUserExist(const string& username)
{
    ifstream userFile(username + ".txt");
    return userFile.good();
}
//funtion to login 
bool login(const string& username,const string& password)
{
    ifstream userFile(username + ".txt");
    string savedPassword;
    if(userFile>>savedPassword)
    {
     if(savedPassword==password)
     {
        cout<<"Login Succesful.WELCOME."<<endl;
        return true;
     }
     else
     {
        cout<<"Login failed.Inncorrect Password."<<endl;
     }
    } 
    else
    {
       cout<<"Login failed.user not found."<<endl;
    }
    return false;
}
int main()
{
    string username,password;
    cout<<"Welcome to Registration & Login System!"<<endl;
    cout<<"Enter new username:";//registration
    cin>>username;
    if(doesUserExist(username))
    {
        cout<<"Entered username already exists choose another username."<<endl;
        return 1;
    }
    cout<<"Enter a password:";
    cin>>password;
    registerUser(username,password);
    cout<<"Login to your Account:"<<endl;//login 
    cout<<"Username:";
    cin>>username;
    cout<<"password:";
    cin>>password;
    login(username,password);
    return 0;    
}