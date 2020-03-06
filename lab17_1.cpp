#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string textline;
    ifstream source;
    source.open("C:\\Users\\lab303-22\\Desktop\\lab17\\name_score.txt");
    bool havetext;
    havetext = getline(source,textline);
    vector <string> list_name;
    vector <float> list_score;
    vector <char> list_grade;
    while(havetext){
        char format[]="%[^:]: %f %f %f";
        char name[100];
        float a,b,c;
        sscanf(textline.c_str(),format,name,&a,&b,&c);
        list_name.push_back(name);
        list_score.push_back(a);
        list_score.push_back(b);
        list_score.push_back(c);  
        int sum=a+b+c;
        char grade;
        if(sum >= 80)
        {
         grade == 'A';   
        }
        else if(sum >= 70)
        {
        grade == 'B';
        }
        else if (sum >= 60)
        {
        grade == 'C';   
        }
        else if (sum >= 50)
        {
        grade == 'D';    
        }
        else if (sum < 50)
        {
        grade == 'F';
        }
       list_grade.push_back(grade);
       havetext = getline(source,textline); 
    }

    while(true){
      string commandtext;
      cout<<"Please input your command: ";
      getline(cin,commandtext);

      if (commandtext == "exit") break;
      else if (commandtext.substr(0,6) == "grade ")
      {
       string key = commandtext.substr(6,7);
       for(int i=0 ; i<26 ; i++)
        {
        if(list_grade[i] = key[0])
          {
        cout<< list_name[i]<<endl;    
          }        
        }
      }
      else if (commandtext.substr(0,5)=="name ")
      {
       string word = commandtext.substr(5,90);
       for(int i =0 ; i< 26 ; i++)
       {
        if(list_name[i]== word)
        {
         cout << list_name[i] << "'s grade = " << list_grade[i] << "\n"; 
        }      
      }
    }
    else
    {
        cout << "Invalid command" << "\n";
    }
  }
}