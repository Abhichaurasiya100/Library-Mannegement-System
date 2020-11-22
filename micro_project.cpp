
#include<iostream>
#include<conio.h>
#include <fstream>
using namespace std;
void truncate_obj(int i);
void clear()
{
  system("cls");
}
int authenticate_student(string user_name,string password)
{ clear();
  int result=0;



  ifstream file;

  file.open("user_student.csv");
  string user;
  string pass;
  while (file.good())
  {
    getline(file,user,',');
    getline(file,pass,'\n');
    if(user==user_name && pass==password)
    {
      result=1;
break;
    }
    else
    {
      result=0;
    }


  }
return result;
}
int authenticate_admin()
{
  int result=0;
  string user_name;
  string password;
  clear();
  cout<<"Hi\nPlease enter your Username and Password. \n\n";
  cout<<"Enter your Username :- ";
  cin>>user_name;
  cout<<"Enter your password :- ";
  cin>>password;

  ifstream file;

  file.open("user_admin.csv");
  string user;
  string pass;
  while (file.good())
  {
    getline(file,user,',');
    getline(file,pass,'\n');
    if(user==user_name && pass==password)
    {
      result=1;
break;
    }
    else
    {
      result=0;
    }


  }
  clear();
return result;
}
void user_student();
void user_admin(int status);
class book
{
public:
  string book_id;
  string title;
  string author;
  string publisher;
  string description;
  string stock;

public:
  void read(int j)
  {
    int i=0;
    string temp;
    ifstream file;
    file.open("book_rec.csv");

    while(file.good())
    { ++i;
      if(i!=j)
      {
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,'\n');
      }
      else
      {
        getline(file,book_id,',');
        getline(file,title,',');
        getline(file,author,',');
        getline(file,publisher,',');
        getline(file,description,',');
        getline(file,stock,'\n');
        break;
      }
    }
  file.close();

  }
  void show()
  {
      cout<<"Book id :- "<<book_id<<"\n"<<"Title :- "<<title<<"\n"<<"Author :- "
      <<author<<"\n"<<"Publisher :- "<<publisher<<"\n"<<"Description :- "
      <<description<<"\n"<<"Stock :- "<<stock<<endl;
      cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
  }

}book_obj[10];

class user_student
{
public:
  string user_name;
  string name;
  string course_code;
  string division;
  string contact_no;

  void read(int j)
  {
    int i=0;
    string temp;
    ifstream file;
    file.open("user_student_rec.csv");
    while(file.good())
    { ++i;
      if(i!=j)
      {
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,'\n');
      }
      else
      {
        getline(file,user_name,',');
        getline(file,name,',');
        getline(file,course_code,',');
        getline(file,division,',');
        getline(file,contact_no,'\n');
        break;
      }
    }
  file.close();
  }
  void show()
  {
    cout<<"User name :- "<<user_name<<"\n"<<"Name :- "<<name<<"\n"<<"Course Code :- "
    <<course_code<<"\n"<<"Division :- "<<division<<"\n"<<"Contact No :- "
    <<contact_no<<"\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

  }
}user_student_obj[10];


class borrowed_rec
{
public:
  string book_id;
  string title;
  string author;
  string publisher;
  string date;
  string name;
  string user_name;
  void read(int j)
  {
    int i=0;
    string temp;
    ifstream file;
    file.open("borrowed_rec.csv");

    while(file.good())
    { ++i;
      if(i!=j)
      {
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,',');
      getline(file,temp,'\n');
      }
      else
      {
        getline(file,book_id,',');
        getline(file,title,',');
        getline(file,author,',');
        getline(file,publisher,',');
        getline(file,name,',');
        getline(file,user_name,',');
        getline(file,date,'\n');
        break;
      }
    }
  file.close();
  }
  void show()
  {
    cout<<"Book id :- "<<book_id<<"\n"<<"Title :- "<<title<<"\n"<<"Author :- "<<author<<"\n"<<"Publisher :- "<<publisher<<"\n"<<"Name :- "<<name<<"\n"<<"User name :- "<<user_name<<"\n"<<"Date :- "<<date<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

  }
void borrow()
{
  cout<<"Enter book id which is going to borrowed :- ";
  cin>>book_id;
  cout<<"Enter user name of student who is borrowing the book  :- ";
  cin>>user_name;
  cout<<"Enter borrow date :- ";
  cin>>date;
  for(int i=1;i<=10;i++)
  {
    if(book_id==book_obj[i].book_id)
    {  title=book_obj[i].title;
      author=book_obj[i].author;
      publisher=book_obj[i].publisher;
      if(user_name==user_student_obj[i].user_name)
      {
        name=user_student_obj[i].name;
      }
    }

  }
  ofstream file;
  file.open("borrowed_rec.csv",ios::app);
  file<<book_id<<","<<title<<","<<author<<","<<publisher<<","<<name<<","<<user_name<<","<<date<<endl;

  }

  void update(int insert_status)
  { ofstream file;
    file.open("borrowed_rec.csv",ios::out);
    file<<book_id<<","<<title<<","<<author<<","<<publisher<<","<<name<<","<<user_name<<","<<date<<endl;
    file.close();}
    void update()
    {
    ofstream file;
    file.open("borrowed_rec.csv",ios::app);
    file<<book_id<<","<<title<<","<<author<<","<<publisher<<","<<name<<","<<user_name<<","<<date<<endl;
    file.close();}

}borrowed_rec_obj[10];
void truncate_obj(int i)
{
  borrowed_rec_obj[i].book_id="";
  borrowed_rec_obj[i].title="";
  borrowed_rec_obj[i].author="";
  borrowed_rec_obj[i].publisher="";
  borrowed_rec_obj[i].date="";
  borrowed_rec_obj[i].name="";
  borrowed_rec_obj[i].user_name="";
}
void add_book()
{
  string book_id;
  string title;
  string author;
  string publisher;
  string description;
  string stock;
  cout<<"Book id :- ";
  cin>>book_id;
  cout<<"Title :- ";
  cin>>title;
  cout<<"Author :- ";
  cin>>author;
  cout<<"Publisher :- ";
  cin>>publisher;
  cout<<"Description :- ";
  cin>>description;
  cout<<"Stock :- ";
  cin>>stock;
  ofstream file;
  file.open("book_rec.csv",ios::app);
  file<<book_id<<","<<title<<","<<author<<","<<publisher<<","<<description<<","<<stock<<endl;
}
void fetch_data()
{
  int i;
  for(i=1;i<=10;i++)
  {
    book_obj[i].read(i);
    user_student_obj[i].read(i);
    borrowed_rec_obj[i].read(i);
  }
}
void return_book()
{ int insert_status=1;
  string book_id;
  string user_name;
  cout<<"Enter book id which is going to returned :- ";
  cin>>book_id;
  cout<<"Enter user name of student who is returning the book  :- ";
  cin>>user_name;
  for(int i=1;i<=10;i++)
  {
    if(book_id!=borrowed_rec_obj[i].book_id&&user_name==borrowed_rec_obj[i].user_name)
    {     if(insert_status==1)
      {
        borrowed_rec_obj[i].update(insert_status);
        insert_status++;
      }
      else
      {
        borrowed_rec_obj[i].update();}
    }
    if(book_id==borrowed_rec_obj[i].book_id&&user_name==borrowed_rec_obj[i].user_name)
    {
    truncate_obj(i);
    }
  }
  if(insert_status==1)
  {
    ofstream file;
    file.open("borrowed_rec.csv",ios::trunc);
    file.close();
  }
}
int main()
{
  int choice;
  fetch_data();
  cout<<"                                                                       Library Management System\n";

cout<<"\n\n\n\n\n\n\n                                                      --->> Please select appropriate option to move further <<---\n";
while(1)
{
  cout<<"--->> Enter '1' if you are student <<---\n";
  cout<<"--->> Enter '2' if you are Admin <<---\n";
  cout<<"--->> Enter '3' if you want to exit <<---\n";
  cout<<"\n\n Enter your choice :-  ";
  cin>>choice;
  if(choice==1||choice==2||choice==3)
  {
    break;
  }
  else
  {
    clear();
    cout<<" Wrong option! \n";
  }
}

  switch (choice)
  {
    case 1:clear();user_student(); break;
    case 2:clear();user_admin(0); break;
    case 3:exit(0);

  }
}
void user_student()
{
  int result=1,choice;
cout<<"Hi\nPlease enter your Username and Password which is given to you. \n\n";
string user_name;
  string password;
do{
  cout<<"Enter your Username :- ";
  cin>>user_name;
  cout<<"Enter your password :- ";
  cin>>password;

  result=authenticate_student(user_name,password);}
  while(result!=1);
  while(1){
cout<<"\n\n\n\n\n\n\n                                                      --->> Please select appropriate option to move further <<---\n";
cout<<"--->> Enter '1' To view list of books <<---\n";
cout<<"--->> Enter '2' To view your borrowed record <<---\n";
cout<<"--->> Enter '3' if you want to exit <<---\n";
cin>>choice;
if(choice==1||choice==2||choice==3)
{break;}
else
{clear();
  cout<<" Wrong option! \n";
}
}
clear();
switch(choice)
{
  case 1:
  for(int i=1;i<=10;i++)
    {
      book_obj[i].show();
    }
    break;
  case 2:

  for(int i=1;i<=10;i++)
    { if(user_name==borrowed_rec_obj[i].user_name)
        {
          borrowed_rec_obj[i].show();
        }
    }
    break;
  case 3:
exit(0);

}
cout<<"\n\nPress 1 to reach previous menu and 0 to exit : ";
cin>>choice;
if(choice==1)
{
  clear();
  user_student();
}
else
{
  exit(0);
}
}
void user_admin(int status)
{ cout<<"Hi\nPlease enter your Username and Password. \n\n";
  int result=0,choice;
if(status!=1)
{  do{
  result=authenticate_admin();
}
  while(result!=1);}
  while(1){
  cout<<"\n\n\n\n\n\n\n                                                      --->> Please select appropriate option to move further <<---\n";
  cout<<"--->> Enter '1' To view list of books <<---\n";
  cout<<"--->> Enter '2' To view student record <<---\n";
  cout<<"--->> Enter '3' To view book borrowed record <<---\n";
  cout<<"--->> Enter '4' To make new borrow entry <<---\n";
  cout<<"--->> Enter '5' To make return book entry <<---\n";
  cout<<"--->> Enter '6' To Add book <<---\n";
  cout<<"--->> Enter '7' if you want to exit <<---\n";
  cin>>choice;
  if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7)
  {break;}
  else
  {clear();
    cout<<" Wrong option! \n";
  }
  }
  clear();
  switch(choice)
  {
    case 1:
    for(int i=1;i<=10;i++)
      {
        book_obj[i].show();
      }
      break;

    case 2:
    for(int i=1;i<=10;i++)
      {
        user_student_obj[i].show();

      }
      break;

    case 3:
    for(int i=1;i<=10;i++)

      {
        borrowed_rec_obj[i].show();
      }break;

    case 4:
    int limit;
    cout<<"Enter how much entry do you want to make : ";
    cin>>limit;
for(int x=1;x<=limit;x++){
borrowed_rec_obj[1].borrow();}
fetch_data();
    break;
    case 5:
    return_book();
    fetch_data();

    {

      int i=0;
      string temp;
      ifstream file;
      file.open("borrowed_rec.csv");
      while(file.good())
      { ++i;
        getline(file,temp,',');
        getline(file,temp,',');
        getline(file,temp,',');
        getline(file,temp,',');
        getline(file,temp,',');
        getline(file,temp,',');
        getline(file,temp,'\n');
      }
    file.close();
    truncate_obj(i);
    }
    break;
    case 6:

    cout<<"Enter how many books do you want to add : ";
    cin>>limit;
for(int x=1;x<=limit;x++){
    add_book();}
    fetch_data();
    break;
    case 7:
    exit(0);
  }
  cout<<"\n\nPress 1 to reach previous menu and 0 to exit : ";
  cin>>choice;
  if(choice==1)
  { clear();

    user_admin(1);
  }
  else
  {
    exit(0);
  }
}
