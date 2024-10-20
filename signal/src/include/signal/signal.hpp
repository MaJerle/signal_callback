/**
 * \file            signal.hpp
 * \brief           Signal callback system library for C++
 */

/*
 * Copyright (c) 2024 Tilen MAJERLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of Signal - Simple callback system for C++.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         v0.0.0
 */
#ifndef SIGNAL_CALLBACK_HDR_HPP
#define SIGNAL_CALLBACK_HDR_HPP

#include <functional>

namespace sigback {

/**
 * \brief           Default signal class implementation,
 *                  that can emit up to 3 parameters
 * 
 * \tparam T1 
 * \tparam T2 
 * \tparam T3 
 */
template <typename T1 = void, typename T2 = void, typename T3 = void>
class Signal {
  public:
    /**
     * \brief           Connect object to call on emit
     * \param           fn: Function object used as callback.
     *                      Normally used from std::bind
     */
    template <typename FN, typename OBJ>
    void
    connect(FN func_ptr, OBJ obj_ptr) {
        callback = std::bind(func_ptr, obj_ptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    /**
     * \brief           Emit function with 3 parameters
     */
    void
    emit(T1 val1, T2 val2, T2 val3) {
        if (callback != nullptr) {
            callback(val1, val2, val3);
        }
    }

  private:
    std::function<void(T1, T2, T3)> callback = nullptr;
};

/**
 * \brief           Signal implementation with 2 emitted parameters
 * 
 * \tparam T1 
 * \tparam T2 
 */
template <typename T1, typename T2>
class Signal<T1, T2, void> {
  public:
    /**
     * \brief           Connect object to call on emit
     * \param           fn: Function object used as callback.
     *                      Normally used from std::bind
     */
    template <typename FN, typename OBJ>
    void
    connect(FN func_ptr, OBJ obj_ptr) {
        callback = std::bind(func_ptr, obj_ptr, std::placeholders::_1, std::placeholders::_2);
    }

    /**
     * \brief           Emit function with 2 parameters
     */
    void
    emit(T1 val1, T2 val2) {
        if (callback != nullptr) {
            callback(val1, val2);
        }
    }

  private:
    std::function<void(T1, T2)> callback = nullptr;
};

/**
 * \brief           Signal implementation with 1 emitted parameter
 * 
 * \tparam T1 
 * \tparam T2 
 */
template <typename T1>
class Signal<T1, void, void> {
  public:
    /**
     * \brief           Connect object to call on emit
     * \param           fn: Function object used as callback.
     *                      Normally used from std::bind
     */
    template <typename FN, typename OBJ>
    void
    connect(FN func_ptr, OBJ obj_ptr) {
        callback = std::bind(func_ptr, obj_ptr, std::placeholders::_1);
    }

    /**
     * \brief           Emit function w/o any parameters as callback
     */
    void
    emit(T1 val1) {
        if (callback != nullptr) {
            callback(val1);
        }
    }

  private:
    std::function<void(T1)> callback = nullptr;
};

/**
 * \brief           Signal implementation with no emitted parameters
 * 
 * \tparam T1 
 * \tparam T2 
 */
template <>
class Signal<void, void, void> {
  public:
    /**
     * \brief           Connect object to call on emit
     * \param           fn: Function object used as callback.
     *                      Normally used from std::bind
     */
    template <typename FN, typename OBJ>
    void
    connect(FN func_ptr, OBJ obj_ptr) {
        callback = std::bind(func_ptr, obj_ptr);
    }

    /**
     * \brief           Emit function w/o any parameters as callback
     */
    void
    emit() {
        if (callback != nullptr) {
            callback();
        }
    }

  private:
    std::function<void(void)> callback = nullptr;
};
}; // namespace sigback

#endif /* SIGNAL_CALLBACK_HDR_HPP */