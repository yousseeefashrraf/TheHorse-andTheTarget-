


//note: i'm using additional arrays as a way to store varriables.

#include <iostream>
using namespace std;
void board(char brd[][51]){
    
  
    int r,c;
  
    for(r=0;r<26;r++){
        
        for(c=0;c<51;c++){
            brd[r][c]=' ';
        }
        
        
    }
    
    
    for(r=1;r<25;r++){
        
        for(c=8;c<51;c+=6){
            brd[r][c]='|';
            }
        
        brd[r][2]='|';
    }

    
    for(r=3;r<26;r+=3){
        
        for(c=2;c<51;c++){
            brd[r][c]='-';
        }
        
    }
    
    for(r=3;r<26;r+=3){
        
        for(c=8;c<51-6;c+=6){
            brd[r][c]='+';
        }
        
    }

    for(c=2;c<51;c++){
        brd[0][c]=brd[24][c]='-';
        brd[25][c]=' ';
      
    }
    int i=97;
    for(c=5;c<51-3;c+=6){
        brd[25][c]=i;
        i++;
    }
    
    i=49;
    for(r=2;r<26;r+=3){
        
        brd[r][0]=i;
        brd[r][1]=' ';
        i++;
        }
    
    
    
}


void check(char brd[][51], int& posc, int &posr, int addc, int addr, int sr, int sc, int& f){
    
    if(sr==posr+(addr*3) && sc==posc+(addc*6) &&f==0){
        brd[sr][sc]='$';
        brd[posr][posc]=' ';
        posr=sr;
        posc=sc;
        f=1;
    }
    
    
    
    
}

void Cout(char x[][51]){
    int r, c;
    for(r=0;r<26;r++){
        for(c=0;c<51;c++){
            cout<<x[r][c];
        }
        cout<<endl;
    }
    cout<<"\n\n";
}
int main() {
    int f=0;
    char brd[26][51];
    char position[3];
    char xtarget[3];
    char xmovement[3];
   
 
        
        board(brd);
       
        
        cout<<"Enter Target(*) cell to start [e.g 2a,4b,8g] : ";
        cin.getline(xtarget,3);
        cout<<"Enter horse($) position to start [e.g 2a,4b,8g] : ";
        cin.getline(position, 3);
        
        
        int posr=position[0]-49;
        int posc=position[1]-97;
        
      
        
        int posrt=xtarget[0]-49;
        int posct=xtarget[1]-97;
       
        
       
        
        brd[posr*3+2][posc*6+5]='$';  //put horse
        brd[posrt*3+2][posct*6+5]='*';//put target
        int ct=0;
        Cout(brd);
        
        //game
        
        int sr,sc;
       
        posr=posr*3+2;
        posc=posc*6+5;
        
        while(posrt*3+2!=posr || posct*6+5!=posc){
            ct++;
            f=0;
            
            cout<<"Enter position to move the horse($) [e.g 2a,4b,8g] : ";
            cin.getline(xmovement, 3);
            sr=(xmovement[0]-49)*3+2;
            sc=(xmovement[1]-97)*6+5;
            check(brd,posc, posr,2,1,sr,sc,f);
            check(brd,posc, posr,2,-1,sr,sc,f);
            check(brd,posc, posr,-2,1,sr,sc,f);
            check(brd,posc, posr,-2,-1,sr,sc,f);
            check(brd,posc, posr,1,2,sr,sc,f);
            check(brd,posc, posr,-1,2,sr,sc,f);
            check(brd,posc, posr,1,-2,sr,sc,f);
            check(brd,posc, posr,-1,-2,sr,sc,f);
            
            while(!f){
                cout<<"Wrong move, Enter position to move the horse($) [e.g 2a,4b,8g] : ";
                cin.getline(xmovement, 3);
                sr=(xmovement[0]-49)*3+2;
                sc=(xmovement[1]-97)*6+5;
                check(brd,posc, posr,2,1,sr,sc,f);
                check(brd,posc, posr,2,-1,sr,sc,f);
                check(brd,posc, posr,-2,1,sr,sc,f);
                check(brd,posc, posr,-2,-1,sr,sc,f);
                check(brd,posc, posr,1,2,sr,sc,f);
                check(brd,posc, posr,-1,2,sr,sc,f);
                check(brd,posc, posr,1,-2,sr,sc,f);
                check(brd,posc, posr,-1,-2,sr,sc,f);
                
            }
           
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n"<<"  Movements: "<<ct<<"                            Gameover."<<"\n\n";
            Cout(brd);
        }
        
    cout<<"\n\n";
    

}
