#include <iostream>
#include <stdint.h>
#include <string.h>
#include "signal/signal.hpp"

class Producer {
  public:
    // Producer will emit callback when something happens...
    sigback::Signal<int> signal_number_changed;

    void
    do_something_that_can_emit(int value) {
        signal_number_changed.emit(value);
    }

  private:
};

// Consumer will link itself to producer
class Consumer {
  public:
    void
    on_number_changed(int number) {
        std::cout << "Number changed to " << number << std::endl;
    }
};

int
main(void) {
    Producer prod;
    Consumer cons;

    // Connect consumer's function to the producer signal
    prod.signal_number_changed.connect(&Consumer::on_number_changed, &cons);

    // Producer will change number
    prod.do_something_that_can_emit(10);
    prod.do_something_that_can_emit(11);
    prod.do_something_that_can_emit(12);
    return 0;
}
