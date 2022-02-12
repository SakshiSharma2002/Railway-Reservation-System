# RAILWAY-RESERVATION-SYSTEM

This system is concerned with the reservation of railway tickets and live enquiries for the passenger.

## TOTAL SCREENS IN THE PROJECT

Overall , the project "Railway Reservation System" , have the following screens:
1. Main Screen
2. View Trains
3. Book Ticket
4. View Ticket
5. Search Ticket No
6. View All Bookings
7. View Train Bookings
8. Cancel Ticket
9. Cancel Train

## STEPS TO BE DONE BEFORE DESIGNING THE "Main Screen"

Before designing the Main Screen , we need to do the following:
1. Add support of conio2.h in the project.
2. Create a header file called "rlyres.h" which will contain structure declarations, typedef statements and function declarations.
3. Create a source code file called "rlyres.c" which will contain definitions of the functions declared in the file "rlyres.h". 

## ADDING "conio2.h" SUPPORT
1. Create the project "Railway Reservation System" in CODEBLOCKS.
2. Download the file conio21.zip from the url https://sourceforge.net/projects/conio/.
3. Unzip the file and copy 2 files "conio.c" and "conio2.h" from it into your project folder.
4. Now we can call all BORLAND style functions like clrscr(),getch(), textcolor(),gotoxy() etc in the project.

## STRUCTURES

The project have 2 structures called "TRAIN" and "PASSENGER" .

The structure TRAIN have following data members:
1. train_no :- string (for storing train number).
2. from :- string (for storing FROM station code).
3. to :- string(for storing TO station code).
4. fac_fare :- int (for storing fare amount of FIRST AC).
5. sac_fare :- int(for storing fare amount of SECOND AC). 

The structure PASSENGER have following data members:
1. p_name :- string (for storing name of the passenger).
2. gender :- char (for storing gender of the passenger as M or F).
3. train_no :- string(for storing train number).
4. p_class :- char (for storing the F for FIRST AC and S for SECOND AC).
5. address :- string(for address of the passenger).
6. age :- int (for storing passenger's age).
7. ticketno :- int(for storing ticket number).
8. mob_no :- string(for storing passenger's mobile number).

## THE "MAIN SCREEN" OF THE PROJECT
============================================================================================

![Main Screen](https://user-images.githubusercontent.com/77681258/153720843-07c94706-16cd-4c66-9e49-a769adf01457.jpg)

## VIDEO OF THE PROJECT
============================================================================================
https://user-images.githubusercontent.com/77681258/153721731-3bacf6fe-7c61-42e0-9f87-cd45ac6790e7.mp4

