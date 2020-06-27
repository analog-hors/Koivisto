//
// Created by finne on 5/31/2020.
//

#include <iomanip>
#include "eval.h"


Score psqt_pawn_endgame[] = {
        0,  0,  0,  0,  0,  0,  0,  0,
        3,  3,  2, -1,  2,  5,  4,  4,
        2,  4,  4,  3,  5,  4,  5,  3,
        5, 10,  2,  3,  3,  4,  6, -1,
        19, 20, 15,  7,  7, 26, 25, 19,
        61, 68, 52, 44, 55, 65, 79, 65,
        98, 73, 80, 67, 75, 80, 80, 90,
        0,  0,  0,  0,  0,  0,  0,  0
};

Score psqt_pawn[] = {
        0,  0,  0,  0,  0,  0,  0,  0,
        7, 11, -3,-26,  8,  8,  8, 14,
        -7,-13,  0, -9,  0,-20,  6,-10,
        -13,  0, -5,  7, -2,-21,-16,-36,
        7, 13, 14, 18, 16, 19,  4,  0,
        22, 39, 59, 52, 45, 45, 31, 22,
        46, 53, 56, 57, 63, 41, 45, 29,
        0,  0,  0,  0,  0,  0,  0,  0
};

Score psqt_knight[] = {
        -50,-40,-30,-30,-30,-30,-40,-50,
        -40,-20,  0,  0,  0,  0,-20,-40,
        -30,  0, 10, 15, 15, 10,  0,-30,
        -30,  5, 15, 20, 20, 15,  5,-30,
        -30,  0, 15, 20, 20, 15,  0,-30,
        -30,  5, 10, 15, 15, 10,  5,-30,
        -40,-20,  0,  5,  5,  0,-20,-40,
        -50,-40,-30,-30,-30,-30,-40,-50,
};



Score psqt_bishop[] = {
        -37,-4,-36,-42,-31,-23,-17,-34,
        -2,4,-3,2,0,11,2,50,
        -11,-5,12,6,10,9,5,-11,
        -17,11,17,19,35,11,24,-10,
        17,10,22,44,20,37,-2,16,
        5,19,29,46,42,43,30,5,
        -12,24,52,30,42,34,21,5,
        51,17,20,48,24,7,16,57
};

Score psqt_bishop_endgame[] = {
        -44,-1,-23,-20,-17,-15,-3,-31,
        -4,4,-2,0,0,7,1,12,
        -2,0,1,13,14,1,1,-2,
        0,19,15,13,18,14,21,0,
        22,10,30,27,13,40,6,28,
        17,23,32,44,50,50,34,19,
        -1,17,29,35,35,31,27,3,
        40,45,36,55,43,30,50,31
};




Score psqt_rook[] = {
        0,  0,  0,  0,  0,  0,  0,  0,
        5, 10, 10, 10, 10, 10, 10,  5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        0,  0,  0,  5,  5,  0,  0,  0
};

Score psqt_queen[] = {
        -20,-10,-10, -5, -5,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5,  5,  5,  5,  0,-10,
        -5,  0,  5,  5,  5,  5,  0, -5,
        0,  0,  5,  5,  5,  5,  0, -5,
        -10,  5,  5,  5,  5,  5,  0,-10,
        -10,  0,  5,  0,  0,  0,  0,-10,
        -20,-10,-10, -5, -5,-10,-10,-20
};

Score psqt_king[] = {
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -20,-30,-30,-40,-40,-30,-30,-20,
        -10,-20,-20,-20,-20,-20,-20,-10,
        20, 20,  0,  0,  0,  0, 20, 20,
        20, 30, 10,  0,  0, 10, 30, 20
};
Score psqt_king_endgame[] = {
        -50,-40,-30,-20,-20,-30,-40,-50,
        -30,-20,-10,  0,  0,-10,-20,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-30,  0,  0,  0,  0,-30,-30,
        -50,-30,-30,-30,-30,-30,-30,-50
};


int unusedVariable = 0;

int INDEX_PAWN_VALUE = unusedVariable++;
int INDEX_PAWN_PSQT = unusedVariable++;
int INDEX_PAWN_STRUCTURE = unusedVariable++;
int INDEX_PAWN_PASSED = unusedVariable++;
int INDEX_PAWN_ISOLATED = unusedVariable++;
int INDEX_PAWN_DOUBLED = unusedVariable++;
int INDEX_PAWN_DOUBLED_AND_ISOLATED = unusedVariable++;

int INDEX_KNIGHT_VALUE = unusedVariable++;
int INDEX_KNIGHT_PSQT = unusedVariable++;
int INDEX_KNIGHT_MOBILITY = unusedVariable++;
int INDEX_KNIGHT_OUTPOST = unusedVariable++;

int INDEX_BISHOP_VALUE = unusedVariable++;
int INDEX_BISHOP_PSQT = unusedVariable++;
int INDEX_BISHOP_MOBILITY = unusedVariable++;
int INDEX_BISHOP_DOUBLED = unusedVariable++;
int INDEX_BISHOP_PAWN_SAME_SQUARE = unusedVariable++;
int INDEX_BISHOP_FIANCHETTO = unusedVariable++;

int INDEX_ROOK_VALUE = unusedVariable++;
int INDEX_ROOK_PSQT = unusedVariable++;
int INDEX_ROOK_MOBILITY = unusedVariable++;
int INDEX_ROOK_OPEN_FILE = unusedVariable++;
int INDEX_ROOK_HALF_OPEN_FILE = unusedVariable++;
int INDEX_ROOK_KING_LINE = unusedVariable++;

int INDEX_QUEEN_VALUE = unusedVariable++;
int INDEX_QUEEN_PSQT = unusedVariable++;
int INDEX_QUEEN_MOBILITY = unusedVariable++;

int INDEX_KING_SAFETY = unusedVariable++;
int INDEX_KING_PSQT = unusedVariable++;
int INDEX_KING_CLOSE_OPPONENT = unusedVariable++;
int INDEX_KING_PAWN_SHIELD = unusedVariable++;


double* _pieceValuesEarly = new double[unusedVariable]{
        98.6423,       16.5249,       2.99681,      -14.4001,      -12.5356,      0.171409,      -23.6882,       376.415,       61.2558,       29.3162,       41.5542,       424.944,       34.5504,       23.6178,       27.7169,      -4.37584,       11.9598,       558.332,       141.602,       12.1858,       47.2119,        18.385,       23.3907,       1165.71,      -0.03737,       7.46494,       366.888,       239.123,       -64.153,       13.2171,
    
};

double* _pieceValuesLate = new double[unusedVariable]{
        118.648,        186.64,       3.24607,       42.0323,      -10.9291,      -9.90538,      -24.8109,       358.821,       107.184,       23.4736,       33.4458,        312.52,       3.10072,       40.8573,       62.9856,       6.44621,         10.15,       639.243,        117.64,       28.3109,       3.98184,      -1.75178,       4.39457,       1181.54,       112.675,       62.2153,      -23.3872,       50.5677,       51.2386,      -2.42515,
    
    
    
};

//TODO tweak values
double _kingSafetyTable[100] {
        0  ,   0,   1,   2,   3,   5,   7,   9,  12,  15,
        18 ,  22,  26,  30,  35,  39,  44,  50,  56,  62,
        68 ,  75,  82,  85,  89,  97, 105, 113, 122, 131,
        140, 150, 169, 180, 191, 202, 213, 225, 237, 248,
        260, 272, 283, 295, 307, 319, 330, 342, 354, 366,
        377, 389, 401, 412, 424, 436, 448, 459, 471, 483,
        494, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500
};



double* _features          = new double[unusedVariable];

double  _phase;

/**
 * adds the factor to value of attacks if the piece attacks the kingzone
 * @param attacks
 * @param kingZone
 * @param pieceCount
 * @param valueOfAttacks
 * @param factor
 */
void addToKingSafety(U64 attacks, U64 kingZone, int &pieceCount, int &valueOfAttacks, int factor){
    if(attacks & kingZone){
        pieceCount ++;
        valueOfAttacks += factor * bitCount(attacks & kingZone);
    }
}

/**
 * checks if the given square is an outpost given the color and a bitboard of the opponent pawns
 */
bool isOutpost(Square s, Color c, U64 opponentPawns, U64 pawnCover){
    U64 sq = ONE << s;
    
    if(c == WHITE){
        if(((whitePassedPawnMask[s] & ~FILES[fileIndex(s)]) & opponentPawns) == 0 && (sq & pawnCover)){
            return true;
        }
    }else{
        if(((blackPassedPawnMask[s] & ~FILES[fileIndex(s)]) & opponentPawns) == 0 && (sq & pawnCover)){
            return true;
        }
    }
    return false;
    
}


/**
 * evaluates the board.
 * @param b
 * @return
 */
bb::Score Evaluator::evaluate(Board *b) {
    
    Score res = 0;
    
    U64 k;
    int phase = 0;
    
    U64 whiteTeam = b->getTeamOccupied()[WHITE];
    U64 blackTeam = b->getTeamOccupied()[BLACK];
    U64 occupied = *b->getOccupied();
    
    U64 whiteKingZone = KING_ATTACKS[bitscanForward(b->getPieces()[WHITE_KING])];
    U64 blackKingZone = KING_ATTACKS[bitscanForward(b->getPieces()[BLACK_KING])];
    
    Square s;
    U64 attacks;
    
    
    
    _phase =
            (18 - bitCount(
                    b->getPieces()[WHITE_BISHOP] |
                    b->getPieces()[BLACK_BISHOP] |
                    b->getPieces()[WHITE_KNIGHT] |
                    b->getPieces()[BLACK_KNIGHT] |
                    b->getPieces()[WHITE_ROOK] |
                    b->getPieces()[BLACK_ROOK]) -
             3*bitCount(
                     b->getPieces()[WHITE_QUEEN] |
                     b->getPieces()[BLACK_QUEEN])) / 18.0;
    
    
    int whitekingSafety_attackingPiecesCount = 0;
    int whitekingSafety_valueOfAttacks       = 0;
    
    int blackkingSafety_attackingPiecesCount = 0;
    int blackkingSafety_valueOfAttacks       = 0;
    /**********************************************************************************
     *                                  P A W N S                                     *
     **********************************************************************************/
    
    
    U64 whitePawns = b->getPieces()[WHITE_PAWN];
    U64 blackPawns = b->getPieces()[BLACK_PAWN];
    
    
    k = whitePawns;
    _features[INDEX_PAWN_PASSED] = 0;
    _features[INDEX_PAWN_ISOLATED] = 0;
    _features[INDEX_PAWN_DOUBLED] = 0;
    _features[INDEX_PAWN_DOUBLED_AND_ISOLATED] = 0;
    _features[INDEX_PAWN_PSQT] = 0;
    while(k){
        Square s = bitscanForward(k);
        
        bool isolated = (FILES_NEIGHBOUR[fileIndex(s)] & whitePawns) == 0;
        bool doubled = (FILES[fileIndex(s)] & (whitePawns & ~(ONE << s))) != 0;
        
        if(isolated && doubled){
            _features[INDEX_PAWN_DOUBLED_AND_ISOLATED] += 1;
        }else if(isolated){
            _features[INDEX_PAWN_ISOLATED] += 1;
        }else if(doubled){
            _features[INDEX_PAWN_DOUBLED] += 1;
        }
        
        
        //passed pawn
        if((whitePassedPawnMask[s] & blackPawns) == 0){
            _features[INDEX_PAWN_PASSED] += 1;
        }
        
        _features[INDEX_PAWN_PSQT]  += psqt_pawn            [s] * (1-_phase)    / 100.0;
        _features[INDEX_PAWN_PSQT]  += psqt_pawn_endgame    [s] * (  _phase)    / 100.0;
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_PAWN];
    while(k){
        Square s = bitscanForward(k);
    
    
    
        bool isolated = (FILES_NEIGHBOUR[fileIndex(s)] & blackPawns) == 0;
        bool doubled = (FILES[fileIndex(s)] & (blackPawns & ~(ONE << s))) != 0;
    
        if(isolated && doubled){
            _features[INDEX_PAWN_DOUBLED_AND_ISOLATED] -= 1;
        }else if(isolated){
            _features[INDEX_PAWN_ISOLATED] -= 1;
        }else if(doubled){
            _features[INDEX_PAWN_DOUBLED] -= 1;
        }
        
        
        //passed pawn
        if((blackPassedPawnMask[s] & whitePawns) == 0){
            _features[INDEX_PAWN_PASSED] -= 1;
        }
        
        _features[INDEX_PAWN_PSQT] -= psqt_pawn         [squareIndex(7-rankIndex(s), fileIndex(s))] * (1-_phase) / 100.0;
        _features[INDEX_PAWN_PSQT] -= psqt_pawn_endgame [squareIndex(7-rankIndex(s), fileIndex(s))] * _phase     / 100.0;
        
        
        k = lsbReset(k);
    }
    
    
    
    U64 whitePawnEastCover = shiftNorthEast(whitePawns) & whitePawns;
    U64 whitePawnWestCover = shiftNorthEast(whitePawns) & whitePawns;
    U64 blackPawnEastCover = shiftNorthEast(blackPawns) & blackPawns;
    U64 blackPawnWestCover = shiftNorthEast(blackPawns) & blackPawns;
    
    _features[INDEX_PAWN_VALUE] =
            + bitCount(b->getPieces()[WHITE_PAWN])
            - bitCount(b->getPieces()[BLACK_PAWN]);
    _features[INDEX_PAWN_STRUCTURE] =
            + bitCount(whitePawnEastCover)
            + bitCount(whitePawnWestCover)
            - bitCount(blackPawnEastCover)
            - bitCount(blackPawnWestCover);
    
    
    U64 whitePawnCover = shiftNorthEast(whitePawns) | shiftNorthWest(whitePawns);
    U64 blackPawnCover = shiftSouthEast(blackPawns) | shiftSouthWest(blackPawns);
    
    /*
     * only these squares are counted for mobility
     */
    U64 mobilitySquaresWhite = ~whiteTeam & ~(blackPawnCover);
    U64 mobilitySquaresBlack = ~blackTeam & ~(whitePawnCover);
    
    /**********************************************************************************
     *                                  K N I G H T S                                 *
     **********************************************************************************/
    
    _features[INDEX_KNIGHT_MOBILITY] = 0;
    _features[INDEX_KNIGHT_PSQT] = 0;
    _features[INDEX_KNIGHT_OUTPOST] = 0;
    
    k = b->getPieces()[WHITE_KNIGHT];
    while(k){
        s = bitscanForward(k);
        attacks = KNIGHT_ATTACKS[s];
        
        
        
        _features[INDEX_KNIGHT_PSQT] += psqt_knight[63 - s]/ 100.0;
        _features[INDEX_KNIGHT_MOBILITY] += sqrt(bitCount(KNIGHT_ATTACKS[s] & mobilitySquaresWhite));
        
        
        _features[INDEX_KNIGHT_OUTPOST] += isOutpost(s, WHITE, blackPawns, whitePawnCover);
        
        
        
        phase++;
        addToKingSafety(attacks, blackKingZone, blackkingSafety_attackingPiecesCount, blackkingSafety_valueOfAttacks, 2);
        
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_KNIGHT];
    while(k){
        s = bitscanForward(k);
        attacks = KNIGHT_ATTACKS[s];
        
        _features[INDEX_KNIGHT_PSQT]  -= psqt_knight[s]/ 100.0;
        _features[INDEX_KNIGHT_MOBILITY] -= sqrt(bitCount(attacks & mobilitySquaresBlack));
        
        _features[INDEX_KNIGHT_OUTPOST] -= isOutpost(s, BLACK, whitePawns, blackPawnCover);
        
        phase++;
        addToKingSafety(attacks, whiteKingZone, whitekingSafety_attackingPiecesCount, whitekingSafety_valueOfAttacks, 2);
        
        k = lsbReset(k);
    }
    _features[INDEX_KNIGHT_VALUE] = (bitCount(b->getPieces()[WHITE_KNIGHT]) - bitCount(b->getPieces()[BLACK_KNIGHT]));
    /**********************************************************************************
     *                                  B I S H O P S                                 *
     **********************************************************************************/
    _features[INDEX_BISHOP_MOBILITY] = 0;
    _features[INDEX_BISHOP_PAWN_SAME_SQUARE] = 0;
    _features[INDEX_BISHOP_PSQT] = 0;
    _features[INDEX_BISHOP_FIANCHETTO] = 0;
    
    k = b->getPieces()[WHITE_BISHOP];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpBishopAttack(s, occupied);
        
        
        
        _features[INDEX_BISHOP_PSQT]  += psqt_bishop            [s] * (1-_phase)    / 100.0;
        _features[INDEX_BISHOP_PSQT]  += psqt_bishop_endgame    [s] * (  _phase)    / 100.0;
        
        _features[INDEX_BISHOP_MOBILITY] += sqrt(bitCount(attacks & mobilitySquaresWhite));
        _features[INDEX_BISHOP_PAWN_SAME_SQUARE] += bitCount(blackPawns & ((ONE << s) & WHITE_SQUARES ? WHITE_SQUARES:BLACK_SQUARES));
        
        
        _features[INDEX_BISHOP_FIANCHETTO] +=
                (s == G2 &&
                 whitePawns & ONE<<F2 &&
                 whitePawns & ONE<<H2 &&
                 whitePawns & (ONE<<G3 | ONE<<G4));
        _features[INDEX_BISHOP_FIANCHETTO] +=
                (s == B2 &&
                 whitePawns & ONE<<A2 &&
                 whitePawns & ONE<<C2 &&
                 whitePawns & (ONE<<B3 | ONE<<B4));
        
        
        phase++;
        addToKingSafety(attacks, blackKingZone, blackkingSafety_attackingPiecesCount, blackkingSafety_valueOfAttacks, 2);
        
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_BISHOP];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpBishopAttack(s, occupied);
        
        _features[INDEX_BISHOP_PSQT] -= psqt_bishop         [squareIndex(7-rankIndex(s), fileIndex(s))] * (1-_phase) / 100.0;
        _features[INDEX_BISHOP_PSQT] -= psqt_bishop_endgame [squareIndex(7-rankIndex(s), fileIndex(s))] * _phase     / 100.0;
        
        _features[INDEX_BISHOP_MOBILITY] -= sqrt(bitCount(attacks & mobilitySquaresBlack));
        _features[INDEX_BISHOP_PAWN_SAME_SQUARE] -= bitCount(whitePawns & ((ONE << s) & WHITE_SQUARES ? WHITE_SQUARES:BLACK_SQUARES));
        
        
        _features[INDEX_BISHOP_FIANCHETTO] -=
                (s == G7 &&
                 blackPawns & ONE<<F7 &&
                 blackPawns & ONE<<H7 &&
                 blackPawns & (ONE<<G6 | ONE<<G5));
        _features[INDEX_BISHOP_FIANCHETTO] -=
                (s == B2 &&
                 blackPawns & ONE<<A7 &&
                 blackPawns & ONE<<C7 &&
                 blackPawns & (ONE<<B6 | ONE<<B5));
        
        phase++;
        addToKingSafety(attacks, whiteKingZone, whitekingSafety_attackingPiecesCount, whitekingSafety_valueOfAttacks, 2);
        
        k = lsbReset(k);
    }
    _features[INDEX_BISHOP_VALUE] = (bitCount(b->getPieces()[WHITE_BISHOP]) - bitCount(b->getPieces()[BLACK_BISHOP]));
    _features[INDEX_BISHOP_DOUBLED] = (bitCount(b->getPieces()[WHITE_BISHOP])==2) - (bitCount(b->getPieces()[BLACK_BISHOP])==2);
    /**********************************************************************************
     *                                  R O O K S                                     *
     **********************************************************************************/
    
    _features[INDEX_ROOK_MOBILITY] = 0;
    _features[INDEX_ROOK_OPEN_FILE] = 0;
    _features[INDEX_ROOK_HALF_OPEN_FILE] = 0;
    _features[INDEX_ROOK_KING_LINE]  = 0;
    _features[INDEX_ROOK_PSQT] = 0;
    
    k = b->getPieces()[WHITE_ROOK];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpRookAttack(s,occupied);
        
        
        _features[INDEX_ROOK_PSQT] += psqt_rook[63 - s] / 100.0;
        _features[INDEX_ROOK_MOBILITY] += sqrt(bitCount(attacks & mobilitySquaresWhite));
        
        if(lookUpRookAttack(s, ZERO) & b->getPieces()[BLACK_KING]){
            //rook on same file or rank as king
            _features[INDEX_ROOK_KING_LINE] ++;
        }
        if((whitePawns & FILES[fileIndex(s)]) == 0){
            if((blackPawns & FILES[fileIndex(s)]) == 0){
                //open
                _features[INDEX_ROOK_OPEN_FILE] ++;
            }else{
                //half open
                _features[INDEX_ROOK_HALF_OPEN_FILE] ++;
            }
        }
        
        phase++;
        addToKingSafety(attacks, blackKingZone, blackkingSafety_attackingPiecesCount, blackkingSafety_valueOfAttacks, 3);
        
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_ROOK];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpRookAttack(s,occupied);
        
        _features[INDEX_ROOK_PSQT] -= psqt_rook[s] / 100.0;
        _features[INDEX_ROOK_MOBILITY] -= sqrt(bitCount(attacks & mobilitySquaresBlack));
        
        if(lookUpRookAttack(s, ZERO) & b->getPieces()[WHITE_KING]){
            //rook on same file or rank as king
            _features[INDEX_ROOK_KING_LINE] --;
        }
        
        if((whitePawns & FILES[fileIndex(s)]) == 0){
            if((blackPawns & FILES[fileIndex(s)]) == 0){
                //open
                _features[INDEX_ROOK_OPEN_FILE] --;
            }else{
                //half open
                _features[INDEX_ROOK_HALF_OPEN_FILE] --;
            }
        }
        
        
        phase++;
        addToKingSafety(attacks, whiteKingZone, whitekingSafety_attackingPiecesCount, whitekingSafety_valueOfAttacks, 3);
        
        k = lsbReset(k);
    }
    _features[INDEX_ROOK_VALUE] = (bitCount(b->getPieces()[WHITE_ROOK])   - bitCount(b->getPieces()[BLACK_ROOK]));
    
    /**********************************************************************************
     *                                  Q U E E N S                                   *
     **********************************************************************************/
    _features[INDEX_QUEEN_MOBILITY] = 0;
    _features[INDEX_QUEEN_PSQT] = 0;
    
    k = b->getPieces()[WHITE_QUEEN];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpRookAttack(s, occupied) | lookUpBishopAttack(s, occupied);
        
        _features[INDEX_QUEEN_PSQT] += psqt_queen[63 - s] / 100.0;
        _features[INDEX_QUEEN_MOBILITY] += sqrt(bitCount(attacks & mobilitySquaresWhite));
        
        phase+=3;
        addToKingSafety(attacks, blackKingZone, blackkingSafety_attackingPiecesCount, blackkingSafety_valueOfAttacks, 4);
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_QUEEN];
    while(k){
        Square s = bitscanForward(k);
        attacks = lookUpRookAttack(s, occupied) | lookUpBishopAttack(s, occupied);
        
        _features[INDEX_QUEEN_PSQT] -= psqt_queen[s] / 100.0;
        _features[INDEX_QUEEN_MOBILITY] -= sqrt(bitCount(attacks & mobilitySquaresBlack));
        
        phase+=3;
        addToKingSafety(attacks, whiteKingZone, whitekingSafety_attackingPiecesCount, whitekingSafety_valueOfAttacks, 4);
        
        k = lsbReset(k);
    }
    _features[INDEX_QUEEN_VALUE] = (bitCount(b->getPieces()[WHITE_QUEEN])  - bitCount(b->getPieces()[BLACK_QUEEN]));
    
    /**********************************************************************************
     *                                  K I N G S                                     *
     **********************************************************************************/
    k = b->getPieces()[WHITE_KING];
    _features[INDEX_KING_PSQT] = 0;
    _features[INDEX_KING_PAWN_SHIELD] = 0;
    _features[INDEX_KING_CLOSE_OPPONENT] = 0;
    
    while(k){
        Square s = bitscanForward(k);
        
        _features[INDEX_KING_PSQT] += psqt_king[63 - s]*(1-_phase) / 100.0;
        _features[INDEX_KING_PSQT] += psqt_king_endgame[63 - s]*_phase / 100.0;
        
        _features[INDEX_KING_PAWN_SHIELD]       += bitCount(KING_ATTACKS[s] & whitePawns);
        _features[INDEX_KING_CLOSE_OPPONENT]    += bitCount(KING_ATTACKS[s] & blackTeam);
        
        k = lsbReset(k);
    }
    
    k = b->getPieces()[BLACK_KING];
    while(k){
        Square s = bitscanForward(k);
        
        _features[INDEX_KING_PSQT] -= psqt_king[s]*(1-_phase) / 100.0;
        _features[INDEX_KING_PSQT] -= psqt_king_endgame[s]*_phase / 100.0;
        
        
        _features[INDEX_KING_PAWN_SHIELD]       -= bitCount(KING_ATTACKS[s] & blackPawns);
        _features[INDEX_KING_CLOSE_OPPONENT]    -= bitCount(KING_ATTACKS[s] & whiteTeam);
        
        k = lsbReset(k);
    }
    
    _features[INDEX_KING_SAFETY] = (_kingSafetyTable[blackkingSafety_valueOfAttacks] - _kingSafetyTable[whitekingSafety_valueOfAttacks]) / 100;
    
    
    
    
    
    
    
    
    for(int i = 0; i < unusedVariable; i++){
        res += _features[i] * (_phase * _pieceValuesLate[i] + (1-_phase) * _pieceValuesEarly[i]);
    }
    
    return res;
}

void printEvaluation(Board *board){
    
    using namespace std;
    
    Evaluator ev{};
    Score s = ev.evaluate(board);
    double phase = ev.getPhase();
    
    
    
    stringstream ss{};
    
    
    //String format = "%-30s | %-20s | %-20s %n";
    
    ss << std::setw(40) << std::left << "feature" << " | "
       << std::setw(20) << std::right << "difference" << " | "
       << std::setw(20) << "early weight" << " | "
       << std::setw(20) << "late weight" << " | "
       << std::setw(20) << "tapered weight" << " | "
       << std::setw(20) << "sum" << "\n";
    
    
    ss << "-----------------------------------------+----------------------+"
          "----------------------+----------------------+"
          "----------------------+----------------------+\n";
    ss << std::setw(40) << std::left << "PHASE" << " | "
       << std::setw(20) << std::right << "" << " | "
       << std::setw(20) << "0" << " | "
       << std::setw(20) << "1" << " | "
       << std::setw(20) << phase<< " | "
       << std::setw(20) << phase << " | \n";
    
    ss << "-----------------------------------------+----------------------+"
          "----------------------+----------------------+"
          "----------------------+----------------------+\n";
    
    string names[]{
            "INDEX_PAWN_VALUE",
            "INDEX_PAWN_PSQT",
            "INDEX_PAWN_STRUCTURE",
            "INDEX_PAWN_PASSED",
            "INDEX_PAWN_ISOLATED",
            "INDEX_PAWN_DOUBLED",
            "INDEX_PAWN_DOUBLED_AND_ISOLATED",
        
            "INDEX_KNIGHT_VALUE",
            "INDEX_KNIGHT_PSQT",
            "INDEX_KNIGHT_MOBILITY",
            "INDEX_KNIGHT_OUTPOST",
        
            "INDEX_BISHOP_VALUE",
            "INDEX_BISHOP_PSQT",
            "INDEX_BISHOP_MOBILITY",
            "INDEX_BISHOP_DOUBLED",
            "INDEX_BISHOP_PAWN_SAME_SQUARE",
            "INDEX_BISHOP_FIANCHETTO",
        
            "INDEX_ROOK_VALUE",
            "INDEX_ROOK_PSQT",
            "INDEX_ROOK_MOBILITY",
            "INDEX_ROOK_OPEN_FILE",
            "INDEX_ROOK_HALF_OPEN_FILE",
            "INDEX_ROOK_KING_LINE",
        
            "INDEX_QUEEN_VALUE",
            "INDEX_QUEEN_PSQT",
            "INDEX_QUEEN_MOBILITY",
        
            "INDEX_KING_SAFETY",
            "INDEX_KING_PSQT",
            "INDEX_KING_CLOSE_OPPONENT",
            "INDEX_KING_PAWN_SHIELD"
    };
    
    for(int i = 0; i < unusedVariable; i++){
        
        ss << std::setw(40) << std::left << names[i] << " | "
           << std::setw(20) << std::right << ev.getFeatures()[i] << " | "
           << std::setw(20) << ev.getEarlyGameParams()[i] << " | "
           << std::setw(20) << ev.getLateGameParams()[i] << " | "
           << std::setw(20) << ev.getEarlyGameParams()[i] * (1-phase) + ev.getLateGameParams()[i] * phase<< " | "
           << std::setw(20) << (ev.getEarlyGameParams()[i] * (1-phase) + ev.getLateGameParams()[i] * phase) * ev.getFeatures()[i] << " | \n";
    }
    ss << "-----------------------------------------+----------------------+"
          "----------------------+----------------------+"
          "----------------------+----------------------+\n";
    
    
    ss << std::setw(40) << std::left << "TOTAL" << " | "
       << std::setw(20) << std::right << "" << " | "
       << std::setw(20) << "" << " | "
       << std::setw(20) << "" << " | "
       << std::setw(20) << ""<< " | "
       << std::setw(20) << s << " | \n";
    
    ss << "-----------------------------------------+----------------------+"
          "----------------------+----------------------+"
          "----------------------+----------------------+\n";
    
    std::cout << ss.str() << std::endl;
}

double *Evaluator::getFeatures() {
    return _features;
}

double Evaluator::getPhase() {
    return _phase;
}

double *Evaluator::getEarlyGameParams() {
    return _pieceValuesEarly;
}

double *Evaluator::getLateGameParams() {
    return _pieceValuesLate;
}

int Evaluator::paramCount(){
    return unusedVariable;
}

