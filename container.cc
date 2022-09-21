#include <vector>
#include "observer.h"
#include <vector>
#include <iostream>
#include "container.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"

bool needtoadd(int lack, Cell* neighbor) {
    if (neighbor->impossibe[lack - 1] == 0) {
        return false;
    } else {
        return true;
    }
}


void Container::notify() {
    std::cout << std::endl << this << std::endl;
    for(int i = 0; i < 9; i++) {
        contained[i]->cantaddall();
        }
    // for(int i = 0; i < 9; i++) {
    //     contained[i]->notify();
        
    // }
    notifyObservers();
    for(int i = 0; i < 9; i++) {
        if (contained[i]->value == 0) {
            int lack;
            bool needadd = true;
            for (int j = 0; j < 9; j++) {
                if (contained[i]->impossibe[j] == 0) {
                int lack = j + 1;
                for (int k = 0; k < 9; k++) {
                    if (i == k) {
                    continue;
                } else {

                

                
                    if (needtoadd(lack, contained[k]) == false) {
                        needadd = false;
                    }
                }
            }
            if (needadd == true) {
                
            contained[i]->setValue(lack);
            return;
            }
        }
    }
        }
    }
    
}

Container::Container(std::vector<Cell*> contained): contained{contained} {}

Container::~Container() {
    // for (int i = 0; i < 9; i++) {
    // delete contained[i];
    // }
}

