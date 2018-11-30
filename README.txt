Group 7-Project
Inside the folder you will find some files containing our work for the project.
To open it, you can use the executable file (ConsoleApplication.exe) which will open the console and let you see our work:
You can choose what action you want to execute by entering the number corresponding to the action:
Press 7 and Enter to exit the program
Press 1 and Enter for Zero-order-hold
Press 2 and Enter for Moving average
Press 3 and Enter for Holt tau=1
Press 4 and Enter for Holt tau=1,2,3
Press 6 and Enter for High-low method (we were 5 in the group so we needed another method although it is not for prediction
but analysis)
Press 5 and Enter to execute every method of data prediction

Once you choose a method, the program will ask you which time series you want to choose:
Press 1 and Enter for Random Series
(The following ones are normally only for Holt's method but we added them so you can have more examples)
Press 2 and Enter for Labour Hours
Press 3 and Enter for Total Costs

The Program repeats itself until you decide to Exit (7)

You will also find every program inside the files, named after what they do (i.e. zero_hold.cpp for the zero_order_hold)
The main function is in ConsoleApplication.cpp but it redirects to menu.cpp
Every definition is inside Header.h
Both excel tables are included in the program, make sure to add them if you want to compile the program on your own.
