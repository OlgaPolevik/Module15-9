//
//  chat.cpp
//  Module15-9
//
//  Created by Ольга Полевик on 13.09.2021.
//

#include <stdio.h>
#include "chat.h"
#include "iostream"
#include "string.h"

using namespace std;

Chat::Chat()
{
}

void Chat::reg(std::string _login, std::string _pwd) {
    uint* hash = sha1(_pwd.c_str(), (int)_pwd.length());
    data.add( AuthData( _login, hash ) );
    cout << "login: " << _login << "\npassword: " << _pwd << endl;
}
bool Chat::login(std::string _login, std::string _pwd) {
    cout << "Trying to log in" << endl;
    uint* hash = sha1(_pwd.c_str(), (int)_pwd.length());
    AuthData this_data(_login, hash);
    
    if ( const AuthData* creds = data.find( _login ) )
    {
        if ( *creds == this_data )
        {
            cout << "login: " << _login << "\npassword: " << _pwd << endl;
            cout << "Returning true\n";
            return true;
        }
    }
    cout << "login: " << _login << "\npassword: " << _pwd << endl;
    cout << "Returning false\n";
    return false;
}
