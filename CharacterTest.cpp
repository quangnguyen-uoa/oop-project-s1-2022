#include<iostream>
#include<string>
#include"character.h"
#include"Bar.h"

using namespace std;

int main()
{
    {
        Character Alpha;
        if(Alpha.move_left() == "left")
        {
            cout<<Alpha.move_left()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.move_left()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.move_right() == "right")
        {
            cout<<Alpha.move_left()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.move_left()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.check_stand() == 0)
        {
            cout<<Alpha.stand()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.stand()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.check_fall() == 1)
        {
            cout<<Alpha.fall()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.fall()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.get_x() == 100)
        {
            cout<<Alpha.get_x()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.get_x()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.get_y() == 100)
        {
            cout<<Alpha.get_y()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.get_y()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.get_size() == 10)
        {
            cout<<Alpha.get_size()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.get_size()<<"\nTest failed!"<<endl;
        }
    }
    {
        Character Alpha;
        if(Alpha.get_life() == 3)
        {
            cout<<Alpha.get_life()<<"\nTest complete!"<<endl;
        }
        else{
            cout<<Alpha.get_life()<<"\nTest failed!"<<endl;
        }
    }
    return 0;
}