#include <iostream>
#include <stdlib.h> // does this work?

using namespace std;
 
void ExecuteSeriesOfSteps(int& PriorSelectedValue, bool& Win, int& NumbertoStore, int& GameOfEight, string& Player){
            
            bool failure = true;            
            do
            {
                failure = false;
                cout << "\nNumber Chosen by the previous player: " << PriorSelectedValue << endl;
                cout << "Please Enter From One of the Given Numbers: ";
                cin >> NumbertoStore;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\n**REVENTH** Nice Try Ma Boi \n" << endl;
                    failure = true;
                }
                
            }while((NumbertoStore == PriorSelectedValue) || (NumbertoStore < 1 || NumbertoStore > 3) || failure);

            GameOfEight -= NumbertoStore;
            PriorSelectedValue = NumbertoStore;
            if(GameOfEight == 0){
                cout << "\n\t\t" << Player << " Wins" << endl;
                Win = false;
            }
            else if (GameOfEight < 0){
                cout << "\n\t\t" << Player << " Loses" << endl;
                Win = false;
            }
}
 
void PlayerTurn(int& PriorSelectedValue, bool& Win,int& GameOfEight, string& Player, int& NumbertoStore){
    
    switch (PriorSelectedValue){
        case 0:
            cout << "\n\t\t" << Player << " Turn";
            cout << "\n\nPlease enter one of the following numbers \n1 2 3\n";
            ExecuteSeriesOfSteps(PriorSelectedValue, Win, NumbertoStore, GameOfEight, Player);
            break;
        case 1:
            cout << "\n\t\t" << Player << " Turn";
            cout << "\n\nPlease enter one of the following numbers \n2 3\n";
            ExecuteSeriesOfSteps(PriorSelectedValue, Win, NumbertoStore, GameOfEight, Player);
            break;
        case 2:
            cout << "\n\t\t" << Player << " Turn";
            cout << "\n\nPlease enter one of the following numbers \n1 3\n";
            ExecuteSeriesOfSteps(PriorSelectedValue, Win, NumbertoStore, GameOfEight, Player);
            break;
 
        case 3:
            cout << "\n\t\t" << Player << " Turn";
            cout << "\n\nPlease enter one of the following numbers \n1 2\n";
            ExecuteSeriesOfSteps(PriorSelectedValue, Win, NumbertoStore, GameOfEight, Player);
            break;
 
            
    }
}
 
int PlayAgain(){
    char Choice = 'n';
    while(true)
    {
        cout << "\nDo You want to play again??\nPlease Enter y or n: ";
        cin >> Choice;
        if(Choice == 'y')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
 
void PlayGame(){
    int GameOfEight = 8;
    cout <<"Rules of The Game" << endl;
    cout << "\tWhoever Gets the Number to Zero on Their Turn Wins\n\tNumber is Eight\n\tChoose Between 1 to 3\n\tNumber you choose will be substracted from 8\n\tDont Come to me with bugs this is not even gonna go commercial\n\n Reventh Honorable Mention when this code goes on github\n\n" << endl;
    string Player1 = "Player 1";
    string Player2 = "Player 2";
    int PriorSelectedValue = 0;
    int NumbertoStore = 0;
    bool Win = true;
    do{
        PlayerTurn(PriorSelectedValue, Win, GameOfEight, Player1, NumbertoStore);
        if(!Win)
        {
            return;
        }
        PlayerTurn(PriorSelectedValue, Win, GameOfEight, Player2, NumbertoStore);
          if(!Win)
        {
            return;
        }
    }while(Win);
}
 
int main(){
    do{
        system ("CLS");
        PlayGame();
    }while(PlayAgain());
}