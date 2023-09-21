#include<iostream>
#include<fstream> //File handling operation
#include<sstream> // provide template for string buffers
#include<string>
using namespace std;
int main()
{
    int a,i=0;
    string text,old,password0,password1,password2,pass,name,age,user,word,word1;
    string creds[2],cp[2];
    cout<<"         Security Check        "<<endl;
    cout<<"                               "<<endl;
    cout<<"|-----------------------------|"<<endl;
    cout<<"|        1.Register           |"<<endl;
    cout<<"|        2.Login              |"<<endl;
    cout<<"|        3.Change Password    |"<<endl;
    cout<<"|        4.End Program        |"<<endl;
    cout<<"|-----------------------------|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your Choice:- ";
        cin>>a;
        switch(a)
        {
            case 1:{
                cout<<"                           "<<endl<<endl;
                cout<<"========= Register ========"<<endl;
                cout<<"                           "<<endl<<endl;
                cout<<"Please  enter Username:  ";
                cin>>name;
                cout<<"Please enter the Password: ";
                cin>>password0;
                cout<<"Please enter your age: ";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");//To open file
                if(of1.is_open()){ //To check all the files
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration Successfull"<<endl;
                }
                break;
                
            }
            case 2:{
                i=0;
                cout<<"                           "<<endl<<endl;
                cout<<"========== Login ==========="<<endl;
                cout<<"                           "<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:- ";
                cin>>user;
                cout<<"Please enter the password:- ";
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof()) //end of file function return 0 if file ends
                    {
                        while(getline(of2,text)) //while loop with getline is used to read file line by line
                        {
                            istringstream iss(text); //i string stream object is used to stream string and store using extraction operator
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }
                        if(user==creds[0] && pass== creds[1])
                        {
                            cout<<"--------Log in Successful-----------";
                            cout<<endl<<endl;
                            cout<<"Details: "<<endl;
                            cout<<"username: "+ name<<endl;
                            cout<<"Password: "+pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }
                        else
                        {
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|             a.Press 2 to LOGIN            |"<<endl;
                            cout<<"|        b.Press 3 to Change Password       |"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"--------------Change Password----------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password:- ";
                cin>>old;
                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1; //new password
                            i++;
                        }
                        if(old==cp[1])
                        {
                            of0.close();
                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"Enter Your New Password:- ";
                                cin>>password1;
                                cout<<"Enter your password again:- ";
                                cin>>password2;
                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password Changed Successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password does not match"<<endl;
                                }
                            }
                            else{
                                cout<<"Please Enter a Valid Password"<<endl;
                                break;
                            }
                        }
                    }
                    
                }
                break;
            }
                case 4:{
                    cout<<"----------- Thank You ------------"<<endl;
                    break;
                }
                default:
                {
                    cout<<"Enter a Valid Choice"<<endl;
                }
        }
    } while(a!=4);
    return 0;
}