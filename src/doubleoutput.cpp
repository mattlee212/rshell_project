#include "../header/doubleoutput.hpp"

int DoubleOutput::run() {
    int savestdout = dup(1);
    int file = open(right->run.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0664);
    dup2(file, 1);
    if (left->run() == -1){
        return -1;
    }
    dup2(savestdout, 1);
    return 1;
}
