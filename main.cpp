#include<iostream>
#include "Circle.h"
#include <fstream>
#include <vector>
#include <memory>
#include<cstdlib>
#include <fstream>
#include <sstream>
using namespace std;
const int SIZE = 10;
// pay attention to this parameter list
int inputData(vector<shared_ptr<Circle>> &circlePointerArray, string filename)

{
  ifstream inputFile(filename);
  istringstream instream;
  string data;
  int count =0;
  int x,y,radius;
  try{
  if (inputFile){
    while (!inputFile.eof() && count <SIZE){
      getline(inputFile,data);
       istringstream instream(data);
       instream>>x;
       instream>>y;
       instream>>radius;
       //create a new Circle object and push it into
       //the vector
       shared_ptr<Circle> circle = make_shared<Circle>(x,y,radius);
       circlePointerArray.push_back(circle);
  
       count++;    
  
    }

  }
  else throw string("File Not Found");
  }
  catch (string message){
    cout<<message<<endl;
    exit(0);
  }
 return count;
}
//bool greaterThan(shared_ptr<Circle> other)
//{
//	return radius>other->getRadius();
//}
int main(){
   shared_ptr<Circle> circleOnePtr = make_shared<Circle>(0,0,5);
   // create a new shared pointer to a Circle Object

	shared_ptr<Circle> circleTwoPtr = make_shared<Circle>(-2,-2,10);
   //*************** create another shared pointer called circleTwoPtr
   //
   

   if (circleOnePtr->greaterThan(circleTwoPtr))
      cout<<" Circle One is bigger "<<endl;
   else 
      cout<<" Circle Two is bigger "<<endl;

// declare a vector of shared pointers to Circle objects
   
   std::vector<shared_ptr<Circle>>circlePointerVector;
   int count = inputData(circlePointerVector, "dataLab4.txt");
   cout<<"The total number of circles is "<<count<<endl;
   cout<<"They are :"<<endl;
   for (int i=0;i<count;i++)
    cout<<circlePointerVector[i]->toString()<<endl;
    double sumOfAreas=0;
    for (int i=0;i<count;i++)
      sumOfAreas+=circlePointerVector[i]->getArea();
   cout<<"The total sum of the areas is "<<sumOfAreas<<endl;
  shared_ptr <Circle>tmpPtr=make_shared<Circle>();
   circlePointerVector[1]=circlePointerVector[3];
   cout<<"The modified array is "<<endl;
   for (int i=0;i<count;i++)
    cout<<circlePointerVector[i]->toString()<<endl;
   return 0;
   
}
