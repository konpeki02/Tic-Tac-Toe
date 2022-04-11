#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#pragma once
using namespace std;

class iofiles {



public:
    ofstream input;
    ofstream game;
    ifstream output;
    ifstream game_out;

    void clearFile_write(){
        input.open("TTTwins.txt",ios::trunc);
        input.close();
    }
    void clearFile_game(){
        game.open("gameresults.txt",ios::trunc);
        game.close();
    }

    void write_game(int entry, string user,char board[]){
        game.open("gameresults.txt",ios::app);
        game << user << " choose " << entry << endl;
        game << "\t" << board[1] << "  " << board[2] << "  " << board[3] << endl;
        game << "\t" << board[4] << "  " << board[5] << "  " << board[6] << endl;
        game << "\t" << board[7] << "  " << board[8] << "  " << board[9] << endl;
        game << "\t" << "* * * *" << endl;
        game.close();
    }

    void write_Horiz(int i,string choice){
        game.open("gameresults.txt",ios::app);
        input.open("TTTwins.txt",ios::app);
        input << choice << " " << i << "-" << i+1 << "-" << i+2 << " horizontal win" << "\n";
        game << choice << " " << i << "-" << i+1 << "-" << i+2 << " horizontal win" << "\n";
        input.close();
        game.close();
    }
    void write_Vert(int i,string choice){
        game.open("gameresults.txt",ios::app);
        input.open("TTTwins.txt",ios::app);
        input << choice << " " << i << "-" << i+3 << "-" << i+6 << " vertical win" << endl;
        game << choice << " " << i << "-" << i+3 << "-" << i+6 << " vertical win" << endl;
        input.close();
        game.close();
    }
    void write_Diag_1(string choice){
        game.open("gameresults.txt",ios::app);
        input.open("TTTwins.txt",ios::app);
        input << choice << " " << "1-5-9" << " diagonal win" << endl;
        game << choice << " " << "1-5-9" << " diagonal win" << endl;
        input.close();
        game.close();
    }
    void write_Diag_2(string choice){
        game.open("gameresults.txt",ios::app);
        input.open("TTTwins.txt",ios::app);
        input << choice << " " << "3-5-7" << " diagonal win" << endl;
        game << choice << " " << "3-5-7" << " diagonal win" << endl;
        input.close();
        game.close();
    }

    void writeDraw(){
        game.open("gameresults.txt",ios::app);
        input.open("TTTwins.txt",ios::app);
        input << "Tie" << endl;
        game << "Tie" << endl;
        input.close();
        game.close();
    }

    void display_Results(string capture){
        output.open("TTTwins.txt",ios::in);

        while(getline(output,capture)){

            cout << capture << endl;

        }
        output.close();
    }

    void display_results(string cap){
        game_out.open("gameresults.txt",ios::in);

        while(getline(game_out,cap)){
            cout << cap << endl;
        }

        game_out.close();
    }

    void display(){
        cout << "Filename: " << getFilename() << endl;
        cout << "Number of Wins: " << getNumberOfWins() << endl;
        cout << "Past Wins: ";
        for(string x:list){
            cout << x << " ";
        }
    }
    void writeResults(string input,string attribute,int pos1, int pos2, int pos3){
        string line = input + " " + attribute + " " + to_string(pos1) + "-" + to_string(pos2) + "-" + to_string(pos3);
        if(attribute=="Draw") {
            list.push_back("Draw");
        }
        else if(attribute != "Draw") {
            list.push_back(line);
        }
    }

    void display_stats(string entry){

        bool elementFound;
        string const val = entry;
        sort(list.begin(),list.end());
        elementFound = binary_search(list.begin(),list.end(),val);
        if(!elementFound){
            cout << "\nFound " << entry;
        }
        else
            cout << "\nNot Found "  << entry;
    }


    int getNumberOfWins(){
        return numberOfWins;
    }
    void setNumberOfWins(int inNumber){
        numberOfWins = inNumber;
    }


    string getWinMessage(string player){
        if(player == "Player") {
            numberOfWins++;
            return win;
        }
        if(player == "Computer")
            return lose;
    }

    void setFilename(string inName){
        Filename = inName;
    }
    string getFilename(){
        return Filename;
    }


private:

    vector <string> list;
    string Filename = "playerName";
    int numberOfWins{};
    string win = "Win";
    string lose = "Loss";

};
