
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


int random[4]  ,int_guess[4] , table_data_array[12][1] , score[12][2] , int_friend_number[4];
static int max_score = 100 ;
string guess , friend_number;





/******** Menu Section *********/

void printLine_menu_frame(int n){
    cout << "  ";
    for(int i = 0 ; i < n ; i++){
        SetConsoleTextAttribute( h , 6);
        cout << "~";
    }
    cout << endl;
}
void menu_frame(){

        int num_OF_line[4] = {16, 23, 18, 24};
        string name_OF_line[4] = {"| 1 | StartNewGame", "| 2 | Table", "| 3 | ScoreBoard", "| 4 | Exit"};
        printLine_menu_frame(50);
        for (int i = 0; i < 4; ++i) {
            SetConsoleTextAttribute(h, 6);
            cout << "||" ;
            cout << "                  " ;
            SetConsoleTextAttribute(h, 14);
            cout << name_OF_line[i] << setw(num_OF_line[i]);

            SetConsoleTextAttribute(h, 6);
            cout << "||" << endl;
            printLine_menu_frame(50);
        }
    }
string menu_possible_error(){
    string menu_data ;
    while (true){
        cin >> menu_data ;
        if (menu_data == "1" || menu_data == "2" || menu_data == "3" || menu_data == "4") {
            return menu_data;
        }else {
            SetConsoleTextAttribute(h, 4);
            cout << "Dear Friend You Have To Choose From 1 TO 4" << endl << "Pleas Try again" << endl;
        }
    }
}
void computer_or_friend(){
    printLine_menu_frame(22);
    cout << "||    " ;
    cout << "Computer | 1 |";
    cout << "    ||\n" ;
    printLine_menu_frame(22);
    cout << "||    " ;
    cout << "  Friend | 2 |";
    cout << "    ||\n";
    printLine_menu_frame(22);
}
bool computer_OR_friend_possible_error(){
    string computer_OR_friend_data ;
    while (true) {
        cin >> computer_OR_friend_data;
        if(computer_OR_friend_data == "1") {
            return true;
        }else if (computer_OR_friend_data == "2"){
            return false;
        }
        else {
            SetConsoleTextAttribute(h, 4);
            cout << "Dear Friend You Have To Choose | 1 | OR | 2 | " << endl << "Pleas Try again" << endl;
        }
    }
}
void menu () ;


/******** Menu_Guide Section ***********/

void Guide_frame () {
    SetConsoleTextAttribute(h , 6);
    cout << "Need A Guide" << endl;
    printLine_menu_frame(14);
    cout << "||  " ;
    cout << "Yes  | 1 |";
    cout << "  ||\n" ;
    printLine_menu_frame(14);
    cout << "||  " ;
    cout << " No  | 2 |";
    cout << "  ||\n";
    printLine_menu_frame(14);

}
bool Guide_possible_error () {
    string Guide_data ;
    while (true){
        cin >> Guide_data ;
        if (Guide_data == "1" ){
            return true;
        }
        else if (Guide_data == "2" ){
            return false;
        }else {
            SetConsoleTextAttribute(h, 4);
            cout << "Dear Friend You Have To Choose | 1 | OR | 2 | " << endl << "Pleas Try again" << endl;
        }
    }
}
void computer_Guide () {
    SetConsoleTextAttribute(h , 6);
    cout << "You Have 12 Chances TO Guess Number Right And If You Don't Game IS Over" << endl
         <<"If You saw 'T' It Means You've Guessed Right" << endl
         << "If You saw 'F' It Means You've Guessed Place Right But Number Is Wrong" << endl
         << "And If You Saw '0' It Means You've Guessed Wrong\n" ;
}
void friend_Guide() {
    SetConsoleTextAttribute(h , 6);
    cout << "First You Have To Choose Four Number From 1 TO 6" << endl << "Then You Have TO Guess Where Are These Numbers"
         << endl << "If You saw 'T' It Means You've Guessed Right" << endl << "If You saw 'F' It Means You've Guessed Place Right But Number Is Wrong"
         << endl << "And If You Saw '0' It Means You've Guessed Wrong\n" ;
}
void Guide_friend () {
    Guide_frame();
    if (Guide_possible_error()){
        friend_Guide();
    }
}
void Guide_computer () {
    Guide_frame();
    if (Guide_possible_error()){
        computer_Guide();
    }
}

/******** StartNewGame Section *********/
void StartNewGame();
void printLine_Guess(){
    cout << "  " ;
    for (int i = 0 ; i < 36; i ++){
        cout << "_" ;
    }
    cout << endl;
}
void main_game_theme(string a[] , int forbid){
    printLine_Guess();
    cout << "|| Guess" << forbid+1 << " ||" ;
    for (int j = 0; j < 4 ; ++j) {
        cout << "  " << a[j] << "  ||";
    }
    cout << endl;
    printLine_Guess();
}
void calculate_score(int a , int b) {
    score[b][0] = max_score - a*3;
    score[b][1] = 0 + a*3;
    max_score -= a*3;
}


void table_data (int a[] , int b){
    int temp = 0 , k = 1000;
    for (int i = 0; i < 4 ; ++i) {
        temp += a[i] * k;
        k /= 10 ;
    }
    table_data_array[b][0] = temp;
}
void convert_str_to_arr(int a[] , string b){
    stringstream ss(b);
    int strAsInt =0;
    ss>>strAsInt;
    for (int j = 3; j >= 0 ; j--) {
        a[j] = strAsInt % 10 ;
        strAsInt /= 10;
    }
}
void random_num(int a[]){
    const int max = 6 ;
    srand(time(0));
    for (int i = 0; i < 4 ; ++i) {
        a[i] = rand() % max + 1;
    }
}
void Game_error () {
    SetConsoleTextAttribute(h , 4);
    cout << "Dear Friend You Have To Choose From 1 To 6\n"
            "Please Try Again\n";
}
bool Game_possible_error(){
    for (char const &c : guess) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
bool Game_possible_error2(){
    return guess.length() == 4 ;
}
bool Game_possible_error3(string b){
    int temp[4];
    convert_str_to_arr(temp , b);
    for (int i = 0; i < 4 ; ++i) {
        if (temp[i] > 6){
            return false;
        }
    }
    return true;
}
bool Game_input (string b) {
    cin >> guess ;
    while (true){
        if (Game_possible_error() &&
            Game_possible_error2() &&
            Game_possible_error3(b)) {
            return true;
        }
        else {
            Game_error();
            cin >> guess;
        }
    }
}

/***** Lost&Won Section ****/
void printLine_you_won(){
    cout << "  ";
    for (int i = 0; i < 14; ++i) {
        cout << "_" ;
    }
    cout << endl;
}
bool you_lost(int a){
    return a == 12 || score[a][0] < 0 ;
}
void you_lost_frame(){
    printLine_you_won();
    cout << "||  YOU LOST !! ||" << endl;
    printLine_you_won();
}
bool you_won(int a){
    return a==4 ;
}
void you_won_frame(){
    printLine_you_won();
    cout << "||  YOU WON !!  ||" << endl;
    printLine_you_won();
}

void main_game_computer () {
    random_num(random);
    int counterT = 0, counterF = 0;
    for (int forbid = 0; forbid < 12 ; ++forbid) {
        string true_false_zero[4];
        if (you_won(counterT)){
            you_won_frame();
            break;
        } else{
            counterT = 0;
        }
        cout << endl;
        if(Game_input(guess)){
            convert_str_to_arr(int_guess , guess);
            table_data(int_guess , forbid);
            for (int i = 0; i < 4; ++i) {
                if (random[i] == int_guess[i]) {
                    true_false_zero[i] = "T";
                    counterT++;
                } else {
                    for (int j = 0; j < 4; ++j) {
                        if (int_guess[i] == random[j]) {
                            true_false_zero[i] = "F";
                            counterF++;
                        }
                        if (counterF != 0)
                            break;
                    }
                    if (counterF == 0) {
                        true_false_zero[i] = "0";
                    } else {
                        calculate_score(counterF , forbid);
                        counterF = 0;
                    }
                }
            }
        }
        main_game_theme(true_false_zero , forbid);
        if(you_lost(forbid)){
            you_lost_frame();
            max_score = 100;
            break;
        }
    }
    cout << endl;
}


/****** Friend Section *****/
void printLine_friend() {
    cout << "            " ;
    SetConsoleTextAttribute(h , 6);
    for (int i = 0; i < 25 ; ++i) {
        cout << "_" ;
    }
    cout << endl;
}
void friend_number_frame (int a[]){
    printLine_friend();
    cout << "          ||" ;
    for (int i = 0; i < 4 ; ++i) {
        cout << "  " << a[i] << "  ||";
    }
    cout << endl;
    printLine_friend();
}
bool Game_possible_error_friend(){
    for (char const &c : friend_number) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
bool Game_possible_error2_friend(){
    return friend_number.length() == 4 ;
}
bool Friend_Number_Input (){
    cin >> friend_number ;
    while (true){
        if (Game_possible_error_friend() &&
            Game_possible_error2_friend() &&
            Game_possible_error3(friend_number)) {
            return true;
        }
        else {
            Game_error();
            cin >> friend_number;
        }
    }
}
void friend_number_ask(){
    SetConsoleTextAttribute(h , 6);
    cout << "Please Ask Your Friend To Enter A 4_digit Number From 1 To 6 :\n";
}
void main_game_friend (){
    friend_number_ask();
    if (Friend_Number_Input()){
        convert_str_to_arr(int_friend_number , friend_number);
        friend_number_frame(int_friend_number);
    }
    int counterT = 0, counterF = 0;
    for (int forbid = 0; forbid < 12 ; ++forbid) {
        string true_false_zero[4];
        if (you_won(counterT)){
            you_won_frame();
            break;
        } else{
            counterT = 0;
        }
        cout << endl;
        if(Game_input(guess)){
            convert_str_to_arr(int_guess , guess);
            table_data(int_guess , forbid);
            for (int i = 0; i < 4; ++i) {
                if (int_friend_number[i] == int_guess[i]) {
                    true_false_zero[i] = "T";
                    counterT++;
                } else {
                    for (int j = 0; j < 4; ++j) {
                        if (int_guess[i] == int_friend_number[j]) {
                            true_false_zero[i] = "F";
                            counterF++;
                        }
                        if (counterF != 0)
                            break;
                    }
                    if (counterF == 0) {
                        true_false_zero[i] = "0";
                    } else {
                        calculate_score(counterF , forbid);
                        counterF = 0;
                    }
                }
            }
        }
        main_game_theme(true_false_zero , forbid);
        if (you_lost(forbid)){
            you_lost_frame();
            max_score = 100;
            break;
        }
    }
    cout << endl;
}

/****** Back Section ******/

void Back_exit_NewGame_frame (){
    for (int i = 0; i < 3 ; ++i) {
        cout << endl;
    }
    SetConsoleTextAttribute(h , 6);
    cout << "Back | 3 |" << "   " << "NewGame | 4 |" << "   " << "Exit | 5 |" << endl;
}
string Back_exit_NewGame_possible_error(){
    string Back_exit_NewGame_data ;
    while (true){
        cin >> Back_exit_NewGame_data ;
        if (Back_exit_NewGame_data == "3" || Back_exit_NewGame_data == "4" || Back_exit_NewGame_data == "5"  ){
            return Back_exit_NewGame_data;
        }else {
            SetConsoleTextAttribute(h, 4);
            cout << "Dear Friend you are wrong " << endl << "Pleas Try again" << endl;
        }
    }
}

/******* Table Section ******/

void Table() ;
void printLine_table(){
    cout << endl << "  ";
    for (int k = 0; k < 64; ++k) {
        SetConsoleTextAttribute(h, 14);
        cout << "~";
    }
    cout << endl;
}
void table_chart (int z){
        string array2[3] = {"|  First_Guess   | Second_Guess  |  Third_Guess   | Fourth_Guess  |",
                            "|  Fifth_Guess   | Sixth_Guess   | Seventh_Guess  | Eighth_Guess  |",
                            "|  Ninth_Guess   | Tenth_Guess   | Eleventh_Guess | Twelfth_Guess |"};
        SetConsoleTextAttribute(h , 6);
        cout << array2[z];
}

/********* ScoreBoard Section ****/
void ScoreBoard();
void printLine_scoreBoard(){
    cout << "  " ;
    for (int i = 0 ; i < 58 ; i ++){
        cout << "~" ;
    }
    cout << endl;
}
void chart_scoreBoard (){
    cout << "||    Guess     ||     Your Point     ||      Your Loss     ||" << endl;
}
void double_line(){
    cout << "||";
}
bool ScoreBoard_possible_error(string a){
    return a == "1" || a == "2" ;
}
bool ScoreBoard_Input(){
    string ScoreBoard_data ;
    cin >> ScoreBoard_data;
    while (true){
        if (ScoreBoard_possible_error(ScoreBoard_data)){
            return ScoreBoard_data == "1";
        }else {
            cin >> ScoreBoard_data ;
        }
    }
}
void ScoreBoard_Guide() {
    cout << "You Have 100 Points\n"
            "For Every False | F | Guess You Have , You'll Lose 3 Points\n"
            "In ScoreBoard Section You Can See Your Points In Every Level\n";
}
void ScoreBoard_Table_Guess(int i){
    double_line();
    cout << "      " << i+1 << "       ";
    double_line();
}
void ScoreBoar_Table_YourPoint(int i ) {
    for (int j = 0; j < 2; ++j) {

        cout << "        " << score[i][j] << "           ";
        double_line();
    }
    cout << endl;
}


int Exit (){
    return 0 ;
}
void ScoreBoard(){
    printLine_scoreBoard();
    chart_scoreBoard();
    printLine_scoreBoard();
    for (int i = 0; i < 12 ; ++i) {
        if (score[i][1] != 0) {
            ScoreBoard_Table_Guess(i);
            ScoreBoar_Table_YourPoint(i);
            printLine_scoreBoard();
        }else {
            break;
        }
        }
        Back_exit_NewGame_frame();
    if (Back_exit_NewGame_possible_error() == "3"){
        menu();
    }else if (Back_exit_NewGame_possible_error() == "4"){
        StartNewGame();
    }else {
        Exit();
    }
    }
void StartNewGame() {
    computer_or_friend();
    if (computer_OR_friend_possible_error()){
        Guide_computer();
        main_game_computer();
        Back_exit_NewGame_frame();
        if (Back_exit_NewGame_possible_error() == "4") {
            StartNewGame();
        }else if( Back_exit_NewGame_possible_error() == "3" ){
            menu();
        }else {
            Exit();
        }
    }else {
        Guide_friend();
        main_game_friend();
        Back_exit_NewGame_frame();
        if (Back_exit_NewGame_possible_error() == "4"){
            StartNewGame();
        }else if (Back_exit_NewGame_possible_error() == "3"){
            menu();
        }else {
            Exit();
        }
    }
}
void Table () {
    for (int i = 0; i < 12; ++i) {
        if (i % 4 == 0){
            printLine_table();
            table_chart(i / 4);
            printLine_table();
            cout << "| " ;
        }
        if (i % 4 == 2 ){
            cout << " ";
        }
        if (table_data_array[i][0] != 0) {
            SetConsoleTextAttribute(h, 6);
            cout << "    " << table_data_array[i][0];
            SetConsoleTextAttribute(h, 14);
            cout << "       |";
        } else {
            SetConsoleTextAttribute(h, 6);
            cout << "   NO GUESS   ";
            SetConsoleTextAttribute(h, 14);
            cout << " |";
        }
    }
    Back_exit_NewGame_frame();
    if (Back_exit_NewGame_possible_error() == "3"){
        menu();
    }else if(Back_exit_NewGame_possible_error() == "4"){
        StartNewGame();
    }else {
        Exit();
    }
}
void menu() {
    menu_frame();
    if (menu_possible_error() == "1") {
        StartNewGame();
    }else if (menu_possible_error() == "2"){
        Table();
    }else if (menu_possible_error() == "3"){
        Guide_frame();
        if(ScoreBoard_Input()){
            ScoreBoard_Guide();
        }
        ScoreBoard();
    }else {
        Exit();
    }
}



int main () {
    menu();
}