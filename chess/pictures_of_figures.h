#pragma once
#define BOARD L"pictures\\chessboard.bmp"

#define WHITE_HORSE_WHITE L"pictures\\figures\\white\\whiteHorse_white.bmp"
#define WHITE_HORSE_BLACK L"pictures\\figures\\white\\whiteHorse_black.bmp"

#define WHITE_ROOK_WHITE L"pictures\\figures\\white\\whiteRook_white.bmp"
#define WHITE_ROOK_BLACK L"pictures\\figures\\white\\whiteRook_black.bmp"

#define WHITE_BISHOP_WHITE L"pictures\\figures\\white\\whiteBishop_white.bmp"
#define WHITE_BISHOP_BLACK L"pictures\\figures\\white\\whiteBishop_black.bmp"

#define WHITE_KING_WHITE L"pictures\\figures\\white\\whiteKing_white.bmp"
#define WHITE_KING_BLACK L"pictures\\figures\\white\\whiteKing_black.bmp"

#define WHITE_PAWN_WHITE L"pictures\\figures\\white\\whitePawn_white.bmp"
#define WHITE_PAWN_BLACK L"pictures\\figures\\white\\whitePawn_black.bmp"

#define WHITE_QUEEN_WHITE L"pictures\\figures\\white\\whiteQueen_white.bmp"
#define WHITE_QUEEN_BLACK L"pictures\\figures\\white\\whiteQueen_black.bmp"




#define BLACK_HORSE_WHITE L"pictures\\figures\\black\\blackHorse_white.bmp"
#define BLACK_HORSE_BLACK L"pictures\\figures\\black\\blackHorse_black.bmp"

#define BLACK_ROOK_WHITE L"pictures\\figures\\black\\blackRook_white.bmp"
#define BLACK_ROOK_BLACK L"pictures\\figures\\black\\blackRook_black.bmp"

#define BLACK_BISHOP_WHITE L"pictures\\figures\\black\\blackBishop_white.bmp"
#define BLACK_BISHOP_BLACK L"pictures\\figures\\black\\blackBishop_black.bmp"

#define BLACK_KING_WHITE L"pictures\\figures\\black\\blackKing_white.bmp"
#define BLACK_KING_BLACK L"pictures\\figures\\black\\blackKing_black.bmp"

#define BLACK_PAWN_WHITE L"pictures\\figures\\black\\blackPawn_white.bmp"
#define BLACK_PAWN_BLACK L"pictures\\figures\\black\\blackPawn_black.bmp"

#define BLACK_QUEEN_WHITE L"pictures\\figures\\black\\blackQueen_white.bmp"
#define BLACKE_QUEEN_BLACK L"pictures\\figures\\black\\blackQueen_black.bmp"


#define SIZECELL 40
#define X_START 400
#define Y_START 1

HWND hWnd = GetConsoleWindow();
HDC hdc = GetDC(hWnd);
// создание memory DC для этого bitmap-а:
HDC bmpDC = CreateCompatibleDC(hdc);

const unsigned short HEIGHT = GetDeviceCaps(hdc, VERTRES);
const unsigned short WIDTH = GetDeviceCaps(hdc, HORZRES);