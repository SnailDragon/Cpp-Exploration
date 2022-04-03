#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

string GetValidInput(string inputOptions);
string PromptAction(string description, string options);
void GoStartingPlace();

void GoSouth();
void EnterMine();
void ClimbTree();
void ContinueMine();
void ClimbIntoHole();
void GoRightMine();
void GoLeftMine();
void NoFlashlightSneak();
void ContinueAsYouAre();

void GoNorth();
void ContinueTrail();
void FloatDownRiver();
void ClimbChain();
void ClimbChainLive();
void ClimbChainDie();
void HikeSwitchbacks();
void HikeSwitchbacksLive();
void HikeSwitchbacksDie();

void PrintVictoryHat(char fillChar, char hatChar, char tipChar, int maxSize);


int main(){

    //setup rand
    srand(time(0));

    cout << "Welcome to your amazing forest adventure. Enter b to begin." << endl;
    GetValidInput("b");
    GoStartingPlace();
    
    return 0;
}

string GetValidInput(string inputOptions){
    string inputValue = "";
    cin >> inputValue;
    while(inputOptions.find(inputValue) == string::npos){
        cout << "Bad input, must be: " << inputOptions << endl;
        cin >> inputValue;
    }
    return inputValue;
}

string PromptAction(string description, string options){
    int split = description.find("Do you");
    cout << endl;
    cout << description.substr(0,split) << endl;
    cout << description.substr(split) << endl;
    return GetValidInput(options);
}


void GoStartingPlace(){
    string inputValue = "";
    string message = "You come to in the middle of what looks to be a disused hiking trail with no memory of how you got there and no service. The trail goes downhill to the north and uphill to the south. Do you a) go south or b) go north?";
    string options = "ab";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        GoSouth();
    }
    else {
        GoNorth();
    }

}

// north branch

void GoNorth(){
    string inputValue = "";
    string message = "You walk north. After a bit you come to a bridge over a fairly large, lazy river. There is a small amount of wooden debris by the bridge including a very intact looking barre. Looking ahead you can see the trail following the river until it disappears behind a bend. Do you a) continue hiking along the trail or b) float down the river in the barrel or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        ContinueTrail();
    }
    else if(inputValue == "b") {
        FloatDownRiver();
    }
    else {
        GoStartingPlace();
    }
}

void ContinueTrail(){
    string inputValue = "";
    string message = "You continue hiking and after following the lazy river for a brief stretch you see it speed up and tumble into a large waterfall. Next to the waterfall there are two ways down the cliffs, a rusty chain drilled into a large boulder and a series of very shallow switchbacks cut into the side of the cliffs. Do you a) climb down the chain or b) hike down the switchbacks or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        ClimbChain();
    }
    else if(inputValue == "b") {
        HikeSwitchbacks();
    }
    else {
        GoNorth();
    }
}

void ClimbChain(){
    int liveOrDieProb = rand() % 10;
    if(liveOrDieProb < 7){
        ClimbChainLive();
    }
    else{
        ClimbChainDie();
    }
}

void ClimbChainLive(){
    cout << endl;
    cout << "You pull on chain, it feels sturdy enough, and begin to climb down the cliff. You have a few close calls but the chain holds and you make it down the cliff. In the distance you can see a small town as the river open up into a lake. Finally, people." << endl;
    cout << "Here's your victory hat!" << endl;
    PrintVictoryHat(' ', '*', '+', 6);
    cout << "THE END" << endl;
}

void ClimbChainDie(){
    cout << endl;
    cout << "You pull on the chain, it doesn't budge, surely it will be sturdy enough. You put your weight on the chain and lean out over the cliff. Suddenly you hear a snap as one of the chain loops breaks and you tumble over the edge." << endl;
    cout << "THE END" << endl;
}

void HikeSwitchbacks(){
    int liveOrDieProb = rand() % 2;
    if(liveOrDieProb == 0){
        HikeSwitchbacksLive();
    }
    else{
        HikeSwitchbacksDie();
    }
}

void HikeSwitchbacksLive(){
    cout << endl;
    cout << "That chain does look rusty. You begin to inch your way down the tiny switchbacks and after a few close calls you make it to the bottom. Looking out you can see a town on the lake in the distance. You are saved." << endl;
    cout << "Here's your victory hat!" << endl;
    PrintVictoryHat(' ', '+', '*', 6);
    cout << "THE END" << endl;
}

void HikeSwitchbacksDie(){
    cout << endl;
    cout << "Not trusting the chain you begin to inch your way down the tiny switchbacks. Halfway down the cliff you hear a cracking sound under your feet and the trail beneath you gives way, sending you tumbling down the rocky cliff to your death." << endl;
    cout << "THE END" << endl;
}

void FloatDownRiver(){
    cout << endl;
    cout << "Grabbing the barrel and hopping inside you begin to float down the river. After a stretch of lazy river, the current starts to increase rapidly. Panicked you try to swim to side but it is too late, and a waterfall sweeps you over the edge. As you fall you can see a lake town in the distance, but that doesn't matter now." << endl;
    cout << "THE END" << endl;
}


// south branch

void GoSouth(){
    string inputValue = "";
    string message = "You walk south. After a bit the trail up ahead reaches the entrance of an abandoned mine. Next to mine is a tall tree that looks climbable. Do you a) enter the mine or b) climb the tree or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        EnterMine();
    }
    else if(inputValue == "b") {
        ClimbTree();
    }
    else {
        GoStartingPlace();
    }
}

void ClimbTree(){
    cout << endl;
    cout << "You climb the tree and see over the forest. Around you, you can see a few Black Emperor butterflies. At the top of the tree your phone buzzes to life. Service! You call for help and a search and rescue is dispatched to find you." << endl;
    cout << "Here's your victory hat!" << endl;
    PrintVictoryHat(' ', 'o', '#', 6);
    cout << "THE END" << endl;
}

void EnterMine(){
    string inputValue = "";
    string message = "Using your phone flashlight you enter the mine. The mine shaft is cold and damp, as you walk deeper you come to a hole in the floor. It's not too deep and you can see something glinting in the light of your flashlight. Do you a) continue into the mine or b) climb into the hole or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        ContinueMine();
    }
    else if(inputValue == "b") {
        ClimbIntoHole();
    }
    else {
        GoSouth();
    }
}

void ClimbIntoHole(){
    string inputValue = "";
    cout << "You climb into the hole and find a small metal box, half buried in the dirt. You open it to find a single slip of ancient looking paper. All you can make out of the writing says, \"beware the breezing breath\"" << endl;
    cout << "Enter a to continue on" << endl;
    string options = "a";
    inputValue = GetValidInput("a");
    ContinueMine();
}

void ContinueMine(){
    string inputValue = "";
    string message = "As you continue into the mine, you come to a fork in the tunnels. On the left, you can feel a slight draft, and on the right you can see a faint glimmer of light. Do you a) go left or b) go right or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        GoLeftMine();
    }
    else if(inputValue == "b") {
        GoRightMine();
    }
    else {
        EnterMine();
    }
}

void GoRightMine(){
    cout << endl;
    cout << "You go right, as and you walk the light grows larger and larger until you step out of a small cave in a grassy hillside. At the base of the hill, there is a small summer camp by the ocean, surrounded by strawberry fields. These people can help, you are saved." << endl;
    cout << "Here's your victory hat!" << endl;
    PrintVictoryHat(' ', '^', '@', 6);
    cout << "THE END" << endl;
}

void GoLeftMine(){
    string inputValue = "";
    string message = "You go left, hoping the draft mean a way out. After a few minutes of walking you hear a shuffling ahead of you. Do you a) turn off your flashlight and sneak or b) walk forwards as you are or c) go back";
    string options = "abc";
    inputValue = PromptAction(message, options);
    if(inputValue == "a"){
        NoFlashlightSneak();
    }
    else if(inputValue == "b") {
        ContinueAsYouAre();
    }
    else {
        ContinueMine();
    }
}

void NoFlashlightSneak(){
    cout << endl;
    cout << "You turn off your flashlight and begin to creep forwards. As you move forwards the shuffling stops. You continue forwards only to hear the shuffling start up again faster and this time coming towards you, attacking you." << endl;
    cout << "You have been pwned by a grue." << endl;
    cout << "THE END" << endl;
    
}

void ContinueAsYouAre(){
    cout << endl;
    cout << "You walk forwards as you are, light is your friend anyways. As you get closer to the shuffling it suddenly stops. You walk forwards to see nothing up a glint of animal eyes disappearing into the darkness.You keep walking and eventually reach a metal grate. After kicking open the grate you find yourself on the side of a small rural highway. Finally, back to civilization." << endl;
    cout << "Here's your victory hat!" << endl;
    PrintVictoryHat(' ', '#', '@', 6);    
    cout << "THE END" << endl;
}
// " " 0 + 6
void PrintVictoryHat(char fillChar, char hatChar, char tipChar, int maxSize){
    string layer = "";
    int height = rand() % maxSize + 5;
    for(int i = 0; i < height; ++i){
        for(int j = 1; j < (height*2); ++j){
            if( abs(j - (height)) < i){
                if(i == 1){
                    cout << tipChar;
                    break;
                }
                cout << hatChar;
            }
            else {
                cout << fillChar;
            }

        }
        cout << endl;
    }
    cout << "|";
    for(int i = 0; i < (height * 2)-3; i++){
        cout << "_";
    }
    cout << "|" << endl;
}




