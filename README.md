#Managing daily activities, events, and tasks is an essential part of any department or organization. But what if you could build your own mini activity tracking system  using nothing more than the C programming language?

#In this blog, we walk through a clean and functional Department Activity Diary project written in C. This project demonstrates file handling, structures, CRUD operations, and menu-driven logic making it perfect for beginners looking to strengthen their fundamentals.
Project Overview

#The Department Activity Diary is a console-based C program that allows users to:
Add new activities
View all existing activities
Search activities by date
Edit an existing activity
Delete an activity
Store all data persistently in a simple text file
This project uses a flat-file database (diary.txt) instead of complicated databases, helping beginners understand the core logic clearly.

#Why This Project Is Useful:
This mini-project teaches some of the most important concepts in C:
1.Working with Structures
 The program defines a structure for activity entries
 2.File Handling (One of the most important C concepts)
It uses:
fopen()
fscanf()
fprintf()
remove()
rename() 

#How the Program Works
The program runs in a loop, showing a menu each time:
1. Add Activity
2. View All Activities
3. Search Activity
4. Edit Activity
5. Delete Activity
6. Exit
   
1. Adding an Activity
When the user chooses to add an activity, the program asks for:
a)Date
b)Task Name
c)Description
It then appends this record to diary.txt in this format:
(DD/MM/YYYY|Task Name|Description)
Using the pipe character (|) makes it easy to parse later.

2. Viewing All Activities
All lines from diary.txt are read and printed one by one.
[printf("\nDate: %s\nTask: %s\nDescription: %s\n", a.date, a.taskName, a.description);]
This gives the user a clean list of every recorded activity.
