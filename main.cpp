#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;


char xo[3][3];
char playerA;
char playerB;

void displayBoard(){
    cout << endl;
    cout<< "\t\t\t\t       "<<" C "<< "  O "<<"  L "<< endl;
    cout<< "\t\t\t\t       "<<"[0]"<< " [1]"<<" [2]"<< endl;
    cout<< "\t\t\t\t R [0]  "<<xo[0][0] << " | " << xo[0][1] << " | " << xo[0][2] << endl;
    cout<< "\t\t\t\t       ---"<< (char)193 << "---" << (char)193 << "---" << endl;
    cout<< "\t\t\t\t O [1]  "<<xo[1][0] << " | " << xo[1][1] << " | " << xo[1][2] << endl;
    cout<< "\t\t\t\t       ---"<< (char)193 << "---" << (char)193 << "---" << endl;
    cout<< "\t\t\t\t W [2]  "<<xo[2][0] << " | " << xo[2][1] << " | " << xo[2][2] << endl;
}

bool check(){
    for(int i=0;i<3;i++){
        if(xo[i][0] != ' ' && xo[i][0] == xo[i][1] && xo[i][1] == xo[i][2])
            return true;
    }
    for(int i=0;i<3;i++){
        if(xo[0][i] != ' ' && xo[0][i] == xo[1][i] && xo[1][i] == xo[2][i])
            return true;
    }
    if(xo[0][0] != ' ' && xo[0][0] == xo[1][1] && xo[1][1] == xo[2][2])
            return true;
    if(xo[0][2] != ' ' && xo[0][2] == xo[1][1] && xo[1][1] == xo[2][0])
            return true;

    return false;

}

void choose(char& playerA, char& playerB){
    char temp;

A:
    cin.clear();
    cin >>  temp;
if(temp != 'X' && temp != 'O' && temp != 'x' && temp != 'o'){
    cout << "You have entered the wrong symbol!\nPlease choose from these two symbols ( X or O )" << endl;
    goto A;
}else{
    if(temp >= 97 ){
        temp = temp -32;
    }
playerA = temp;
if(temp == 'X'){
    playerB='O';
}else
    playerB='X';
}
}

void setValue(int c,int row, int col){
            if(c%2 == 1){
                xo[row][col]=playerA;

            }else{
                xo[row][col]=playerB;

            }
}

void clearBoard(){
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        xo[i][j] = ' ';
    }
}
}
void delay(int milliseconds){
clock_t now= clock();
while(clock() < (now + milliseconds));
}

void displayTicTacToe(int milliseconds){
cout << "_______________________________________________________________________________"<< endl;delay(milliseconds);
cout << "_______________________________________________________________________________"<< endl << endl;delay(milliseconds);
cout << "-------- -------- -------   -------- ------- -------   -------- ------- -------"<< endl;delay(milliseconds);
cout << "-------- -------- ||-----   -------- |-----| ||-----   -------- ||---|| ||     "<< endl;delay(milliseconds);
cout << "   ||       ||    ||           ||    ||   || ||           ||    ||   || -----  "<< endl;delay(milliseconds);
cout << "   ||       ||    ||           ||    ||---|| ||           ||    ||   || -----  "<< endl;delay(milliseconds);
cout << "   ||    -------- ||-----      ||    ||---|| ||-----      ||    ||---|| ||     "<< endl;delay(milliseconds);
cout << "   ||    -------- -------      ||    ||   || -------      ||    ------- -------"<< endl<< endl;delay(milliseconds);
cout << "_______________________________________________________________________________"<< endl;delay(milliseconds);
cout << "_______________________________________________________________________________"<< endl;delay(milliseconds);

}


int main(){


    char more;
    int c;
    int row,col;
    bool winner=false;
    displayTicTacToe(300);
    cout << "\t\t\tWelcome to TicTacToe\n" ;
    cout << "There are only two symbols ( X and O ) from which you can choose." << endl;
    cout << "Choose your symbol." << endl;
    cout << "Player 1: ";
    choose(playerA,playerB);


    cout<< "Let's start the game!"<< endl;

    do{
    system("cls");
    clearBoard();
    displayBoard();
    cout << "We will start with player 1.\n";
    delay(2000);
    c=9;
    winner = false;

    while(c > 0){
            system("cls");
            displayTicTacToe(0);
            displayBoard();
            if(c%2 == 1){
                cout<< endl;
                cout<< "Player 1: Enter the position at which you want to put the symbol!"<< endl;

            }else{
                cout<< endl;
                cout<< "Player 2: Enter the position at which you want to put the symbol!" << endl;

            }


        cout<< "\t  Enter the row: ";
        cin >> row;
        cout << "\t  Enter the column: ";
        cin >> col;
        setValue(c,row,col);


        if(check()){
            if(c%2 == 1){
                system("cls");
                displayTicTacToe(150);
                displayBoard();
                cout<< "\nPlayer 1 win!\n";
                winner=true;
                break;
            }else{
                system("cls");
                displayTicTacToe(150);
                displayBoard();
                cout<< "\nPlayer 2 win!\n";
                winner=true;
                break;
            }
        }

    c--;

    }
    if(c==0){
        cout<< "The match was a tie!" << endl;
        cout<< "Do you wanna play again(Y/N): ";
        cin >> more;
    }
    if(winner){
        cout<< "Do you wanna play again(Y/N): ";
        cin >> more;
    }
    }while(more == 'Y' || more =='y');
    system("exit");
    return 0;
}
