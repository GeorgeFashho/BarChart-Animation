/* barchartanimate.h - header file that holds functions to store
                       frames and animate the bar chart

        written by: [George Fashho] on [10/16/2022]
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"
#include "barchart.h"

using namespace std;

class BarChartAnimate {

private:

    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    int unsigned color = 0; // variable to keep track of color index

    string title ;
    string xlabel;
    string source;

    map<string, string> colorMap; //map to map colors to their categories

    /* addFrameStringParse(ifstream &param):
     *
     *  Function that parses a single frame, adds bars to the barchart, maps
     *  the category to a color and setsFrame name.
     *
     * @param file : file to parse
     * ...
     */
    void addFrameStringParse( ifstream &file ) {

        int frameIndex = 0;
        int value = 0 ;

        string line, name, valueStr, category, frame;

        getline(file, line);    // skipping blank line
        getline(file, line);

        if (file.good()) {

            frameIndex = stoi(line); //setting frame Size

            BarChart tempBar(frameIndex);

            while (frameIndex >= 1) {    //parses each line in frame

                getline(file, frame, ',');
                tempBar.setFrame(frame);
                getline(file, name, ',');
                getline(file, line, ',');
                getline(file, valueStr, ',');
                getline(file, category);

                if (colorMap.count(category) == 0) { //checking if category is already mapped

                    if (color == COLORS.size()) { // checking if all colors have been used before
                        color = 0;
                    }
                    colorMap[category] = COLORS[color]; //mapping category to a color
                    color++;
                }

                value = stoi(valueStr);
                tempBar.addBar(name, value, category); //adding bar to char chart
                frameIndex--;
            }
            barcharts[size] = tempBar;
            size++; //incrementing size
        }
    }

public:


    /*  Parameterized constructor:
     *  Takes in 3 parameter values for the frame.
     *  Initializes capacity of pointer to Array to be 4.
     */
    BarChartAnimate(string title, string xlabel, string source) {

        size = 0;
        capacity = 4;
        barcharts = new BarChart[capacity];
        // color = 0;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }


    /* Destructor:
    *  Automatically frees all memory allocated to the array,
    *  then points array to nullptr to avoid errors
    */
    virtual ~BarChartAnimate() {

//        for(int i = 0 ; i < barcharts->getSize() ; i++){
//             delete &barcharts[i];
//        } //Causes errors when running make file for some reason?

        if(barcharts != nullptr) {
            delete[] barcharts;
            barcharts = nullptr;
        }
    }


    /* addFrame(ifstream &file):
     *  Function that dynamically expands array when capacity is reached.
     *  If not at full capacity then calls unto function addFrameStringParse();
     *  and adds a new BarChart to the BarChartAnimate array.
     *
     *  @param file: file to parse
    */
    void addFrame(ifstream &file) {

        if(size == capacity){ //checks if capacity is reached

            int doubleCapacity = capacity *2; //doubles capacity
            BarChart *newBarChart = new BarChart[doubleCapacity]; //creates new array with new size

            for(int i = 0 ; i < size ; ++i){ //transferring old content to new array
                newBarChart[i] = this->barcharts[i];
            }

            delete [] this->barcharts;
            this->barcharts = newBarChart;
            capacity = doubleCapacity;
        }
        addFrameStringParse(file);

    }


    /* animate(ostream &output, int param1, int param2 ):
     *
     *  Function that prints out each frame in the barchart, then clears
     *  the screen to display new bar
     *
     *  @param1 : Amount of bars you would like to display
     *  @param2: Amount of frames you would like displayed
     *
   */
    void animate(ostream &output, int top, int endIter) {

        unsigned int microsecond = 50000;

        if(endIter > size || endIter == -1){
            endIter = size;
        }
        else{
            size = endIter;
        }

        for(int i = 0 ; i < endIter ; i++){

            usleep(3 * microsecond);
            output << CLEARCONSOLE;

            output << BLACK << title << endl << BLACK
                   << source << endl;

            barcharts[i].graph(output, colorMap, top);

            output << BLACK << xlabel << endl << BLACK
                   << "Frame: " << barcharts[i].getFrame()
                   << endl;
        }
    }


    /* getSize():
     * Returns number of frames added to BarChartAnimate Array
     */
    int getSize(){
        return size;
    }


     /* Returns BarChart element in BarChartAnimate. Throws
     out_of_range message if i is out of bounds         */
    BarChart& operator[](int i){

        if(i < 0 || i>= size){
            throw out_of_range("BarChartAnimate: i out of bounds");
        }

        return barcharts[i];
    }
};
