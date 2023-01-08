#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

void Winner(){
    // Code to display winner with an ascii art from the net
    system ("CLS");
    string name;
    cout << "Enter your Name:" << endl;
    cin.ignore();
    getline(cin,name);
    cout << "Winner >>" << name << "<<" << endl;
    cout << "\t" <<" .__." << endl;
    cout << "\t" <<"(|  |)"<< endl;
    cout << "\t" <<" (  )"<< endl;
    cout << "\t" <<" _)(_"<< endl;
}

bool PlayAgain(){
    // Basic Play again code anything other than Y or y is going to exit
    char Choice;
    cout << "\n\nDo You want to play again??\nPlease Enter y or n: ";
    cin >> Choice;
    if(Choice == 'y' || Choice =='Y')
    {
        return 1;
    }
    return 0;
}

void DrawTable(char Matrix[][3]){ 
    // Table which will initially display the numbers post which refresh after every input by the user
    system ("CLS");
    for (int i = 0; i < 3; i++)
    {
        cout << "_____________" << endl;
        cout << "| ";
        for(int j = 0; j < 3; j++){
            cout <<Matrix[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "_____________" << endl;
}

// Check if Valid and if Valid Assign Value which is assigned to the player
bool LocationIsValid(const char& n, char Matrix[][3], const char& Player){
    switch(n){
        case '1':
            if(Matrix[0][0] == n){
                Matrix[0][0] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '2':
            if(Matrix[0][1] == n){
                Matrix[0][1] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
        }
        case '3':
            if(Matrix[0][2] == n){
                Matrix[0][2] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '4':
            if(Matrix[1][0] == n){
                Matrix[1][0] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '5':
            if(Matrix[1][1] == n){
                Matrix[1][1] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '6':
            if(Matrix[1][2] == n){
                Matrix[1][2] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '7':
            if(Matrix[2][0] == n){
                Matrix[2][0] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '8':
            if(Matrix[2][1] == n){
                Matrix[2][1] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        case '9':
            if(Matrix[2][2] == n){
                Matrix[2][2] = Player;
                return false;
            }
            else
            {
                cout << "Location Entered is already occupied. Please Re-Enter: ";
                return true;
            }
        default:
            cout <<"Location is not part of the above mentioned Locations. Please Re-Enter: ";
            return true;
    }
}

void PlayerTurn(const char& Player, int& counter, char Matrix[][3], char& n){
    do{
        cin >> n;
    }while(LocationIsValid(n, Matrix, Player));
    DrawTable(Matrix);
    counter++;
}


bool CheckForWinner(const int& counter, char Matrix[][3], const char& n, char& Player){
    if(counter > 4){
        switch(n){
            case '1':
                //          1            2               2                 3                1               4               4               7               1                  5                5               9
                if((Matrix[0][0] == Matrix[0][1] && Matrix[0][1] == Matrix[0][2]) || (Matrix[0][0] == Matrix[1][0] && Matrix[1][0] == Matrix[2][0]) || (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])){
                    Winner();
                    return false;
                }
                else
                {
                    return true;
                }
            case '2':
                //          1            2               2                 3                2               5              5               8
                if((Matrix[0][0] == Matrix[0][1] && Matrix[0][1] == Matrix[0][2]) || (Matrix[0][1] == Matrix[1][1] && Matrix[1][1] == Matrix[2][1])){
                    Winner();
                    return false;
                }
                return true;
            case '3':
                //          1            2               2                 3                3               6               6               9                   3               5               5               9
                if((Matrix[0][0] == Matrix[0][1] && Matrix[0][1] == Matrix[0][2]) || (Matrix[0][2] == Matrix[1][2] && Matrix[1][2] == Matrix[2][2]) || (Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])){
                    Winner();
                    return false;
                }
                return true;
            case '4':
                //          1            4                  4                7               4               5               5               6
                if((Matrix[0][0] == Matrix[1][0] && Matrix[1][0] == Matrix[2][0]) || (Matrix[1][0] == Matrix[1][1] && Matrix[1][1] == Matrix[1][2])){
                    Winner();
                    return false;
                }
                return true;
            case '5':
                //          4            5                  5                6               2               5               5               8
                if((Matrix[1][0] == Matrix[1][1] && Matrix[1][1] == Matrix[1][2]) || (Matrix[0][1] == Matrix[1][1] && Matrix[1][1] == Matrix[2][1])){
                    Winner();
                    return false;
                }
                return true;
            case '6':
                //          3               6               6                9               4               5               5               6
                if((Matrix[0][2] == Matrix[1][2] && Matrix[1][2] == Matrix[2][2]) || (Matrix[1][0] == Matrix[1][1] && Matrix[1][1] == Matrix[1][2])){
                    Winner();
                    return false;
                }
                return true;
            case '7':
                //           1           4                  4                7               7               8               8               9                  3               5               5               7
                if((Matrix[0][0] == Matrix[1][0] && Matrix[1][0] == Matrix[2][0]) || (Matrix[2][0] == Matrix[2][1] && Matrix[2][1] == Matrix[2][2]) || (Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])){
                    Winner();
                    return false;
                }
                return true;
            case '8':
                //          7               8                8               9               2               5               5               8
                if((Matrix[2][0] == Matrix[2][1] && Matrix[2][1] == Matrix[2][2]) || (Matrix[0][1] == Matrix[1][1] && Matrix[1][1] == Matrix[2][1])){
                    Winner();
                    return false;
                }
                return true;
            case '9':
                //          3            6               6                 9                7               8               8               9               1                  5                5               9
                if((Matrix[0][2] == Matrix[1][2] && Matrix[1][2] == Matrix[2][2]) || (Matrix[2][0] == Matrix[2][1] && Matrix[2][1] == Matrix[2][2]) || (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])){
                    Winner();
                    return false;
                }
                return true;
        }
    }
    if(counter == 9){
        cout << "It is a Draw" << endl;
        return false;
    }
    return true;
}


void PlayGame(){
    char Matrix[3][3]{0};
    char Counter = '1';
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++, Counter++){
            Matrix[i][j] = Counter;
        }
    }
    char Player1 = 'X';
    char Player2 = 'O';
    DrawTable(Matrix);
    bool ContinueLoop = true;
    do{
        cout << "\t\tPlayer 1 Turn \nEnter One of the Numbers Mentioned in the Matrix to Insert X: ";
        char n = '0';
        PlayerTurn(Player1, counter, Matrix, n);
        ContinueLoop = CheckForWinner(counter, Matrix, n , Player1);
        if(ContinueLoop){
        cout << "\t\tPlayer 2 Turn \nEnter One of the Numbers Mentioned in the Matrix to Insert O: ";
        PlayerTurn(Player2, counter, Matrix, n);
        ContinueLoop = CheckForWinner(counter, Matrix, n , Player2);
        }
    }while(ContinueLoop); 
}


int main(){
    do{
        system ("CLS");
        PlayGame();
    }while(PlayAgain());
}