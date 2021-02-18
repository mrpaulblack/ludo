# ludo
a small ludo clone written in c++



## Build
```git clone https://github.com/MrPaulBlack/ludo.git```

```cd ludo```

```g++ -Wall -std=c++11 Main.cpp -o ludo```



## Run
```./ludo```



## Default setup in Main.cpp:
Game game(4, 0);
std::vector<Player> player(game.getPlayer() + game.getCPU(), 4);
Board board(game.getPlayer() + game.getCPU(), 10);
stuff that can be changed in Main.cpp:


Line 6: Game game([number of real player], [number of cpu's]);
Line 7: std::vector<Player> player(game.getPlayer() + game.getCPU(), [number of figures each player has]);
Line 8: Board board(game.getPlayer() + game.getCPU(), [size of the board per player]);



## If you want to test the game with only cpus:

change Line 6 in Main.cpp to:
Game game(0, 4);

If you want 1 player and 3 cpus for example:
Game game(1, 3);



## You can also stresstest the game and increase the number of players, figures and size of the board:
change the following Line6, Line 7 and Line 8 in Main.cpp

Game game(0, 10);
std::vector<Player> player(game.getPlayer() + game.getCPU(), 10);
Board board(game.getPlayer() + game.getCPU(), 20);