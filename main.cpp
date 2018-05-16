//
//  main.cpp
//  P2
//
//  Created by this.p1.cpu(); on 10/30/17.
//  Copyright © 2017 this.p1.cpu();. All rights reserved.
//

#include "Inventory.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iterator>
#include <map>
//#include <unordered_map>

using namespace std;


int main() {
    int items = 0;
    map<string, string> mapTable;
    map<string, string> :: iterator itr;
    
    string menu = "Commands,\n\t(p)-Print List\n\t(i)-Insert Item\n\t(f)-Find Item\n\t(d)-Delete Item\n\t(n)-Number of Items\n\t(q)-Quit";
    
    bool running = true;
    while(running){
        cout << menu << endl;
        cout << "Please enter a command: ";
        char input;
        cin >> input;
        switch(input){
            case 'P':
            case 'p':
            {
                cout << "\nThe map mapTable is : \n";
                cout << "\tKEY\t\tITEM\n";
                
                for (itr = mapTable.begin(); itr != mapTable.end(); ++itr)
                {
                    cout  <<  '\t' << itr->first
                    <<  '\t' << itr->second << '\n';
                }
                cout << endl;
            }
            break;
            
            case 'I':
            case 'i':
            {
                string key;
                string item;
                cout << "Enter the key for the item: ";
                cin >> key;
                
                //checks to see if key already exsits
                if(mapTable.find(key)->first == key)
                {
                    cout << "Item key already exsits. Try again...\n" << endl;
                    break;
                }
                
                cout << "Enter the item: ";
                cin >> item;
                cout << endl;
               
                //inserts into the map
                mapTable.insert(pair<string, string> (key, item));
                items++;
            }
            break;
                
            case 'D':
            case 'd':
            {
                string key;
                cout << "What would you like to delete? Please enter key. ";
                cin >> key;
                
                if(mapTable.find(key)->first != key)
                {
                    cout << "Item key does not exsit. Try again...\n" << endl;
                    break;
                }
                mapTable.erase(key);
                cout << key << " removed \n" ;
                items--;
            }
            break;
                
            case 'F':
            case 'f':
            {
                string item;
                cout << "Which item would you like to search? ";
                cin >> item;
                if(mapTable.find(item) != mapTable.end()){
                    cout << item << " found \n \tKEY\t\tITEM\n";
                    cout <<  '\t' << mapTable.find(item)->first << '\t' << mapTable.find(item)->second << '\n';
                }else{
                    cout << "Item not found...\n" << endl;
                }
            }
            break;
                
            case 'N':
            case 'n':
                cout << "Total number of items: " << items << endl;
                break;
                
            case 'Q':
            case 'q':
                running = false;
                break;
                
            default:
                cout << "Invalid input. Try again..." << endl;
        }
    }
    
    return 0;
};
