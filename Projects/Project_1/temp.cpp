//Old algorithm that took up too much space lmao
// for (int i = 0; i <= counter; i++)  {
    //   if      (dir == 0)  { r += 0;     c += -1; } //Backwards (right)
    //   else if (dir == 1)  { r += -1;    c += -1; } //Upper right diagonal
    //   else if (dir == 2)  { r += -1;    c += 0;  } //Up
    //   else if (dir == 3)  { r += -1;    c += 1;  } //Upper left diagonal
    //   else if (dir == 4)  { r += 0;     c += 1;  } //Left
    //   else if (dir == 5)  { r += 1;     c += 1;  } //Lower left diagonal
    //   else if (dir == 6)  { r += 1;     c += 0;  } //Down
    //   else if (dir == 7)  { r += 1;     c += -1; } //Lower right diagonal
    //   board[r][c] = currentPlayer;
    // }