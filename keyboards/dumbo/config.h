/*
Copyright 2020 Adam Naldal <adamnaldal@gmail.com>
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


// wiring
#define MATRIX_ROW_PINS { D4, D7, E6, B4 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6}

#define ENCODERS_PAD_A { F4, C6 }
#define ENCODERS_PAD_B { F5, B5 }
#define ENCODERS_PAD_A_RIGHT { F5, B5 }
#define ENCODERS_PAD_B_RIGHT { F4, C6 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
