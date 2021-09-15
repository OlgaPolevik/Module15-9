//
//  main.cpp
//  Module15-9
//
//  Created by Ольга Полевик on 13.09.2021.
//

#include <iostream>
#include "chat.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    /*Chat c;
    c.reg("A", "12345678");
    assert( c.login("A", "12345678") == true );
    assert( c.login("B", "12345678") == false );
    */
    
    Chat chat;
    cout << "Enter login" << endl;
    string l;
    cin >> l;
    cout << "Enter pass" << endl;
    string p;
    cin >> p;
    
    chat.reg (l, p);
    
    cout << "Enter login" << endl;
    string l_;
    cin >> l_;
    cout << "Enter pass" << endl;
    string p_;
    cin >> p_;
    
    chat.login (l_, p_);
    
    return 0;
}
