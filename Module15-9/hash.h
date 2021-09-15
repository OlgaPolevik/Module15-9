//
//  hash.h
//  Module15-9
//
//  Created by Ольга Полевик on 14.09.2021.
//

#ifndef hash_h
#define hash_h

#include <string.h>
#include "Authdata.h"

class HashTable
{
public:
    HashTable();
    ~HashTable();
    
    void add(AuthData data);
    const AuthData* find( const std::string& key ) const;
     
private:
    enum enPairStatus
    {
        free,
        engaged,
        deleted
    };

    struct Pair
    {
        Pair():
            status(enPairStatus::free)
        {
        }
        
        Pair(AuthData data):
            data(data),
            status(enPairStatus::engaged)
        {
        }
       
        bool operator == ( const Pair& other )
        {
            return  status == other.status &&
                  ( status != enPairStatus::engaged || data == other.data );
        }
                    
        AuthData data;
        enPairStatus status;
    };
    
    void resize();
    int hash_func(std::string login, int offset) const;
    
    Pair* array;
    int mem_size;
    int count;
};

#endif /* hash_h */
