#ifndef SHLIST_HPP
#define SHLIST_HPP

#include <string>             // For string class
#include <fstream>

using namespace std;

class Shlist{
public:
    Shlist();
    void openFile();
    void makeRow(string name, int quantity, double lineTot);
    void finishTable();
    void printSubtot();
    void closeFile();
private:
    ofstream outputFile;
    string header;
    string topOfFile;
    string endOfFile;
    double subTotal;
};

#endif // SHLIST_HPP
