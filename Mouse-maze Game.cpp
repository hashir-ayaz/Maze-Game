//hashir ayaz 22i2407 SEF
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
int mouserow=13;
int mousecol=13;
int cheeserow=1;
int cheesecol=1;

void printmaze(string maze[15][15]);
void runmouse(string maze[15][15]);
void stuck(string maze[15][15]);

void stuck(string maze[15][15]){
    if(maze[mouserow][mousecol-1]=="*" ){       //check left
        maze[mouserow][mousecol-1]="M";
        maze[mouserow][mousecol]="^";
        mousecol--;}
else if(maze[mouserow-1][mousecol]=="*"){  //check up
        maze[mouserow-1][mousecol]="M";
        maze[mouserow][mousecol]="^";
        mouserow--;}
else if(maze[mouserow+1][mousecol]=="*"){   //check down
        maze[mouserow+1][mousecol]="M";
        maze[mouserow][mousecol]="^";
        mouserow++;}
else if(maze[mouserow][mousecol+1]=="*"){   //check right
        maze[mouserow][mousecol+1]="M";
        maze[mouserow][mousecol]="^";
        mousecol++;
    }
}

void runmouse(string maze[15][15]){
    if(maze[mouserow][mousecol-1]=="O" || maze[mouserow][mousecol-1]=="$" ){       //check left
        maze[mouserow][mousecol-1]="M";
        maze[mouserow][mousecol]="*";
        mousecol--;

        if(mouserow==1 && mousecol==1){
            cout<<"mouse found the cheese";
            exit(0);}
    }
    else if(maze[mouserow-1][mousecol]=="O" || maze[mouserow-1][mousecol]=="$"){  //check up
        maze[mouserow-1][mousecol]="M";
        maze[mouserow][mousecol]="*";
        mouserow--;

        if(mouserow==1 && mousecol==1){
            cout<<"mouse found the cheese";
            exit(0);}
    }
    else if(maze[mouserow+1][mousecol]=="O" || maze[mouserow+1][mousecol]=="$" ){   //check down
        maze[mouserow+1][mousecol]="M";
        maze[mouserow][mousecol]="*";
        mouserow++;

        if(mouserow==1 && mousecol==1){
            cout<<"mouse found the cheese";
            exit(0);}
    }
    else if(maze[mouserow][mousecol+1]=="O" || maze[mouserow][mousecol+1]=="$" ){   //check right
        maze[mouserow][mousecol+1]="M";
        maze[mouserow][mousecol]="*";
        mousecol++;

        if(mouserow==cheeserow && mousecol==cheesecol){
            cout<<"mouse found the cheese";
            exit(0);}
    }
    else{stuck(maze);}
    
}


void printmaze(string maze[15][15]){
 for(int row = 0; row<15; row++){
    for(int col = 0; col < 15; col++){
        cout << maze[row][col]<<" ";
    }
    cout << endl;
} 

}


int main(){

string maze[15][15]={
    {"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"},   //m is mouse  / x is wall / $ is cheese // * means mouse visited alrdy //+ is boundary // ^ visitied twice
    {"+","$","O","X","O","O","X","O","O","O","O","O","X","O","+"},
    {"+","X","O","O","X","X","X","X","X","O","X","O","X","O","+"},
    {"+","O","X","O","X","X","X","O","X","O","X","O","O","O","+"},
    {"+","X","X","O","X","X","O","X","X","O","X","O","X","O","+"},
    {"+","O","O","O","O","O","O","X","X","X","X","O","O","O","+"},
    {"+","O","X","O","X","O","O","X","O","O","X","X","X","O","+"},
    {"+","O","X","X","X","X","X","X","X","O","O","O","X","O","+"},
    {"+","O","O","O","O","O","O","O","O","O","O","O","X","O","+"},
    {"+","O","X","O","X","X","O","X","X","X","X","X","X","O","+"},
    {"+","O","X","O","O","O","O","X","O","O","O","X","O","O","+"},
    {"+","O","X","X","X","O","X","X","O","X","X","X","X","O","+"},
    {"+","O","X","O","O","O","O","O","O","X","O","O","O","O","+"},
    {"+","X","X","X","X","X","X","X","O","O","O","O","X","M","+"},
    {"+","+","+","+","+","+","+","+","+","+","+","+","+","+","+"}
};



int count=0;
while(count<1000 || (mouserow!=1 && mousecol!=1)){
    printmaze(maze);
    runmouse(maze);
    sleep(1);
    system("clear");
    count++;
}
cout<<"the mouse found the cheese! ";
    return 0;
}