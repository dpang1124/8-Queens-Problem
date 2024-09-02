/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

//check function
bool check(int q[], int c){
for(int i=0; i<c; i++){
if(q[c]==q[i] || (c-i)==abs(q[c]-q[i]))
return false;
}
return true;
}

//backtrack function
void backtrack(int q[], int &c){
c--;
if(c==-1) return;
}
	
//print fancy queens based off solutions from previous functions
	void print(int q[], int c){
	   static int count=0;
	   cout << "Board " << ++count << ": " << endl;
	   int i, j, k, l;
	   typedef char box[5][7];
	   box wb, bb, wq, bq, *board[8][8];
	   
	   for(i=0; i<5; i++){          //fill in black and white boards with respective colors
	       for(j=0; j<7; j++){
	           wb[i][j] = ' ';
	           bb[i][j] = char(219);
	           wq[i][j] = ' ';
	           bq[i][j] = char(219);
	       }
	   }
	   
 wq[1][1]=char(219); wq[2][1]=char(219);	//create respective design for black and white queens
 wq[3][1]=char(219); wq[3][2]=char(219);	
 wq[1][3]=char(219); wq[2][3]=char(219);	
 wq[3][3]=char(219); wq[3][4]=char(219);
 wq[1][5]=char(219); wq[2][5]=char(219);
 wq[3][5]=char(219); bq[1][1]=' ';
 bq[2][1]=' ';  	 bq[3][1]=' ';
 bq[3][2]=' ';       bq[1][3]=' ';
 bq[2][3]=' ';       bq[3][3]=' ';
 bq[3][4]=' ';       bq[1][5]=' ';
 bq[2][5]=' ';       bq[3][5]=' ';
	   
//create fancy queens board
for(i=0; i<8; i++){
for(j=0; j<8; j++){
		    
if(q[j]==i){    //for queen filling
if((i+j)%2==0)
{board[i][j]=&wq;}
else{ board[i][j]=&bq;}
}

else{           //for white/black board filling
if((i+j)%2==0){
board[i][j]=&wb;}
else{ board[i][j]=&bb; }
}

}
}   
	//start printing board
	//first print upper boarder
	cout<<" ";
	for(i=0; i<7*8; i++) cout<<'_';
	cout<<endl;
	
	//now print the board
	for(i=0; i<8; i++){
		for(int k=0; k<5; k++){
			cout<<" "<<char(179); //print left boarder
	for(j=0; j<8; j++){
		for(l=0; l<7; l++){
			cout<<(*board[i][j])[k][l];
		}
	}
			cout<<char(179)<<endl; //at end of line print bar then newline
		}
	}
	//before exiting print lower boarder
	cout<<" ";
	for(i=0;i<7*8;i++){
		cout<<char(169);
	}
	cout<<endl<<endl;
}
	    

//create solutions first and insert them into print
//the check, backtrack, and int main functions are all the same from my 1-dim q with no gotos, I just modified the print function with the help of the video waxman posted.
int main(){
int q[8], c=1;
q[0]=0;

bool from_backtrack=false;
while(true){
    
while(c<8){
if(!from_backtrack)
q[c]=-1;
from_backtrack=false;
while(q[c]<8){
q[c]++;

while(q[c]==8){					
backtrack(q, c);
q[c]++;
}

if(check(q,c)){
break;
}
			
}	
c++;
}		
print(q, c);
backtrack(q, c);
from_backtrack=true;
}

return 0;
}



