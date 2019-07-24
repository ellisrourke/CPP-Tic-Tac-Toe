#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
//new from clion 11:11
using namespace std;
class Tictactoe{
public:
    //constructor method
    Tictactoe(){
        srand(time(nullptr));
    }

    //data members
    string board[9] = {"1","2","3","4","5","6","7","8","9"};
    vector<int> filled = {}; // vector of unavailable board positions
    int totalTurns =0; // total number of turns taken in the game
    bool gameOver = false; // current state of the game

    //member functions

    //checks if a value is in a vector
   int inArray(vector<int> arr,int check) {
    if(find(arr.begin(), arr.end(), check) != arr.end()){
          return 1;
        } else {
          return 0;
        }
    }

    //outputs the winner of the game and sets the game status to over
   void outputWinner(int i){

      if(board[i] == "X"){
        cout << "Computer Wins" << endl;
      } else {
        cout << "Player Wins" << endl;
      }
      gameOver = true;
    }


    //checks for all possible winning combinations on the Board
    //calls outputWinner method if a winning combination is found
   int checkWin(){
      for(int i=0;i<9;i+=3){
        //Check for horizontal wins//
        if(board[i] == board[i+1] && board[i] == board[i+2]){
          outputWinner(i);
          return 1;
          }
        }

        //Check for vertical wins//
        for(int j=0;j<3;j++){
          if(board[j] == board[j+3] && board[j] == board[j+6]){
            outputWinner(j);
            return 1;
          }
      }

        //Check for diagonalWins//
      if(board[0]==board[4] && board[0]==board[8]){
        outputWinner(0);
        return 1;
      } else if(board[2]==board[4]&&board[2]==board[6]){
        outputWinner(2);
        return 1;
      }
      return 0;
    }

    //takes a board position and a players char indicator
    //updates the board array with the given move
   void updateBoard(int i,char player){
        board[i] = player;
        filled.push_back(i);
        totalTurns++;
        checkWin();
    }

    //displays the current state of the board with formatting
   void displayBoard(){
        for(int i=1;i<10;i++){
            cout << " | " << board[i-1];
            if(i%3==0){
                cout << " |" << endl;
            }
        }
        cout << "-----------------------" << endl;
    }

    // takes input from the user, checks the input is valid
    // and the position chosen is unavailable
    // then updates and displays the board
   void humanTurn(){
      if(gameOver == false){
      int pos=-1;
        while(pos>9 || pos<1 || inArray(filled,pos-1)==1){
            cout << "choose a board position" << endl;
            cin >> pos; //change to better syntax!!
        }
        pos--;
            updateBoard(pos,'0');
            displayBoard();
        }
      }

      // once the computer has chosen a turn, this method is called
      // to update the board, display the board and inform
      // the player of the board postion that was chosen
   void submitComputerTurn(int x){
     updateBoard(x,'X');
     displayBoard();
     cout << "The computer chose position " << x+1 << endl;
   }

   int computerTurn(){
     //check for possible horizontal moves//
     for(int i=0;i<9;i+=3){
       if(board[i]==board[i+1] && inArray(filled,i+2)==0){
         submitComputerTurn(i+2);
         return 1;
       } else if(board[i]==board[i+2] && inArray(filled,i+1)==0){
         submitComputerTurn(i+1);
         return 1;
       } else if(board[i+1]==board[i+2]  && inArray(filled,i)==0){
         submitComputerTurn(i);
         return 1;
       }
     }

     //check vertical moves//
     for(int j=0;j<3;j++){
       if(board[j]==board[j+3] && inArray(filled,j+6)==0){
         submitComputerTurn(j+6);
         return 1;
     } else if(board[j]==board[j+6] && inArray(filled,j+3)==0){
       submitComputerTurn(j+3);
         return 1;
     } else if(board[j+3]==board[j+6] && inArray(filled,j)==0){
       submitComputerTurn(j);
         return 1;
     }
   }
   //////////////////////////////////////////////
   //check diagonal moves (already including centre)
   //check if middle
   if(inArray(filled,4)==1){
     if(board[0]==board[4]){
       submitComputerTurn(8);
       return 1;
     } else if(board[2]==board[4]){
       submitComputerTurn(6);
       return 1;
     } else if(board[6]==board[4]){
       submitComputerTurn(2);
       return 1;
     } else if(board[8]==board[4]){
       submitComputerTurn(0);
       return 1;
     }
  } else if(inArray(filled,4)==0){
           if(board[0]==board[8]){
             submitComputerTurn(4);
             return 1;
           } else if (board[2]==board[6]){
             submitComputerTurn(4);
             return 1;
           }
  }
  // if no moves found, choose random board position
     int num = rand() % 9;
     while(inArray(filled,num)==1){
       num = rand() % 9;
   }
      submitComputerTurn(num);
}

int play(){
        displayBoard();
        while(totalTurns<9){
          if(gameOver==false){
            humanTurn();
            }
          if(totalTurns<9 && gameOver==false){
              computerTurn();
            } else {
              return 0;
            }
        }
    }


};


int main() {
    Tictactoe mygame;
    mygame.play();


}
