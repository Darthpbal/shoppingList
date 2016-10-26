#include <iostream>
#include <iomanip>
#include <fstream>
#include "Shlist.hpp"
using namespace std;


Shlist::Shlist(){
    subTotal = 0;
    topOfFile = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>Shopping list</title></head><body class=\"container\"><div class=\"panel panel-info\"><div class=\"panel-heading\"><h3 class=\"panel-title\">Shopping list</h3></div><div class=\"panel-body\"><table class=\"table\">";
    header = "<tr><th>Product</th><th>Quantity</th><th>lineTot</th></tr><tr><hr></tr>";
    endOfFile = "</body><footer><!-- Latest compiled and minified CSS --><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\" integrity=\"sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7\" crossorigin=\"anonymous\"<!-- Optional theme --><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css\" integrity=\"sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r\" crossorigin=\"anonymous\"<!-- Latest compiled and minified JavaScript --><script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\" integrity=\"sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS\" crossorigin=\"anonymous\"></script></footer></html>";
    openFile();
}

void Shlist::openFile(){
    outputFile.open("shoppingList.html");
    outputFile << topOfFile << endl << header;
}

void Shlist::makeRow(string name, int quantity, double lineTot){
    outputFile << "\n<tr><td><div class=\"checkbox\"><label><input type=\"checkbox\">" << name << "</label></div></td><td>" << quantity << "</td><td>$" << setprecision(4) << lineTot << "</td></tr>\n";
    subTotal += lineTot;
}

void Shlist::finishTable(){
    outputFile << "</table>\n";
}

void Shlist::printSubtot(){
    outputFile << "</div><div class=\"panel-footer\"><p>Subtotal = $" << setprecision(4) << subTotal << "</p></div></div>\n";
}

void Shlist::closeFile(){
    finishTable();
    printSubtot();
    outputFile << endOfFile;
    outputFile.close();
}
