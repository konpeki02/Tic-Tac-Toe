#include <iostream>
#include <random>
#include <fstream>
#include "iofiles.h"
#include <algorithm>
using namespace std;

char board[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };

void display();
int player_function();
int computer_player();
bool check_win();
int protect_data(int x);
void reset_board();
string check_winner(int i);
string tempi;

iofiles player;                         // NOLINT(cert-err58-cpp)

int main() {
    string username;
    cout << "\nEnter player name: ";
    cin >> username;

    player.setFilename(username);

    int temp;
    int tmp2;
    player.clearFile_game();
    player.clearFile_write();

    player.setNumberOfWins(0);

    while(true) {

        char response = 'Y';
        reset_board();

        bool win = false;
        while (!win) {

            check_win();
            temp = player_function();
            player.write_game(temp,"Player",board);
            win = check_win();
            if (win){
                break;
            }
            if(board[1]!= '1' && board[2]!= '2' && board[3]!= '3' && board[4]!= '4' && board[5]!= '5' && board[7]!= '7' && board[8]!= '8' && board[9]!= '9' ){
                display();
                break;
            }
            tmp2 = computer_player();

            player.write_game(tmp2,"Computer",board);
            win = check_win();

        }
        player.display();
        cout << "\nDo you want to play again Y or N ";

        cin >> response;
        if (response == 'N'){
            string capture;
            cout << "\nResults:\n" << endl;
            player.display_Results(capture);
            break;
        }

    }

    char resp;
    cout << "\nDo you want to see game results Y or N ";
    cin >> resp;
    if (resp == 'Y'){
        string cap;
        cout << "\nGame Results: " << endl;
        player.display_results(cap);
    }

    cout << "\nDo you want to search up stats Y or N? ";
    cin >> resp;
    if(resp == 'Y'){
        string in;
        cout << "Enter game result to verify (ie Tie, 1-2-3, 1-5-9) ";
        cin >> in;

        player.display_stats(in);
    }

    return 0;
}

void display() {

    cout << "\t" << board[1] << "  " << board[2] << "  " << board[3] << endl;
    cout << "\t" << board[4] << "  " << board[5] << "  " << board[6] << endl;
    cout << "\t" << board[7] << "  " << board[8] << "  " << board[9] << endl;

}
int player_function() {

    int num_selected;
    Label:
    display();
    cout << "Choose a box 1-9 \n";
    cin >> num_selected;
    protect_data(num_selected);

    if (num_selected >= 1 && num_selected <= 9 && board[num_selected] != 'X' && board[num_selected] != 'O') {
        board[num_selected] = 'X';
        return num_selected;
    }

    else {
        cout << "\nChoose again\n";
        goto Label;
    }

}


int computer_player() {
    LAB:
    uniform_int_distribution<int> distribution(1, 9);
    random_device rand;
    default_random_engine generator(rand());
    int computer_choice = distribution(generator);
    // cin >> computer_choice;


    if (board[computer_choice] != 'X' && board[computer_choice] != 'O' && computer_choice != 0) {
        board[computer_choice] = 'O';
        return computer_choice;
    }
    else
        goto LAB;

}

bool check_win() {


    string choice;
    for (int i = 1; i <= 9; i += 3) {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
            choice = check_winner(i);
            cout << "* * *\n";
            cout << choice << " horizontal win\n";
            cout << i << "-" << i+1 << "-" << i+2 << endl;

            tempi = player.getWinMessage(choice);
            player.writeResults(tempi,"horizontal",i,i+1,i+2);
            player.write_Horiz(i,choice);

            display();
            return true;
        }
    }

    for (int i = 1; i <= 3; i += 1) {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
            choice = check_winner(i);
            cout << "* * *\n";
            cout << choice << " vertical win\n";
            cout << i << "-" << i+3 << "-" << i+6 << endl;

            tempi = player.getWinMessage(choice);
            player.writeResults(tempi,"vertical",i,i+3,i+6);
            player.write_Vert(i,choice);

            display();
            return true;
        }
    }
    if (board[1] == board[5] && board[5] == board[9]) {
        choice = check_winner(1);
        cout << "* * *\n";
        cout << choice << " diagonal win\n";
        cout << "1-5-9\n";
        tempi = player.getWinMessage(choice);
        player.writeResults(tempi,"diagonal",1,5,9);
        player.write_Diag_1(choice);

        display();
        return true;
    }
    if (board[3] == board[5] && board[5] == board[7]) {
        choice = check_winner(3);
        cout << "* * *\n";
        cout << choice << " diagonal win\n";
        cout << "3-5-7\n";
        tempi = player.getWinMessage(choice);
        player.writeResults(tempi,"diagonal",3,5,7);
        player.write_Diag_2(choice);

        display();
        return true;

    }

    if(board[1]!= '1' && board[2]!= '2' && board[3]!= '3' && board[4]!= '4' && board[5]!= '5' && board[7]!= '7' && board[8]!= '8' && board[9]!= '9' ){
        cout << "Tie";
        player.writeDraw();
        tempi = "";
        player.writeResults(tempi,"Draw",0,0,0);
        display();
        return true;

    }

    return false;
}
int protect_data(int x) {

    while (x < 1 || x > 9 || cin.fail()) {

        cin.clear();
        cin.ignore();

        cout << "incorrect data or number added\nenter new input\n";
        cin >> x;
    }

    return x;
}

void reset_board(){
    board[0]='0';
    board[1]='1';
    board[2]='2';
    board[3]='3';
    board[4]='4';
    board[5]='5';
    board[6]='6';
    board[7]='7';
    board[8]='8';
    board[9]='9';
}
string check_winner(int i){
    if(board[i]=='X'){
        return "Player";
    }
    else
        return "Computer";
}
