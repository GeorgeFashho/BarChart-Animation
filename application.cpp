// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago

    /*                  Edited by: [George Fashho] on [10/16/2022]
     *
     *                          [CREATIVE COMPONENT]
     *
     *             Menu Interface that allows user to enter a filename,
     *             how many bars to display, and the time frame for
     *                     what they would like to view!
     *
     *      I believe that this is an important addition to add more of a real
     *      program feel to this application. Users are able to interact freely with the
     *      menu options and chose what they would like to view from the bar chart
     *
     *
     *                                                                                  */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"

using namespace std;


int main() {
    ifstream inFile;

    string filename;
    cout<< "Please enter a file name you'd like to display: \n";
    cin>>filename;


    inFile.open(filename);

    while(!inFile.is_open()){

        cout<<"You entered an invalid filename!\n";
        cout<< "Please enter a file name you'd like to display: \n";
        cin>>filename;
        inFile.open(filename);
    }

    string title;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);

    BarChartAnimate bca(title, xlabel, source);

    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }




    cout<<"Choose from the list below Top(number) to display \n"
          "or 0 to enter a specified amount: \n"
        <<"(1) Top 5\n"
        <<"(2) Top 10\n"
        <<"(3) Top 15\n"
        <<"(4) Top 20\n";

    int userChoice ;
    int top = 0;
    cin >>userChoice;

    switch(userChoice){
        case 0:
            cout<<"Please specify a number of bars to display: \n";
            cin>>top;
            break;

        case 1:
            top = 5;
            break;

        case 2:
            top = 10;
            break;

        case 3:
            top = 15;
            break;

        case 4:
            top = 20;
            break;

        default:
            cout<<"Not a valid option! >:(";
            return 0;
    }


    cout<<"Please chose how much of the data you would like to view: \n";
    cout<<"(1) All the data\n"
        <<"(2) Specific amount\n";

    cin>>userChoice ;
    int endIter = 0;

    switch(userChoice){
        case 1:
            endIter = -1;
            break;
        case 2:
            cout<<"Please enter a time frame: \n";
            cin>>endIter;
            break;

        default:
            cout<<"Not a valid option! >:(";
            return 0;
    }


    bca.animate(cout,top,endIter);

    return 0;
}
