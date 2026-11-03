//Jasmine Lawrence
//Project 2 Shooting Queue: This program will simulate a shooting queue at a shooting range by reading from the text file given.

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

//Shooter Class with the attributes: name, bulletCount, and initialBulletCount
class Shooter {
private: 
    string name;
    int bulletCount;
    int initialBulletCount;

public: 
    Shooter(string shooterName, int bullet) {       //creates object with Name and bullet number
      name = shooterName;               //initalize the name attribute
      bulletCount = bullet;               //initalize the bulletCount attribute
      initialBulletCount = bullet;        //initalize the initialBulletCount attribute  
    }

    void shooting(){
      if (bulletCount > 0) { //check if there are bullets left and decrement the bullet count every time
        bulletCount--;
      }
    }

    string getName(){       //returns the name of the shooter
      return name;
    }

    int getQuantity(){       //returns the number of bullets the shooter has
      return bulletCount;
    }

    void display(){       //displays the shooter's name and number of bullets
      cout << "Shooter: " << name;
      cout << " Bullets: " << bulletCount << endl;
    }
};

//Shooting Range Queue
int main(){

  queue<Shooter> shootingRange;

  ifstream inputFile("Week3-bulletCount.txt");    //opens text file

  if(!inputFile){       //checks if file was opened 
    cout << "Error opening file." << endl;
    return 1;
  }

  string name;
  int bullets;

//read shooter information from text file
while (inputFile >> name >> bullets){
  if(bullets < 0){
    cout << "Error: Cannot have negative amount of bullets." << endl;
  }
  else if(bullets == 0){
    cout << "Shooter: " << name << " has already completed their round!" << endl;
  }
  else{
    Shooter newShooter(name, bullets);        //create a shooter
    shootingRange.push(newShooter);           //add the shooter to the queue
    newShooter.display();                        //display the shooter's information  
  }
}
inputFile.close();    //close the input file 

  while(!shootingRange.empty()){    //while the queue is not empty
    Shooter currentShooter = shootingRange.front();     //get the head of the queue
    shootingRange.pop();     //remove the head of the queue
    currentShooter.shooting();     //let the current shooter shoot
    
    if(currentShooter.getQuantity() == 0 ){
      cout << "Shooter: " << currentShooter.getName() << " is completed!"<< endl;       //checks if shooter has used all bullets
    }
    else{
      cout << "Shooter: " << currentShooter.getName() << " needs to shoot "<< currentShooter.getQuantity() << " more bullets." << endl;
      shootingRange.push(currentShooter);     //add the shooter back to the queue to continue shooting
      cout << "Shooter: " << currentShooter.getName() << " is sent back to the queue. Remaining bullets: " << currentShooter.getQuantity() << endl;     //gets remaining bullets number
    }

  }
  cout << "Shooter Queue is completed" << endl;
  return 0;
}
