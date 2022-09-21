#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <vector>
#include "observer.h"
#include "subject.h"
class Cell;
class Container : public Subject, public Observer {
  public:
    std::vector<Cell*> contained;
  public:
    virtual void notify() override;
    Container(std::vector<Cell*>);
    virtual ~Container();
    // You may add additional helper functions, public or private.
    // But you must ensure you are still implementing the observer pattern.
};
#endif
