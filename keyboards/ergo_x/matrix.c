/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2015 ZSA Technology Labs Inc (@zsa)
Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)

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


/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "ergo_x.h"


/*
 * This constant define not debouncing time in msecs, assuming eager_pr.
 *
 * On Ergodox matrix scan rate is relatively low, because of slow I2C.
 * Now it's only 317 scans/second, or about 3.15 msec/scan.
 * According to Cherry specs, debouncing time is 5 msec.
 *
 * However, some switches seem to have higher debouncing requirements, or
 * something else might be wrong. (Also, the scan speed has improved since
 * that comment was written.)
 */

/* matrix state(1:on, 0:off) */
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values

static matrix_row_t read_cols(uint8_t row);
static void         init_cols(void);
static void         unselect_rows(void);
static void         select_row(uint8_t row);


void matrix_init_custom(void) {
    // initialize row and col

    unselect_rows();
    init_cols();
}

// Reads and stores a row, returning
// whether a change occurred.
static inline bool store_raw_matrix_row(uint8_t index) {
    matrix_row_t temp = read_cols(index);
    if (raw_matrix[index] != temp) {
        raw_matrix[index] = temp;
        return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    for (uint8_t i = 0; i < MATRIX_ROWS_PER_SIDE; i++) {
        // select rows from left and right hands
        uint8_t left_index  = i;
        uint8_t right_index = i + MATRIX_ROWS_PER_SIDE;
        select_row(left_index);
        select_row(right_index);

        changed |= store_raw_matrix_row(left_index);
        changed |= store_raw_matrix_row(right_index);

        unselect_rows();
    }

    return changed;
}

/* Column pin configuration
 *
 * col: 0   1   2   3   4   5
 * pin: F0  F1  F4  F5  F6  F7
 */
static void init_cols(void) {
    // init on teensy
    setPinInputHigh(F0);
    setPinInputHigh(F1);
    setPinInputHigh(F4);
    setPinInputHigh(F5);
    setPinInputHigh(F6);
    setPinInputHigh(F7);
}

static matrix_row_t read_cols(uint8_t row) {
    if (row < 7) {
		return 0; // MCP code removed from here
    } else {
        /* read from teensy
         * bitmask is 0b11110011, but we want those all
         * in the lower six bits.
         * we'll return 1s for the top two, but that's harmless.
         */

		return ~((PINF & 0x03) | ((PINF & 0xF0) >> 2));
    }
}

/* Row pin configuration
 *
 * row: 7   8   9   10  11  12  13
 * pin: B0  B1  B2  B3  D2  D3  C6
 */
static void unselect_rows(void) {
    // no need to unselect on mcp23018, because the select step sets all
    // the other row bits high, and it's not changing to a different
    // direction

    // unselect on teensy
    setPinInput(B0);
    setPinInput(B1);
    setPinInput(B2);
    setPinInput(B3);
    setPinInput(D2);
    setPinInput(D3);
    setPinInput(C6);
}

static void select_row(uint8_t row) {
    if (row < 7) {
		// MCP code removed from here
    } else {
        // select on teensy
        // Output low(DDR:1, PORT:0) to select
        switch (row) {
            case 7:
                setPinOutput(B0);
                writePinLow(B0);
                break;
            case 8:
                setPinOutput(B1);
                writePinLow(B1);
                break;
            case 9:
                setPinOutput(B2);
                writePinLow(B2);
                break;
            case 10:
                setPinOutput(B3);
                writePinLow(B3);
                break;
            case 11:
                setPinOutput(D2);
                writePinLow(D2);
                break;
            case 12:
                setPinOutput(D3);
                writePinLow(D3);
                break;
            case 13:
                setPinOutput(C6);
                writePinLow(C6);
                break;
        }
    }
}

// DO NOT REMOVE
// Needed for proper wake/sleep
void matrix_power_up(void) {
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

}
