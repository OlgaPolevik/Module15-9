//
//  Authdata.h
//  Module15-9
//
//  Created by Ольга Полевик on 14.09.2021.
//
#ifndef Authdata_h
#define Authdata_h

#include <string>
#include "sha1.h"

struct AuthData {
    AuthData():
        pass_sha1_hash(nullptr)
    {
    }
    
    ~AuthData()
    {
        delete [] pass_sha1_hash;
    }
    
    AuthData(std::string login, uint* sh1)
        : login( login )
        , pass_sha1_hash( sh1 )
    {
    }
    
    bool operator == (const AuthData& other) const
    {
        return login == other.login && !memcmp(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHUINTS);
    }
    
    AuthData(const AuthData& other )
        : login( other.login )
        , pass_sha1_hash( nullptr )
    {
        pass_sha1_hash = new uint[SHA1HASHLENGTHBYTES];
        memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);
    }
    
    AuthData& operator = (const AuthData& other) {
        if ( this == &other )
            return *this;
        
        login = other.login;
        
        delete [] pass_sha1_hash;
        pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];
        
        memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);
        
        return *this;
    }
    
    std::string login;
    uint* pass_sha1_hash;
};
#endif /* Authdata_h */
