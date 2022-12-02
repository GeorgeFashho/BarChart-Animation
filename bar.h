/* bar.h - header file that holds information for each bar element

        written by: [George Fashho] on [10/16/2022]
*/

#include <iostream>
#include <string>
#include "myrandom.h"

using namespace std;

class Bar {
 private:
    string category, name;
    int value;

 public:

    /* Default Constructor */
    Bar() {
        category = "" ;
        name = "" ;
        value = 0 ;
    }


    /*Bar(string, int, string):
     * Constructor to add variables
     *
     * @param string: name of city
     * @param int: year
     * @param string: Continent
     */
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
    }

    /* destructor: */
    virtual ~Bar() {

    }

	string getName() {
        return name ;
	}

	int getValue() {
        return value;
    }

	string getCategory() {
        return category;
	}


	/* operators( < , <= , > , >=):
	 *
	 * Allows comparison between the bars values
	 * returns true if conditions met else returns false
	 */
    bool operator<(const Bar &other) const {

        if(this->value < other.value){
        return true;
        }
        return false;
	}

	bool operator<=(const Bar &other) const {
        if(this->value <= other.value){
            return true;
        }
        return false;
	}

	bool operator>(const Bar &other) const {
        if(this->value > other.value){
            return true;
        }
        return false;
	}

	bool operator>=(const Bar &other) const {
        if(this->value >= other.value){
            return true;
        }
        return false;
	}
};

