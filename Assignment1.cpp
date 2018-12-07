#include <iostream>
#include <fstream>
#include <list>
using namespace std;


int insertIntoSortedArray(int myArray[], int size, int newValue)
{
    // find position going backwards, copying over
    bool done = false;
    int i=size;
    while (i>0 && !done)
    {
        if (newValue > myArray[i-1])
            done = true;
                    else
        {
            myArray[i] = myArray[i-1];
            i--;
        }
    }
    myArray[i] = newValue;
    size++;
    return size;
}
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
  int p, temp;

    for (int i = 0; i < numEntries+1; i++)
    {
      if (myArray[i] < newValue && myArray[i] > 0)
      {
        i++;
      }
      else
      {
        temp = myArray[i];
        p = i+1;
        myArray[i] = newValue;
        break;
      }
    }

  for (int i = p; i < numEntries+1; i++)
  {
    int temp1 = myArray[i];
    myArray[i] = temp;
    temp = temp1;
  }
}

struct User
{
  string username;
  float gpa;
  int age;
};

void addUser(vector<User> *users, string _username, float _gpa, int _age)
{
  User newUser;
  newUser.username = _username;
  newUser.gpa = _gpa;
  newUser.age = _age;

  users->push_back(newUser);
}

void printList(const vector<User> users)
{
  for (int i = 0; i < users.size(); i++)
  {
    cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << endl;
  }
}

class Movie
{
private:
  string title;
  int year;
  float rating;
public:
  Movie()
  {
    title = "unknown";
    year = 2018;
    rating = 0.0;
  }
  Movie(string ititle, int iyear, float irating)
  {
    title = ititle;
    year = iyear;
    rating = irating;
  }
  string getTitle();
  void setTitle(string newTitle);
  int getYear();
  void setYear(int newyear);
  float getRating();
  void setRating(float newrating);
};

string Movie::getTitle()
{
  return title;
}
void Movie::setTitle(string newtitle)
{
  title = newtitle;
}
int Movie::getYear()
{
  return year;
}
void Movie::setYear(int newyear)
{
  year = newyear;
}
float Movie::getRating()
{
  return rating;
}
void Movie::setRating(float newrating)
{
  rating = newrating;
}

int main(int argc, char * argv[])
{
  int array[100];
  ifsteam filename;
  string line;
  int numentries = 0;
  int value;
  filename.open("assignment1problem1.docx");
  if(filename.is_open())
  {
    while(getline(filename,line));
    {
      value = stoi(line);
      numentries++;
      insertIntoSortedArray(array,numentries,value);
      line++;
      cout << array[0];
      for (int i = 1; i < numentries; i++)
      {
        cout << ", " << array[i];
      }
    }
  }
}
