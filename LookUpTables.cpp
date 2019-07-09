/*
    CALCULATING THE PARITY OF THE NUMBER:

    We can directly calculate the parity by covering all bits;
    OR:
    Number : 32 Bits -- left 16 bits ^ right 16 bits - - 16bits
    left 8 bits ^ right 8 bits -- 8 bits
    Look the parity of 8 bits in LookUpTable.
*/


// Generating the look-up table while pre-processing
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

// LOOK_UP is the macro expansion to generate the table
unsigned int table[256] = { LOOK_UP };
