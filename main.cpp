#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
//newChange2
//3
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
        int x =-1;
        x = (find(arr.begin(), arr.end(), check) != arr.end());
        if(x==-1){
          return 0;
        } else {
          return x;
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

    void updateBoard2D(int i,char player){
        //find array index to update
        int x = i % 3;    // % is the "modulo operator", the remainder of i / width;
        int y = i / 3;    // where "/" is an integer division
        cout << "board [" << x << "][" << y << "]" << endl;
        board[y][x] = player;
        displayBoard2D();


    }

    void displayBoard2D(){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                cout << board[x][y] << " ";
            }
            cout <<  endl ;
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
            filled.push_back(pos);
        }
      }

    void computerTurnOld(){
        int num = rand() % 9;
        while(inArray(filled,num)==1){
          num = rand() % 9;
        }
            updateBoard(num,'X');
            displayBoard();
            filled.push_back(num);
   }

   void submitComputerTurn(int x){
     updateBoard(x,'X');
     displayBoard();
     filled.push_back(x);
     cout << "The computer chose position " << x << endl;
   }

   void computerTurn(){
     //check for possible horizontal moves
     for(int i=0;i<9;i+=3){
       //check if end pos is free
       if(board[i]==board[i+1] && inArray(filled,i+2)==0){
         submitComputerTurn(i+2);
         break;
         //check if middle is free
       } else if(board[i]==board[i+2] && inArray(filled,i+1)==0){
         submitComputerTurn(i+1);
         break;
         //check if first pos is free
       } else if(board[i+1]==board[i+2]  && inArray(filled,i)==0){
         submitComputerTurn(i);
         break;
       }
     }
     //////////////////////////////////////////////
     //check vertical moves
     for(int j=0;j<3;j++){
       if(board[j]==board[j+3] && inArray(filled,j+6)==0){
         submitComputerTurn(j+6);
         break;
     } else if(board[j]==board[j+6] && inArray(filled,j+3)==0){
       submitComputerTurn(j+3);
       break;
     } else if(board[j+3]==board[j+6] && inArray(filled,j)==0){
       submitComputerTurn(j);
       break;
     }
   }
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
