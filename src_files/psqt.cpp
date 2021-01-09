//
// Created by Luecx on 06.12.2020.
//

#include "psqt.h"

EvalScore piece_square_tables[64][64][12][64]{};

// indexed by piece
EvalScore piece_values[6] = {
    M(90, 104), M(463, 326), M(474, 288), M(577, 594), M(1359, 1121), M(0, 0),
};


// indexed by piece, relation to king
EvalScore piece_our_king_square_table[5][15*15]{
    {
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(  250,  -45), M(   41,  -93), M(  -27,   32), M( -148,   62), M(  -34,  -13),
            M(  -53,  -15), M(  -43,  -27), M(   13,  -71), M(   15,  -49), M(  -40,  -11),
            M(  -32,    5), M(  -28,   22), M(   -5,   30), M(  -15,   40), M(  -63,   88),
            M(   38,  -55), M(  -23,   -2), M(   -3,   -2), M(  -29,    5), M(    3,   -9),
            M(  -25,   -5), M(   -4,  -16), M(  -32,   -2), M(  -20,  -16), M(  -10,   -7),
            M(   -0,  -24), M(  -15,    7), M(  -15,   11), M(   -0,   18), M(    5,   10),
            M(  -61,  -38), M(   -1,  -17), M(   -2,    2), M(   -2,  -10), M(  -25,    5),
            M(  -12,  -12), M(   -5,  -17), M(    2,  -14), M(   -3,  -25), M(  -10,  -18),
            M(   -3,  -14), M(   -5,   -1), M(   -2,   -2), M(   -5,    1), M(   -2,  -11),
            M(  -24,    4), M(   10,    0), M(   -8,    8), M(   -1,    2), M(  -11,    7),
            M(   -4,   -5), M(    7,    1), M(   16,   -9), M(    1,  -11), M(   -7,   -5),
            M(   -7,   -3), M(   -7,   -1), M(   -5,    2), M(   -4,   -1), M(    3,  -13),
            M(   20,   -7), M(    6,    0), M(  -14,    4), M(   -5,    2), M(   -9,    5),
            M(   -3,    8), M(   16,    7), M(   27,    3), M(    3,    7), M(    2,    6),
            M(   -4,   -2), M(   -3,    0), M(   -7,    4), M(   -6,    1), M(    4,  -17),
            M(  -42,    5), M(   -1,   -3), M(   -7,    1), M(    3,   -3), M(    3,    2),
            M(   -1,    9), M(   -6,  -12), M(    8,   -5), M(   -9,   -3), M(    1,    6),
            M(    0,    4), M(   -6,    2), M(   -6,    2), M(   -6,    1), M(    5,  -10),
            M(  -27,   -5), M(    9,   -6), M(  -11,    2), M(    3,    2), M(    6,    5),
            M(    0,   11), M(   -8,   -3), M(    0,    0), M(    7,   -1), M(   -2,   13),
            M(    1,    4), M(   -6,    5), M(   -3,    0), M(   -5,   -2), M(   13,  -12),
            M(  -29,   15), M(   33,   -5), M(    4,    0), M(   -1,   -2), M(   -5,   10),
            M(  -12,   12), M(  -46,    5), M(  -35,   29), M(  -57,    2), M(   -8,   14),
            M(  -19,    9), M(   -3,    3), M(  -13,    5), M(    9,   -2), M(    3,    3),
            M(  -41,    5), M(   63,  -22), M(  -51,   11), M(  -26,   -2), M(  -11,    6),
            M( -120,   23), M(  -60,   19), M(  -17,    7), M(  -81,   17), M(  -50,    3),
            M(  -35,   17), M(   -2,    4), M(  -20,    7), M(   18,    4), M(  -30,    6),
            M(   58,  -18), M( -127,   23), M(   21,   12), M(  -56,    2), M(  -29,   12),
            M( -143,   24), M(    7,    3), M(  -59,   25), M( -129,   14), M( -101,    9),
            M( -166,   39), M(   -7,   -7), M( -119,   15), M(   79,   -8), M( -126,   10),
            M( -354,   25), M( -192,    8), M(  228,  -23), M( -114,   18), M( -132,   29),
            M( -187,   26), M( -117,   27), M(  -92,   27), M(  -60,    8), M(    1,    7),
            M(  -84,   20), M( -183,    4), M(    8,    3), M(  197,  -34), M( -306,   36),
            M( -336,   14), M( -328,   24), M(  -18,   18), M( -133,   68), M( -138,   27),
            M(  -80,    9), M(  109,   15), M( -156,   42), M(  -66,   16), M(  -77,   38),
            M(   73,   34), M(   29,   26), M( -219,   28), M(   22,   84), M( -607,  102),
            M( -477,  235), M(-3171,  173), M(   31,   61), M(-1006,  114), M(  865,  -27),
            M(  252,   96), M( -597,  108), M( -247,  230), M( -518,   -8), M( -628,  -11),
            M(  178, -136), M(  115,  -16), M(  728, -102), M(  149,  -50), M(-1083,  507),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
    },
    {
    
    },
    {
    
    },
    {
    
    },
    {
    
    },
};
EvalScore piece_opp_king_square_table[5][15*15]{
    {
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(   33,   49), M( -649,  215), M( -395,  156), M( -305,  155), M( -274,  207),
            M( -286,  206), M(  -23,  219), M( -218,  324), M(  -68,  248), M(  -44,  198),
            M(  -11,  159), M( -721,  235), M( -566,  153), M( -372,  118), M( -456,  132),
            M( -260,  140), M( -440,  113), M( -347,  103), M( -379,  125), M( -276,  139),
            M( -246,  190), M( -184,  190), M( -200,  164), M(  -72,  151), M( -200,  161),
            M( -120,  116), M( -333,   98), M( -470,  106), M( -581,  154), M( -338,   90),
            M( -235,   81), M( -249,   70), M( -241,   57), M( -209,   43), M( -100,   59),
            M(  -99,   97), M(  -94,  106), M(  -75,   99), M(  -88,   95), M(  -92,   90),
            M( -108,   61), M( -153,   23), M( -191,   32), M( -275,   59), M( -303,   50),
            M( -193,   40), M( -125,   31), M( -109,   19), M(  -91,   14), M(  -49,   24),
            M(  -64,   45), M(  -80,   58), M(  -71,   42), M(   14,   41), M(  -81,   43),
            M(  -75,   23), M(  -83,    3), M( -100,   16), M( -157,   29), M( -166,   43),
            M( -119,   39), M(  -50,   13), M(  -63,   11), M(  -55,    1), M(  -25,   13),
            M(  -48,   11), M(  -73,   19), M(  -82,   11), M(  -60,   15), M(  -50,    8),
            M(  -41,   18), M(  -72,    3), M(  -49,    8), M(  -60,   19), M(  -38,   24),
            M(  -29,   18), M(  -22,   11), M(  -14,    2), M(  -12,   -3), M(   23,   -2),
            M(  -26,    4), M(  -50,   -8), M(  -91,   -4), M(  -88,   -2), M(  -40,    7),
            M(  -18,    6), M(  -15,    1), M(  -22,    8), M(  -27,   19), M(  -25,   17),
            M(   -5,   17), M(  -11,    7), M(    2,    3), M(   -4,   -3), M(    3,    1),
            M(   -2,   -0), M(   23,  -51), M(    0,    0), M(   -7,  -50), M(  -29,    5),
            M(  -11,    5), M(  -11,    6), M(   -6,    9), M(  -12,   15), M(  -18,   22),
            M(  -19,   20), M(   -5,   11), M(   -1,    8), M(   -3,    4), M(    8,    4),
            M(   18,    2), M(  -72,  -22), M(  -80,  -27), M(  -83,  -22), M(    4,    4),
            M(   -3,   10), M(   -5,   11), M(   -7,   17), M(  -12,   22), M(  -21,   28),
            M(   -2,   13), M(   -8,   18), M(   -3,   10), M(   -1,   10), M(   11,    3),
            M(   11,    8), M(   31,    2), M(   35,   -6), M(   35,    4), M(    8,    9),
            M(   -1,   10), M(   -6,   17), M(   -6,   19), M(   -4,   22), M(  -10,   22),
            M(  -11,   22), M(    4,   14), M(   -1,   16), M(    5,   12), M(    7,    7),
            M(   11,    7), M(   11,    8), M(   -1,    4), M(   16,    9), M(    9,    9),
            M(    2,   10), M(    4,   16), M(    1,   19), M(    3,   20), M(   -5,   23),
            M(   -2,   14), M(    6,   17), M(    6,   15), M(    1,   16), M(    5,   11),
            M(    6,    6), M(    2,    7), M(   -3,    1), M(    3,    9), M(    6,    7),
            M(    4,   12), M(    3,   16), M(    8,   19), M(   10,   20), M(    3,   22),
            M(    2,   17), M(   11,   19), M(    8,   18), M(    5,   18), M(    3,   12),
            M(    4,   10), M(   -7,   10), M(  -12,    9), M(   -4,   16), M(    2,   14),
            M(    3,   13), M(    6,   20), M(    9,   21), M(   13,   21), M(    6,   22),
            M(   10,   16), M(   18,   13), M(   11,   18), M(   -2,   22), M(   -5,   21),
            M(   -7,   17), M(  -10,    7), M(  -15,   11), M(   -9,   24), M(   -4,   15),
            M(    2,   16), M(    3,   23), M(    9,   23), M(   16,   21), M(   11,   21),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
            M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0)
    },
    {
    
    },
    {
    
    },
    {
    
    },
    {
    
    },
};



// indexed by piece, sameSideCastle, square
EvalScore piece_square_table[6][2][64]{
        {
                {

                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(    1,    6), M(   26,   20), M(   16,   40), M(   -5,   46),
                        M(  -10,   32), M(  -15,   27), M(  -21,   27), M(  -25,   38),
                        M(    2,   16), M(    8,   20), M(    5,   36), M(    1,   34),
                        M(   -5,   23), M(  -14,   26), M(  -22,   27), M(  -22,   33),
                        M(   -3,   26), M(    8,   33), M(    9,   32), M(   18,   26),
                        M(    8,   21), M(    3,   23), M(  -13,   38), M(  -15,   43),
                        M(    4,   43), M(   14,   49), M(   33,   37), M(   33,   28),
                        M(   24,   19), M(    7,   41), M(    2,   51), M(   -5,   63),
                        M(    4,   66), M(   57,   58), M(   91,   42), M(   55,   33),
                        M(   38,   42), M(   36,   69), M(   24,   90), M(   -2,   99),
                        M(   58,  141), M(  101,  129), M(  206,   87), M(  195,  104),
                        M(  172,  138), M(  164,  169), M(  150,  193), M(  175,  181),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                },
                {

                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(   10,   20), M(   36,   16), M(   22,   29), M(   -1,   39),
                        M(   -4,   42), M(   -9,   44), M(  -19,   47), M(  -24,   48),
                        M(   18,   22), M(   24,   21), M(    7,   33), M(    2,   33),
                        M(    2,   35), M(   -3,   38), M(  -25,   42), M(  -29,   45),
                        M(   21,   45), M(   20,   48), M(   16,   37), M(   16,   33),
                        M(   19,   29), M(   14,   34), M(   -9,   43), M(  -27,   45),
                        M(   26,   89), M(   31,   79), M(   26,   64), M(   29,   44),
                        M(   41,   28), M(   39,   30), M(   -1,   48), M(  -19,   45),
                        M(   16,  164), M(   56,  154), M(   46,  127), M(   45,   76),
                        M(   73,   25), M(   81,   18), M(   54,   24), M(   -6,   43),
                        M(  208,  248), M(  206,  257), M(  174,  232), M(  194,  173),
                        M(  216,  101), M(  222,   52), M(  106,   82), M(   82,   84),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                        M(    0,    0), M(    0,    0), M(    0,    0), M(    0,    0),
                },
        },
        {
                {

                        M( -104,   21), M(  -77,   41), M(  -69,   50), M(  -69,   66),
                        M(  -71,   67), M(  -77,   37), M(  -79,   16), M( -114,   -3),
                        M(  -77,   56), M(  -83,   64), M(  -66,   51), M(  -66,   68),
                        M(  -63,   67), M(  -81,   48), M(  -96,   53), M( -101,   34),
                        M(  -76,   47), M(  -63,   70), M(  -63,   73), M(  -59,   84),
                        M(  -65,   83), M(  -77,   60), M(  -79,   45), M(  -94,   17),
                        M(  -65,   72), M(  -36,   82), M(  -59,   99), M(  -53,  102),
                        M(  -67,   99), M(  -71,   89), M(  -81,   70), M(  -85,   46),
                        M(  -59,   69), M(  -66,   82), M(  -36,   99), M(  -66,  109),
                        M(  -54,  111), M(  -60,   93), M(  -73,   64), M(  -80,   57),
                        M(  -82,   60), M(  -55,   69), M(   -7,   88), M(  -17,   86),
                        M(  -43,   95), M(  -48,   92), M(  -76,   63), M( -102,   46),
                        M(  -62,   52), M( -107,   63), M(  -14,   46), M(  -32,   79),
                        M(  -23,   83), M(  -45,   58), M(  -93,   61), M(  -89,   41),
                        M( -203,   -6), M( -164,   72), M( -206,  107), M(  -80,   69),
                        M( -115,   74), M( -215,  101), M( -206,   74), M( -281,   14),
                },
                {

                        M(  -70,  -27), M(  -54,   18), M(  -30,   15), M(  -22,   36),
                        M(  -24,   28), M(  -39,   11), M(  -43,    4), M(  -82,    3),
                        M(  -42,   12), M(  -49,   32), M(  -24,   16), M(  -19,   32),
                        M(  -15,   34), M(  -29,   24), M(  -62,   33), M(  -62,   11),
                        M(  -43,    7), M(  -28,   28), M(  -16,   35), M(  -14,   51),
                        M(   -6,   50), M(  -24,   32), M(  -23,   14), M(  -51,   -1),
                        M(  -23,   30), M(   -3,   39), M(   -6,   58), M(   -3,   61),
                        M(    9,   57), M(   -2,   49), M(    9,   30), M(  -18,   17),
                        M(  -25,   35), M(   -8,   34), M(   13,   53), M(   20,   65),
                        M(    5,   66), M(   17,   53), M(   -5,   27), M(   -7,   18),
                        M(  -60,   24), M(    3,   22), M(   18,   52), M(   30,   51),
                        M(   42,   47), M(   48,   40), M(    9,   12), M(  -21,    3),
                        M(  -35,    3), M(  -32,   25), M(   31,   10), M(   58,   36),
                        M(   25,   34), M(   13,   16), M(  -47,   18), M(  -17,   -1),
                        M( -218,  -28), M( -163,   38), M( -143,   50), M(  -64,   37),
                        M(  -46,   22), M( -134,   42), M(  -37,    6), M( -191,  -38),
                },
        },
        {
                {

                        M(  -52,    5), M(  -66,   20), M(  -57,   26), M(  -59,   38),
                        M(  -54,   33), M(  -52,   31), M(  -47,   32), M(  -40,   12),
                        M(  -44,   -9), M(  -30,   10), M(  -41,   25), M(  -46,   36),
                        M(  -49,   40), M(  -43,   28), M(  -40,   12), M(  -44,   10),
                        M(  -33,   32), M(  -38,   41), M(  -39,   47), M(  -41,   52),
                        M(  -40,   48), M(  -42,   46), M(  -37,   35), M(  -51,   25),
                        M(  -41,   30), M(  -41,   44), M(  -46,   56), M(  -27,   56),
                        M(  -30,   60), M(  -40,   54), M(  -44,   38), M(  -59,   21),
                        M(  -54,   42), M(  -34,   50), M(  -27,   54), M(  -25,   64),
                        M(  -10,   59), M(  -39,   52), M(  -37,   44), M(  -67,   40),
                        M(  -42,   44), M(  -11,   53), M(   -8,   58), M(   -6,   51),
                        M(  -26,   52), M(  -22,   51), M(  -51,   54), M(  -59,   36),
                        M(  -82,   46), M(  -51,   51), M(  -29,   44), M(  -55,   53),
                        M(  -69,   56), M(  -55,   55), M(  -60,   55), M( -105,   53),
                        M( -103,   51), M(  -88,   47), M( -192,   65), M( -145,   64),
                        M( -169,   75), M( -177,   69), M( -119,   67), M( -114,   62),
                },
                {

                        M(   14,  -16), M(  -10,   -4), M(    0,    1), M(   -7,    9),
                        M(   -6,    8), M(  -12,   -2), M(  -12,    5), M(   -7,  -11),
                        M(   20,  -24), M(   48,  -14), M(   25,   -3), M(   17,    4),
                        M(    2,    7), M(    1,    1), M(   -4,  -13), M(    1,  -19),
                        M(   20,   -5), M(   37,    7), M(   41,   11), M(   21,   12),
                        M(   17,   18), M(    4,   12), M(    5,    3), M(   -4,   -3),
                        M(    9,   -3), M(   25,   12), M(   25,   20), M(   47,   22),
                        M(   28,   22), M(   19,   17), M(   15,    2), M(   10,   -7),
                        M(    2,   14), M(   25,   17), M(   28,   28), M(   44,   29),
                        M(   63,   21), M(   32,   10), M(   37,   12), M(   10,   -2),
                        M(   -4,   13), M(   27,   22), M(   32,   25), M(   41,   24),
                        M(   68,   13), M(   79,   12), M(   56,    4), M(   17,   -0),
                        M(  -40,   22), M(  -18,   34), M(    5,   29), M(  -24,   29),
                        M(    2,   22), M(   44,    8), M(   15,   13), M(  -38,    4),
                        M(  -46,   36), M(  -86,   34), M(  -89,   32), M(  -93,   38),
                        M( -128,   34), M( -113,   28), M(   21,    9), M(  -21,   23),
                },
        },
        {
                {

                        M( -104,   57), M(  -76,   72), M(  -73,   82), M(  -71,   77),
                        M(  -70,   78), M(  -79,   86), M(  -87,   82), M(  -93,   75),
                        M( -165,   79), M(  -83,   63), M(  -75,   65), M(  -87,   74),
                        M(  -86,   77), M(  -96,   84), M(  -99,   76), M( -132,   83),
                        M( -108,   69), M(  -75,   85), M(  -90,   86), M(  -93,   84),
                        M(  -93,   88), M( -106,   95), M(  -99,   96), M( -112,   85),
                        M(  -98,   94), M(  -74,  101), M(  -89,  107), M(  -92,  104),
                        M(  -91,  108), M( -102,  116), M( -106,  117), M( -105,  102),
                        M(  -64,  107), M(  -47,  100), M(  -45,  106), M(  -51,  105),
                        M(  -44,  108), M(  -70,  118), M(  -79,  114), M(  -90,  116),
                        M(  -44,  111), M(   15,   88), M(   10,  101), M(  -11,   97),
                        M(  -32,  107), M(  -58,  121), M(  -48,  111), M(  -91,  125),
                        M(  -61,  122), M(  -56,  121), M(    5,  101), M(  -56,  138),
                        M(  -57,  139), M(  -72,  140), M(  -96,  143), M(  -89,  136),
                        M(  -25,  130), M(  -40,  136), M(  -33,  136), M(  -80,  140),
                        M(  -90,  146), M(  -99,  153), M(  -72,  143), M(  -71,  138),
                },
                {

                        M(  -56,   36), M(  -26,   34), M(  -21,   40), M(  -15,   34),
                        M(  -10,   29), M(   -5,   34), M(   -4,   30), M(  -32,   29),
                        M( -111,   44), M(  -54,   28), M(  -38,   33), M(  -37,   37),
                        M(  -30,   34), M(  -21,   30), M(  -13,   21), M(  -62,   36),
                        M(  -63,   34), M(  -25,   40), M(  -49,   47), M(  -41,   45),
                        M(  -41,   42), M(  -33,   43), M(  -22,   43), M(  -38,   34),
                        M(  -41,   55), M(  -14,   56), M(  -37,   67), M(  -33,   63),
                        M(  -30,   54), M(  -29,   59), M(  -25,   58), M(  -35,   49),
                        M(  -10,   66), M(   -1,   61), M(   13,   60), M(   22,   61),
                        M(   18,   52), M(   10,   58), M(   14,   49), M(    6,   51),
                        M(    0,   68), M(   48,   47), M(   30,   66), M(   46,   54),
                        M(   57,   49), M(   56,   50), M(   73,   39), M(   16,   58),
                        M(    4,   75), M(    9,   75), M(   17,   77), M(   10,   89),
                        M(   22,   78), M(   61,   53), M(    5,   69), M(   11,   64),
                        M(   54,   63), M(   23,   80), M(    5,   90), M(  -14,   94),
                        M(   -0,   85), M(   60,   66), M(   48,   69), M(   16,   80),
                },
        },
        {
                {

                        M( -133,   86), M( -124,   66), M( -114,   86), M( -103,  105),
                        M( -104,  124), M( -109,  106), M( -114,  112), M( -117,  121),
                        M( -130,   80), M( -105,   48), M(  -96,   52), M( -104,  105),
                        M( -106,  112), M( -103,   84), M( -111,  102), M( -120,  113),
                        M( -104,  101), M( -101,  113), M( -111,  128), M( -112,  105),
                        M( -115,  106), M( -115,  118), M( -111,  111), M( -124,  117),
                        M( -102,  141), M( -103,  137), M( -111,  136), M( -125,  147),
                        M( -130,  143), M( -125,  116), M( -121,  134), M( -124,  130),
                        M( -114,  150), M( -104,  174), M( -120,  175), M( -134,  162),
                        M( -143,  163), M( -138,  127), M( -136,  156), M( -136,  153),
                        M( -157,  176), M( -109,  187), M( -116,  170), M( -116,  156),
                        M( -131,  136), M( -138,  135), M( -141,  147), M( -147,  170),
                        M( -123,  197), M( -177,  240), M(  -62,  136), M( -189,  209),
                        M( -180,  191), M( -151,  163), M( -190,  205), M( -152,  187),
                        M(  -97,  148), M( -136,  195), M( -108,  153), M( -160,  166),
                        M( -144,  157), M( -152,  182), M( -148,  192), M( -167,  207),
                },
                {

                        M(  -24,    6), M(   -2,  -22), M(    8,  -20), M(    9,   27),
                        M(    7,   35), M(    3,   19), M(    1,   51), M(    3,   33),
                        M(  -35,    7), M(   -6,   -1), M(   25,  -31), M(   19,   27),
                        M(   13,   21), M(   21,    4), M(   24,    9), M(   16,   27),
                        M(  -20,   36), M(    5,   36), M(    4,   50), M(    5,   34),
                        M(    4,   35), M(   12,   37), M(   18,   28), M(   19,   27),
                        M(   -9,   58), M(   -0,   68), M(  -14,   70), M(   -4,   86),
                        M(   -6,   72), M(    9,   54), M(   16,   46), M(   24,   27),
                        M(   -5,   74), M(  -19,   96), M(  -20,   69), M(  -17,   94),
                        M(    3,   84), M(   11,   71), M(   32,   64), M(   14,   43),
                        M(  -15,   98), M(    1,   58), M(    4,   63), M(   -5,   71),
                        M(   19,   78), M(    9,   94), M(   39,   45), M(   -8,   56),
                        M(  -13,   88), M(  -53,  129), M(  -17,   90), M(  -58,  125),
                        M(  -73,  143), M(   45,   60), M(  -39,  105), M(   -7,   61),
                        M(   -8,   90), M(   -5,   98), M(  -18,   91), M(  -35,  101),
                        M(  -37,   96), M(   98,   13), M(  -27,   86), M(   -1,   53),
                },
        },
        {
                {

                        M(   43, -134), M(  -13,    6), M(   61,    6), M(  119,   -6),
                        M(  146,  -39), M(   78,  -12), M(   10,   -6), M(   27, -166),
                        M( -151,  -32), M(   81,   12), M(  155,  -15), M(  184,  -27),
                        M(  172,  -38), M(  155,  -29), M(    7,   19), M(  -64,  -49),
                        M(   13,  -16), M(  201,   -6), M(  244,  -21), M(  213,  -26),
                        M(  227,  -39), M(  245,  -27), M(  166,  -12), M(    8,  -30),
                        M(   11,  -13), M(  140,  -24), M(  163,  -12), M(  111,   -2),
                        M(  154,  -14), M(  177,  -19), M(  109,  -25), M(  -44,  -18),
                        M(  -34,  -28), M(  117,  -21), M(  126,   -2), M(   83,   10),
                        M(  114,    4), M(   98,   -1), M(  103,  -15), M(  -28,  -26),
                        M(  -15,  -13), M(   41,   -4), M(   57,    6), M(   48,   17),
                        M(   62,   13), M(   50,    7), M(   33,   -2), M(  -12,  -12),
                        M(   39,  -15), M(   38,   -1), M(   22,   11), M(  -15,   19),
                        M(    6,   12), M(   -1,   18), M(   31,   -2), M(   45,  -23),
                        M(   39,  -66), M(   39,  -21), M(   13,    1), M(   -2,  -15),
                        M(   -7,  -27), M(  -17,   -0), M(   49,  -21), M(   63,  -78),
                },
                {

                        M(   51, -150), M(   75,  -56), M(   46,  -31), M(   33,    7),
                        M(   39,  -13), M(   17,  -27), M(   65,  -45), M(   22, -131),
                        M(  -23,  -36), M(   79,    1), M(  131,  -10), M(  152,  -19),
                        M(  102,  -13), M(  146,   -9), M(   52,    9), M(   40,  -45),
                        M(   16,   -8), M(  140,    1), M(  185,   -9), M(  180,  -16),
                        M(  157,   -7), M(  180,   -5), M(  127,    4), M(   27,  -11),
                        M(  -12,   -0), M(  133,  -12), M(  152,   -3), M(  120,    3),
                        M(  117,    8), M(  133,    6), M(  111,   -2), M(   -9,   -0),
                        M(    9,  -23), M(  103,  -10), M(  121,    1), M(   68,   15),
                        M(   80,   18), M(   97,   11), M(  102,   -0), M(    8,  -21),
                        M(   -7,  -16), M(   30,   -1), M(   52,    4), M(   30,   19),
                        M(   36,   23), M(   40,   14), M(   37,    5), M(   -1,   -8),
                        M(   35,  -17), M(   32,   -4), M(   13,    9), M(  -37,   21),
                        M(  -12,   21), M(   -8,   21), M(   33,   -0), M(   47,  -18),
                        M(   41,  -75), M(   50,  -32), M(    9,   -5), M(  -18,  -16),
                        M(   -5,  -23), M(  -16,    0), M(   58,  -26), M(   67,  -73),
                },
        },
};

// indexed by wking, bking, piece, square
EvalScore piece_kk_square_tables[64][64][12][64];

void psqt_init() {
    for(Square wKingSq = 0; wKingSq < 64; wKingSq++){
        for(Square bKingSq = 0; bKingSq < 64; bKingSq++){
            
            bool   wKSide            = (fileIndex(wKingSq) > 3 ? 0 : 1);
            bool   bKSide            = (fileIndex(bKingSq) > 3 ? 0 : 1);
            bool   sameSideCastle    = wKSide == bKSide;
            
            // pawn, knight, bishop, rook, queen
            for(Piece p = 0; p < 5; p++){
                for(Square sq = 0; sq < 64; sq++){

                    piece_kk_square_tables[wKingSq][bKingSq][p]  [sq] =
                          + piece_square_table              [p][!sameSideCastle][pst_index_white(sq, wKSide)]
                          + piece_values                    [p]
                          + piece_our_king_square_table     [p]     [pst_index_relative_white(sq, wKingSq)]
                          + piece_opp_king_square_table     [p]     [pst_index_relative_white(sq, bKingSq)];

                    piece_kk_square_tables[wKingSq][bKingSq][p+6][sq] =
                          - piece_square_table              [p][!sameSideCastle][pst_index_black(sq, bKSide)]
                          - piece_values                    [p]
                          - piece_our_king_square_table     [p]     [pst_index_relative_black(sq, bKingSq)]
                          - piece_opp_king_square_table     [p]     [pst_index_relative_black(sq, wKingSq)];
                }
            }

            // kings
            for(Square sq = 0; sq < 64; sq++){
                piece_kk_square_tables[wKingSq][bKingSq][WHITE_KING][sq]
                    = + piece_square_table[KING][0][pst_index_white_s(sq)];
                piece_kk_square_tables[wKingSq][bKingSq][BLACK_KING][sq]
                    = - piece_square_table[KING][0][pst_index_black_s(sq)];
            }
            
        }
    }
}