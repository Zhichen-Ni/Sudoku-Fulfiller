#ifndef CELL_H_
#define CELL_H_
#include "container.h"
#include "observer.h"
#include "subject.h"
class Cell : public Observer, public Subject {
    public:
    std::vector<int> impossibe;
    
    int value;
    Container *row;
    Container *col;
    Container *box;
    
    // You may add any fields or private helpers you
    // see fit, so long as you are still implementing
    // the observer pattern.
  public:
    Cell();
    virtual void notify() override;
    // Suggested helper function, sets the value of this cell
    // and notifies observers.
    void setValue(int);
    // Suggested helper function, returns the value of this
    // cell.
    int getValue();
    // You may add any public helpers/getters/setters you
    // see fit, so long as you are still implementing
    // the observer pattern.

    void cantaddall();
};

#endif
