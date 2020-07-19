#include <iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class PQueue;
class Queue;
//class Stack;
class Team;
class Player;
class Game;

class Bid{

public:

    int bids;
    int player_no;
    Bid *next;

    Bid(){
    next = NULL;
    }
    friend class PQueue;
    friend class Player;
};

class PQueue{

public :
        Bid *front;
        Bid *rear;


        PQueue(){
		front = NULL;
		rear = NULL;
        }

        void insert(int x, int y){
        	Bid *new1 = new Bid;
            new1->bids = x;
            new1->player_no = y;

        	if(front == NULL){
        		front = new1;
        		rear = new1;
        	}

        	else if(new1->bids >=front->bids){
        		new1->next = front;
        		front = new1;
        	}

        	else if(new1->bids < rear->bids){
        		rear->next = new1;
        		rear = new1;
        	}

        	else{
			Bid *curr = front;
			Bid *prev = NULL;

			while(curr->bids > new1->bids){
				prev = curr;
				curr = curr->next;
			}
			prev->next = new1;
			new1->next = curr;
        	}


        }

        void display(){
        	Bid *new1 = front;
        	Bid *new2 = front;

        	 cout<<"\nPQueue is : ";
             cout<<endl;

        	 while(new2 != NULL){
        	 	cout<< new2->bids <<"\t"<<new2->player_no<<"\n";
        	 	new2 = new2->next;
        	 }
        	 cout<<endl;
        }

        void delete_Bid(){

        	if(front == NULL){

        		cout<<"\nQueue is Empty\n";
        		/*Bid *curr = front;
        		delete curr;
        		front = NULL;
        		cout<<"\nUnderflow\n";*/
        	}

        	else{
                Bid *curr = front;
                front = front->next;
                curr->next = NULL;
                delete curr;
                curr = NULL;
        	}
        }

};



class Player{
    public:
        string name;
        PQueue player_bid;
        int rating;
        //int base_price;

        Player *next;

        Player(){
            next = NULL;

        }

friend class PQueue;
friend class Queue;
friend class Stack;
friend class Team;

};



class Queue{

        Player *front;
        Player *rear;

        public :
        Queue(){
		front = NULL;
		rear = NULL;
        }

        void insert(Player *x){
        	Player *new1 = new Player;
            new1 = x;

        	if(front == NULL){
        		front = new1;
        		rear = new1;
        	}

        	else if(front->next == NULL){
        		front->next = new1;
        		rear = new1;
        		rear->next = NULL;
        	}

        	else{
        		rear->next = new1;
        		rear = new1;
        		rear->next = NULL;
        	}
        }

        void display(){
        	Player *new1 = front;
        	 cout<<"\nQueue is : \n";
        	 while(new1 != NULL){
                cout<<endl;
                cout<< new1->name<< " ";
        	 	cout<< new1->rating <<"\t";
        	 	new1->player_bid.display();
        	 	cout<<endl;

        	 	new1 = new1->next;
        	 }
        	 cout<<endl;
        }

        void delete_Player(){

        	if(front == NULL){

        		cout<<"\nQueue is Empty\n";
        		/*Player *curr = front;
        		delete curr;
        		front = NULL;
        		cout<<"\nUnderflow\n";*/
        	}
            else{
                Player *curr = front;
                front = front->next;
                curr->next = NULL;
                delete curr;
                curr = NULL;
        	}
        }

        Player* returnFront(){
            Player *curr = front;
            return curr;
        }
         friend class Game;

};
/*
class Stack{

	Player *top;

	public:
	Stack(){
		top = NULL;
 	}

 	void push(Player *x){

 		Player *new1 = new Player;
 		new1 = x;

 		if(top == NULL){
 			top = new1;
 		}

 		else{
 			new1->next = top;
 			top = new1;
 		}
 	}

	int pop(){

		int a = top->rating;

 		Player *curr;
 		curr = top;
 		top = top->next;
 		curr->next = NULL;
 		delete curr;
 		curr = NULL;

 		return a;

 	}

};*/


class Team{
public:
    Queue myTeam;
    int teamCount;


    Team(){
        teamCount = 0;
    }
    void BuildTeam(Player *x){
        Player *curr = x;
        myTeam.insert(curr);
        teamCount++;
    }

    friend class Game;
};

class Game{
    Team A;
    Team B;

public:
    void auction(Queue myP){
    int i ;
    int bid;
    myP.display();
    Player *CurrPlayer;
    int Amoney = 500;
    int Bmoney = 500;


INPUT1 : cout<<"Player A place your Bids : \n";
    Amoney = 500;
    CurrPlayer = myP.returnFront();
    cout<<"\nYou have $500 to spend : \n";
        for(i = 0 ; i<14 ; i++){

        cout<<endl;
        cout<<"Bid for Player : "<<CurrPlayer->name<<"\t"<<CurrPlayer->rating<<endl;
        cin>>bid;
        while(bid<0){
            cout<<"Enter bid again : ";
            cin>>bid;
        }
        CurrPlayer->player_bid.insert(bid,1);
        CurrPlayer = CurrPlayer->next;
        Amoney = Amoney - bid;
        if(Amoney<0){
            cout<<"You have exceeded the Budget, try again\n " ;
            goto INPUT1;
        }
        cout<<"Remaining Money : "<<Amoney<<endl;

    }
        for(i=0 ; i<10 ; i++){
            cout<<endl;
        }
INPUT2 : cout<<"\n\nPlayer B place your Bids : \n";
    Bmoney = 500;
    CurrPlayer = myP.returnFront();
    cout<<"\nYou have $500 to spend : \n";
    for(i = 0 ; i<14 ; i++){
        cout<<endl;
        cout<<"Bid for Player : "<<CurrPlayer->name<<endl;
        cin>>bid;
        CurrPlayer->player_bid.insert(bid,2);
        CurrPlayer = CurrPlayer->next;
        Bmoney = Bmoney - bid;
        if(Bmoney<0){
            cout<<"You have exceeded the Budget, try again \n" ;
            goto INPUT1;
        }
        cout<<"Remaining Money : "<<Bmoney<<endl;

    }

    myP.display();

    cout<<"==========================================\n                 MATCH BEGINS\n==========================================\n";

    Player *newPlayer;
    newPlayer = myP.returnFront();
    int score1 = 0;
    int score2 = 0;
    for(i=0 ; i<14 ; i++){
        char x;
        cout<<"Enter any key to continue : ";
        cin>>x;
        cout<<endl;
        /*
       // cout<<newPlayer->player_bid.front->player_no;
        if(newPlayer->player_bid.front->player_no == 1){
            A.BuildTeam(newPlayer);

        }
        else{
            B.BuildTeam(newPlayer);
        }


        newPlayer = newPlayer->next;
    }*/


        if(newPlayer->player_bid.front->player_no == 1){
           cout<<endl<<newPlayer->name<<" has taken a shot!\n";
           float gksave = (((float)(rand()%(50))+(float)50)/(float)100)*(float)85;//((((rand()%35) + 65)/100)*85);
           int rate = newPlayer->rating;
           float playerscore = (((float)(rand()%(50))+(float)50)/(float)100)*(float)rate;//((((rand()%35) + 65)/100)*rate);

           if(playerscore > gksave){
                cout<<"\n Player 1 Scores\n";
                score1++;
           }
           else{
                cout<<"\nSave\n";
           }
           cout<<"Player 1 : GK-"<<gksave<<" ST-"<<playerscore<<endl;
        }

        else{
           cout<<endl<<newPlayer->name<<" has taken a shot!\n";
           float gksave = (((float)(rand()%(50))+(float)50)/(float)100)*(float)85; //((((ra nd()%35) + 65)/100)*85);
           int rate = newPlayer->rating;
           float playerscore = (((float)(rand()%(50))+(float)50)/(float)100)*(float)rate; //((((rand()%35) + 65)/100)*rate);

           if(playerscore > gksave){
                cout<<"\n Player 2 Scores\n";
                score2++;
           }
           else{
                cout<<"\nSave\n";
           }
            cout<<"Player 2 : GK-"<<gksave<<" ST-"<<playerscore<<endl;
        }
        newPlayer = newPlayer->next;


    }
        cout<<endl<<endl;
        cout<<"Final Score : \nPlayer 1 - Player 2\n"<<score1<<" - "<<score2<<endl;


    }
};

int main()
{
Queue BidList;

Player *Ronaldo;
Ronaldo = new Player;
Ronaldo->rating = 95;
Ronaldo->name = "Ronaldo";
BidList.insert(Ronaldo);

Player *Messi;
Messi = new Player;
Messi->rating = 95;
Messi->name = "Messi";
BidList.insert(Messi);

Player *Neymar;
Neymar = new Player;
Neymar->rating = 93;
Neymar->name = "Neymar";
BidList.insert(Neymar);

Player *Chettri;
Chettri = new Player;
Chettri->rating = 75;
Chettri->name = "Chettri";
BidList.insert(Chettri);

Player *Mbappe;
Mbappe = new Player;
Mbappe->rating = 88;
Mbappe->name = "Mbappe";
BidList.insert(Mbappe);

Player *Hazard;
Hazard = new Player;
Hazard->rating = 90;
Hazard->name = "Hazard";
BidList.insert(Hazard);

Player *Ibrahimovic;
Ibrahimovic = new Player;
Ibrahimovic->rating = 82;
Ibrahimovic->name = "Ibrahimovic";
BidList.insert(Ibrahimovic);

Player *Kane;
Kane = new Player;
Kane->rating = 85;
Kane->name = "Kane";
BidList.insert(Kane);

Player *Pogba;
Pogba = new Player;
Pogba->rating = 76;
Pogba->name = "Pogba";
BidList.insert(Pogba);

Player *DeBruyne;
DeBruyne = new Player;
DeBruyne->rating = 91;
DeBruyne->name = "DeBruyne";
BidList.insert(DeBruyne);

Player *Salah;
Salah = new Player;
Salah->rating = 87;
Salah->name = "Salah";
BidList.insert(Salah);

Player *Aubameyang;
Aubameyang = new Player;
Aubameyang->rating = 84;
Aubameyang->name = "Aubameyang";
BidList.insert(Aubameyang);

Player *Griezmann;
Griezmann = new Player;
Griezmann->rating = 86;
Griezmann->name = "Griezmann";
BidList.insert(Griezmann);

Player *Torres;
Torres = new Player;
Torres->rating = 82;
Torres->name = "Torres";
BidList.insert(Torres);

Game Football;

Football.auction(BidList);


return 0;
}
