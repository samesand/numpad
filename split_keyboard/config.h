/*
Copyright 2018 Yiancar

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { B2, B6, B5, B4, D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGB_DI_PIN D0
#define RGBLED_NUM 7

#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 3
#define RGBLIGHT_DEFAULT_HUE 100

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define AUTO_SHIFT_TIMEOUT 300