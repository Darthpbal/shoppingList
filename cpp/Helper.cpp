#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Helper.hpp"
#include "Shlist.hpp"
using namespace std;


string getUserChoice(){
    cout << "Welcome to the shopping list program" << endl;
    cout << "what would you like to do? (word)" << endl;
    cout << "1. display - creates a formatted text file with all options.\n";
    cout << "2. gen - run the main shopping list generator\n";
    cout << "3. exit - terminates the program.\n";
    string choice;
    cin >> choice;
    return choice;
}

void generateShoppingList(string items[], double prices[], int optionsCount){
    Shlist myShList;
    cout << "\nWhat are you thinking about buying? Item followed by quantity\n\n";
    string response = "";
    cin >> response;
    while(response != "exit"){
        int itemPos = searchArrItems(response, items, optionsCount);
        if(itemPos > -1){
            int quantity;
            cin >> quantity;
            myShList.makeRow(items[itemPos], quantity, prices[itemPos] * quantity);
        }else{
            cout << "Item not found... Add new item? (yes/no)\n";
            string confirmation;
            cin >> confirmation;
            if(confirmation == "yes") addNewItem(myShList, response);
        }
        cin >> response;
    }
    myShList.closeFile();
}

void createTextFiles(string fileName1, string fileName2, ifstream& sourceFile1, ofstream& sourceFile2){
	sourceFile1.open(fileName1.c_str());
	sourceFile2.open(fileName2.c_str());
	if(!sourceFile1 || !sourceFile2 ){
        cout << "unable to open one of the files\n";
        exit(-1);
    }
}

void displayOptions(){
    //Open input/output files
    ifstream indexFile;
    ofstream outputFile;
    createTextFiles("index", "options", indexFile, outputFile);

    //print the options header
    printHeader(outputFile);
    createOptionsFile(indexFile, outputFile);

    //cleanup files and terminal
	indexFile.close();
    outputFile.close();
}

void addNewItem(Shlist& myShList,string response){
    double unitPrice;
    int quantity;
    cout << "What's the unit price? ";
    cin >> unitPrice;
    cout << "How many? ";
    cin >> quantity;
    ofstream indexFile("index", ios::app);
    indexFile << response << "," << unitPrice << endl;
    indexFile.close();
    myShList.makeRow(response, quantity, unitPrice * quantity);
}

int getCommaPos(string line){
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ',') return i;
    }
    return 0;
}

void printHeader(ofstream& outputFile){
    outputFile << left << setw(15) << "Line name";
    outputFile << right << setw(7) << "Price" << endl;
    outputFile << "======================\n";
}

void createOptionsFile(ifstream& indexFile, ofstream& outputFile){
    while(!indexFile.eof()){
        //extract line from source file
        string line;
        getline(indexFile, line);
        //if the line isn't empty, like the common empty line @ end of file
        if(line.size()){
            //print line option label
            outputFile << left << setw(15) << line.substr(0, getCommaPos(line));
            //print option unit price
            outputFile << right << setw(7) << line.substr(getCommaPos(line) + 1, line.length()) << endl;
        }
    }
}

int countOptions(ifstream& indexFile){
    int i = 0;
    while(!indexFile.eof()){
        string line;
        getline(indexFile, line);
        if(line.size()){
            i++;
        }
    }
    return i;
}

void constructPriceItemArray(ifstream& indexFile, string items[], double prices[]){
    int i = 0;
    while(!indexFile.eof()){
        string line;
        getline(indexFile, line);
        if(line.size()){
            items[i] = line.substr(0, getCommaPos(line));
            line = line.substr(getCommaPos(line) + 1, line.length());
            prices[i] = strtod(line.c_str(), NULL);
            i++;
        }
    }
}

int searchArrItems(string needle, string hayStack[], int hayStackSize){
    for(int i = 0; i < hayStackSize; i++){
        if(needle == hayStack[i]){
            return i;
        }else{
        }
    }
    return -1;
}
