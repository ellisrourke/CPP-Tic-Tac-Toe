#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
//new from clion 11:11
using namespace std;
class Board{
public:
    //constructor method
    Board(){
        srand(time(nullptr));
    }

    //data members
    string board[9] = {"1","2","3","4","5","6","7","8","9"};
    vector<int> filled = {};
    int totalTurns =0;
    bool gameOver = false;

    //member functions
   int inArray(vector<int> &arr,int check) {
    if(find(arr.begin(), arr.end(), check) != arr.end()){
          return 1;
        } else {
          return 0;
        }
    }

   void outputWinner(int i){
      if(board[i] == "X"){
        cout << "Computer Wins" << endl;
      } else {
        cout << "Player Wins" << endl;
      }
      gameOver = true;
    }

   int checkWin(){
      for(int i=0;i<9;i+=3){
        //Check for horizontal wins
        if(board[i] == board[i+1] && board[i] == board[i+2]){
          outputWinner(i);
          gameOver = true;
          return 1;
          }
        }

        //Check for vertical wins
        for(int j=0;j<3;j++){
          //Check For horizontal wins
          if(board[j] == board[j+3] && board[j] == board[j+6]){
            outputWinner(j);
            //gameOver = true;
            return 1;
          }
      }



        //Check for diagonalWins
      if(board[0]==board[4] && board[0]==board[8]){
        outputWinner(0);
      } else if(board[2]==board[4]&&board[2]==board[6]){
        outputWinner(2);
      }
    }

   void updateBoard(int i,char player){
        board[i] = player;
        filled.push_back(i);
        totalTurns++;
        checkWin();
        //cout << totalTurns << endl;

    }

   void displayBoard(){
        for(int i=1;i<10;i++){
            cout << " | " << board[i-1];
            if(i%3==0){
                cout << " |" << endl;
            }
        }
        cout << "-----------------------";
        cout << endl;
    }

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

   void submitComputerTurn(int x){
     updateBoard(x,'X');
     displayBoard();
     cout << "The computer chose position " << x << endl;
   }

   int computerTurn(){
     //check for possible horizontal moves
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
     //////////////////////////////////////////////
     //check vertical moves
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
    Board myBoard;
    myBoard.play();









}
