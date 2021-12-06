//CS20B1109
//Nischal Pradyoth
#include<iostream>
using namespace std;
//NOTE:If any of the parameter is less than or equal to zero we treat it as zero only and do calculations respectively
//Area class 
/*
Note: No need of a separate header file.	
Write a C++ program with Area and Volume class. The Area class has length, breath, and radius private data members. 
It has rectangle, and circle public member functions that calculate and return the area of the respective shape. 
All the member functions are inline functions and friend functions. If the parameters of a shape are not given,
 it calculates the unit area of the respective shape.

The Volume class has length, breadth, height and radius private data members. It has cuboid, sphere, compare cuboid, 
and compare sphere public member functions. The cuboid and sphere member functions are inline functions that use the 
respective area friend function of Area class to calculate the volume of the respective shapes. The compare volume function 
prints which among the two volumes is greater than the other. Utilize this pointer when calling compare volume function. 
If the parameters of a shape are not given, it calculates the unit volume of the respective shape.

Write a menu driven program to calculate the area of rectangle, area of circle, unit area of rectangle,
 unit area of circle, unit volume of cuboid, unit volume of sphere, volume of cuboid, volume of sphere,
  compare volume of two cuboids and compare volume of two spheres options. 
*/
class Area
{
    //Keeping data members private
    private:
        float length,breadth,radius;
    public:
        friend float Rectangle(Area,float,float);
        friend float Circle(Area,float);
};
inline float Circle(Area a1,float r=1)//Circle friend function for calculating area of Circle
{
    a1.radius=r;
    if(a1.radius<=0){return 0; }
    return(a1.radius*a1.radius*22/7);
}
inline float Rectangle(Area a1,float l=1,float b=1)//Rectangle friend function for calculating area of Rectangle
{
    a1.length=l;
    a1.breadth=b;
    if(a1.length<=0||a1.breadth<=0){  return 0;}
    return (a1.length*a1.breadth);
}
//Volume class 
class Volume
{
    private://private data members
        float length,breadth,height,radius;
    public:
        //Using Rectangle and Circle functions from Area class as they are friend functions
        friend float Rectangle(Area,float,float);
        friend float Circle(Area,float);
        //For the below two functions we are calculating volume by creating Area object and calling respective area function 
        inline float Cuboid(float l=1,float b=1,float h=1)
        {
            length=l; breadth=b; height=h;
            if(length<=0||breadth<=0||height<=0){return 0;}
            Area object;
            float area=Rectangle(object,length,breadth);
            return (area*height);
        }
        inline float Sphere(float r=1)
        {
            radius=r;
            if(radius<=0){return 0;}
            Area object;
            float area=Circle(object,radius);
            return (area*radius*4/3);
        }
        //For the below two functions we are comparing volumes by using the above two functions
        void compareCuboid(Volume v2)
        {
            
            int choice; float volume1,volume2;
            //Here we are asking whether he want to enter the parameters or not, if not we call by default
            cout<<"Do you want to enter parameters for cuboid1, if so enter 1:";
            cin>>choice;
            if(choice==1)
            {   cout<<"Enter length,breadth and height for cuboid1:";
                cin>>this->length>>this->breadth>>this->height;
                volume1=this->Cuboid(this->length,this->breadth,this->height);
            }
            else{volume1=this->Cuboid();}
            cout<<"Do you want to enter parameters for cuboid2, if so enter 1:";
            cin>>choice;
            if(choice==1)
            {   cout<<"Enter length,breadth and height for cuboid2:";
                cin>>v2.length>>v2.breadth>>v2.height;
                volume2=v2.Cuboid(v2.length,v2.breadth,v2.height);
            }
            else{volume2=v2.Cuboid();}
            
            if(volume1>volume2)
            {
                cout<<"Cuboid1 is higher with volume="<<volume1<<endl;
            }
            else if(volume1<volume2)
            {
                cout<<"Cuboid2 is higher with volume="<<volume2<<endl;
            }
            else
            {
                cout<<"Both are of equal volume="<<volume1<<endl;
            }
        }
        void compareSphere(Volume v2)
        {
            int choice; float volume1,volume2;
                //Here we are asking whether he want to enter the parameters or not, if not we call by default
            cout<<"Do you want to enter parameters for sphere1, if so enter 1:";
            cin>>choice;
            if(choice==1)
            {   cout<<"Enter radius for Sphere1:";
                cin>>this->radius;
                volume1=this->Sphere(this->radius);
            }
            else{volume1=this->Sphere();}
            cout<<"Do you want to enter parameters for sphere2, if so enter 1:";
            cin>>choice;
            if(choice==1)
            {   cout<<"Enter radius for Sphere2:";
                cin>>v2.radius;
                volume2=v2.Sphere(v2.radius);
            }
            else{volume2=v2.Sphere();}
            
            if(volume1>volume2)
            {
                cout<<"Sphere1 is higher with volume="<<volume1<<endl;
            }
            else if(volume1<volume2)
            {
                cout<<"Sphere2 is higher with volume="<<volume2<<endl;
            }
            else
            {
                cout<<"Both are of equal volume="<<volume1<<endl;
            }
        }
};
//Main function 
int main()
{
    int choice,length,breadth,radius,height;
    Area a1;
    Volume v1,v2;
    //printing menu
    cout<<"1.Area of Rectangle"<<endl;
    cout<<"2.Area of Circle"<<endl;
    cout<<"3.Unit area of Rectangle"<<endl;
    cout<<"4.Unit area of Circle"<<endl;
    cout<<"5.Unit volume of Cuboid"<<endl;
    cout<<"6.Unit volume of Sphere"<<endl;
    cout<<"7.Volume of Cuboid"<<endl;
    cout<<"8.Volume of Sphere"<<endl;
    cout<<"9.Compare volume of 2 cuboids"<<endl;
    cout<<"10.Compare volume of 2 spheres"<<endl;
    cout<<"11.Exit"<<endl;
    while(1)
    {
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter length and breadth of Rectangle:";
            cin>>length>>breadth;
            cout<<"Area of Rectangle is:";
            cout<<Rectangle(a1,length,breadth)<<endl;
            break;
        case 2:
            cout<<"Enter radius of Circle:";
            cin>>radius;
            cout<<"Area of Circle is:"<<Circle(a1,radius)<<endl;
            break;
        case 3:
            cout<<"Area of Unit Rectangle is:"<<Rectangle(a1)<<endl;
            break;
        case 4:
            cout<<"Area of Unit Circle is:"<<Circle(a1)<<endl;
            break;
        case 5:
            cout<<"Volume of Unit Cuboid is:"<<v1.Cuboid()<<endl;
            break;
        case 6:
            cout<<"Volume of Unit Sphere is:"<<v1.Sphere()<<endl;
            break;
        case 7:
            cout<<"Enter length,breadth,height of Cuboid:";
            cin>>length>>breadth>>height;
            cout<<"Volume of Cuboid is:"<<v1.Cuboid(length,breadth,height)<<endl;
            break;
        case 8:
            cout<<"Enter radius of Sphere:";
            cin>>radius;
            cout<<"Volume of Sphere is:"<<v1.Sphere(radius)<<endl;
            break;
        case 9:
            v1.compareCuboid(v2);//Here we are calling w.r.t one object and passing other as parameter
            break;
        case 10:
            v1.compareSphere(v2);
            break;
        case 11:
            return(1);
            break;
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
    }
    }
    return 0;
}