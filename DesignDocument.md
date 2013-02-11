# Design Document for PA1 - Trevor Reed

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

> Third, there is a GMLWriter class which has only a single method called write(). This method takes in a list of user pointers and an output file and converts the user information to a gml file.

## Global Data/Functions
> I have only one global function in the sn.cpp file. It's called addUserData, and it takes in a pointer to a user object and a stringstream which it uses to populate the user object with information from an outside file.

> My global data include:
> + MyList<User*> userList - This list holds pointers to all of the users from the input gml file.
> + vector<string> nodes and vector<string> edges - These vectors hold the node and edge information in strings.
> + ofstream outputFile - This is the file that the GMLWriter will output the new gml file into.

## High-level Architecture
> My program takes an input gml file and uses it to fill in a list of user objects. Each user object has its own list of friend id numbers as well. Therefore, I can use the methods of the MyList class to make necessary changes to the users or their friend lists, and the methods of the User class can be used to change user information.

> The main algorithm that my code uses is mostly linear. The information from the input gml file is first split up into separate stringstreams and used to populate a list of user objects. Then, the program can do anything it needs to do with the list of user objects, including printing out user information, adding/removing friends, and changing information. Then, at the end, the list of users is printed out into a well-formatted GML file by the GMLWriter class.

> There are a few levels of complexity of object interaction, mostly because there is a MyList<User*> object which is full of Users, and each of the Users also has a MyList<int> inside of it. Therefore, these two classes are intertwined in order to create an efficient way to store lists of users who each have their own friend lists.

## User Interface
> Users will interact with this software completely through the terminal and through input gml and txt files. The input gml file will include information on all of the social network users, so the user will be able to edit this information before the program is run. Also, I could add options for the user to change information or add new users after the program has been started. The user will also be able to input a list of the friend connections they want to add or remove, through an input txt file, and then the program will implement the connections itself.

>The software won't have a GUI, but it should be simple to run using only the terminal and correct input/output files.

##Test Cases
> I will test my system by creating multiple different test gml files and test txt files. These files will include user data and connections in multiple different orders and numbers to make sure my program can handle the input files regardless of their size and order of information.
> + I'll test the system by running it multiple times with the different gml and txt files and making sure it runs correctly with all of them.
> + Some potential problem cases are: Incomplete gml files (users without all of the information needed), multiple users with the same names/ages/zip codes, and txt files that try to make connections between non-existent users.
> + To test these, I'll make input gml files that are incomplete and make sure the user objects are instantiated correctly. Also, I'll make gml files that have users with the same information to see how my program deals with them. Then, I'll also create input txt files that try to create connections between users that exist and don't exist and see how it handles it.

> + For my addUserData() function, I'll try to test it using incomplete gml files (users missing a name/age or other information). I would expect it to create the users normally but simply leave some fields blank. 
> + For my GMLWriter::write() function, I'll try running it with many different lists of users to make sure it can handle different sizes and orders of information. I expect it to work the same and organize the data itself. Also, I can run it with incomplete users, in which case I would expect it to fill the output gml file normally but with a few blank fields for the missing information.
