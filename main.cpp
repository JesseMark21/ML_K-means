#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <ostream>
using namespace std;
struct Point {
    double x{0}, y{0};
    int exNo;
};

double sq(double rt){
    return (rt)*(rt);
}

double calcDistanceSq(Point first, Point second){
    return sq(first.x - second.x) + sq(first.y - second.y);
}
int main(int argc, char** argv)
{
    double t1, t2, t3;
    int itNum = 1;
 
    ofstream myfile;
    myfile.open("Output.txt");
    
    int numberExamples;
    cout<<"\nEnter the number of Examples:\n";
    cin>>numberExamples;

    double xValues[10];
    double yValues[10];

    Point cluster1[numberExamples];
    Point cluster2[numberExamples];
    Point cluster3[numberExamples];

 
    cout<<"\nEnter X attributes(in order):\n";
    for(int i = 0; i < numberExamples; i++)
    {
        cin>>xValues[i];
    }
    cout<<"\nEnter corresponding Y attributes:\n";
    for(int i = 0; i < numberExamples; i++)
    {
        cin>>yValues[i];
    }

    vector<Point> points(numberExamples);

    for(int i = 0; i < numberExamples; i++){
        Point temp;
        temp.x = xValues[i];
        temp.y = yValues[i];
        temp.exNo =i+1;

        points[i] = temp;
    }
    Point cent1 = points[0];
    Point cent2 = points[3];
    Point cent3 = points[6];
    Point oldC1, oldC2, oldC3;
 
    do
    {
     
    //saving old means
    myfile << endl << "Iteration " << itNum<< endl;

    itNum+=1;
    oldC1 = cent1;
    oldC2 = cent2;
    oldC3 = cent3;
 
    int int1 = 0;
    int int2 = 0;
    int int3 = 0;
    int int4 = 0;


    for(int k=0; k<numberExamples;k++)
    {
        t1= sqrt(calcDistanceSq(points[k], cent1));
        if(t1<0){t1=-t1;}
 
        t2= sqrt(calcDistanceSq(points[k], cent2));
        if(t2<0){t2=-t2;}

        t3= sqrt(calcDistanceSq(points[k], cent3));
        if(t3<0){t3=-t3;}
 
        if(t1<t2 && t1<t3)
        {
            cluster1[int2] = points[k];
            int2++;
        }
        else if(t2<t1 && t2<t3)
        {
            cluster2[int3]= points[k];
            int3++;
        }
        else if(t3<t1 && t3<t2){
            cluster3[int4]= points[k];
            int4++;
        }
 
    }
 

    double xSum = 0;
    double ySum = 0;
    double xMean = 0;
    double yMean = 0;


    for(int j=0;j<int2;j++)
    {
        double newX = cluster1[j].x;
        double newY = cluster1[j].y;
        
        xSum += newX;
        ySum += newY;

    }
    double d2 = (double) int2;

    xMean = xSum/d2;
    yMean = ySum/d2;
    cent1.x = xMean;
    cent1.y = yMean;

    xSum=0;
    ySum=0;
    xMean = 0;
    yMean = 0;

    for(int j = 0;j < int3; j++)
    {
        double newX = cluster2[j].x;
        double newY = cluster2[j].y;
        
        xSum += newX;
        ySum += newY;
    }

    double d3 = (double) int3;
    xMean = xSum/d3;
    yMean = ySum/d3;
    cent2.x = xMean;
    cent2.y = yMean;

    xSum=0;
    ySum=0;
    xMean = 0;
    yMean = 0;

    for(int j = 0;j < int4; j++)
    {
        double newX = cluster3[j].x;
        double newY = cluster3[j].y;
        
        xSum += newX;
        ySum += newY;
    }
    double d4 = (double) int4;
    xMean = xSum/d4;
    yMean = ySum/d4;
    cent3.x = xMean;
    cent3.y = yMean;
 
    myfile<<"\nCluster 1: ";
    for(int k=0;k<int2;k++)
    {
        if(k == int2-1){
            myfile<<cluster1[k].exNo << endl;
        }
        else{
        myfile<<cluster1[k].exNo << ", ";
        }
    }
    myfile<<"\nCentroid: "<<"("<<cent1.x<<", "<<cent1.y<<")"<<endl;
 
    myfile<<"\nCluster 2: ";
    for(int k=0;k<int3;k++)
    {
        if(k == int3-1){
            myfile<<cluster2[k].exNo << endl;
        }
        else{
        myfile<<cluster2[k].exNo << ", ";
        }
    }
    myfile<<"\nCentroid: "<<"("<<cent2.x<<", "<<cent2.y<<")"<<endl;

    myfile<<"\nCluster 3: ";
    for(int k=0;k<int4;k++)
    {
        if(k == int4-1){
            myfile<<cluster3[k].exNo << endl;
        }
        else{
        myfile<<cluster3[k].exNo << ", ";
        }
    }
    myfile<<"\nCentroid: "<<"("<<cent3.x<<", "<<cent3.y<<")"<<endl;
 
    myfile<<endl;
    }while(!(calcDistanceSq(cent1, oldC1)==0 &&calcDistanceSq(cent2, oldC2)==0 &&calcDistanceSq(cent3, oldC3)==0));

   
 
    cout<< endl << "Clusters created. Number of iterations: " << itNum-1;
 

}