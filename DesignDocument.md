# Design Document for PA1

## Purpose/Overview
> This piece of software will emulate a basic social networking platform. It will do this by storing information and ID's for multiple users and keeping track of the connections between different users. Also, it will be able to read GML files to create new users and create GML files from the user information.


## Requirements
> This software is supposed to read gml files and transfer their information into a list of users who all have unique attributes. Also, this program must also do the opposite - take a list of users and print all the information out into a properly-formatted gml file. Lastly, this program has to manage all the connections between users (edges connecting nodes).rs, each with their own data, and handle the connections between all the different users (edges between nodes).

## Classes
> The first class is the MyList class.
> + Its purpose is to hold and manage a list of pointers to variables of any kind (templated class).
> + Its member data include an integer called size to keep track of the list's size, an integer called capacity to determine when the list needs to be allocated more memory, and T* data_ to hold the actual array of data.
> + Its methods include a constructor and destructor, size() to return the size of the list, push_back(T item) to add an item to the list, at(int loc) to return the value at a certain location, and remove(T val) to remove the first instance of a certain value from the list.

> Second, there is a User class.
> + Its purpose is to store the information of a single user, include name, zip code, age, id number, and friend list.
> + Its member data include three integers to store a user's zip code, age, and id number. It also has a string to hold the user's name and an integer list (MyList<int>) to store the user's friends' id numbers.
> + It has constructors and a destructor, getters and setters for each of the user's attributes (name, id, zip, age), and a function friend() which returns a pointer to the user's friend list.

> What classes do you need to create?
> + Describe the purpose of each class.
> + What member data will they have? Why?
> + What methods will they have? Why?
> Make sure you describe each member variable and member function.


## Global Data/Functions
> What global data & functions do you have? Describe any pieces of your program that are not within a class. You don't need to describe every single variable you use, but are there any global variables or functions that are integral to how your program works?

## High-level Architecture
> What is the high level flow of data through your program? How will all of your objects interact? What are the algorithms that your code will use?

> You will spend a lot of time describing in detail all the objects and functions that you'll use, but you need to talk a bit about how they all fit together.


## User Interface
> Describe how the user will interact with your software.

> If you have a GUI, how will it be laid out (provide a sketch if possible)?
> + Where will buttons and other controls be located?
> + Describe how the user will interact with it.

> If you don't have a GUI, what kind of interaction will the user have?
> + What data will the user enter?
> + How will they enter it?


##Test Cases
> + How do you plan on testing your system?
> + What are the potential problem cases?
> + What are some nominal test cases?
> + For each function, describe some possible tests (what data would you pass in? What results do you expect?)
