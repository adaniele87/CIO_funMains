/*********************************************************/
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* October 09, 2013                                      */
/* animations.h                                          */
/*                                                       */
/* This file is to contain all the declarations of       */
/* animation functions. An animation function for the    */
/* time being may not return anything, and must take in  */
/* exactly 3 referenced integers where:                  */
/* int& firstParam = c; will hold the column of where to */
/*                      start displaying the animation   */
/* int& secondParam= r; will hold the row of where to    */
/*                      start displaying the animation   */
/* int& thirdParam = f; f will hold the frame to display */
/*                      when function is called          */
/*********************************************************/

const int DRAWRATE = 15; // how many times frame will print to screen

void marioWalking(int& c, int& r, int& f);