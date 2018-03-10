/* Copyright 2017 Benjamin Kesselring
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// place overrides here

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
// #define RETRO_TAPPING
// #define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define LEADER_TIMEOUT 500
#define PREVENT_STUCK_MODIFIERS

#endif
