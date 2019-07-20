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

    Board(){
        srand(time(nullptr));
    }

    //data members
    string board[9] = {"1","2","3","4","5","6","7","8","9"};
    vector<int> filled = {};
    int totalTurns =0;

    //member functions
    int inArray(vector<int> &arr,int check) {
        int x = (find(arr.begin(), arr.end(), check) != arr.end());
        return x;
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
      int pos=-1;
        while(pos>9 || pos<1){
            cout << "choose a board position" << endl;
            cin >> pos; //change to better syntax!!
        }

        pos--;
        if(inArray(filled,pos)==0) {
            updateBoard(pos,'0');
            displayBoard();
            filled.push_back(pos);
        } else {
            cout << "!spot taken try again!" << endl;
            humanTurn();
        }
    }
    void computerTurn(){
        int num = rand() % 9;
        if(inArray(filled,num)==0) {
            updateBoard(num,'X');
            displayBoard();
            filled.push_back(num);
        } else {
            computerTurn();
        }
    }

    /*void checkWin(){
      if()
    }
*/



    void play(){
        displayBoard();
        while(totalTurns<9){
            humanTurn();
            if(totalTurns<9)
                computerTurn();
        }
    }

};


int main() {
    Board myBoard;

    myBoard.play();
    //new









}
