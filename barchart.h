/* barchart.h - Holds a single frame in an array of bars
                Not Dynamically Allocated!!

        written by: [George Fashho] on [10/16/2022]
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"
#include "bar.h"

using namespace std;

const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");

// Light - Mode Terminals:
 const string RED("\033[1;36m");
 const string PURPLE("\033[1;32m");
 const string BLUE("\033[1;33m");
 const string CYAN("\033[1;31m");
 const string GREEN("\033[1;35m");
 const string GOLD("\033[1;34m");
 const string BLACK("\033[1;37m");
 const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Dark - Mode Terminals:
//const string CYAN("\033[1;36m");
//const string GREEN("\033[1;32m");
//const string GOLD("\033[1;33m");
//const string RED("\033[1;31m");
//const string PURPLE("\033[1;35m");
//const string BLUE("\033[1;34m");
//const string WHITE("\033[1;37m");
//const string RESET("\033[0m");
//const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};


class BarChart {
private:

    Bar *bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;

public:

    /* Default Constructor Intializes all variables to 0, "" or nullptr*/
    BarChart() {
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }


    /* Parameterized constructor:
     * Sets a fixed size to the array
     *
     * @param n : size of array
     */
    BarChart(int n) {
        bars = new Bar[n];
        capacity = n;
        size = 0;
        frame = "";
    }


    /* Copy constructor:
     * Automatically called to make a copy of a BarChart
     */
    BarChart(const BarChart &other) {

        this->bars = new Bar[other.capacity];
        this->capacity = other.capacity;
        this->size = other.size;
        this->frame = other.frame;

        for (int i = 0; i < other.size; ++i) {
            this->bars[i] = other.bars[i];
        }
    }


    /* Copy Operator(=):
     * Called when you assign one BarChart into another, i.e. this = other;
     * Copies the content of one BarChart into another
     */
    BarChart &operator=(const BarChart &other) {

        if (this == &other) {
            return *this;
        }

        if (other.size > 0) {
            delete[] bars;
        }

        this->capacity = other.capacity;
        this->bars = new Bar[capacity];
        this->size = other.size;
        this->frame = other.frame;

        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }

        return *this;
    }


    /* clear():
     * frees memory and resets all private member variables to default values.
     */
    void clear() {
        delete[] bars;
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }


    /* Destructor:
    *  Automatically frees all memory allocated to the array,
    *  then points array to nullptr to avoid errors
    */
    virtual ~BarChart() {
        if (bars != nullptr) {
//            for(int i = 0 ; i<size ; i++){
//                delete &bars[i];
//            }
            delete[] bars;
            bars = nullptr;
        }
    }


    /* Sets Frame Variable*/
    void setFrame(string frame) {
        this->frame = frame;
    }


    /* getFrame():
     * Returns the frame of the BarChart oboject.
     */
    string getFrame() {
        return frame;
    }


    /* addBar():
    * Adds a Bar to the BarChart.
    * returns true if successful
    * returns false if there is not room
    */
    bool addBar(string name, int value, string category) {

        Bar tempBar(name, value, category);

        if (size < capacity) {
            bars[size] = tempBar;
            size++;
            return true;
        }

        return false;
    }

    /* getSize():
     * Returns the size (number of bars) of the BarChart object.
     */
    int getSize() {
        return size;
    }


    /* operator[]:
     * Returns Bar element in BarChart.
     * This gives public access to Bars stored in the Barchart.
     * If i is out of bounds, throws an out_of_range error message:
     */
    Bar &operator[](int i) {

        if (i <0 || i >= size) {
            throw out_of_range(" Barchart: i out of bounds");
        }
        return bars[i];
    }


    /* dump():
     * Prints BarChart Objects in sorted order
     */
    void dump(ostream &output) {

        sort(bars, bars + size, greater<Bar>());
        output << "frame: " << frame << "\n";

        for (int i = 0; i < size; i++) {
            output << bars[i].getName() << " "<< bars[i].getValue() << " "<< bars[i].getCategory() << endl;
        }
    }

    /* graph(ostream, map<string, string>, int top):
     *
     * Prints out a bar using any output stream.
     *
     * @param ostream : stream youd like to print with
     * @param map<string, string> : map of catagories and colors assosatied with them
     * @param top: how many bars you want printed every frame
     */
    void graph(ostream &output, map<string, string> &colorMap, int top) {

        sort(bars, bars + size, greater<Bar>()); //sorting bars in decending order

        int lenMax = 60;

        double topValue = bars[0].getValue(); //largest bar value
        string color;
        int frameSize = this->size;

        if (top < frameSize) {
            frameSize = top;
        }

        for (int i = 0; i < frameSize; i++) {

            string barBox = "";

            if (colorMap.count(bars[i].getCategory()) > 0) {

                color = colorMap.at(bars[i].getCategory());
            }
            else {
                color = BLACK;
            }

            if (i == 0) {
                for (int j = 0; j < lenMax; j++) {
                    barBox += BOX;
                } //boxes for first bar
            }
            else{ //boxes for all other bars

                double barLenCalc = (bars[i].getValue() / topValue) * lenMax ; //calculating amount of boxes for each
                int barLen = floor(barLenCalc);                            //bar

                for(int j = 0 ; j <barLen ; j++){
                    barBox += BOX;
                }
            }

            output<< color << barBox << ' ' << bars[i].getName() //outputting bar
            << ' ' << bars[i].getValue() << endl ;
        }
    }//end graph()

};

