//
// Created by pedro on 02/12/2021.
//

#ifndef AED_PROJ1_INPUT_H
#define AED_PROJ1_INPUT_H


#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Date.h"

using namespace std;

#define MAX_NAME_LENGHT 20

namespace input {
    /**
     * Get a string from cin
     * @return string
     */
    string getRaw();


    /**
     * Convert a string to a var of type T
     * @tparam T - Type with defined >> operator
     * @param str - String to be read
     * @param var - Output after reading
     * @return true if operation was successful
     */
    template<typename T>
    bool strToVar(const string &str, T &var) {
        istringstream ss{str};
        ss >> var;
        if (ss.fail() || !ss.eof()) {
            return false;
        }
        return true;
    }

    /**
     * Get a var of type T from cin
     * @tparam T - Type with defined >> operator
     * @param var - Output
     * @return true if operation was successful
     */
    template<typename T>
    bool get(T &var) {
        string str = getRaw();
        if (str.empty()) {
            return false;
        }
        return strToVar(str, var);
    }

    /**
     * Wait for user to press enter
     */
    void waitEnter();

    void trimString(string &str);
    /**
     * Check if name is valid
     * @param name
     * @return true if valid
     */
    bool validateID(const string &userid);

    /**
     * Check if name is valid
     * @param name
     * @return true if valid
     */

}

#endif //AED_PROJ1_INPUT_H
