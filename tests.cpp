/* tests.cpp - Multiple tests to make sure all functions work
                properly.
        written by: [George Fashho] on [10/16/2022]
*/

#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() { //tests default constructor
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool operatorTests(){ //tests operators on values
    Bar Chicago("Chicago", 9234324, "US");
    Bar LV("LosVegas", 1000, "US");
    Bar NY("NewYork", 1000, "US");

    if(!(Chicago > LV)){
        cout<< "operatorTests: > failed\n";
        return false;
    }
    else if( !(LV >= NY)){
        cout<< "operatorTests: >= failed\n";
        return false;

    }
    else if( !(LV <= NY)){
        cout<< "operatorTests: <= failed\n";
        return false;

    }
    else if( !(LV < Chicago)){
        cout<< "operatorTests: >= failed\n";
        return false;

    }
    cout<<"operatorTests: all passed!\n";
    return true;
}


bool testBarChart(){ //tests BarChart Constructor

    Bar b("Chicago", 9234324, "US");
    BarChart f1(1);
    f1.addBar("Chicago", 9234324, "US");

    if(f1[0].getName() != "Chicago"){
        cout<<"testBarChart: getName() failed!"<<endl;
        return false;
    }

    cout<<" testBarChart: all passed!"<<endl;
    return true;
}

bool defaultBarChart(){ //tests default constructor

    BarChart defaultChart;

    if(defaultChart.getSize() != 0 ){
        cout<<"defaultBarChart: getSize() = 0 failed!\n";
        return false;
    }
    else if(defaultChart.getFrame() != "") {
        cout << "defaultBarChart: getFrame() = '' failed!\n";
        return false;
    }

    cout<<" defaultBarChart: all passed!"<<endl;
    return true;
}

bool SizedBarChart(){ // tests parametrized constructor

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing",672,"Asia");
    SizedChart.addBar("Cairo",400,"MiddleEast");
    SizedChart.addBar("Cuttack",140,"Asia");
    SizedChart.addBar("Fez",130,"MiddleEast");


    if(SizedChart.getSize() != 4 ){
        cout<<"SizedBarChart: getSize() = 4 failed!\n";
        return false;
    }

    else if(!(SizedChart.getFrame().empty())) {
        cout << "SizedBarChart: getFrame() = '' failed!\n";
        return false;
    }

    else if( SizedChart[3].getName() != "Fez"){
        cout << "SizedBarChart: getName() = 'Fez' failed!\n";
        return false;
    }

    else if( SizedChart[3].getValue() != 130){
        cout << "SizedBarChart: getValue() = 130 failed!\n";
        return false;
    }

    else if( SizedChart[3].getCategory() != "MiddleEast"){
        cout << "SizedBarChart: getCategory() = 'MiddleEast' failed!\n";
        return false;
    }

    cout<<" SizedBarChart: all passed!"<<endl;
    return true;
}

bool copyBarChartOperator() { //tests copy constructor operator

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing", 672, "Asia");
    SizedChart.addBar("Cairo", 400, "MiddleEast");
    SizedChart.addBar("Cuttack", 140, "Asia");
    SizedChart.addBar("Fez", 130, "MiddleEast");

    BarChart copyBarChart;
    copyBarChart = SizedChart;

    if(copyBarChart.getSize() != 4 ){
        cout<<"copyBarChartOperator: getSize() = 4 failed!\n";
        return false;
    }
    else if(copyBarChart.getFrame() != "") {
        cout << "copyBarChartOperator: getFrame() = '' failed!\n";
        return false;
    }
    else if(copyBarChart[3].getName() != "Fez"){
        cout << "copyBarChartOperator: getName() = 'Fez' failed!\n";
        return false;

    }
    else if(copyBarChart[3].getValue() != 130){
        cout << "copyBarChartOperator: getValue() = 130 failed!\n";
        return false;

    }
    else if(copyBarChart[3].getCategory() != "MiddleEast"){
        cout << "copyBarChartOperator: getCategory() = 'MiddleEast' failed!\n";
        return false;

    }

    cout<<" copyBarChartOperator: all passed!"<<endl;
    return true;


}

bool copyBarChart() { //tests in copy constructor function

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing", 672, "Asia");
    SizedChart.addBar("Cairo", 400, "MiddleEast");
    SizedChart.addBar("Cuttack", 140, "Asia");
    SizedChart.addBar("Fez", 130, "MiddleEast");

    BarChart copyBarChart(SizedChart);

    if(copyBarChart.getSize() != 4 ){
        cout<<"copyBarChart: getSize() = 4 failed!\n";
        return false;
    }
    else if(copyBarChart.getFrame() != "") {
        cout << "copyBarChart: getFrame() = '' failed!\n";
        return false;
    }
    else if(copyBarChart[3].getName() != "Fez"){
        cout << "copyBarChart: getName() = 'Fez' failed!\n";
        return false;

    }
    else if(copyBarChart[3].getValue() != 130){
        cout << "copyBarChart: getValue() = 130 failed!\n";
        return false;

    }
    else if(copyBarChart[3].getCategory() != "MiddleEast"){
        cout << "copyBarChart: getCategory() = 'MiddleEast' failed!\n";
        return false;

    }

    cout<<" copyBarChart: all passed!"<<endl;
    return true;
}

bool barChartClear(){ //tests clear() function

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing", 672, "Asia");
    SizedChart.addBar("Cairo", 400, "MiddleEast");
    SizedChart.addBar("Cuttack", 140, "Asia");
    SizedChart.addBar("Fez", 130, "MiddleEast");

    SizedChart.clear();

    if(SizedChart.getSize() != 0){
        cout << "barChartClear: .clear() failed!\n";
        return false;
    }
    cout<<" barChartClear: all passed!"<<endl;
    return true;

}

bool getFrame(){ //tests getFrame function

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing", 672, "Asia");
    SizedChart.addBar("Cairo", 400, "MiddleEast");
    SizedChart.addBar("Cuttack", 140, "Asia");
    SizedChart.addBar("Fez", 130, "MiddleEast");

    SizedChart.setFrame("1500");

    if(SizedChart.getFrame() != "1500"){
        cout << "getFrame() failed!\n";
        return false;
    }
    SizedChart.setFrame("1501");

    if(SizedChart.getFrame() != "1501"){
        cout << "getFrame() failed!\n";
        return false;
    }

    cout<<" getFrame: all passed!"<<endl;
    return true;

}

bool dumpFunction() { //tests dump function

    BarChart SizedChart(20);

    SizedChart.addBar("Beijing", 672, "Asia");

    SizedChart.setFrame("1500");
    stringstream s("");
    SizedChart.dump(s);

    if(s.str() != "frame: 1500\nBeijing 672 Asia\n"){
        cout << "dump() failed!\n";
        return false;
    }
    SizedChart.addBar("Cairo", 400, "MiddleEast");

    stringstream s2("");
    SizedChart.dump(s2);

    if(s2.str() != "frame: 1500\nBeijing 672 Asia\nCairo 400 MiddleEast\n"){
        cout << "dump() failed!\n";
        return false;
    }

    cout<<" dump(): all passed!"<<endl;
    return true;

}

            /*TESTS BELOW ALL PRINT OUT GRAPHS*/
    /*Comment out the text file you would like to view*/

    /*tests for amount of frames printed returns true
                         if valid                  */
bool animationsCities(){

    string filename = "cities.txt";
    ifstream inFile(filename);
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

    bca.animate(cout, 12, -1);

    if(bca.getSize() != (2018-1500)){
        cout<< "BarChartAnimate: FAILED!";
        return false;
    }

    cout<<" BarChartAnimate(): all passed!"<<endl;
    return true;

}

void animationGOT(){
    string filename = "game-of-thrones.txt";
    ifstream inFile(filename);
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

    bca.animate(cout, 12, -1);

}

void animationEndGame(){
    string filename = "endgame.txt";
    ifstream inFile(filename);
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

    bca.animate(cout, 20, -1);

}


int main() {

    testBarDefaultConstructor();
	testBarParamConstructor();
    operatorTests();
    testBarChart();
    defaultBarChart();
    SizedBarChart();
    copyBarChartOperator();
    copyBarChart();
    barChartClear();
    getFrame();
    dumpFunction();

    //uncomment to view graphs printed!
//    animationsCities();
//    animationGOT();
//    animationEndGame();

    return 0;

}

