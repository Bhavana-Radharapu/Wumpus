/*
 * Name: Bhavana Laxmi R
 * Class: CS 141
 * Professor: Mark Hallenbeck
 * program 5
   Hunt the Wumpus
 */
#include<iostream>
#include<cstdlib>
#include<iomanip>


using namespace std;

//------------------------------------------------------------------------------------------------------
//Variables for the program
int board[20][3] ={{2,5,8},{1,3,10},{2,4,12},{3,5,14},{1,4,6},{5,7,15},{6,8,17},{1,7,9},{8,10,18},{2,9,11},{10,12,19},
                   {3,11,13},{12,14,20},{4,13,15},{6,14,16},{15,17,20},{7,16,18},{9,17,19},{11,18,20},{13,16,19}} ;

char c;
int player;
int wumpus;
int bats_1;
int bats_2;
int pit_1;
int pit_2;
int arrow;

//------------------------------------------------------------------------------------------------------
//To check for hazards like pits, bats or wumpus.
void hazards(){
   for(int i=0;i<3;i++)
    {
        if(board[player-1][i]== wumpus)
        {
        cout<<"You smell a stench ";
        }
        else if (board[player-1][i]==bats_1||board[player-1][i]==bats_2)
        {
            cout<<"You hear rustling of bat wings. ";
        }
       else if (board[player-1][i]==pit_1||board[player-1][i]==pit_2)
        {
            cout<<"You feel a draft.";
        }     
    } 
}

//------------------------------------------------------------------------------------------------------
// It display the instructions and the maze 
void maze(){
cout<<endl;
cout<<"        _______18________          "<<endl
    <<"       /        |        \\        "<<endl
    <<"      /      ___9__       \\       "<<endl
    <<"     /      /      \\       \\     "<<endl
    <<"    /      /        \\       \\    "<<endl
    <<"   17      8        10      19     "<<endl
    <<"   |\\     /\\        /\\      /|  "<<endl
    <<"   | \\   /  \\      /  \\    / |  "<<endl
    <<"   |   7     1----2     11   |     "<<endl
    <<"   |   |    /      \\     |   |    "<<endl
    <<"   |   6---5        3---12   |     "<<endl
    <<"   |   |    \\      /     |   |    "<<endl
    <<"   |   \\     \\    /      |   |    "<<endl
    <<"   |    \\      4        /    |    "<<endl
    <<"   |     \\     |       /     |    "<<endl
    <<"    \\    15----14-----13    /     "<<endl
    <<"     \\   /             \\   /     "<<endl
    <<"      \\ /               \\ /      "<<endl
    <<"       16----------------20        "<<endl;
    
    cout<<"Hunt the Wumpus:\n"
        <<"The Wumpus lives in a completely dark cave of 20 rooms.Each\n"
        <<"room has 3 tunnels leading to other rooms.\n\n";
    cout<<"Hazards:"
        <<"1. Two rooms have bottomless pits in them. If you go there you fall and die.\n"
        <<"2. Two other rooms have super-bats. If you go there, the bats grab you and fly"
        <<"you to some random room, which could be troublesome.\nThen those bats go to a new"
        <<"room different from where they came from and from the other bats.\n"
        <<"3.The Wumpus is not bothered by the pits or bats, as he has sucker feet"
        <<"and is too heavy for bats to lift. Usually he is asleep. \nTwo things wake him up:"
        <<"Anytime you shoot an arrow, or you entering his room. The Wumpus will move into the"
        <<"lowest-numbered adjacent \nroom anytime you shoot an arrow. When you move into the Wumpus' room,"
        <<"then he wakes and moves if he is in an odd-numbered room, \nbut stays still otherwise. After that, "
        <<"if he is in your room, he snaps your neck and you die!\n";
    cout<<"Moves:\nOn each move you can do the following, where input can be upper or lower-case:\n1. Move into an adjacent room. To move enter 'M' followed"
        <<"by a space and then a room number.\n";
    cout<<"2. Shoot your guided arrow through a list of up to three adjacent rooms, which you specify. Your arrow ends up in the final room. To \nshoot enter 'S'"
        <<"followed by the number of rooms (1..3), and then the list of the desired number (up to 3) of adjacent room numbers, \nseparated by spaces. If an "
        <<"arrow can't go a direction because there is no connecting tunnel, it ricochets and moves to the \nlowest-numbered adjacent room and continues doing this "
        <<"until it has traveled the designated number of rooms. If the arrow hits the \nWumpus, you win! If the arrow hits you, you lose. You automatically pick up "
        <<"the arrow if you go through a room with the arrow in it.\n";
    cout<<"3. Enter 'R' to reset the person and hazard locations, useful for testing.\n";
    cout<<"4. Enter 'C' to cheat and display current board positions.\n";
    cout<<"5. Enter 'D' to display this set of instructions.\n";
    cout<<"6. Enter 'P' to print the maze room layout.\n";
    cout<<"7. Enter 'X' to exit the game.\n\n";
    cout<<"Good luck!"<<endl;;
    
    cout<<"You are in room "<<player<<".";
    hazards();
    
}

//------------------------------------------------------------------------------------------------------
// prints the maze 
void printLayout(){
    
    cout<<endl;
cout<<"        _______18________          "<<endl
    <<"       /        |        \\        "<<endl
    <<"      /      ___9__       \\       "<<endl
    <<"     /      /      \\       \\     "<<endl
    <<"    /      /        \\       \\    "<<endl
    <<"   17      8        10      19     "<<endl
    <<"   |\\     /\\        /\\      /|  "<<endl
    <<"   | \\   /  \\      /  \\    / |  "<<endl
    <<"   |   7     1----2     11   |     "<<endl
    <<"   |   |    /      \\     |   |    "<<endl
    <<"   |   6---5        3---12   |     "<<endl
    <<"   |   |    \\      /     |   |    "<<endl
    <<"   |   \\     \\    /      |   |    "<<endl
    <<"   |    \\      4        /    |    "<<endl
    <<"   |     \\     |       /     |    "<<endl
    <<"    \\    15----14-----13    /     "<<endl
    <<"     \\   /             \\   /     "<<endl
    <<"      \\ /               \\ /      "<<endl
    <<"       16----------------20        "<<endl;

    cout<<"You are in room "<<player<<".";
    hazards();

}


//------------------------------------------------------------------------------------------------------
// When the user enters to move the following steps are executed 
void playerMove()
{
    int move;
    cin>>move;
    int tempPlayer = player;
    int tempBats;
    for(int i=0;i<3;i++)
    {
        if(move == board[player-1][i])
        {
            player = move;
        }
    }  
    cout<<"You are in room "<<player<<".";
//............................    
    if(player == arrow) // to check if the player entered the room with arrow
    {
        arrow = -1;
        cout<<"Congratulations, you found the arrow and can once again shoot.";
    }
//............................
    if(player == bats_1) // to check if the player entered the room with bats
    {
        tempBats = bats_1;
        do
        {
            bats_1 = (rand()%20)+1;
            player = (rand()%20)+1;
        } 
        while(player == wumpus || player == bats_1 || player == pit_1 || player == bats_2||
              player == pit_2  || bats_1 == pit_2  || bats_1 == pit_1 || bats_2 == bats_1||bats_1 == tempBats);
        
        cout<<"You've just been transported by bats to room "<<player<<endl;
        cout<<"You are in room "<<player<<".";
    }
    else if( player == bats_2)
    {
        tempBats = bats_2;
        do
        {
            bats_2 = (rand()%20)+1;
            player = (rand()%20)+1;
        } 
        while(player == wumpus || player == bats_1 || player == pit_1 || player == bats_2||
              player == pit_2  || bats_2 == pit_2  || bats_2 == pit_1 || bats_2 == bats_1||bats_2 == tempBats);
        cout<<"You've just been transported by bats to room "<<player<<endl;
        cout<<"You are in room "<<player<<".";
    }
//............................
    
    if(player == pit_1 || player == pit_2) // to check if player entered the room with pits
    { 
        cout<<"Aaaaaaaaahhhhhh....\nYou fall into a pit and die.";
        exit (0);
    }
    hazards();
    cout<<endl;
//............................

    if(player == wumpus)
    {
        if(wumpus%2 == 0)
        {
            cout<<"You briefly feel a slimy tentacled arm as your neck is snapped. It is over."<<endl;
            exit (0);
        }
        else
        {
            for(int i = 0;i<3;i++)
            {
                if(board[wumpus-1][i] != tempPlayer)
                {
                    cout<<"You hear a slithering sound, as the Wumpus slips away. Whew,that was close!";
                    wumpus = board[wumpus-1][i];
                    break;
                }
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------
// if the player shoots the arrow the following conditions are checked
void shoot()
{
    bool b1 = false;
    if(arrow == -1) // if the arrow was with player
    {
        int roomNum;
        cout<<"Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves:";
        cin>>roomNum;
        int tempArrow = player;
        
        for(int j=0;j<roomNum;j++)
        {
            cin >> arrow;
            for(int i=0;i<3;i++)
            {
                if(board[tempArrow-1][i] == arrow)
                {
                    tempArrow = arrow;
                    b1 = true;
                    //cout<<tempArrow;
                }
            }
            if(!b1){
                cout<<"Room "<<arrow<<" is not adjacent. Arrow ricochets..."<<endl; 
               tempArrow = board[tempArrow-1][0];
                //cout<<tempArrow;
               if(tempArrow == player){
                   cout<<" You just shot yourself, and are dying. It didn't take long, you're dead."<<endl;
                   exit(0);
               }
                if(tempArrow == wumpus){
                    cout<<" Your arrow ricochet killed the Wumpus, you lucky dog! Accidental victory, but still you win!"<<endl;
                    exit(0);
                }
            }     
        }
        arrow = tempArrow;
        if(arrow == wumpus)
            {
                cout<<"Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter.";
                cout<<endl<<"Exiting Program......"<<endl;
                exit (0);
            }
    }
    else
    {
        cout<<"Sorry, you can't shoot an arrow you don't have. Go find it.";
    }
}


//------------------------------------------------------------------------------------------------------
// this is the starting function where the user chooses what they want to do 
void start()
{

    cout<<endl<<"Enter your move (or 'D' for directions): ";
    cin>>c;
    c = tolower(c);
    int tempArrow;
    
    if(c == 'd'){
    maze();
    }
//............................
//to reveal the rooms
    else if(c =='c'){
        cout<<"Cheating! Game elements are in the following rooms:"<<endl;
        cout<<"player"<<" "<< "Wumpus"<<" "<< "bats_1" <<"  "<< "bats_2" <<"  "<< "pit_1"<<"  "<<"pit_2"<<"  "<<"arrow"<<endl;
        cout<<setw(3)<< player <<setw(8)<<wumpus <<setw(7)<< bats_1 <<setw(8)<< bats_2<<setw(8)<< pit_1<<setw(7)<<pit_2<<setw(7)<<arrow<<endl;
    }
//............................
//to print the layout of the cave
    else if(c=='p'){
        printLayout();
    }
//............................
//to manually give in the room number
    else if(c=='r')
    {
        cout<<"(Remember arrow value of -1 means it is with the person.)"
            <<"Enter the 7 room locations (1..20) for player, wumpus, bats1, bats2, pit1, pit2, \nand arrow:";
        cin>>player>>wumpus>>bats_1>>bats_2>>pit_1>>pit_2>>arrow;
        //cout<< player <<" "<< wumpus <<" "<< bats_1 << " "<< bats_2<<" "<< pit_1<<" "<<pit_2<<" "<<arrow<<endl;
        
        if(player == arrow)
        {
            cout<<" Congratulations, you found the arrow and can once again shoot."<<endl;
            arrow = -1;
        }
        cout<<"You are in room "<<player<<".";
        hazards();
    }
//............................ 
//to move the player   
    else if(c=='m')
    {
        playerMove();
    }
//............................ 
//to shoot an arrow   
    else if(c == 's')
    {
       shoot();
    }
//............................
//to exit the game
    else if( c == 'x')
    {
        exit(0);
    }
//............................
//recession for the game to continue till wumpus pr player dies
    while(arrow != wumpus)
    {
        start();
    }
}
//------------------------------------------------------------------------------------------------------
// does some basic work of generating the the first room of the participants and calls the start function which then continues the game using recursion
int main()
{
    do
    {
        srand(time(0));
        player = (rand()%20)+1;
        wumpus = (rand()%20)+1;
        bats_1 = (rand()%20)+1;
        bats_2 = (rand()%20)+1;
        pit_1 = (rand()%20)+1;
        pit_2 = (rand()%20)+1;
        arrow = (rand()%20)+1;
    }
    while( player == wumpus || player == bats_1 || player == pit_1 || 
           player == bats_2 || bats_1 == bats_2 || pit_1 == pit_2  || 
           bats_2 == pit_2  || player == pit_2  || arrow == wumpus || 
           arrow == bats_1  || arrow == pit_1   || arrow == pit_2  || 
           arrow == bats_2  || bats_1 == pit_2  || bats_1 == pit_1 || bats_2 == pit_1 );
    
    //cout<< player <<" "<< wumpus <<" "<< bats_1 << " "<< bats_2<<" "<< pit_1<<" "<<pit_2<<" "<<arrow<<endl;
    if(player == arrow) // to check if the random of player and arrow match
    { 
        arrow = -1;
        cout<<"Congratulations, you found the arrow and can once again shoot."<<endl;
    }
    
    cout<<"You are in room "<<player<<".";
    hazards(); // to check for hazards for the first generated randoms
    start(); // calls the start function to continue the game further
   
    return 0;
}