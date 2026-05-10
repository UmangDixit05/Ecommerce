#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string name, user;

    cout << "===================================" << endl;
    cout << " Welcome to ABC Customer Support " << endl;
    cout << "===================================" << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Hello " << name << "!" << endl;
    cout << "Type 'bye' to exit the chat." << endl;

    while(true)
    {
        cout << "\nYou: ";
        getline(cin, user);

        // Greeting
        if(user == "hello" || user == "hi")
        {
            cout << "Bot: Hello! How can I help you?" << endl;
        } 

        // Services
        else if(user.find("service") != string::npos)
        {
            cout << "Bot: We provide mobile, laptop, and software support services." << endl;
        }

        // Timing
        else if(user.find("time") != string::npos || user.find("open") != string::npos ||  user.find("timing")!= string::npos)
        {
            cout << "Bot: Our customer support is available from 9 AM to 6 PM." << endl;
        }

        // Contact
        else if(user.find("contact") != string::npos || user.find("phone") != string::npos)
        {
            cout << "Bot: You can contact us at 9876543210." << endl;
        }

        // Location
        else if(user.find("location") != string::npos || user.find("address") != string::npos)
        {
            cout << "Bot: We are located in Pune, Maharashtra." << endl;
        }

        // Thank you
        else if(user.find("thank") != string::npos)
        {
            cout << "Bot: You're welcome!" << endl;
        }

        // Exit
        else if(user == "bye")
        {
            cout << "Bot: Thank you for visiting ABC Customer Support." << endl;
            cout << "Bot: Have a nice day!" << endl;
            break;
        }

        // Default
        else
        {
            cout << "Bot: Sorry, I did not understand your question." << endl;
        }
    }

    return 0;
}
