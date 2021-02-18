#include "bytePrinter.hh"

#include <iostream>

BytePrinter::BytePrinter(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(printData);
}

void BytePrinter::printData() {
  while (true) {
    wait(dataReady.posedge_event());

    uint8_t value = inputSig.read();

    std::cout << value;

    assertRead = true;
  }
}