#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXN 20
#define MAXPATH 50

int N;
string cities[MAXN];
int graph[MAXN][MAXN];

// Utility Functions
int getCityIndex(string name){
    for(int i = 0; i < N; i++){
        if(cities[i] == name){
            return i;
        }
    }
    return -1;
}

string toUpper(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

bool edgeExists(string a, string b){
    int u = getCityIndex(a);
    int v = getCityIndex(b);
    if(u == -1 || v == -1){
        return false;
    }
    return graph[u][v] == 1;
}

int parseSequence(string input, string seq[]){ 
    string word = "";
    int n = 0;  

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '-' && i + 1 < input.length() && input[i + 1] == '>'){
            seq[n] = toUpper(word);
            n++;
            word = "";
            i++;
        }
        else{
            word += input[i];
        }
    }

    seq[n] = toUpper(word);
    n++;

    return n; 
}

// Student Functions
bool isWalk(string seq[], int len){ 
    for(int i = 0; i < len - 1; i++){
        if(!edgeExists(seq[i], seq[i + 1])){
            return false;
        }
    }
    return true; 
}

bool isTrail(string seq[], int len){
    if(!isWalk(seq, len)){
        return false;
    }

    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len - 1; j++){
            if(seq[i] == seq[j] && seq[i + 1] == seq[j + 1]){
                return false;
            }
        }
    }
    return true; 
}

bool isPath(string seq[], int len){
    if(!isWalk(seq, len)){
        return false;
    }
    
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(seq[i] == seq[j]){
                return false;
            }
        }
    }
    return true;
}

bool isClosedWalk(string seq[], int len){ 
    if(!isWalk(seq, len)){
        return false;
    }
    
    if(seq[0] == seq[len - 1]){
        return true;
    }
    return false;
}

bool isCircuit(string seq[], int len){
    if(!isClosedWalk(seq, len)){
        return false;
    }

    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len - 1; j++){
            if(seq[i] == seq[j] && seq[i + 1] == seq[j + 1]){
                return false;
            }
        }
    }
    return true;
}

bool isSimpleCircuit(string seq[], int len){ 
    if(!isClosedWalk(seq, len)){
        return false;
    }

    for(int i = 1; i < len - 1; i++){
        for(int j = i + 1; j < len - 1; j++){
            if(seq[i] == seq[j]){
                return false;
            }
        }
    }
    return true;
}

// BONUS
void printMapEnhanced(){
    cout << "\n";
    cout << "========================================\n";
    cout << "           CITY CONNECTION MAP          \n";
    cout << "========================================\n\n";
    
    cout << "ADJACENCY MATRIX:\n";
    cout << setw(15) << " ";
    for(int i = 0; i < N; i++){
        cout << setw(4) << i;
    }
    cout << "\n";
    cout << setw(15) << " ";
    for(int i = 0; i < N; i++){
        cout << "----";
    }
    cout << "\n";
    
    for(int i = 0; i < N; i++){
        cout << setw(2) << i << ". " << setw(11) << left << cities[i].substr(0, 10) << right << "|";
        for(int j = 0; j < N; j++){
            cout << setw(4) << graph[i][j];
        }
        cout << "\n";
    }
    
    cout << "\n----------------------------------------\n\n";
    cout << "GRAPH CONNECTIONS:\n\n";
    
    for(int i = 0; i < N; i++){
        cout << "[" << i << "] " << cities[i] << "\n";
        cout << "     |";
        
        bool hasConnection = false;
        for(int j = 0; j < N; j++){
            if(graph[i][j] == 1){
                hasConnection = true;
                break;
            }
        }
        
        if(!hasConnection){
            cout << "\n     +---> (No connections)\n";
        }
        else{
            bool first = true;
            for(int j = 0; j < N; j++){
                if(graph[i][j] == 1){
                    if(!first){
                        cout << "     |";
                    }
                    cout << "\n     +---> [" << j << "] " << cities[j];
                    first = false;
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    cout << "========================================\n";
    
    // Stats
    int totalEdges = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == 1){
                totalEdges++;
            }
        }
    }
    
    cout << "\nGRAPH STATISTICS:\n";
    cout << "  Total Cities (Vertices): " << N << "\n";
    cout << "  Total Connections (Edges): " << totalEdges << "\n";
    cout << "========================================\n";
}

void printMap(){ 
    cout << "\n--- Map ---\n";
    for(int i = 0; i < N; i++){
        cout << cities[i] << " connected to: ";
        bool first = true;
        for(int j = 0; j < N; j++){
            if(graph[i][j]){
                if(!first){
                    cout << ", ";
                }
                cout << cities[j];
                first = false;
            }
        }
        if(first){
            cout << "None";
        }
        cout << "\n";
    }
}

//Grading
int marks[6] = {0, 0, 0, 0, 0, 0};
string moduleNames[6] = {"Path", "Walk", "Trail", "Closed Walk", "Circuit", "Simple Circuit"};

void grade(string seq[], int len, bool expected[6]){
    bool results[6] = {
        isPath(seq, len),
        isWalk(seq, len),
        isTrail(seq, len),
        isClosedWalk(seq, len),
        isCircuit(seq, len),
        isSimpleCircuit(seq, len)
    };

    for(int i = 0; i < 6; i++){
        if(results[i] == expected[i]){
            marks[i] = 5;
        }
        else{
            marks[i] = 0;
        }
    }
}

// ----- Main -----
int main(){
    ifstream fin("map.txt");
    if(!fin){
        cout << "Error: map.txt not found!\n";
        return 1;
    }

    fin >> N;
    fin.ignore();
    for(int i = 0; i < N; i++){
        getline(fin, cities[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }
    fin.close();

    printMapEnhanced();

    string testSeqStr = "ISLAMABAD->RAWALPINDI->SIALKOT->GUJRANWALA->LAHORE->ISLAMABAD";
    string seq[MAXPATH];
    int len = parseSequence(testSeqStr, seq);

    bool expected[6] = {false, true, true, true, true, true};

    cout << "\nTesting predefined sequence: " << testSeqStr << endl;
    cout << "Length of sequence: " << len << endl;

    grade(seq, len, expected);

    cout << "\n--- Module Marks ---\n";
    int total = 0;
    for(int i = 0; i < 6; i++){
        cout << i + 1 << ". " << moduleNames[i] << ": " << marks[i] << "/5\n";
        total += marks[i];
    }
    cout << "Total Score: " << total << "/30\n";

    while(true){
        cout << "\nEnter your own sequence (format A->B->C->...):\n";
        string input;
        getline(cin, input);
        if(input == "QUIT" || input == "quit"){
            break;
        }
        
        len = parseSequence(input, seq);

        cout << "\nLength (edges): " << len - 1 << "\n";
        cout << "Sequence classification (Yes/No):\n";
        
        if(isPath(seq, len)){
            cout << "Path: Yes\n";
        }
        else{
            cout << "Path: No\n";
        }
        
        if(isWalk(seq, len)){
            cout << "Walk: Yes\n";
        }
        else{
            cout << "Walk: No\n";
        }
        
        if(isTrail(seq, len)){
            cout << "Trail: Yes\n";
        }
        else{
            cout << "Trail: No\n";
        }
        
        if(isClosedWalk(seq, len)){
            cout << "Closed Walk: Yes\n";
        }
        else{
            cout << "Closed Walk: No\n";
        }
        
        if(isCircuit(seq, len)){
            cout << "Circuit: Yes\n";
        }
        else{
            cout << "Circuit: No\n";
        }
        
        if(isSimpleCircuit(seq, len)){
            cout << "Simple Circuit: Yes\n";
        }
        else{
            cout << "Simple Circuit: No\n";
        }
    }
    return 0;
}
