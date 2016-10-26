#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Shlist.hpp"
#include "Helper.hpp"
using namespace std;


int main(){
    ifstream indexFile("index");
    if(!indexFile){
        cout << "unable to open index file\n";
        exit(-1);
    }

    int optionsCount = countOptions(indexFile);
    string items[optionsCount];
    double prices[optionsCount];
    //reset fstream flags and reading position to start reading the file from beginning
    indexFile.clear();
    indexFile.seekg(0, indexFile.beg);
    constructPriceItemArray(indexFile, items, prices);
    indexFile.close();

    string choice = "";
    do {
        choice = getUserChoice();
        if(choice == "display"){
            displayOptions();
        }
        else if (choice == "gen") {
            generateShoppingList(items, prices, optionsCount);
        }else{
            cout << "Unknown option...";
        }
    } while(choice != "exit");

    cout << "\nTerminating...\n";
	return 0;
}
