#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
class TOH{
    vector<string> cubics = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    vector<string> stack1;
    vector<string> stack2;
    vector<string> stack3;
    vector<string> winning_stack;
    int stack_size;
    int size1;
    int size2;
    int size3;
    int move_counts;
    public:
        TOH(int no_cubics){
            int count = 0;
            for(int i = 0; i < no_cubics; i++){
                stack1.push_back("_");
                stack2.push_back("_");
                stack3.push_back("_");
            }
            for(int i = no_cubics-1; i>=0 ; i--){
                stack1[i] = cubics[i];
            }
            stack_size = no_cubics;
            size1 = stack_size;
            size2 = 0;
            size3 = 0;
            move_counts = 0;
            winning_stack = stack1;
        }
        void print(){
            cout<<"                 ||TOWER OF HANOI||\n";
            cout<<"                 ``````````````````\n\n";
            cout<<"MOVES :- "<<move_counts<<"\n\n";
            for (int i = 0; i < stack_size; i++) {
                if (i < stack1.size()) {
                    cout << stack1[i] << "\t\t";
                } else {
                    cout << "\t\t";
                }
                if (i < stack2.size()) {
                    cout << stack2[i] << "\t\t";
                } else {
                    cout << "\t\t";
                }
                if (i < stack3.size()) {
                    cout << stack3[i] << "\n";
                } else {
                    cout << "\n";
                }
                cout<<"\n";
            }
        }
    string pop(vector<string> &vec,int &size){
        if(size <= 0){
            cout<<"Invalid selection of stack.\n";
            return "";
        }
        int index = stack_size - size;
        string temp = vec[index];
        vec[index] = "_";
        size--;
        return temp;
    }
    void push(vector<string> &vec,int &size,string cube){
        int index = stack_size - size -1; 
        if(size >= stack_size){
            cout<<"Invalid selection of stack.\n";
            return;
        }
        vec[index] = cube;
        size++;
    }
    string cubes_exchange(int stack_no1,int stack_no2){
        if (stack_no1 == 1 && stack_no2 == 2){
            string temp = pop(stack1,size1);
            if(temp != ""){
                game_rule(stack1,size1,stack2,size2,temp);
            }
        }
        else if (stack_no1 == 1 && stack_no2 == 3){
            string temp = pop(stack1,size1);
            if(temp != ""){
                game_rule(stack1,size1,stack3,size3,temp);
            }
        }
        else if (stack_no1 == 2 && stack_no2 == 1){
            string temp = pop(stack2,size2);
            if(temp != ""){
                game_rule(stack2,size2,stack1,size1,temp);
            }
        }
        else if (stack_no1 == 2 && stack_no2 == 3){
            string temp = pop(stack2,size2);
            if(temp != ""){
                game_rule(stack2,size2,stack3,size3,temp);
            }
        }
        else if (stack_no1 == 3 && stack_no2 == 1){
            string temp = pop(stack3,size3);
            if(temp != ""){
                game_rule(stack3,size3,stack1,size1,temp);
            }
        }
        else if (stack_no1 == 3 && stack_no2 == 2){
            string temp = pop(stack3,size3);
            if(temp != ""){
                game_rule(stack3,size3,stack2,size2,temp);
                
            }
        }
        else{
            cout<<"Invalid selection of stack.";
        }
    }
    int findIndex(vector<string>& vec, string value) {
    auto it = find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        return distance(vec.begin(), it);
    }
}
    void game_rule(vector<string> &s1,int &size_1,vector<string> &s2,int &size_2,string temp){
        if (size_2 == 0){
            push(s2,size_2,temp);
            move_counts++;
        }
        else{
            int index = stack_size - size_2;
            string top_of_s2 = s2[index];
            int index_of_top_s2 = findIndex(cubics,top_of_s2);
            int index_of_top_s1 = findIndex(cubics,temp);
            if(index_of_top_s1 < index_of_top_s2){
                push(s2,size_2,temp);
                move_counts++;
            }
            else{
                push(s1,size_1,temp);
                cout<<"\n\n\nInvalid selection of stack.";
            }
        }
    }
    bool areVectorsEqual(vector<string>& vec1,vector<string>& vec2) {
        return vec1 == vec2;
    }
    void player_input(){
        int a,b;
    cout<<"Enter the numbers between 1-3 for POP & PUSH.\n\n";
    while(true){
        cout<<"Enter the POP stack no. :- ";
        cin>>a;
        if (a >= 1 && a <= 3){
            break;
        }
        else{
            cout<<"Enter valid number.\n";
        }
    }
    while(true){
        cout<<"Enter the PUSH stack no. :- ";
        cin>>b;
        if (b >= 1 && b <= 3 && b != a){
            break;
        }
        else{
            cout<<"Enter valid number.\n";
        }
    }
        cubes_exchange(a,b);
    }
    int game_play(){
        while(true){
            system("CLS");
            if(areVectorsEqual(winning_stack, stack3)){
                cout<<"player WINs the game at "<<move_counts<<" moves.";
                return 1;
            }
            print();
            player_input();
        }
    }
};
int main(){
    system("CLS");
    int no_of_disc;
    {
        cout<<"                 ||TOWER OF HANOI||\n";
        cout<<"                 ``````````````````\n\n";
        cout<<"Enter the number of discs:- ";
        cin>>no_of_disc;
    }
    TOH obj(no_of_disc);
    obj.game_play();
    return 0;
}