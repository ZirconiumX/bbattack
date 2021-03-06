/*
 * MIT License
 *
 * Copyright (c) 2017 Dan Ravensloft
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef BBATTACK_H
#define BBATTACK_H

#include <stdint.h>

// Which bitboard attack generation system should be used?
// Note: don't define multiple attack systems, because you'll get linker errors.

// The classical approach from Chess 4.5.
// Low memory, medium speed.
#define USE_CLASSICAL

// Dumb7Fill, based on the code from the Chess Programming Wiki.
// Near-zero memory, very slow, could be faster with a smart compiler.
//#define USE_DUMB7FILL

// Hyperbola Quintessence, based in part on the code from Amoeba.
// Low memory, reasonably fast, worse on Intel compared to AMD.
//#define USE_HYPERBOLA

// Michael Hoffman's Obstruction Difference. Similiarish to HQ.
// Low memory, reasonably fast. 
//#define USE_OBSTRUCTION

// Steffan Westcott's Kogge-Stone algorithm.
// Near-zero memory, faster than Dumb7Fill.
//#define USE_KOGGE_STONE

// Volker Annuss' fixed-shift fancy magic bitboards.
// High memory, very fast.
//#define USE_MAGIC

// Syed Fahad's Subtraction-based Attack Mask Generation algorithm.
// Low memory, about HQ speed.
//#define USE_SBAMG

// Dann Corbit's "switch" approach. May God have mercy on your soul.
// Zero memory, very long compile time, about Kogge-Stone speed.
//#define USE_SWITCH

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

// Initialisation code
extern void BBAttackInit();

// Bishop sliding moves
extern uint64_t BBAttackBishop(const uint64_t occupancy, const unsigned int square);

// Rook sliding moves
extern uint64_t BBAttackRook(const uint64_t occupancy, const unsigned int square);

// Helper for queen sliding moves
static uint64_t BBAttackQueen(const uint64_t occupancy, const unsigned int square)
{
    return BBAttackBishop(occupancy, square) | BBAttackRook(occupancy, square);
}

#ifdef __cplusplus
}
#endif

#endif // #ifndef BBATTACK_H
