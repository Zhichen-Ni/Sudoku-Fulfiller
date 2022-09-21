#include "container.h"
#include "observer.h"
#include "subject.h"
#include <iostream>
#include <vector>
#include "cell.h"


Cell::

Cell::Cell(): value{0}, row{nullptr}, col{nullptr}, box{nullptr}
           {  
               for (int i = 0; i < 9; i++) {
                   impossibe.emplace_back(0);
                   
               }
           }


void cantadd(Container* con, Cell* cell) {
    
    for (int i = 0; i < 9; i++) {
        
        int get = con->contained[i]->value;
        if ((get != 0) && (cell->impossibe[get - 1] == 0)) {
            cell->impossibe[get - 1] = get;
        }
    }
}


void Cell::cantaddall() {
    cantadd(row, this);
    cantadd(col, this);
    cantadd(box, this);
}

void Cell::notify() {
    for(int i = 0; i < 9; i++) {
        row->contained[i]->cantaddall();
        col->contained[i]->cantaddall();
        box->contained[i]->cantaddall();
        }
    cantaddall();
    int blank = 0;
    int left;
    for (int i = 0; i < 9; i++) {
        if (impossibe[i] == 0) {
            left = (i + 1);
            blank++;
        }
    }
    if (blank == 1) {
        setValue(left);
    }
}


void Cell::setValue(int val) {
    if ((value != 0) || (val == 0)) {
        return;
    }
   
    value = val;
    impossibe[0] = 1;
    impossibe[1] = 2;
    impossibe[2] = 3;
    impossibe[3] = 4;
    impossibe[4] = 5;
    impossibe[5] = 6;
    impossibe[6] = 7;
    impossibe[7] = 8;
    impossibe[8] = 9;
    impossibe[value -1] = 0;
    // for (int i = 0; i < 9; i++) {
    //     if (row->contained[i] != this) {
    //         row->contained[i]->notify();
    //     }
    //     if (col->contained[i] != this) {
    //         col->contained[i]->notify();
    //     }
    //     if (box->contained[i] != this) {
    //         box->contained[i]->notify();
    //     }
    // }
   
    // row->notify();
    // col->notify();
    // box->notify();
    // for (int i = 0; i < 9; i++) {
    //     row->contained[i]->box->notify();
    //     col->contained[i]->box->notify();
    // }
    notifyObservers();

}

int Cell::getValue() {
    return value;
    }