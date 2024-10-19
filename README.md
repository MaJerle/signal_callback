# Signal callback

Signal callback library is an easy to use callback system for C++ applications.

Its purpose is to allow different objects to communicate between each other by emitting the callback functions
to the class that has connected to the signal.

> Name signal is inspired by Qt naming convention.

This method is very useful when C++ implements classes with *has-a* relation, where
another object may want to notify the parent when some event occurs.

Main motivation behind the library is to simplify events data between GUI development and its UI widgets,
where parent widget might want to get notified about events coming from the children object.

## Features

* Lightweight and easy to use, developed in C++
* Template classes for `0-3` parameters callback system
* Available as CMake interface library
* User friendly MIT license

## How to use

1. In your producer class define new signal with its appropriate type:

```cpp
sigback::Signal<int> signal_with_int_type;
```

2. Connect your producer callback function to the signal:

```cpp
signal_with_int_type.connect(&ClassName::method_name, &classobject);
```

3. Call emit function in producer class

```cpp
signal_with_int_type.emit(10);
```

Full example

```cpp
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

```

## Contribute

Fresh contributions are always welcome. Simple instructions to proceed:

1. Fork Github repository
2. Follow [C style & coding rules](https://github.com/MaJerle/c-code-style) already used in the project
3. Create a pull request to develop branch with new features or bug fixes

Alternatively you may:

1. Report a bug
2. Ask for a feature request
