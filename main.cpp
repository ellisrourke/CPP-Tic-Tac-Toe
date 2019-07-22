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
        int x = (find(arr.begin(), arr.end(), check) != arr.end());
        return x;
    }

    int checkWin(){
      for(int i=0;i<9;i+=3){
        //Check For horizontal wins
        if(board[i] == board[i+1] && board[i] == board[i+2]){
          if(board[i] == "X"){
            cout << "Computer Wins" << endl;
          } else {
            cout << "Player Wins" << endl;
          }
          gameOver = true;
          return 1;
        }





          //for(int k=0;k<3;K++){
            //Check for diagonalWins
        //  }
        }
        for(int j=0;j<3;j++){
          //Check For horizontal wins
          if(board[j] == board[j+3] && board[j] == board[j+6]){
            if(board[j] == "X"){
              cout << "Computer Wins" << endl;
            } else {
              cout << "Player Wins" << endl;
            }
            gameOver = true;
            return 1;
          }
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


    void computerTurn(){

        int num = rand() % 9;


        while(inArray(filled,num)==1){
          num = rand() % 9;
        }
            updateBoard(num,'X');
            displayBoard();
            filled.push_back(num);
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
