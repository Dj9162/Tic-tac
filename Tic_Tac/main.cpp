#include <iostream>

using namespace std;
char arr[9] = {'1','2','3','4','5','6','7','8','9'};
bool one = true;
int cnt = 0;

void board(){
    system("cls");
    cout << "\tWelcome to Tic-Tac Game:~" << endl;
    cout << "\t\tPlayer1[X]" << endl;
    cout << "\t\tPlayer2[0]" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t  "<<arr[0]<<"  |  "<<arr[1]<<"  |  "<<arr[2]<<"   " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t "<<arr[3]<<"   |  "<<arr[4]<<"  |  "<<arr[5]<<"   " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t "<<arr[6]<<"   |  "<<arr[7]<<"  |  "<<arr[8]<<"   " << endl;
    cout << "\t\t\t     |     |     " << endl;
}

void Turn(){
     int choice;
     if( one)
        cout << "Player1[X] turn: ";
     else
        cout << "Player2[0] turn: ";
     cin >> choice;
     if((arr[choice-1] != 'X' && arr[choice-1] != '0')&&(choice >=1 && choice <= 9)){
        if(one){
            arr[choice-1] = 'X';
            one = false;
        }
        else{
            arr[choice-1] = '0';
            one = true;
        }
        cnt++;
     }
     else{
        cout << "Invalid Input!!" << endl;

    }

}

bool decision(){
    for(int i = 0; i < 9; i += 3){
        if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2])
            return true;
    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == arr[i+3] && arr[i+3] == arr[i+6])
            return true;
    }
    if(arr[0] == arr[4] && arr[4] == arr[8])
        return true;
    if(arr[2] == arr[4] && arr[4] == arr[6])
        return true;
    return false;
}

int main()
{

    while(cnt < 9){

        board();
        Turn();
        if(decision()){
            board();
            if(!one){
                cout <<endl<<endl<< "\t\tCongratulation,Player1[X] Win!" << endl;
                return 0;
            }
            else{
                cout <<endl<<endl<< "\t\tCongratulation, Player2[0] Win!" << endl;
                return 0;
            }
        }
    }
    if(cnt == 9){
        board();
        cout <<endl<<endl<< "\t\tDRAW!!, Both Players played well.." << endl;
    }

    return 0;
}
