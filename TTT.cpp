#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
class TTT{
    vector<char> tem = {'1','2','3','4','5','6','7','8','9'};
    public:
        vector<char> digi;
        int player = 0;
        void play(){
            int choice;
            char sign;
            player = (player%2);
            if(player == 1)
                sign = 'X';
            else
                sign = 'O';
            string temp = player == 0 ? "Ist":"IInd";
            cout<<"Player "<<temp<<" Choice :- ";
            cin>>choice;
            
            if(choice <= 9 && choice > 0)
                digi[choice - 1] = sign;
            else
                cout<<"enter the choice between 1 - 9\n";
            player++;
            system("CLS");
        }
        void reset(){
            digi.resize(0);
            }
        void set(){
            for(int i=0; i<tem.size(); i++){
                digi.push_back(tem[i]);
            }
        }
        void playerreset(){
        player = 0;
    }
        void platform(){
            cout<<"      TIC TAC TOI\n";
            printf("---------------------\n");
            printf("|  %c  |   %c   |  %c  |\n",digi[0],digi[1],digi[2]);
            printf("|     |       |     |\n");
            printf("|-------------------|\n");
            printf("|  %c  |   %c   |  %c  |\n",digi[3],digi[4],digi[5]);
            printf("|     |       |     |\n");
            printf("|-------------------|\n");
            printf("|  %c  |   %c   |  %c  |\n",digi[6],digi[7],digi[8]);
            printf("|     |       |     |\n");
            printf("---------------------\n");
        }
        int laws(){
            if(digi[0] == digi[1] && digi[1] == digi[2]) return 0;
            if(digi[3] == digi[4] && digi[4] == digi[5]) return 0;
            if(digi[6] == digi[7] && digi[7] == digi[8]) return 0;
            if(digi[0] == digi[3] && digi[3] == digi[6]) return 0;
            if(digi[1] == digi[4] && digi[4] == digi[7]) return 0;
            if(digi[2] == digi[5] && digi[5] == digi[8]) return 0;
            if(digi[0] == digi[4] && digi[4] == digi[8]) return 0;
            if(digi[2] == digi[4] && digi[4] == digi[6]) return 0;
            int count = 0,i=9;
            while(i--){
                if(digi[i] == 'X' || digi[i] == 'O') count++;
            }
            if(count == 9){
                return 1;
            }
            return -1;
        }
};
int main(){
    TTT obj;
    obj.set();
    int k;
    char ch;
    for(int i=0; i<5; i--){
        for(int j=0; j<5; j--){
        obj.set();
        obj.platform();
        obj.play();
        string temp = obj.player == 0 ? "Ist":"IInd";
        if(obj.laws() == 0){
            cout<<"Player "<<obj.player<<" is Win.\n";
            break;
        }   
        else if(obj.laws() == 1){
            cout<<"Match has been Draw... \n";
            break;
        }
    }
    cout<<"Play again[Y/N] :- ";
    char ans;cin>>ans;
    if(ans == 'y' || ans == 'Y');
    else
        return 0;
    system("CLS");
    obj.reset();
    obj.playerreset();
    }
    return 0;
}