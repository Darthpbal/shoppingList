#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <fstream>
#include "Shlist.hpp"

string getUserChoice();
void generateShoppingList(string items[], double prices[], int optionsCount);
void createTextFiles(string fileName1, string fileName2, ifstream& sourceFile1, ofstream& sourceFile2);
void displayOptions();
void addNewItem(Shlist& myShList,string response);
int getCommaPos(string line);
void printHeader(ofstream& outputFile);
void createOptionsFile(ifstream& indexFile, ofstream& outputFile);
int countOptions(ifstream& indexFile);
void constructPriceItemArray(ifstream& indexFile, string items[], double prices[]);
int searchArrItems(string needle, string hayStack[], int hayStackSize);

#endif
