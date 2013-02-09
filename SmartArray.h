//
//  SmartArray.h
//  InlamningsUppgiftIIB
//
//  Created by Anders Akesson on 1/25/13.
//  Copyright (c) 2013 Anders Akesson. All rights reserved.
//

#ifndef InlamningsUppgiftIIB_SmartArray_h
#define InlamningsUppgiftIIB_SmartArray_h

#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class SmartArray
{
private:
    T * array;
    int sz;
    static T foo;
    
public:
    SmartArray(int s){sz=s; array=new T[sz];}
    ~SmartArray(){delete[] array;}
    
    inline int size() const {return sz;}
    inline T * get_ptr(){return array;}
    
    T& operator[](int i)
    {
        if (i>=0 && i<sz) return array[i];
        
        cerr << "out of bounds!...\n";
        return foo;
        }
        
        const T& operator[](int i) const
        {
            if (i>=0 && i<sz) return array[i];
            
            cerr << "out of bounds!...\n";
            return foo;
        }
        
        };

        template<class T>
        T SmartArray<T>::foo;
        
        template<class T>
        void read_arr(SmartArray<T> * arr)
        {
            int i;
            int size=arr->size();
            for (i=0; i<size; i++)
            {
                cout << "enter element " << i+1 << ": ";
                cin >> (*arr)[i];
            }
        }
        
        template<class T>
        void print_arr(SmartArray<T> * arr)
        {
            int i;
            int size=arr->size();
            
            cout << "{ ";
            for (i=0; i<size; i++)
            {
                cout << (*arr)[i] << ' ';
            }
            cout << '}' << endl;
        }
#endif
