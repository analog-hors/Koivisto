
/****************************************************************************************************
 *                                                                                                  *
 *                                     Koivisto UCI Chess engine                                    *
 *                           by. Kim Kahre, Finn Eggers and Eugenio Bruno                           *
 *                                                                                                  *
 *                 Koivisto is free software: you can redistribute it and/or modify                 *
 *               it under the terms of the GNU General Public License as published by               *
 *                 the Free Software Foundation, either version 3 of the License, or                *
 *                                (at your option) any later version.                               *
 *                    Koivisto is distributed in the hope that it will be useful,                   *
 *                  but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
 *                   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                  *
 *                           GNU General Public License for more details.                           *
 *                 You should have received a copy of the GNU General Public License                *
 *                 along with Koivisto.  If not, see <http://www.gnu.org/licenses/>.                *
 *                                                                                                  *
 ****************************************************************************************************/

#include "Bitboard.h"
#include "Board.h"
#include "Move.h"
#include "MoveOrderer.h"
#include "Verification.h"
#include "uci.h"

#include <iomanip>
#include "gradient.h"
#include "movegen.h"

using namespace std;
using namespace bb;
using namespace move;


int main(int argc, char *argv[]) {

    
//    bb_init();
//
//    Board b{"rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq - 0 1"};
//    SearchData sd{};
//    Depth ply = 0;
//    MoveList mv{};
//
//    generateMoves(&b, &mv, 0, &sd, ply);
//
//    MoveList oldMV{};
//    b.getPseudoLegalMoves(&oldMV);
//
//    std::cout << mv.getSize() << std::endl;
//    for(int i = 0; i< mv.getSize(); i++){
//
//        std::cout << toString(mv.getMove(i)) << "  " << toString(oldMV.getMove(i)) << "   " << (mv.getMove(i) == oldMV.getMove(i)) << std::endl;
//    }

    if (argc == 1) {
        uci_loop(false);
    } else if (argc > 1 && strcmp(argv[1], "bench") == 0) {
        uci_loop(true);
    }

//
//using namespace tuning;
//
//    bb_init();
//    psqt_init();
//
//    load_weights();
//
//    load_positions("../resources/other/E12.33-1M-D12-Resolved.book", 10000000);
//    load_positions("../resources/other/E12.41-1M-D12-Resolved.book", 10000000);
//    load_positions("../resources/other/E12.46FRC-1250k-D12-1s-Resolved.book", 10000000);
//
////    compute_K(2.48617, 100, 1e-7);
//    for(int i = 0; i < 10; i++){
//        train(50, 2.48172, 0.001 * sqrt(1000000));
//        display_params();
//    }




    return 0;
}
