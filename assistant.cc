#include <vector>
#include <iostream>
#include "cell.h"
#include "assistant.h"
using namespace std;





Assistant::Assistant() {

    for (int i = 0; i < 9; i++) {
        vector<Cell*> line;
        for (int j = 0; j < 9; j++) { 
            Cell* cell = new Cell();
            line.emplace_back(cell);
            
    }
    cells.emplace_back(line);
    }


 
    
    for (int i = 0; i < 9; i++) {
        vector<Cell*> line;
      for (int j = 0; j < 9; j++) {
            line.emplace_back(cells[i][j]);
      }
      Container* newcon = new Container(line);
   
      for (int j = 0; j < 9; j++) {
            cells[i][j]->row = newcon;
      }
      rows.emplace_back(newcon);
    }




    for (int i = 0; i < 9; i++) {
        vector<Cell*> line;
      for (int j = 0; j < 9; j++) {
            line.emplace_back(cells[j][i]);
      }
      Container* newcon = new Container(line);
      for (int j = 0; j < 9; j++) {
            cells[j][i]->col = newcon;
      }
      cols.emplace_back(newcon);
    }


    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<Cell*> blo;
            blo.emplace_back(cells[i][j]);
            blo.emplace_back(cells[i][j + 1]);
            blo.emplace_back(cells[i][j + 2]);
            blo.emplace_back(cells[i + 1][j]);
            blo.emplace_back(cells[i + 1][j + 1]);
            blo.emplace_back(cells[i + 1][j + 2]);
            blo.emplace_back(cells[i + 2][j]);
            blo.emplace_back(cells[i + 2][j + 1]);
            blo.emplace_back(cells[i + 2][j + 2]);
            Container* newblo = new Container(blo);
            cells[i][j]->box = newblo;
            cells[i][j + 1]->box = newblo;
            cells[i][j + 2]->box = newblo;
            cells[i + 1][j]->box = newblo;
            cells[i + 1][j + 1]->box = newblo;
            cells[i + 1][j + 2]->box = newblo;
            cells[i + 2][j]->box = newblo;
            cells[i + 2][j + 1]->box = newblo;
            cells[i + 2][j + 2]->box = newblo;
            boxes.emplace_back(newblo);
        }  
    }


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j ++) {
            cells[i][j]->attach(cells[i][j]->row);
            cells[i][j]->attach(cells[i][j]->col);
            cells[i][j]->attach(cells[i][j]->box);
            for (int k = 0; k < 9; k ++) {
            cells[i][j]->attach((cells[i][j]->row->contained[k]->box));
            cells[i][j]->attach((cells[i][j]->col->contained[k]->box));
            }
        
    



            // for (int k = 0; k < 9; k++) {
            // cells[i][j]->attach(rows[k]);
            // cells[i][j]->attach(cols[k]);
            // cells[i][j]->attach(boxes[k]);
            // }
        }
    }


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j ++) {
            rows[i]->attach(cells[i][j]);
            cols[j]->attach(cells[i][j]);
        }


        // for (int j = 0; j < 9; j ++) {
        //     for (int k = 0; k < 9; k++) {
        //         rows[i]->attach(cells[j][k]);
        //         cols[i]->attach(cells[j][k]);
        //         boxes[i]->attach(cells[j][k]);
        //     }
        // }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j ++) {
            boxes[i]->attach((boxes[i]->contained[j]));
        }
    }



    
}





std::istream& operator>>(std::istream & in, Assistant & g) {
    string s;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j += 3) {
            in >> s;

     
            for (int k = 0; k < 3; k++) {
                
                if ((s[k] <= '9') && (s[k] >= '1')) {
                    int val = (s[k] - '0');
                    if (k == 2) {
                       
                    }
                    g.cells[i][j + k]->setValue(val);
                } else {
                    g.cells[i][j + k]->setValue(0);
                }
            }
        }
    }
    
    return in;
}



std::ostream& operator<<(std::ostream & out, const Assistant & g) {
   int linenum = 0;
   int blocknum = 0;
    for (int i = 0; i < 9; i++) {
        int st = 0;
        for (int j = 0; j < 9; j += 3) {
            // std::cout << (g.cells[8][8]->impossibe[7]) << "asdf";
            if (g.cells[i][j]->value != 0) {
                cout << g.cells[i][j]->impossibe[7];
            // cout << g.cells[i][j]->value;
            } else {
                // cout << "-";
                cout << g.cells[i][j]->impossibe[7];
            }
            if (g.cells[i][j+1]->value != 0) {
            // cout << g.cells[i][j+1]->value;
            cout << g.cells[i][j]->impossibe[7];
            } else {
                // cout << "-";
                cout << g.cells[i][j]->impossibe[7];
            }
            if (g.cells[i][j+2]->value != 0) {
            // cout << g.cells[i][j+2]->value;
            cout << g.cells[i][j]->impossibe[7];
            } else {
                cout << g.cells[i][j]->impossibe[7];
                // cout << "-";
            }
            if (st < 2) {
            cout << " ";
            st += 1;
            }
        }
        cout << endl;
        linenum++;
        if ((linenum == 3) && (blocknum < 2)) {
            cout << endl;
            linenum = 0;
            blocknum ++;
        }
    }
    std::cout << (g.cells[7][8]->impossibe[7]);
return out;
}





Assistant::~Assistant() {
    for (int i = 0; i < 9; i++) {
        delete rows[i];
        delete cols[i];
        delete boxes[i];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            delete cells[i][j];
        }
    }
}

