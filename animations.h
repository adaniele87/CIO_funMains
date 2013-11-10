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
/* int& thirdParam = f; will hold the frame to display   */
/*                      when function is called          */
/*********************************************************/

const int DRAWRATE = 10; // how many times frame will print to screen

void car       (int& c, int& r, int& f);
void character (int& c, int& r, int& f);
void oat       (int& c, int& r, int& f);
void house     (int& c, int& r, int& f);
void marioWalk (int& c, int& r, int& f);
void tree      (int& c, int& r, int& f);
void truck     (int& c, int& r, int& f);


//for fighting game
void walkLeft        (int& c, int& r, int& f);
void walkRight       (int& c, int& r, int& f);
void punchLeft       (int& c, int& r, int& f);
void punchRight      (int& c, int& r, int& f);
void getPunchedLeft  (int& c, int& r, int& f);
void getPunchedRight (int& c, int& r, int& f);