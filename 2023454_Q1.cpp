#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
using namespace std;

//function declarations
void TOH_mini(int numDisk, string BEGIN, string AUX, string END );
void TOH_main(int numDisk, string BEGIN, string AUX1, string AUX2, string END);

long long int counter = 0;  //to assess the number of function calls

int main (){

    string BEGIN = "T1", AUX1 = "T2", AUX2 = "T3", END = "T4";

    int numDisk;
    cout<<"Enter the number of disks : ";
    cin>>numDisk;

    if (numDisk < 0){
        cout<<"Invalid";
        exit(0);
    }
    auto start = std::chrono::high_resolution_clock::now();
    //cout<<"The sequence of steps are:- "<<endl;
    TOH_main(numDisk, BEGIN, AUX1, AUX2, END);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time taken by the function: " << duration.count() << " microseconds" << std::endl;


    cout<<"Total number of moves required = "<<counter<<endl;

    return 0;
}

//function definitions
void TOH_mini(int numDisk, string BEGIN, string AUX, string END ){
    
    //base cases
    if (numDisk == 0){
        return;
    }

    if (numDisk == 1){
        //cout<<BEGIN<<" -> "<<END<<endl;
        counter++;
        return;
    }

    //recursive cases
    TOH_mini(numDisk-1, BEGIN, END, AUX);
    //cout<<BEGIN<<" -> "<<END<<endl;
    counter++;

    TOH_mini(numDisk-1, AUX, BEGIN, END);
    return;

}

void TOH_main(int numDisk, string BEGIN, string AUX1, string AUX2, string END){

    int j,k,j1,j2;
    
    j = numDisk/1.5;  //dividing the problem into sub-problem of size n/1.5  --> 
                        //arrived at 1.5 through plotting a graph and checking at 
                        //what value of n/X does Number of Moves reach minimum
    k = numDisk - j;

    j1 = j/2;       //dividing the sub-problem into another sub-problem of size n/4
    j2 = j - j1; 

    TOH_mini(j1, BEGIN, AUX1, AUX2 );   //moving j disks from top of BEGIN to AUX1 using AUX 2 and END
    TOH_mini(j2, BEGIN, END, AUX1 );
    TOH_mini(j1, AUX2, END, AUX1 );

    TOH_mini(k, BEGIN, AUX2, END );    //moving k disks from bottom of BEGIN to END using AUX2

    TOH_mini(j1, AUX1, AUX2, BEGIN );   //moving j disks from AUX1 to END using AUX2 and BEGIN
    TOH_mini(j2, AUX1, AUX2, END );
    TOH_mini(j1, BEGIN, AUX2, END );

    return;
}