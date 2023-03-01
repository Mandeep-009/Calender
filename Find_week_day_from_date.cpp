#include <iostream>

using namespace std;

int main()
{
    int ly=0;
    int m,d,y;int mc,dc,cc;
    
    cout<<"Enter date: ";
    cin>>d;
    
    if(d>31||d<1)
    {
        cout<<"Invalid input\nRestart the program";
        return 0;
    }
    
    cout<<"Enter month number: ";
    cin>>m;
    
    if(m>12||m<1)
    {
        cout<<"Invalid input\nRestart the program";
        return 0;
    }
    
    if(m==2)
    {
        if(d>29)
        {
            cout<<"Invalid input\nRestart the program";
            return 0;
        }
    }
    else if((m==4||m==6||m==9||m==11))
    {   if(d>30){
        cout<<"Invalid input\nRestart the program";
        return 0;}
    }
    
    
    cout<<"Enter year: ";
    cin>>y;
    
    if(y<0)
    {
        cout<<"Invalid input\nRestart the program";
        return 0;
    }
    
    // checking if the year is leap or not
    int ot=y%100;
    if(ot==0)
    {
        if(y%400==0) ly=1;
    }
    else if(ot%4==0)
    {
        ly=1;
    }
    
    // checking validity of date with leap year
    if(ly==0&&m==2&&d==29)
    {
        cout<<"Invalid input\nRestart the program";
        return 0;
    }
    
    // finding century code cc
    cc=(y-ot)%400;
    switch(cc)
    {
        case 100:
        cc=4;break;
        
        case 200:
        cc=2;break;
        
        case 300:
        cc=0;break;
        
        case 000:
        cc=6;break;
    }
    
    // finding month code mc
    switch(m)
    {
        case 1:
        if(ly==1) mc=0;
        else mc=1;
        break;
        
        case 2:
        if(ly==1) mc=3;
        else mc=4;
        break;
        
        case 3:
        mc=4;break;
        
        case 4:
        mc=0;break;
        
        case 5:
        mc=2;break;
        
        case 6:
        mc=5;break;
        
        case 7:
        mc=0;break;
        
        case 8:
        mc=3;break;
        
        case 9:
        mc=6;break;
        
        case 10:
        mc=1;break;
        
        case 11:
        mc=4;break;
        
        case 12:
        mc=6;break;
    }
    
    int wd=(d+mc+cc+ot+(ot/4))%7;
    switch (wd)
    {
        case 1:
        cout<<"Sunday";
        break;
        
        case 2:
        cout<<"Monday";
        break;
        
        case 3:
        cout<<"Tuesday";
        break;
        
        case 4:
        cout<<"Wednesday";
        break;
        
        case 5:
        cout<<"Thursday";
        break;
        
        case 6:
        cout<<"Friday";
        break;
        
        case 0:
        cout<<"Saturday";
        break;
    }

    return 0;
}

