// Mastermind
// Program By:    Giancarlo David

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void playGame(char, char, char);
void options(char&, char&, char&);
void instructions();
bool checkNumbers(int[]);
void compare(int[], int[], bool &, char, char, char);

int main()
{
   int mainMenu;
   char spotOn = 'W';
   char correct = '*';
   char wrong = 'X';

   do
   {
      cout << setw(44) << "Mastermind" << endl << endl;
      cout << "1. Play Game" << endl;
      cout << "2. Options" << endl;
      cout << "3. Instructions" << endl;
      cout << "4. Exit" << endl << endl;

      cin >> mainMenu;

      while (mainMenu < 1 || mainMenu > 4)
      {
         cout << "Enter a valid option" << endl << endl;
         cin >> mainMenu;
      }

      switch (mainMenu)
      {
      case 1: playGame(spotOn, correct, wrong);
         break;
      case 2: options(spotOn, correct, wrong);
         break;
      case 3: instructions();
         break;
      case 4: cout << "Goodbye!" << endl;
         break;
      }
   } while (mainMenu != 4);

   cout << endl;

   system("pause");
   return 0;
}

void playGame(char spotOn, char correct, char wrong)
{
   const int numbers = 4;
   int random[numbers];
   int guess[numbers];
   int tries = 1;
   bool win = false;

   srand(time(NULL));
   
   for (int count = 0; count < 4; count++)
   {
      random[count] = rand() % 9 + 1;
   }

   cout << endl << "Enter your guesses with each number separated by a space.\nThe numbers will be from 1-9 inclusive" << endl << endl;
   cout << "Wrong: " << wrong << "\tCorrect number, wrong position: " << correct << "\nCorrect number and correct position: " << spotOn << endl;

   do
   {
      cout << "\nAttempt " << tries << endl;

      for (int count = 0; count < 4; count++)
      {
         cin >> guess[count];
      }
      
      if (checkNumbers(guess) == false)
      {
         cout << "Please make sure to put a space in between your guesses.\nAlso make sure that your numbers are 1-9 inclusive." << endl;
         continue;
      }

      else
      {
         compare(random, guess, win, spotOn, correct, wrong);

      }

      tries++;
   } while (win == false && tries < 11);

   if (win == true)
   {
      cout << "You won!" << endl;
      system("pause");
   }
   else if (win == false)
   {
      cout << "You lost!" << endl;
      system("pause");
   }
}

void options(char &spotOn, char &correct, char &wrong)
{
   int choice;

   cout << endl;
   do
   {
   cout << "1. Correct number and position = " << spotOn << endl;
   cout << "2. Correct number and wrong position = " << correct << endl;
   cout << "3. Wrong number = " << wrong << endl << endl;
   cout << "Enter 1, 2, or 3 to change the corresponding setting\nor 0 to go back to main menu." << endl;
   cin >> choice;


      switch (choice)
      {
      case 0:
         break;
      case 1:
      {
         cout << "\nPlease enter the symbol you would like to use for\n\"Correct number and position\": " ;
         cin >> spotOn;
         break;
      }
      case 2:
      {
         cout << "\nPlease enter the symbol you would like to use for\n\"Correct number and wrong position\": ";
         cin >> correct;
         break;
      }
      case 3:
      {
         cout << "\nPlease enter the symbol you would like to use for\n\"Wrong number\": ";
         cin >> wrong;
         break;
      }
      default:
      {
         cout << "\nPlease select a valid option." << endl;
      }
      }
      cout << endl;
   } while (choice != 0);
}

void instructions()
{
   cout << endl;
   cout << "* Try to guess the numbers in the correct order" << endl;
   cout << "* You have 10 attempts to get all 4 numbers in the correct order" << endl;
   cout << "* Good luck and have fun!" << endl << endl;

   system("pause");
}

bool checkNumbers(int guess[])
{
   bool check = true;

   for (int count = 0; count < 4; count++)
   {
      if (guess[count] < 1 || guess[count] > 9)
      {
         check = false;
      }
   }
   return check;
}

void compare(int numbers[], int guess[], bool &win, char spotOn, char correct, char wrong)
{
   int spotOnCounter = 0;

   for (int num = 0; num < 4; num++)
   {
      bool right = false;
      bool position = false;
      
      for (int count = 0; count < 4; count++)
      {
         if (guess[num] == numbers[count])
         {
            right = true;
         }
      }
      if (guess[num] == numbers[num])
      {
         position = true;
      }

      if (right == true && position == true)
      {
         cout << spotOn << " ";
         spotOnCounter++;
      }
      else if (right == true && position == false)
      {
         cout << correct << " ";
      }

      else if (right == false && position == false)
      {
         cout << wrong << " ";
      }
   }

   if (spotOnCounter == 4)
   {
      win = true;
   }

   cout << endl;
}
