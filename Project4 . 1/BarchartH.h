#include <iomanip>
#include <iostream>
#ifndef BARCHARTH_H
#define BARCHARTH_H

class BarchartH {
private:
    int t;  // variable storage 

public:
    // Constructor to initialize t
    BarchartH(int initial_value) : t(initial_value) {}

   
    void runLoop() { // runs the while loop 
        while (t < 120) { // loop starts at -30 and runs tell t > 120
            t += 3;

            // Check specific conditions and places numbers at certain values
            if (t == -30) {
                std::cout << std::setw(7) << -30;
                continue;
            }
            if (t == 0) {
                std::cout << 0;
                continue;
            }
            if (t == 27) {
                std::cout << 30;
                continue;
            }
            if (t == 54) {
                std::cout << 60;
                continue;
            }
            if (t == 81) {
                std::cout << 90;
                continue;
            }
            if (t == 108) {
                std::cout << 120 << std::endl;
                break;
            }
            else {
                std::cout << " ";
            }
        }
    }
};

#endif