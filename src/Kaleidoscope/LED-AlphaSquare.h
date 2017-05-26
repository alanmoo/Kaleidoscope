/* -*- mode: c++ -*-
 * Kaleidoscope-LED-AlphaSquare -- 4x4 pixel LED alphabet
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>

#define SYM4x4(                                                   \
               p00, p01, p02, p03,                                \
               p10, p11, p12, p13,                                \
               p20, p21, p22, p23,                                \
               p30, p31, p32, p33                                 \
              )                                                   \
  (uint16_t) (                                                    \
              p00 <<  0 | p01 <<  1 | p02 <<  2 | p03 <<  3 |     \
              p10 <<  4 | p11 <<  5 | p12 <<  6 | p13 <<  7 |     \
              p20 <<  8 | p21 <<  9 | p22 << 10 | p23 << 11 |     \
              p30 << 12 | p31 << 13 | p32 << 14 | p33 << 15       \
             )

namespace KaleidoscopePlugins {
class AlphaSquare : public KaleidoscopePlugin {
  public:
    AlphaSquare (void);

    virtual void begin (void) final;

    static void display (Key key, uint8_t row, uint8_t col, cRGB keyColor);
    static void display (Key key, uint8_t row, uint8_t col);
    static void display (Key key) {
        display (key, 0, 2);
    };
    static void display (Key key, uint8_t col) {
        display (key, 0, col);
    };

    static void display (uint16_t symbol, uint8_t row, uint8_t col, cRGB keyColor);
    static void display (uint16_t symbol, uint8_t row, uint8_t col);
    static void display (uint16_t symbol) {
        display (symbol, 0, 2);
    };
    static void display (uint16_t symbol, uint8_t col) {
        display (symbol, 0, col);
    };

    static void clear (Key key, uint8_t row, uint8_t col) {
        display (key, row, col, {0, 0, 0});
    };
    static void clear (Key key, uint8_t col) {
        clear (key, 0, col);
    };
    static void clear (Key key) {
        clear (key, 0, 2);
    };

    static void clear (uint16_t symbol, uint8_t row, uint8_t col) {
        display (symbol, row, col, {0, 0, 0});
    };
    static void clear (uint16_t symbol, uint8_t col) {
        clear (symbol, 0, col);
    };
    static void clear (uint16_t symbol) {
        clear (symbol, 0, 2);
    };

    static cRGB color;
};
};

extern KaleidoscopePlugins::AlphaSquare AlphaSquare;
