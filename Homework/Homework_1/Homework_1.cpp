#include <iostream>
#include <random>
using namespace std;

//Louis Monfiero
//CECS 282 - 1/31/2020
//Homework#1

int main()  {
    random_device rd{};
    default_random_engine engine{ rd() };
    uniform_int_distribution<int> range{1, 3};
    uniform_int_distribution<int> range2{1,5};

    int winningDoor = range(engine);
    int prize = range2(engine);
    cout << "You've three doors in front of you, one contains a glorious prize!\nYour goal is to choose the correct door.\nThe other two doors have, well, they have goats behind them so let's hope you don't take a goat home today\n";

    char response;
    int goatDoor, chosenDoor, lastDoor;
    cout << "So go ahead, choose a door! (1, 2, or 3)\n";
    cin >> chosenDoor;
    goatDoor = range(engine);
    lastDoor = range(engine);
    while (goatDoor == winningDoor || goatDoor == chosenDoor) {
      goatDoor = range(engine);
    }

    if (chosenDoor == winningDoor)  {
      while (lastDoor == winningDoor || lastDoor == goatDoor) {
        lastDoor = range(engine);
      }
    }

    cout << "You've chosen door number: " << chosenDoor << endl;
    cout << "Now before we finalize your decision, let's open one of the other two doors.\nKaren, would you mind showing us what's behind door #" << goatDoor <<" Oh! It's a goat!\n";
    cout << "Well what do you say, would you like to switch doors\n(Choose 'y' or 'n')\n";
    cin >> response;


    if (response == 'n')  {
      cout << "You've chosen to stay with door #" << chosenDoor << endl;
    }//Ends response if

    else if (response == 'y') {
      if (chosenDoor != winningDoor)  {
        chosenDoor = winningDoor;
      }
      else  {
        chosenDoor = lastDoor;
      }
      cout << "So you've switched to door #" << chosenDoor << endl;
    }

    if (chosenDoor == winningDoor)  {
        cout << "Congrats, you've won the game! And now for your prize..." << endl;
        switch (prize)  {
          case 1: cout << "You've won 2 front-row Laker tickets! How nice is that?\n";
          break;

          case 2: cout << "You've won a brand new laptop! Sweet!\n";
          break;

          case 3: cout << "You've won 2 round trip tickets to any destination in the world! Safe travels!\n";
          break;

          case 4: cout << "A Cybertruck!? You'll be the first to take this bad boy for a cruise!\n";
          break;

          case 5: cout << "Surprise surprise! It's another goat! Except he's a magic goat! Kinda like a unicorn!\n";
          break;
        }
      }
    else  {
        cout << "Looks like you're taking a goat home, how unfortunate!\nJoin us again some time and let's see if you can win it the next time!\n";
      }

}
